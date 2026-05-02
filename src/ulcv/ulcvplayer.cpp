#include "ulcvplayer.h"
#include "dxt_tables.h"

#include <bn_log.h>
#include <bn_assert.h>

#include <gba_compression.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_timers.h>
#include <gba_video.h>

#include "bn_cstring.h"

// ULCV clean container v6 (240x160): matches ``ulcv/src/header.py``,
// ``frame.py`` (split flags + block stream), ``format.py`` / ``blocks/*.py``.

#define FORCEINLINE inline __attribute__((always_inline))
#define NOINLINE __attribute__((noinline))
#define IWRAM_FUNC __attribute__((section(".iwram"), noinline))
#define IWRAM_DATA __attribute__((section(".iwram_data")))

namespace ULCV
{
    namespace
    {
        static constexpr uint32_t ULCV_MAGIC = 0x56434C55; // "ULCV" little-endian
        static constexpr uint8_t ULCV_VERSION = 6;
        static constexpr uint32_t HEADER_BYTES = 20;

        static constexpr uint32_t WIDTH = 240;
        static constexpr uint32_t HEIGHT = 160;
        static constexpr uint32_t FRAME_PIXELS = WIDTH * HEIGHT;
        static constexpr uint32_t FRAME_BYTES = FRAME_PIXELS * 2;
        static constexpr uint32_t FRAME_WORDS = FRAME_BYTES / 4;

        static constexpr uint32_t MB_SIZE = 8;
        static constexpr uint32_t CHILD_SIZE = 4;
        static constexpr uint32_t MBW = WIDTH / MB_SIZE; // 30
        static constexpr uint32_t MBH = HEIGHT / MB_SIZE; // 20
        static constexpr uint32_t SPLIT_WORDS_PER_ROW = (MBW + 15) / 16; // 2
        static constexpr uint32_t SPLIT_FLAG_BYTES = MBH * SPLIT_WORDS_PER_ROW * 2; // 80

        static constexpr uint8_t FRAME_FLAG_KEEP = 1 << 0;
        static constexpr uint8_t FRAME_FLAG_COLOR = 1 << 1;

        // v6 block tokens (see ulcv/src/format.py)
        static constexpr uint16_t DXT_WORD0_MARKER = 0x8000;
        static constexpr uint16_t DXT_WORD1_LITE = 0x8000;
        static constexpr uint16_t BGR555_MASK = 0x7FFF;
        static constexpr uint16_t COMP_MARKER_MASK = 0xC000;
        static constexpr uint16_t COMP_MARKER = 0x4000;

        static constexpr uint8_t FRAME_CODEC_RAW = 0;
        static constexpr uint8_t FRAME_CODEC_LZ4 = 2;
        static constexpr uint8_t FRAME_CODEC_LZ4HC = 3;
        static constexpr uint8_t FRAME_CODEC_GBA_LZ77 = 4;
        static constexpr bool ENABLE_STRICT_BLOCK_CHECKS = false;

        IWRAM_DATA const uint8_t* m_videoSrc = nullptr;
        IWRAM_DATA const uint8_t* m_payloadStart = nullptr;
        IWRAM_DATA const uint8_t* m_payloadCursor = nullptr;
        IWRAM_DATA uint32_t* m_scratchPad = nullptr;
        IWRAM_DATA uint32_t m_scratchPadSize = 0;
        IWRAM_DATA uint16_t* m_currFrame = nullptr;
        IWRAM_DATA uint8_t* m_frameStream = nullptr;
        IWRAM_DATA uint32_t m_frameStreamCapacity = 0;
        IWRAM_DATA uint32_t m_frameIndex = 0;
        IWRAM_DATA int32_t m_framesDecoded = 0;
        IWRAM_DATA bool m_playing = false;
        IWRAM_DATA bool m_decodeFailed = false;
        IWRAM_DATA Info m_info;
        IWRAM_DATA volatile int32_t m_framesRequested = 0;
        IWRAM_DATA uint32_t m_lastErrorCode = 0;
        IWRAM_DATA uint32_t m_lastErrorA = 0;
        IWRAM_DATA uint32_t m_lastErrorB = 0;
        IWRAM_DATA uint32_t m_lastErrorC = 0;
        IWRAM_DATA __attribute__((aligned(4))) uint16_t m_blockColors[4];

        // Delta LUT for ColorCompensation. Computed at compile time and
        // placed in IWRAM so each lookup is 1 cycle (vs ~8 from ROM). The
        // table is 512 bytes — cheap on a 32 KB IWRAM budget.
        struct DeltaLut
        {
            uint8_t v[16][32];
        };

        struct Expand4To5Lut
        {
            uint8_t v[32];
        };

        constexpr auto buildDeltaLut() -> DeltaLut
        {
            DeltaLut lut{};
            for (int32_t d = -8; d <= 7; ++d)
            {
                for (int32_t c = 0; c < 32; ++c)
                {
                    int32_t r = c + d;
                    if (r < 0)
                    {
                        r = 0;
                    }
                    else if (r > 31)
                    {
                        r = 31;
                    }
                    lut.v[d + 8][c] = static_cast<uint8_t>(r);
                }
            }
            return lut;
        }

        // Use a dedicated read-only IWRAM section to avoid a section type
        // conflict with the mutable IWRAM_DATA group. The linker still places
        // .iwram_data.* into IWRAM, so lookups stay 1-cycle.
        __attribute__((section(".iwram_data.ulcv_lut"), aligned(4)))
        constexpr DeltaLut k_deltaLut = buildDeltaLut();

        // FORCEINLINE auto expand4To5(uint32_t v4) -> uint16_t
        // {
        //     v4 &= 0x0F;
        //     return static_cast<uint16_t>(((v4 << 1) | (v4 >> 3)) & 0x1F);
        // }

        constexpr auto build4To5Lut() -> Expand4To5Lut {
            // Expand 4-bit color values to 5 bits by replicating the high bit into the low bit, then masking to 5 bits. This is a common way to convert 4-bit color values to 5 bits while preserving the full range.
            Expand4To5Lut lut{};
            for (int32_t i = 0; i < 32; ++i) {
                const uint32_t v4 = i & 0x0F;
                lut.v[i] = static_cast<uint8_t>(((v4 << 1) | (v4 >> 3)) & 0x1F);
            }
            return lut;
        }

        __attribute__((section(".iwram_data.ulcv_lut"), aligned(4)))
        constexpr Expand4To5Lut k_expand4To5Lut = build4To5Lut();

        FORCEINLINE auto rgb444ToBgr555(const uint32_t r4, const uint32_t g4, const uint32_t b4) -> uint16_t
        {
            // const uint16_t r5 = expand4To5(r4);
            // const uint16_t g5 = expand4To5(g4);
            // const uint16_t b5 = expand4To5(b4);
            // return static_cast<uint16_t>(r5 | (g5 << 5) | (b5 << 10));

            const uint16_t r5 = k_expand4To5Lut.v[r4];
            const uint16_t g5 = k_expand4To5Lut.v[g4];
            const uint16_t b5 = k_expand4To5Lut.v[b4];
            return static_cast<uint16_t>(r5 | (g5 << 5) | (b5 << 10));
        }

