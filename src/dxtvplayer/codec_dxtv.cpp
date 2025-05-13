#include "codec_dxtv.h"

#include <gba_systemcalls.h>
#include <ugba/hardware.h>

#include "dxt_tables.h"
#include "../sound_manager.h"

namespace DXTV
{

    // DXTV encoding:
    //
    // Header:
    //
    // uint16_t frameFlags -> General frame flags, e.g. FRAME_KEEP
    // uint16_t dummy -> empty atm
    //
    // Image data:
    //
    // The image is split into 8x8 pixel blocks (BLOCK_MAX_DIM) which can be futher split into 4x4 blocks.
    //
    // Every 8x8 block (block size 0) has one flag:
    // Bit 0: Block handled entirely (0) or block split into 4x4 (1)
    // These bits are sent in the bitstream for each horizontal 8x8 line in intervals of 16 blocks
    // A 240 pixel image stream will send:
    // - 16 bits at the start of the bitstream
    // - Another 16 bits after 16 encoded blocks (with 2 unused bits)
    //
    // A 4x4 block (block size 1) has no extra flags. If an 8x8 block has been split,
    // 4 motion-compensated or 4 DXT blocks will be read from data.
    //
    // Blocks are sent row-wise. So if a 8x8 block is split into 4 4x4 children ABCD,
    // its first 4x4 child A is sent first then child B and so on. The layout in the image is:
    // A B
    // C D
    //
    // 8x8 and 4x4 DXT and motion-compensated blocks differ in their highest Bit:
    //
    // - If 0 it is a DXT-block with a size of 8 or 20 Bytes:
    //   DXT blocks store verbatim DXT data (2 * uint16_t RGB555 colors and index data depending on blocks size)
    //   So either 2 * 2 + 16 * 2 / 8 = 8 Bytes (4x4 block) or 2 * 2 + 64 * 2 / 8 = 20 Bytes (8x8 block)
    //
    // - If 1 it is a motion-compensated block with a size of 2 Bytes:
    //   Bit 15: Always 1 (see above)
    //   Bit 14: Block is reference to current (0) or previous (1) frame
    //   Bit 13-11: Currently unused
    //   Bit 10-5: y pixel motion of referenced block [-15,16] from top-left corner
    //   Bit  4-0: x pixel motion of referenced block [-15,16] from top-left corner

    static constexpr uint16_t FRAME_KEEP = 0x40; // 1 for frames that are considered a direct copy of the previous frame and can be kept

    static constexpr uint32_t BLOCK_MAX_DIM = 8;           // Maximum block size is 8x8 pixels
    static constexpr bool BLOCK_NO_SPLIT = false;          // The block is a full block
    static constexpr bool BLOCK_IS_SPLIT = true;           // The block is split into smaller sub-blocks
    static constexpr uint16_t BLOCK_IS_DXT = 0;            // The block is a verbatim DXT block
    static constexpr uint16_t BLOCK_IS_REF = (1 << 15);    // The block is a motion-compensated block from the current or previous frame
    static constexpr uint16_t BLOCK_FROM_CURR = (0 << 14); // The reference block is from from the current frame
    static constexpr uint16_t BLOCK_FROM_PREV = (1 << 14); // The reference block is from from the previous frame

    static constexpr uint32_t BLOCK_MOTION_BITS = 5;                                      // Bits available for pixel motion
    static constexpr uint16_t BLOCK_MOTION_MASK = (uint16_t(1) << BLOCK_MOTION_BITS) - 1; // Block x pixel motion mask
    static constexpr uint16_t BLOCK_MOTION_Y_SHIFT = BLOCK_MOTION_BITS;                   // Block y pixel motion shift

    static const uint16_t *last_data_ptr;
    static uint16_t  last_header_flags;

    IWRAM_DATA ALIGN(4) uint16_t blockColors[4]; // intermediate DXT block color storage
    IWRAM_DATA ALIGN(4) bool isBlockMC;          // intermediate DXT block color storage

    /// @brief Copy (un-)aligned block from src to curr
    template <uint32_t BLOCK_DIM>
    FORCEINLINE auto copyBlock(uint32_t *currPtr32, const uint16_t *srcPtr16, const uint32_t LineStride16);