        FORCEINLINE auto signext5(uint32_t u) -> int32_t
        {
            u &= 0x1F;
            return static_cast<int32_t>((u ^ 0x10) - 0x10);
        }

        FORCEINLINE auto signext4(uint32_t u) -> int32_t
        {
            u &= 0x0F;
            return static_cast<int32_t>((u ^ 0x08) - 0x08);
        }

        FORCEINLINE auto clearError() -> void
        {
            m_lastErrorCode = 0;
            m_lastErrorA = 0;
            m_lastErrorB = 0;
            m_lastErrorC = 0;
        }

        FORCEINLINE auto setError(uint32_t code, uint32_t a, uint32_t b, uint32_t c) -> void
        {
            if (m_lastErrorCode == 0)
            {
                m_lastErrorCode = code;
                m_lastErrorA = a;
                m_lastErrorB = b;
                m_lastErrorC = c;
            }
        }

        IWRAM_FUNC auto frameRequest() -> void
        {
            ++m_framesRequested;
        }

        FORCEINLINE auto readU16(const uint8_t* ptr) -> uint16_t
        {
            return static_cast<uint16_t>(ptr[0] | (ptr[1] << 8));
        }

        FORCEINLINE auto readU32(const uint8_t* ptr) -> uint32_t
        {
            return static_cast<uint32_t>(ptr[0]) |
                   (static_cast<uint32_t>(ptr[1]) << 8) |
                   (static_cast<uint32_t>(ptr[2]) << 16) |
                   (static_cast<uint32_t>(ptr[3]) << 24);
        }

        FORCEINLINE auto lz77UncompressedSize(const uint8_t* src, uint32_t srcSize) -> uint32_t
        {
            if (srcSize < 4 || src[0] != 0x10)
            {
                return 0;
            }
            return static_cast<uint32_t>(src[1]) |
                   (static_cast<uint32_t>(src[2]) << 8) |
                   (static_cast<uint32_t>(src[3]) << 16);
        }

        IWRAM_FUNC auto lz77_decompress_safe(const uint8_t* src, uint32_t srcSize, uint8_t* dst, uint32_t dstCapacity, uint32_t& outSize) -> bool
        {
            outSize = 0;
            if (srcSize < 4 || src[0] != 0x10)
            {
                setError(1101, srcSize, srcSize ? src[0] : 0, 0);
                return false;
            }

            const uint32_t expectedSize = lz77UncompressedSize(src, srcSize);
            if (expectedSize == 0 || expectedSize > dstCapacity)
            {
                setError(1102, expectedSize, dstCapacity, srcSize);
                return false;
            }

            uint32_t sp = 4;
            uint32_t dp = 0;
            uint32_t guard = 0;
            while (dp < expectedSize)
            {
                if (++guard > (expectedSize * 3 + 1024))
                {
                    setError(1103, guard, dp, expectedSize);
                    return false;
                }
                if (sp >= srcSize)
                {
                    setError(1104, sp, srcSize, dp);
                    return false;
                }

                const uint8_t flags = src[sp++];
                for (int bit = 0; bit < 8 && dp < expectedSize; ++bit)
                {
                    if ((flags & (0x80 >> bit)) == 0)
                    {
                        if (sp >= srcSize)
                        {
                            setError(1105, sp, srcSize, dp);
                            return false;
                        }
                        dst[dp++] = src[sp++];
                    }
                    else
                    {
                        if (sp + 1 >= srcSize)
                        {
                            setError(1106, sp, srcSize, dp);
                            return false;
                        }
                        const uint8_t first = src[sp++];
                        const uint8_t second = src[sp++];
                        const uint32_t len = ((first >> 4) & 0x0F) + 3;
                        const uint32_t dist = (((first & 0x0F) << 8) | second) + 1;
                        if (dist > dp)
                        {
                            setError(1107, dist, dp, len);
                            return false;
                        }
                        if (dp + len > expectedSize)
                        {
                            setError(1108, dp, len, expectedSize);
                            return false;
                        }
                        for (uint32_t i = 0; i < len; ++i)
                        {
                            dst[dp] = dst[dp - dist];
                            ++dp;
                        }
                    }
                }
            }

            outSize = expectedSize;
            return true;
        }

        FORCEINLINE auto clamp5(int32_t v) -> uint16_t
        {
            return static_cast<uint16_t>(v < 0 ? 0 : (v > 31 ? 31 : v));
        }

        // Hand-written ARM IWRAM routine: 32-byte (8-word) ldmia/stmia chunks.
        // Defined in ulcv_memcpy.s. About 2x faster than the naive C loop on
        // EWRAM->VRAM and EWRAM->EWRAM full-frame copies, which were eating
        // ~18%+9% of total frame time in the profile.
        extern "C" void ulcv_memcpy32(void* dst, const void* src, uint32_t wcount);

        FORCEINLINE auto copyWords32(uint32_t* dst, const uint32_t* src, uint32_t words) -> void
        {
            ulcv_memcpy32(dst, src, words);
        }

        FORCEINLINE auto blitFrameToVram(uint32_t* dst, const uint32_t* src) -> void
        {
            ulcv_memcpy32(dst, src, FRAME_WORDS);
        }

        FORCEINLINE auto copyPrevFrameToCurr(uint32_t* curr, const uint32_t* prev) -> void
        {
            ulcv_memcpy32(curr, prev, FRAME_WORDS);
        }

        // GCC/Clang: 32-bit loads/stores into uint16_t-typed buffers (BGR555 canvas, ``alignas(4)``
        // stack tiles) without global ``-fno-strict-aliasing`` and without per-pair memcpy. Same layout
        // as two LE halfwords. Use this anywhere we read/write a uint16_t[] through a uint32_t pointer.
        using Aliased32 = __attribute__((may_alias)) uint32_t;

        FORCEINLINE auto pack2x16(uint16_t lo, uint16_t hi) -> uint32_t
        {
            return static_cast<uint32_t>(lo) | (static_cast<uint32_t>(hi) << 16);
        }