    /// @brief Copy (un-)aligned block from src to curr
    template <>
    FORCEINLINE auto copyBlock<4>(uint32_t *currPtr32, const uint16_t *srcPtr16, const uint32_t LineStride16)
    {
        // check if block is word-aligned
        if (((uint32_t)srcPtr16 & 3) != 0)
        {
            // unaligned block
            auto currPtr16 = reinterpret_cast<uint16_t *>(currPtr32);
            currPtr16[0] = srcPtr16[0];
            currPtr16[1] = srcPtr16[1];
            currPtr16[2] = srcPtr16[2];
            currPtr16[3] = srcPtr16[3];
            srcPtr16 += LineStride16;
            currPtr16 += LineStride16;
            currPtr16[0] = srcPtr16[0];
            currPtr16[1] = srcPtr16[1];
            currPtr16[2] = srcPtr16[2];
            currPtr16[3] = srcPtr16[3];
            srcPtr16 += LineStride16;
            currPtr16 += LineStride16;
            currPtr16[0] = srcPtr16[0];
            currPtr16[1] = srcPtr16[1];
            currPtr16[2] = srcPtr16[2];
            currPtr16[3] = srcPtr16[3];
            srcPtr16 += LineStride16;
            currPtr16 += LineStride16;
            currPtr16[0] = srcPtr16[0];
            currPtr16[1] = srcPtr16[1];
            currPtr16[2] = srcPtr16[2];
            currPtr16[3] = srcPtr16[3];
        }
        else
        {
            // aligned block
            auto srcPtr32 = reinterpret_cast<const uint32_t *>(srcPtr16);
            currPtr32[0] = srcPtr32[0];
            currPtr32[1] = srcPtr32[1];
            srcPtr32 += LineStride16 / 2;
            currPtr32 += LineStride16 / 2;
            currPtr32[0] = srcPtr32[0];
            currPtr32[1] = srcPtr32[1];
            srcPtr32 += LineStride16 / 2;
            currPtr32 += LineStride16 / 2;
            currPtr32[0] = srcPtr32[0];
            currPtr32[1] = srcPtr32[1];
            srcPtr32 += LineStride16 / 2;
            currPtr32 += LineStride16 / 2;
            currPtr32[0] = srcPtr32[0];
            currPtr32[1] = srcPtr32[1];
        }
    }

    /// @brief Copy (un-)aligned block from src to curr
    template <>
    FORCEINLINE auto copyBlock<8>(uint32_t *currPtr32, const uint16_t *srcPtr16, const uint32_t LineStride16)
    {
        // check if block is word-aligned
        if (((uint32_t)srcPtr16 & 3) != 0)
        {
            // unaligned block
            auto currPtr16 = reinterpret_cast<uint16_t *>(currPtr32);
            for (uint32_t y = 0; y < 8; ++y)
            {
                currPtr16[0] = srcPtr16[0];
                currPtr16[1] = srcPtr16[1];
                currPtr16[2] = srcPtr16[2];
                currPtr16[3] = srcPtr16[3];
                currPtr16[4] = srcPtr16[4];
                currPtr16[5] = srcPtr16[5];
                currPtr16[6] = srcPtr16[6];
                currPtr16[7] = srcPtr16[7];
                srcPtr16 += LineStride16;
                currPtr16 += LineStride16;
            }
        }
        else
        {
            // aligned block
            auto srcPtr32 = reinterpret_cast<const uint32_t *>(srcPtr16);
            for (uint32_t i = 0; i < 8; ++i)
            {
                currPtr32[0] = srcPtr32[0];
                currPtr32[1] = srcPtr32[1];
                currPtr32[2] = srcPtr32[2];
                currPtr32[3] = srcPtr32[3];
                srcPtr32 += LineStride16 / 2;
                currPtr32 += LineStride16 / 2;
            }
        }
    }

    /// @brief Uncompress DXT or motion-compensated block
    /// @return Pointer past whole block data in src
    template <uint32_t BLOCK_DIM>
    FORCEINLINE auto decodeBlock(const uint16_t *dataPtr16, uint32_t *currPtr32, const uint32_t *prevPtr32, const uint32_t LineStride16) -> const uint16_t *;

    /// @brief Uncompress 4x4 or motion-compensated block
    /// @return Pointer past whole block data in src
    template <>
    FORCEINLINE auto decodeBlock<4>(const uint16_t *dataPtr16, uint32_t *currPtr32, const uint32_t *prevPtr32, const uint32_t LineStride16) -> const uint16_t *
    {
        auto currPtr16 = reinterpret_cast<uint16_t *>(currPtr32);
        if (*dataPtr16 & BLOCK_IS_REF)
        {
            // get motion-compensated block info
            const uint16_t blockInfo = *dataPtr16++;
            const bool fromPrev = blockInfo & BLOCK_FROM_PREV;
            auto srcPtr16 = fromPrev ? reinterpret_cast<const uint16_t *>(prevPtr32) : reinterpret_cast<const uint16_t *>(currPtr32);
            // convert offsets to signed values
            auto offsetX = static_cast<int32_t>(blockInfo & BLOCK_MOTION_MASK) - ((1 << BLOCK_MOTION_BITS) / 2 - 1);
            auto offsetY = static_cast<int32_t>((blockInfo >> BLOCK_MOTION_Y_SHIFT) & BLOCK_MOTION_MASK) - ((1 << BLOCK_MOTION_BITS) / 2 - 1);
            // calculate start of block to copy
            srcPtr16 += offsetY * LineStride16 + offsetX;
            // copy pixels to output block
            copyBlock<4>(currPtr32, srcPtr16, LineStride16);
        }
        else
        {
            // get DXT block colors
            dataPtr16 = DXT::getBlockColors(dataPtr16, blockColors);
            // get pixel color indices and set pixels accordingly
            uint16_t indices = *dataPtr16++;
            // select color by 2 bit index from [c0, c1, c2, c3], then move to next line in destination vertically
            currPtr16[0] = blockColors[(indices >> 0) & 0x3];
            currPtr16[1] = blockColors[(indices >> 2) & 0x3];
            currPtr16[2] = blockColors[(indices >> 4) & 0x3];
            currPtr16[3] = blockColors[(indices >> 6) & 0x3];
            currPtr16 += LineStride16;
            currPtr16[0] = blockColors[(indices >> 8) & 0x3];
            currPtr16[1] = blockColors[(indices >> 10) & 0x3];
            currPtr16[2] = blockColors[(indices >> 12) & 0x3];
            currPtr16[3] = blockColors[(indices >> 14) & 0x3];
            currPtr16 += LineStride16;
            indices = *dataPtr16++;
            currPtr16[0] = blockColors[(indices >> 0) & 0x3];
            currPtr16[1] = blockColors[(indices >> 2) & 0x3];
            currPtr16[2] = blockColors[(indices >> 4) & 0x3];
            currPtr16[3] = blockColors[(indices >> 6) & 0x3];
            currPtr16 += LineStride16;
            currPtr16[0] = blockColors[(indices >> 8) & 0x3];
            currPtr16[1] = blockColors[(indices >> 10) & 0x3];
            currPtr16[2] = blockColors[(indices >> 12) & 0x3];
            currPtr16[3] = blockColors[(indices >> 14) & 0x3];
        }
        return dataPtr16;
    }

    /// @brief Uncompress 8x8 or motion-compensated block
    /// @return Pointer past whole block data in src
    template <>
    FORCEINLINE auto decodeBlock<8>(const uint16_t *dataPtr16, uint32_t *currPtr32, const uint32_t *prevPtr32, const uint32_t LineStride16) -> const uint16_t *
    {
        auto currPtr16 = reinterpret_cast<uint16_t *>(currPtr32);
        if (*dataPtr16 & BLOCK_IS_REF)
        {
            // get motion-compensated block info
            const uint16_t blockInfo = *dataPtr16++;
            const bool fromPrev = blockInfo & BLOCK_FROM_PREV;
            auto srcPtr16 = fromPrev ? reinterpret_cast<const uint16_t *>(prevPtr32) : reinterpret_cast<const uint16_t *>(currPtr32);
            // convert offsets to signed values
            auto offsetX = static_cast<int32_t>(blockInfo & BLOCK_MOTION_MASK) - ((1 << BLOCK_MOTION_BITS) / 2 - 1);
            auto offsetY = static_cast<int32_t>((blockInfo >> BLOCK_MOTION_Y_SHIFT) & BLOCK_MOTION_MASK) - ((1 << BLOCK_MOTION_BITS) / 2 - 1);
            // calculate start of block to copy
            srcPtr16 += offsetY * LineStride16 + offsetX;
            // copy pixels to output block
            copyBlock<8>(currPtr32, srcPtr16, LineStride16);
        }
        else
        {
            // get DXT block colors
            dataPtr16 = DXT::getBlockColors(dataPtr16, blockColors);
            // get pixel color indices and set pixels accordingly
            for (uint32_t i = 0; i < 8; ++i)
            {
                uint16_t indices = *dataPtr16++;
                // select color by 2 bit index from [c0, c1, c2, c3], then move to next line in destination vertically
                currPtr16[0] = blockColors[(indices >> 0) & 0x3];
                currPtr16[1] = blockColors[(indices >> 2) & 0x3];
                currPtr16[2] = blockColors[(indices >> 4) & 0x3];
                currPtr16[3] = blockColors[(indices >> 6) & 0x3];
                currPtr16[4] = blockColors[(indices >> 8) & 0x3];
                currPtr16[5] = blockColors[(indices >> 10) & 0x3];
                currPtr16[6] = blockColors[(indices >> 12) & 0x3];
                currPtr16[7] = blockColors[(indices >> 14) & 0x3];
                currPtr16 += LineStride16;
            }
        }
        return dataPtr16;
    }