        IWRAM_FUNC auto lz4_40_decompress(const uint8_t* src, uint32_t srcSize, uint8_t* dst, uint32_t dstCapacity, uint32_t& outSize) -> bool
        {
            outSize = 0;
            if (srcSize < 4)
            {
                setError(1001, srcSize, 0, 0);
                return false;
            }
            const uint32_t header = readU32(src);
            if ((header & 0xFF) != 0x40)
            {
                setError(1002, header, 0, 0);
                return false;
            }
            const uint32_t expectedSize = header >> 8;
            if (expectedSize > dstCapacity)
            {
                setError(1003, expectedSize, dstCapacity, 0);
                return false;
            }
            if (expectedSize == 0)
            {
                outSize = 0;
                return true;
            }

            uint32_t sp = 4;
            uint32_t dp = 0;
            uint32_t guard = 0;
            while (dp < expectedSize)
            {
                if (++guard > (expectedSize * 2 + 1024))
                {
                    setError(1011, guard, dp, expectedSize);
                    return false;
                }
                if (sp >= srcSize)
                {
                    setError(1004, sp, srcSize, dp);
                    return false;
                }
                const uint8_t token = src[sp++];
                uint32_t literalLen = (token >> 4) & 0x0F;
                uint32_t matchLen = token & 0x0F;

                if (literalLen == 15)
                {
                    uint8_t extra = 0;
                    do
                    {
                        if (sp >= srcSize)
                        {
                            setError(1005, sp, srcSize, literalLen);
                            return false;
                        }
                        extra = src[sp++];
                        literalLen += extra;
                    } while (extra == 255);
                }

                if (sp + literalLen > srcSize || dp + literalLen > expectedSize)
                {
                    setError(1006, sp + literalLen, srcSize, dp + literalLen);
                    return false;
                }
                // std::memcpy(dst + dp, src + sp, literalLen);
                // memcpy(dst + dp, src + sp, literalLen);
                bn::memcpy(dst + dp, src + sp, literalLen);

                sp += literalLen;
                dp += literalLen;

                if (dp >= expectedSize)
                {
                    break;
                }

                // LZ4 stores match offset+length only when match nibble != 0.
                if (matchLen)
                {
                    if (sp + 2 > srcSize)
                    {
                        setError(1007, sp + 2, srcSize, dp);
                        return false;
                    }
                    const uint32_t matchOffset = (static_cast<uint32_t>(src[sp]) << 8) | src[sp + 1];
                    sp += 2;
                    if (matchOffset == 0 || matchOffset > dp)
                    {
                        setError(1008, matchOffset, dp, sp);
                        return false;
                    }

                    if (matchLen == 15)
                    {
                        uint8_t extra = 0;
                        do
                        {
                            if (sp >= srcSize)
                            {
                                setError(1009, sp, srcSize, matchLen);
                                return false;
                            }
                            extra = src[sp++];
                            matchLen += extra;
                        } while (extra == 255);
                    }
                    matchLen += 3;
                    if (dp + matchLen > expectedSize)
                    {
                        setError(1010, dp + matchLen, expectedSize, matchLen);
                        return false;
                    }

                    const uint32_t start = dp - matchOffset;
                    for (uint32_t i = 0; i < matchLen; ++i)
                    {
                        dst[dp++] = dst[start + i];
                    }
                }
            }

            outSize = expectedSize;
            return true;
        }

        FORCEINLINE auto buildPaletteLut(uint16_t c0, uint16_t c1, uint16_t* colors) -> void
        {
            colors[0] = c0;
            colors[1] = c1;

            const uint32_t b = ((c0 & 0x7C00) >> 5) | ((c1 & 0x7C00) >> 10);
            const uint32_t g = (c0 & 0x03E0) | ((c1 & 0x03E0) >> 5);
            const uint32_t r = ((c0 & 0x001F) << 5) | (c1 & 0x001F);
            auto* c2c3Ptr = reinterpret_cast<uint32_t*>(&colors[2]);
            if (c0 > c1)
            {
                *c2c3Ptr = (DXT::C2C3_ModeThird_5bit[b] << 10) | (DXT::C2C3_ModeThird_5bit[g] << 5) | DXT::C2C3_ModeThird_5bit[r];
            }
            else
            {
                *c2c3Ptr = (static_cast<uint32_t>(DXT::C2_ModeHalf_5bit[b]) << 10) |
                           (static_cast<uint32_t>(DXT::C2_ModeHalf_5bit[g]) << 5) |
                           static_cast<uint32_t>(DXT::C2_ModeHalf_5bit[r]);
            }
        }

        // SWAR per-pair (2 BGR555 pixels in one u32) constants.
        static constexpr uint32_t CC_RB_MASK  = 0x7C1F7C1F;  // R5+B5 lanes for both pixels
        static constexpr uint32_t CC_G_MASK   = 0x03E003E0;  // G5 lanes
        static constexpr uint32_t CC_RB_CARRY = 0x80208020;  // bit-5 above each R5/B5
        static constexpr uint32_t CC_G_CARRY  = 0x04000400;  // bit-5 above each G5

        // Saturated add of ``rb_d`` (0..31 broadcast into R5/B5 lanes) to ``p``.
        // Writes back into ``rb`` (R5/B5 only); G5 lanes are computed by the caller in parallel.
        FORCEINLINE auto ccAddPair(uint32_t p, uint32_t rb_d, uint32_t g_d) -> uint32_t
        {
            uint32_t rb = (p & CC_RB_MASK) + rb_d;
            uint32_t g  = (p & CC_G_MASK ) + g_d;
            const uint32_t rb_over = rb & CC_RB_CARRY;
            const uint32_t g_over  = g  & CC_G_CARRY;
            rb |= rb_over - (rb_over >> 5);
            g  |= g_over  - (g_over  >> 5);
            return (rb & CC_RB_MASK) | (g & CC_G_MASK);
        }

        FORCEINLINE auto ccSubPair(uint32_t p, uint32_t rb_d, uint32_t g_d) -> uint32_t
        {
            uint32_t rb = (p & CC_RB_MASK) - rb_d;
            uint32_t g  = (p & CC_G_MASK ) - g_d;
            const uint32_t rb_under = rb & CC_RB_CARRY;
            const uint32_t g_under  = g  & CC_G_CARRY;
            rb &= ~(rb_under | (rb_under - (rb_under >> 5)));
            g  &= ~(g_under  | (g_under  - (g_under  >> 5)));
            return (rb & CC_RB_MASK) | (g & CC_G_MASK);
        }

        // Build per-pair SWAR delta operands (broadcast 5-bit |delta| into all six lanes of two u16s).
        FORCEINLINE auto ccBuildDeltaPair(int32_t delta, uint32_t& rb_d, uint32_t& g_d) -> void
        {
            const uint32_t d  = static_cast<uint32_t>(delta < 0 ? -delta : delta) & 0x1F;
            const uint32_t d2 = (d | (d << 5) | (d << 10)) * 0x00010001U;  // splat 16->32
            rb_d = d2 & CC_RB_MASK;
            g_d  = d2 & CC_G_MASK;
        }

        // Fused copy+cc; single non-templated IWRAM function so we don't pay 4×<SIZE>×<sign> code
        // duplication. ``delta != 0`` is required by all call sites (gated by ``hasCc``).
        //
        // src is always read via 2× LDRH (lo|hi<<16); on GBA EWRAM (16-bit bus) that's the same
        // bus cost as a single 32-bit LDR, regardless of src alignment — so we don't need a
        // separate aligned-fast path. dst is always 4-aligned in ULCV (px%4==0; stack tiles
        // alignas(4)) and is stored as Aliased32 to keep the strict-aliasing path legal.
        IWRAM_FUNC auto copyAndApplyColorDelta(uint16_t* dst, const uint16_t* src, int32_t delta,
                                                uint32_t size, uint32_t dstStride16,
                                                uint32_t srcStride16) -> void
        {
            uint32_t rb_d;
            uint32_t g_d;
            ccBuildDeltaPair(delta, rb_d, g_d);

            auto* dstPtr = reinterpret_cast<Aliased32*>(dst);
            const uint16_t* srcHw = src;
            const uint32_t pairsPerRow = size >> 1;
            const uint32_t dstAdv = (dstStride16 - size) >> 1;
            const uint32_t srcAdvHw = srcStride16 - size;
            const bool isAdd = delta > 0;

            for (uint32_t y = size; y--; )
            {
                for (uint32_t x32 = pairsPerRow; x32--; )
                {
                    const uint32_t p =
                        static_cast<uint32_t>(srcHw[0]) | (static_cast<uint32_t>(srcHw[1]) << 16);
                    srcHw += 2;
                    *dstPtr++ = isAdd ? ccAddPair(p, rb_d, g_d) : ccSubPair(p, rb_d, g_d);
                }
                srcHw += srcAdvHw;
                dstPtr += dstAdv;
            }
        }

        // In-place wrapper around the fused routine. FORCEINLINE so it costs zero IWRAM symbols —
        // call sites turn into a single ``copyAndApplyColorDelta(b, b, ...)``.
        FORCEINLINE auto applyColorDelta(uint16_t* block, int32_t delta, uint32_t size,
                                         uint32_t stride16) -> void
        {
            if (delta == 0) return;
            copyAndApplyColorDelta(block, block, delta, size, stride16, stride16);
        }

        // template <int32_t SIZE>
        // FORCEINLINE auto applyColorDeltaInPlace(uint16_t* dst, int32_t dstStride, int32_t delta) -> void
        // {
        //     if (delta == 0)
        //     {
        //         return;
        //     }
        //     const uint8_t* lut = k_deltaLut.v[delta + 8];
        //     for (int32_t y = 0; y < SIZE; ++y)
        //     {
        //         for (int32_t x = 0; x < SIZE; ++x)
        //         {
        //             const uint16_t c = dst[x];
        //             const uint16_t r = lut[c & 0x1F];
        //             const uint16_t g = lut[(c >> 5) & 0x1F];
        //             const uint16_t b = lut[(c >> 10) & 0x1F];
        //             dst[x] = static_cast<uint16_t>(r | (g << 5) | (b << 10));
        //         }
        //         dst += dstStride;
        //     }
        // }

        template <uint32_t BLOCK_DIM>
        FORCEINLINE auto copyBlockFast(uint16_t* dstPtr16, const uint16_t* srcPtr16, const uint32_t lineStride16, const bool linear) -> void;

        template <>
        FORCEINLINE auto copyBlockFast<4>(uint16_t* dstPtr16, const uint16_t* srcPtr16, const uint32_t lineStride16, const bool linear) -> void
        {
            // ARM7TDMI: STR/LDR with non-4-aligned address rotates/aligns down — must check BOTH
            // pointers, otherwise unaligned dst (px odd) silently writes to the wrong halfword pair.
            const uint32_t misalign = static_cast<uint32_t>(
                reinterpret_cast<uintptr_t>(dstPtr16) | reinterpret_cast<uintptr_t>(srcPtr16));
            if ((misalign & 3) != 0)
            {
                dstPtr16[0] = srcPtr16[0];
                dstPtr16[1] = srcPtr16[1];
                dstPtr16[2] = srcPtr16[2];
                dstPtr16[3] = srcPtr16[3];
                if (!linear) {
                    srcPtr16 += lineStride16;
                } else {
                    srcPtr16 += 4;
                }
                dstPtr16 += lineStride16;
                dstPtr16[0] = srcPtr16[0];
                dstPtr16[1] = srcPtr16[1];
                dstPtr16[2] = srcPtr16[2];
                dstPtr16[3] = srcPtr16[3];
                if (!linear) {
                    srcPtr16 += lineStride16;
                } else {
                    srcPtr16 += 4;
                }
                dstPtr16 += lineStride16;
                dstPtr16[0] = srcPtr16[0];
                dstPtr16[1] = srcPtr16[1];
                dstPtr16[2] = srcPtr16[2];
                dstPtr16[3] = srcPtr16[3];
                if (!linear) {
                    srcPtr16 += lineStride16;
                } else {
                    srcPtr16 += 4;
                }
                dstPtr16 += lineStride16;
                dstPtr16[0] = srcPtr16[0];
                dstPtr16[1] = srcPtr16[1];
                dstPtr16[2] = srcPtr16[2];
                dstPtr16[3] = srcPtr16[3];
            }
            else
            {
                auto* dstPtr32 = reinterpret_cast<Aliased32*>(dstPtr16);
                auto* srcPtr32 = reinterpret_cast<const Aliased32*>(srcPtr16);
                const uint32_t lineStride32 = lineStride16 / 2;
                dstPtr32[0] = srcPtr32[0];
                dstPtr32[1] = srcPtr32[1];
                if (!linear) {
                    srcPtr32 += lineStride32;
                } else {
                    srcPtr32 += 2;
                }
                dstPtr32 += lineStride32;
                dstPtr32[0] = srcPtr32[0];
                dstPtr32[1] = srcPtr32[1];
                if (!linear) {
                    srcPtr32 += lineStride32;
                } else {
                    srcPtr32 += 2;
                }
                dstPtr32 += lineStride32;
                dstPtr32[0] = srcPtr32[0];
                dstPtr32[1] = srcPtr32[1];
                if (!linear) {
                    srcPtr32 += lineStride32;
                } else {
                    srcPtr32 += 2;
                }
                dstPtr32 += lineStride32;
                dstPtr32[0] = srcPtr32[0];
                dstPtr32[1] = srcPtr32[1];
            }
        }