    template <>
    IWRAM_FUNC void UnCompWrite16bit<160>(const uint32_t *data, uint32_t *dst, const uint32_t *prevSrc, uint32_t width, uint32_t height, uint8_t part)
//    IWRAM_FUNC void UnCompWrite16bit<240>(const uint32_t *data, uint32_t *dst, const uint32_t *prevSrc, uint32_t width, uint32_t height)
    {
        constexpr uint32_t LineStride16 = 160;                    // stride to next line in dst in half words / pixels
        constexpr uint32_t LineStride32 = LineStride16 / 2;       // stride to next line in dst in words / 2 pixels
        constexpr uint32_t Block4HStride32 = 2;                   // horizontal stride to next 4x4 block in dst in words / 2 pixels
        constexpr uint32_t Block4VStride32 = 4 * LineStride32;    // vertical stride to next 4x4 block in dst in words / 2 pixels
        constexpr uint32_t Block8HStride32 = 2 * Block4HStride32; // horizontal stride to next 8x8 block in dst in words / 2 pixels

        auto dataPtr16 = (part == 0) ? reinterpret_cast<const uint16_t *>(data) : last_data_ptr;
        if (part == 0) {
            last_header_flags = *dataPtr16++;
            dataPtr16++;
        }

        // check if we want to keep this duplicate frame
        if ((last_header_flags & FRAME_KEEP) != 0)
        {
            // Debug::printf("Duplicate frame");
            return;
        }

        // set up some variables
        const uint32_t from = part * (height / BLOCK_MAX_DIM / 4);
        const uint32_t to = (part + 1) * (height / BLOCK_MAX_DIM / 4);
        for (uint32_t by = from; by < to; ++by)
        {
            uint32_t flags = 0;
            uint32_t flagsAvailable = 0;
            auto currPtr32 = dst + by * LineStride32 * BLOCK_MAX_DIM;
            auto prevPtr32 = prevSrc == nullptr ? nullptr : prevSrc + by * LineStride32 * BLOCK_MAX_DIM;
            for (uint32_t bx = 0; bx < width / BLOCK_MAX_DIM; ++bx)
            {
                // read flags if we need to
                if (flagsAvailable < 1)
                {
                    flags = *dataPtr16++;
                    flagsAvailable = 16;
                }
                // check if block is split
                if (flags & 1)
                {
                    dataPtr16 = decodeBlock<4>(dataPtr16, currPtr32, prevPtr32, LineStride16);                                                                         // A - upper-left
                    dataPtr16 = decodeBlock<4>(dataPtr16, currPtr32 + Block4HStride32, prevPtr32 + Block4HStride32, LineStride16);                                     // B - upper-right
                    dataPtr16 = decodeBlock<4>(dataPtr16, currPtr32 + Block4VStride32, prevPtr32 + Block4VStride32, LineStride16);                                     // C - lower-left
                    dataPtr16 = decodeBlock<4>(dataPtr16, currPtr32 + Block4VStride32 + Block4HStride32, prevPtr32 + Block4VStride32 + Block4HStride32, LineStride16); // D - lower-right
                }
                else
                {
                    dataPtr16 = decodeBlock<8>(dataPtr16, currPtr32, prevPtr32, LineStride16);
                }
                currPtr32 += Block8HStride32;
                prevPtr32 += Block8HStride32;
                flags >>= 1;
                --flagsAvailable;
            }
        }

        last_data_ptr = dataPtr16;

        // onDecodePass();
        // VBlankIntrWait();
    }

    template <>
    IWRAM_FUNC void UnCompWrite16bit<160>(const uint32_t *data, uint32_t *dst, const uint32_t *prevSrc, uint32_t width, uint32_t height) {
        for (uint8_t part = 0; part < 2; part++) {
            UnCompWrite16bit<160>(data, dst, prevSrc, width, height, part);
        }
    }
}