        template <>
        FORCEINLINE auto copyBlockFast<8>(uint16_t* dstPtr16, const uint16_t* srcPtr16, const uint32_t lineStride16, const bool linear) -> void
        {
            const uint32_t misalign = static_cast<uint32_t>(
                reinterpret_cast<uintptr_t>(dstPtr16) | reinterpret_cast<uintptr_t>(srcPtr16));
            if ((misalign & 3) != 0)
            {
                for (int32_t y = 0; y < 8; ++y)
                {
                    dstPtr16[0] = srcPtr16[0];
                    dstPtr16[1] = srcPtr16[1];
                    dstPtr16[2] = srcPtr16[2];
                    dstPtr16[3] = srcPtr16[3];
                    dstPtr16[4] = srcPtr16[4];
                    dstPtr16[5] = srcPtr16[5];
                    dstPtr16[6] = srcPtr16[6];
                    dstPtr16[7] = srcPtr16[7];
                    if (!linear) {
                        srcPtr16 += lineStride16;
                    } else {
                        srcPtr16 += 8;
                    }
                    dstPtr16 += lineStride16;
                }
            }
            else
            {
                auto* dstPtr32 = reinterpret_cast<Aliased32*>(dstPtr16);
                auto* srcPtr32 = reinterpret_cast<const Aliased32*>(srcPtr16);
                const uint32_t lineStride32 = lineStride16 / 2;
                for (int32_t y = 0; y < 8; ++y)
                {
                    dstPtr32[0] = srcPtr32[0];
                    dstPtr32[1] = srcPtr32[1];
                    dstPtr32[2] = srcPtr32[2];
                    dstPtr32[3] = srcPtr32[3];
                    if (!linear) {
                        srcPtr32 += lineStride32;
                    } else {
                        srcPtr32 += 4;
                    }
                    dstPtr32 += lineStride32;
                }
            }
        }

        template <int32_t SIZE>
        FORCEINLINE auto copyFrameToLinear(uint16_t* linear, const uint16_t* src, int32_t stride) -> void
        {
            if constexpr (SIZE == 4)
            {
                for (int32_t y = 0; y < 4; ++y)
                {
                    linear[0] = src[0];
                    linear[1] = src[1];
                    linear[2] = src[2];
                    linear[3] = src[3];
                    linear += 4;
                    src += stride;
                }
            }
            else
            {
                for (int32_t y = 0; y < 8; ++y)
                {
                    linear[0] = src[0];
                    linear[1] = src[1];
                    linear[2] = src[2];
                    linear[3] = src[3];
                    linear[4] = src[4];
                    linear[5] = src[5];
                    linear[6] = src[6];
                    linear[7] = src[7];
                    linear += 8;
                    src += stride;
                }
            }
        }

        template <int32_t SIZE>
        FORCEINLINE auto copyLinearToFrame(uint16_t* dst, int32_t stride, const uint16_t* linear) -> void
        {
            if constexpr (SIZE == 4)
            {
                for (int32_t y = 0; y < 4; ++y)
                {
                    dst[0] = linear[0];
                    dst[1] = linear[1];
                    dst[2] = linear[2];
                    dst[3] = linear[3];
                    linear += 4;
                    dst += stride;
                }
            }
            else
            {
                for (int32_t y = 0; y < 8; ++y)
                {
                    dst[0] = linear[0];
                    dst[1] = linear[1];
                    dst[2] = linear[2];
                    dst[3] = linear[3];
                    dst[4] = linear[4];
                    dst[5] = linear[5];
                    dst[6] = linear[6];
                    dst[7] = linear[7];
                    linear += 8;
                    dst += stride;
                }
            }
        }

        template <int32_t SIZE>
        FORCEINLINE auto fillBlockColor(uint16_t* dst, int32_t stride, uint16_t color) -> void
        {
            for (int32_t y = 0; y < SIZE; ++y)
            {
                for (int32_t x = 0; x < SIZE; ++x)
                {
                    dst[x] = color;
                }
                dst += stride;
            }
        }

        // DXT wire matches ``ulcv/src/format.py`` (token + index payload sizes) and ``ulcv/src/blocks/dxt.py``
        // ``from_stream`` / ``_pack_indices`` / ``_unpack_indices``: after 4-byte header, 32 index bits for
        // 4×4 or DXT8_LITE, else 128 bits (16 bytes) for 8×8 full — 2 bits per palette index, k=0 is top-left,
        // raster +x then +y (same flat order as ``bgr.reshape(-1)`` in the encoder).
        template <int32_t SIZE>
        FORCEINLINE auto decodeDxtBlockWithColors(uint16_t c0, uint16_t c1, const uint8_t* stream, uint32_t& pos,
                                                  uint16_t* dst, int32_t dstStride) -> bool
        {
            buildPaletteLut(c0, c1, m_blockColors);

            if constexpr (SIZE == 4)
            {
                const uint32_t bits = readU32(stream + pos);
                pos += 4;
                auto* row32 = reinterpret_cast<Aliased32*>(dst);
                const uint32_t rowStride32 = static_cast<uint32_t>(dstStride / 2);
                row32[0] = pack2x16(m_blockColors[(bits >> 0) & 0x3], m_blockColors[(bits >> 2) & 0x3]);
                row32[1] = pack2x16(m_blockColors[(bits >> 4) & 0x3], m_blockColors[(bits >> 6) & 0x3]);
                row32 += rowStride32;
                row32[0] = pack2x16(m_blockColors[(bits >> 8) & 0x3], m_blockColors[(bits >> 10) & 0x3]);
                row32[1] = pack2x16(m_blockColors[(bits >> 12) & 0x3], m_blockColors[(bits >> 14) & 0x3]);
                row32 += rowStride32;
                row32[0] = pack2x16(m_blockColors[(bits >> 16) & 0x3], m_blockColors[(bits >> 18) & 0x3]);
                row32[1] = pack2x16(m_blockColors[(bits >> 20) & 0x3], m_blockColors[(bits >> 22) & 0x3]);
                row32 += rowStride32;
                row32[0] = pack2x16(m_blockColors[(bits >> 24) & 0x3], m_blockColors[(bits >> 26) & 0x3]);
                row32[1] = pack2x16(m_blockColors[(bits >> 28) & 0x3], m_blockColors[(bits >> 30) & 0x3]);
                return true;
            }
            else
            {
                const uint8_t* bitsPtr = stream + pos;
                pos += 16;
                auto* row32 = reinterpret_cast<Aliased32*>(dst);
                const uint32_t rowStride32 = static_cast<uint32_t>(dstStride / 2);
                for (int32_t y = 0; y < 8; ++y)
                {
                    const uint16_t bits = static_cast<uint16_t>(bitsPtr[0] | (bitsPtr[1] << 8));
                    bitsPtr += 2;
                    row32[0] = pack2x16(m_blockColors[(bits >> 0) & 0x3], m_blockColors[(bits >> 2) & 0x3]);
                    row32[1] = pack2x16(m_blockColors[(bits >> 4) & 0x3], m_blockColors[(bits >> 6) & 0x3]);
                    row32[2] = pack2x16(m_blockColors[(bits >> 8) & 0x3], m_blockColors[(bits >> 10) & 0x3]);
                    row32[3] = pack2x16(m_blockColors[(bits >> 12) & 0x3], m_blockColors[(bits >> 14) & 0x3]);
                    row32 += rowStride32;
                }
                return true;
            }
        }

        // DXT8_LITE: same index payload as DXT4 (4 bytes), then 2x NN upscale to 8x8.
        FORCEINLINE auto decodeDxtLite8WithColors(uint16_t c0, uint16_t c1, const uint8_t* stream, uint32_t size,
                                                  uint32_t& pos, uint16_t* dst, int32_t dstStride) -> bool
        {
            if (pos + 4 > size)
            {
                if constexpr (ENABLE_STRICT_BLOCK_CHECKS)
                {
                    setError(2006, pos, size, 64);
                }
                return false;
            }

            const uint32_t bits = readU32(stream + pos);
            pos += 4;
            buildPaletteLut(c0, c1, m_blockColors);

            uint16_t* rowTop = dst;
            for (int32_t y = 0; y < 4; ++y)
            {
                uint16_t* pxTop = rowTop;
                uint16_t* pxBot = rowTop + dstStride;
                for (int32_t x = 0; x < 4; ++x)
                {
                    const int32_t k = y * 4 + x;
                    const uint16_t c = m_blockColors[(bits >> (2 * k)) & 0x3];
                    pxTop[0] = c;
                    pxTop[1] = c;
                    pxBot[0] = c;
                    pxBot[1] = c;
                    pxTop += 2;
                    pxBot += 2;
                }
                rowTop += dstStride * 2;
            }
            return true;
        }

        template <int32_t SIZE>
        FORCEINLINE auto applyRgb444DeltaToLinear(uint16_t* block, uint32_t r4, uint32_t g4, uint32_t b4, bool isAdd) -> void
        {
            // const int32_t dr = expand4To5(r4);
            // const int32_t dg = expand4To5(g4);
            // const int32_t db = expand4To5(b4);
            const int32_t dr = k_expand4To5Lut.v[r4];
            const int32_t dg = k_expand4To5Lut.v[g4];
            const int32_t db = k_expand4To5Lut.v[b4];
            for (int32_t i = 0; i < SIZE * SIZE; ++i)
            {
                const uint16_t c = block[i];
                int32_t r = static_cast<int32_t>(c & 0x1F);
                int32_t g = static_cast<int32_t>((c >> 5) & 0x1F);
                int32_t b = static_cast<int32_t>((c >> 10) & 0x1F);
                if (isAdd)
                {
                    r += dr;
                    g += dg;
                    b += db;
                }
                else
                {
                    r -= dr;
                    g -= dg;
                    b -= db;
                }
                block[i] = static_cast<uint16_t>(clamp5(r) | (static_cast<uint32_t>(clamp5(g)) << 5) |
                                                 (static_cast<uint32_t>(clamp5(b)) << 10));
            }
        }

        template <int32_t EXPECTED_SIZE>
        FORCEINLINE auto decodeOneBlock(const uint8_t* stream, uint32_t size, uint32_t& pos, uint16_t* curr, const uint16_t* prev, int32_t px, int32_t py) -> bool
        {
            (void)prev;
            if constexpr (ENABLE_STRICT_BLOCK_CHECKS)
            {
                if (pos + 2 > size)
                {
                    setError(2001, pos, size, EXPECTED_SIZE);
                    return false;
                }
            }

            const uint16_t w0 = readU16(stream + pos);
            uint16_t* const dst = curr + py * WIDTH + px;

            // DXT (word0 MSB set): two u16 endpoints then 2-bit indices (see dxt.py).
            if (w0 & DXT_WORD0_MARKER)
            {
                if (pos + 4 > size)
                {
                    setError(2004, pos, size, w0);
                    return false;
                }
                const uint16_t c0 = readU16(stream + pos) & BGR555_MASK;
                const uint16_t w1 = readU16(stream + pos + 2);
                const uint16_t c1 = w1 & BGR555_MASK;
                const bool lite = (w1 & DXT_WORD1_LITE) != 0;
                pos += 4;

                if constexpr (EXPECTED_SIZE == 4)
                {
                    if (lite)
                    {
                        setError(2002, w0, w1, EXPECTED_SIZE);
                        return false;
                    }
                    if (pos + 4 > size)
                    {
                        setError(2005, pos, size, EXPECTED_SIZE);
                        return false;
                    }
                    return decodeDxtBlockWithColors<4>(c0, c1, stream, pos, dst, WIDTH);
                }
                if (lite)
                {
                    return decodeDxtLite8WithColors(c0, c1, stream, size, pos, dst, WIDTH);
                }
                if (pos + 16 > size)
                {
                    setError(2005, pos, size, EXPECTED_SIZE);
                    return false;
                }
                return decodeDxtBlockWithColors<8>(c0, c1, stream, pos, dst, WIDTH);
            }

            // COMP: bits 15..14 == 01; motion + optional cc in one u16 (comp.py).
            if ((w0 & COMP_MARKER_MASK) == COMP_MARKER)
            {
                pos += 2;
                const int32_t dx = signext5(w0 & 0x1F);
                const int32_t dy = signext5((w0 >> 5) & 0x1F);
                const int32_t cc = signext4((w0 >> 10) & 0x0F);
                const bool hasCc = cc != 0;

                const int32_t sx = px + dx;
                const int32_t sy = py + dy;
                // Match ``blocks/comp.py`` ``apply()`` — reject OOB motion (Python always checks).
                if (sx < 0 || sy < 0 || sx + EXPECTED_SIZE > static_cast<int32_t>(WIDTH) ||
                    sy + EXPECTED_SIZE > static_cast<int32_t>(HEIGHT))
                {
                    setError(2003, static_cast<uint32_t>(sx), static_cast<uint32_t>(sy), w0);
                    return false;
                }

                const uint16_t* src = curr + sy * WIDTH + sx;
                const bool overlaps = (dx > -EXPECTED_SIZE) && (dx < EXPECTED_SIZE) && (dy > -EXPECTED_SIZE) &&
                                      (dy < EXPECTED_SIZE);

                // Self-overlap: must snapshot like ``comp.py`` ``.copy()`` before writing dst.
                if (overlaps)
                {
                    // 2-phase snapshot:
                    //   * load EWRAM->IWRAM (with cc fused in if hasCc),
                    //   * write back IWRAM->EWRAM.
                    // Saves the intermediate IWRAM read+write pass that the old 3-phase path did.
                    alignas(4) uint16_t block[EXPECTED_SIZE * EXPECTED_SIZE];
                    if (hasCc)
                    {
                        copyAndApplyColorDelta(block, src, cc, EXPECTED_SIZE, EXPECTED_SIZE, WIDTH);
                    }
                    else
                    {
                        copyFrameToLinear<EXPECTED_SIZE>(block, src, WIDTH);
                    }
                    copyBlockFast<EXPECTED_SIZE>(dst, block, WIDTH, true);
                    return true;
                }

                // Non-overlap: fused single-pass copy + cc — one EWRAM round-trip per pair instead
                // of (copyBlockFast EWRAM->EWRAM) + (applyColorDelta EWRAM->EWRAM).
                if (hasCc)
                {
                    copyAndApplyColorDelta(dst, src, cc, EXPECTED_SIZE, WIDTH, WIDTH);
                    return true;
                }

                if constexpr (EXPECTED_SIZE == 4)
                {
                    copyBlockFast<4>(dst, src, WIDTH, false);
                }
                else
                {
                    copyBlockFast<8>(dst, src, WIDTH, false);
                }
                return true;
            }

            // COLOR: bits 15..14 == 00; type 12..13; RGB444 in low 12 bits (color.py).
            pos += 2;
            const uint32_t ctype = (w0 >> 12) & 3;
            if (ctype == 3)
            {
                setError(2007, w0, ctype, 0);
                return false;
            }
            const uint32_t r4 = (w0 >> 8) & 0x0F;
            const uint32_t g4 = (w0 >> 4) & 0x0F;
            const uint32_t b4 = w0 & 0x0F;

            if (ctype == 0)
            {
                const uint16_t color = rgb444ToBgr555(r4, g4, b4);
                fillBlockColor<EXPECTED_SIZE>(dst, WIDTH, color);
                return true;
            }

            if constexpr (EXPECTED_SIZE == 4)
            {
                alignas(4) uint16_t block[4 * 4];
                copyFrameToLinear<4>(block, dst, WIDTH);
                applyRgb444DeltaToLinear<4>(block, r4, g4, b4, ctype == 1);
                copyBlockFast<4>(dst, block, WIDTH, true);
            }
            else
            {
                alignas(4) uint16_t block[8 * 8];
                copyFrameToLinear<8>(block, dst, WIDTH);
                applyRgb444DeltaToLinear<8>(block, r4, g4, b4, ctype == 1);
                copyBlockFast<8>(dst, block, WIDTH, true);
            }
            return true;
        }

        IWRAM_FUNC auto decodeFrameStream(const uint8_t* stream, uint32_t size, uint16_t* currFrame, const uint16_t* prevFrame) -> bool
        {
            if (size < 1)
            {
                setError(3001, size, 0, 0);
                return false;
            }

            uint32_t pos = 0;
            const uint8_t frameFlags = stream[pos++];

            copyPrevFrameToCurr(reinterpret_cast<uint32_t*>(currFrame), reinterpret_cast<const uint32_t*>(prevFrame));
            if (frameFlags & FRAME_FLAG_KEEP)
            {
                return true;
            }

            if (pos + SPLIT_FLAG_BYTES > size)
            {
                setError(3003, pos, size, SPLIT_FLAG_BYTES);
                return false;
            }
            const uint8_t* splitFlags = stream + pos;
            pos += SPLIT_FLAG_BYTES;

            for (uint32_t my = 0; my < MBH; ++my)
            {
                const uint8_t* rowFlags = splitFlags + my * SPLIT_WORDS_PER_ROW * 2;
                uint32_t flags = 0;
                uint32_t flagsAvailable = 0;
                for (uint32_t mx = 0; mx < MBW; ++mx)
                {
                    if (flagsAvailable == 0)
                    {
                        flags = readU16(rowFlags);
                        rowFlags += 2;
                        flagsAvailable = 16;
                    }
                    const bool split = (flags & 1) != 0;
                    flags >>= 1;
                    --flagsAvailable;
                    const int32_t px = static_cast<int32_t>(mx * MB_SIZE);
                    const int32_t py = static_cast<int32_t>(my * MB_SIZE);
                    if (!split)
                    {
                        if (!decodeOneBlock<8>(stream, size, pos, currFrame, prevFrame, px, py))
                        {
                            setError(3004, mx, my, pos);
                            return false;
                        }
                    }
                    else
                    {
                        if (!decodeOneBlock<4>(stream, size, pos, currFrame, prevFrame, px + 0, py + 0) ||
                            !decodeOneBlock<4>(stream, size, pos, currFrame, prevFrame, px + 4, py + 0) ||
                            !decodeOneBlock<4>(stream, size, pos, currFrame, prevFrame, px + 0, py + 4) ||
                            !decodeOneBlock<4>(stream, size, pos, currFrame, prevFrame, px + 4, py + 4))
                        {
                            setError(3005, mx, my, pos);
                            return false;
                        }
                    }
                }
            }

            if (pos == size)
            {
                return true;
            }
            if ((pos + 1 == size) && (stream[pos] == 0))
            {
                return true;
            }
            setError(3006, pos, size, stream[pos]);
            return false;
        }

        // Called once per frame; cheap parsing — leave in ROM to save IWRAM.
        auto readNextFramePacket(const uint8_t*& packetData, uint32_t& packetSize) -> bool
        {
            packetData = nullptr;
            packetSize = 0;
            if (m_payloadCursor + 4 > m_payloadStart + m_info.payloadSize)
            {
                setError(4001, static_cast<uint32_t>(m_payloadCursor - m_payloadStart), m_info.payloadSize, 4);
                return false;
            }
            const uint32_t n = readU32(m_payloadCursor);
            m_payloadCursor += 4;
            if (m_payloadCursor + n > m_payloadStart + m_info.payloadSize)
            {
                setError(4002, static_cast<uint32_t>(m_payloadCursor - m_payloadStart), n, m_info.payloadSize);
                return false;
            }
            packetData = m_payloadCursor;
            packetSize = n;
            m_payloadCursor += n;
            return true;
        }

        // Once per frame; just a dispatcher that calls into the IWRAM
        // decompressors. Keep this thin shell in ROM.
        auto decodePacketToFrameStream(const uint8_t* packetData, uint32_t packetSize, const uint8_t*& frameStream, uint32_t& frameSize) -> bool
        {
            frameStream = packetData;
            frameSize = packetSize;

            // v6: byte offset 10 ``frame_payload_layout`` — 0 raw, 1 tagged (see header.py / frame_codec.py).
            if (m_info.framePayloadLayout == 0)
            {
                return true;
            }

            if (packetSize < 2)
            {
                setError(5002, packetSize, m_info.framePayloadLayout, 0);
                return false;
            }

            const uint8_t codecTag = packetData[0];
            frameStream = packetData + 1;
            frameSize = packetSize - 1;

            if (codecTag == FRAME_CODEC_RAW)
            {
                return true;
            }

            if (codecTag == FRAME_CODEC_LZ4 || codecTag == FRAME_CODEC_LZ4HC)
            {
                uint32_t lz4OutSize = 0;
                if (!lz4_40_decompress(frameStream, frameSize, m_frameStream, m_frameStreamCapacity, lz4OutSize))
                {
                    setError(5004, codecTag, frameSize, m_lastErrorCode);
                    return false;
                }
                frameStream = m_frameStream;
                frameSize = lz4OutSize;
                return true;
            }

            if (codecTag == FRAME_CODEC_GBA_LZ77)
            {
                const uint32_t outSize = lz77UncompressedSize(frameStream, frameSize);
                if (outSize == 0 || outSize > m_frameStreamCapacity)
                {
                    setError(5005, outSize, m_frameStreamCapacity, frameSize);
                    return false;
                }

                if (frameSize <= FRAME_BYTES)
                {
                    auto* alignedSrc = reinterpret_cast<uint8_t*>(m_currFrame);
                    // std::memcpy(alignedSrc, frameStream, frameSize);
                    bn::memcpy(alignedSrc, frameStream, frameSize);
                    LZ77UnCompWram(alignedSrc, m_frameStream);
                    frameStream = m_frameStream;
                    frameSize = outSize;
                    return true;
                }

                uint32_t safeOutSize = 0;
                if (!lz77_decompress_safe(frameStream, frameSize, m_frameStream, m_frameStreamCapacity, safeOutSize))
                {
                    setError(5007, frameSize, outSize, m_lastErrorCode);
                    return false;
                }
                frameStream = m_frameStream;
                frameSize = safeOutSize;
                return true;
            }

            setError(5003, codecTag, m_info.framePayloadLayout, packetSize);
            return false;
        }

        // Once per frame; trivial wrapper. Keep in ROM.
        auto decodeNextFrame() -> bool
        {
            clearError();
            const uint8_t* packetData = nullptr;
            uint32_t packetSize = 0;
            if (!readNextFramePacket(packetData, packetSize))
            {
                return false;
            }

            const uint8_t* stream = nullptr;
            uint32_t streamSize = 0;
            if (!decodePacketToFrameStream(packetData, packetSize, stream, streamSize))
            {
                setError(6001, packetSize, m_info.framePayloadLayout, m_lastErrorCode);
                return false;
            }

            auto* currFrame = m_currFrame;
            const auto* prevFrame = reinterpret_cast<const uint16_t*>(VRAM);
            if (!decodeFrameStream(stream, streamSize, currFrame, prevFrame))
            {
                setError(6002, streamSize, packetSize, m_lastErrorCode);
                return false;
            }
            return true;
        }

        auto resetState() -> void
        {
            clearError();
            m_payloadCursor = m_payloadStart;
            m_frameIndex = 0;
            m_framesDecoded = 0;
            m_framesRequested = 1;
            m_decodeFailed = false;
            for (uint32_t i = 0; i < FRAME_PIXELS; ++i)
            {
                m_currFrame[i] = 0;
            }
        }
    }

    auto isULCV(const uint32_t* videoSrc) -> bool
    {
        if (!videoSrc)
        {
            return false;
        }
        const auto* bytes = reinterpret_cast<const uint8_t*>(videoSrc);
        return bytes[0] == 'U' && bytes[1] == 'L' && bytes[2] == 'C' && bytes[3] == 'V';
    }

    auto init(const uint32_t* videoSrc, uint32_t* scratchPad, uint32_t scratchPadSize) -> void
    {
        m_videoSrc = reinterpret_cast<const uint8_t*>(videoSrc);
        m_scratchPad = scratchPad;
        m_scratchPadSize = scratchPadSize;
        m_info = {};

        if (!videoSrc || !scratchPad)
        {
            return;
        }
        if (scratchPadSize < FRAME_BYTES + 4096)
        {
            return;
        }

        const uint8_t* hdr = reinterpret_cast<const uint8_t*>(videoSrc);
        const uint32_t magic = readU32(hdr + 0);
        const uint8_t version = hdr[4];
        const uint16_t width = readU16(hdr + 5);
        const uint16_t height = readU16(hdr + 7);
        const uint8_t fps = hdr[9];
        const uint8_t framePayloadLayout = hdr[10];
        const uint32_t frames = readU32(hdr + 12);
        const uint32_t payloadSize = readU32(hdr + 16);
        if (magic != ULCV_MAGIC || version != ULCV_VERSION)
        {
            return;
        }
        if (width != WIDTH || height != HEIGHT || fps == 0 || frames == 0)
        {
            return;
        }
        if (framePayloadLayout > 1)
        {
            return;
        }

        m_info.width = width;
        m_info.height = height;
        m_info.fps = fps;
        m_info.framePayloadLayout = framePayloadLayout;
        m_info.nrOfFrames = frames;
        m_info.payloadSize = payloadSize;
        m_info.valid = true;

        m_payloadStart = m_videoSrc + HEADER_BYTES;
        m_payloadCursor = m_payloadStart;

        auto* scratch16 = reinterpret_cast<uint16_t*>(m_scratchPad);
        m_currFrame = scratch16;
        m_frameStream = reinterpret_cast<uint8_t*>(scratch16 + FRAME_PIXELS);
        m_frameStreamCapacity = scratchPadSize - FRAME_BYTES;

        resetState();
    }

    auto getInfo() -> const Info&
    {
        return m_info;
    }

    auto play() -> void
    {
        if (m_playing || !m_info.valid)
        {
            return;
        }
        resetState();
        m_playing = true;

        irqSet(irqMASKS::IRQ_TIMER2, frameRequest);
        irqEnable(irqMASKS::IRQ_TIMER2);
        REG_TM2CNT = 0;
        const uint32_t fps = m_info.fps == 0 ? 1 : m_info.fps;
        REG_TM2CNT_L = 65536U - (65536U / fps);
        REG_TM2CNT_H = TIMER_START | TIMER_IRQ | 2;
    }

    auto stop() -> void
    {
        if (!m_playing)
        {
            return;
        }
        REG_TM2CNT_H = 0;
        irqDisable(irqMASKS::IRQ_TIMER2);
        m_playing = false;
        m_framesDecoded = 0;
        m_framesRequested = 0;
    }

    auto hasMoreFrames() -> bool
    {
        return m_playing && !m_decodeFailed && m_frameIndex < m_info.nrOfFrames;
    }

    auto decodeAndBlitFrame(uint32_t* dst) -> void
    {
        decodeAndBlitFrame(dst, [] {});
    }

    auto decodeAndBlitFrame(uint32_t* dst, void (*updateCallback)()) -> void
    {
        if (!m_playing || !dst || !updateCallback)
        {
            return;
        }

        if (m_framesDecoded < 1 && (m_frameIndex + static_cast<uint32_t>(m_framesDecoded)) < m_info.nrOfFrames)
        {
            const uint32_t decodeFrameId = m_frameIndex + static_cast<uint32_t>(m_framesDecoded);
            if (!decodeNextFrame())
            {
                BN_LOG("ULCV decode failed frame: ", decodeFrameId);
                BN_LOG("ULCV err code/a/b/c: ", m_lastErrorCode, " / ", m_lastErrorA, " / ", m_lastErrorB, " / ", m_lastErrorC);
                m_decodeFailed = true;
                m_playing = false;
            }
            else
            {
                ++m_framesDecoded;
            }
        }

        if (m_framesRequested > 0 && m_framesDecoded > 0)
        {
            --m_framesRequested;
            --m_framesDecoded;
            VBlankIntrWait();
            blitFrameToVram(reinterpret_cast<uint32_t*>(dst), reinterpret_cast<const uint32_t*>(m_currFrame));
            __asm volatile("nop");
            __asm volatile("nop");
            ++m_frameIndex;
        }
        else
        {
            VBlankIntrWait();
        }

        updateCallback();
    }
}
