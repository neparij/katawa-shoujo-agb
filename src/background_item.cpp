#include "background_item.h"
#include "background_ptr.h"
#include "bn_assert.h"
#include "bn_compression_type.h"
#include "bn_memory.h"
#include "ext_bg_blocks_manager.h"

namespace ks {

    namespace {
        // Returns true if at least one component (tiles/map/palette)
        // of the regular bg is stored in ROM in compressed form. Used
        // to short-circuit the EWRAM-decompression path when the
        // source asset is fully uncompressed already — in that case
        // we can hand the raw `bn::regular_bg_item` to butano and let
        // it commit synchronously (single DMA), skipping the EWRAM
        // alloc/free cycle entirely.
        inline bool _regular_needs_decompression(const bn::regular_bg_item &item) {
            return item.tiles_item().compression() != bn::compression_type::NONE
                || item.map_item().compression() != bn::compression_type::NONE
                || item.palette_item().compression() != bn::compression_type::NONE;
        }
    }

    bool background_item::has_value() const {
        asserts();
        return _regular.has_value() || _affine.has_value() || _huge.has_value();
    }

    bool background_item::is_regular() const {
        asserts();
        return _regular.has_value();
    }

    bool background_item::is_affine() const {
        asserts();
        return _affine.has_value();
    }

    bool background_item::is_huge() const {
        asserts();
        return _huge.has_value();
    }

    [[nodiscard]] ks::background_ptr background_item::create_bg() {
        return create_bg(0, 0);
    }

    [[nodiscard]] ks::background_ptr background_item::create_bg(bn::fixed x, bn::fixed y) {
        BN_ASSERT(has_value(), "Background item is empty");

        if (is_regular()) {
            // Order is intentional and matters visually:
            //
            //   1. Decompress the source asset into freshly-allocated
            //      EWRAM. Pure CPU work, no VRAM/allocator state
            //      touched — whatever is currently on screen stays
            //      on screen for the entire duration of the unpack.
            //
            //   2. `update_and_delay_commit()` flushes every
            //      `TO_REMOVE` bg_blocks entry down to `FREE` (and
            //      merges adjacent free regions) AND arms butano's
            //      `delay_commit` flag. Both halves are mandatory:
            //
            //         - Without the flush, butano's
            //           `_create_impl` would hit its
            //           TO_REMOVE-exact-match fast-path first and
            //           reuse whatever VRAM slot the previous BG
            //           occupied (e.g. start_block 22), so tiles
            //           never migrate to slot 0.
            //         - Without `delay_commit`, butano commits the
            //           freshly allocated FREE-search slot
            //           synchronously inside `_create_item` —
            //           ~20 KB EWRAM→VRAM memcpy mid-frame, which
            //           tears for 1–2 frames.
            //
            //      The combination forces `_create_impl` down its
            //      FREE-search path (lowest aligned start_block —
            //      slot 0 in the common case) AND queues the
            //      resulting commit into
            //      `to_commit_uncompressed_items_array`. The next
            //      vblank then runs `commit_uncompressed(use_dma=
            //      true)` and the whole BG lands in VRAM in a
            //      single atomic DMA, completely invisible.
            //
            //   3. Hand the uncompressed `bn::regular_bg_item`
            //      (referencing our EWRAM buffers) to butano's
            //      allocator. The returned `background_ptr` takes
            //      ownership of the EWRAM buffers and frees them
            //      after dropping its underlying bg_ptr, so butano
            //      never reads freed memory.
            //
            // Note that `delay_commit` is auto-cleared by butano's
            // own per-frame `update()`, so the side effect is
            // scoped to exactly one allocation.
            if (_regular_needs_decompression(*_regular)) {
                void *tiles_ewram = nullptr;
                void *map_ewram = nullptr;
                void *palette_ewram = nullptr;
                bn::regular_bg_item dec = ks::background_ptr::decompress_to_ewram(
                        *_regular, tiles_ewram, map_ewram, palette_ewram);
                bn::bg_blocks_manager::update_and_delay_commit();
                return ks::background_ptr(*this, dec.create_bg(x, y),
                                          tiles_ewram, map_ewram, palette_ewram);
            }
            // Uncompressed source: same defrag+delay-commit combo,
            // no EWRAM work needed since data already sits in ROM
            // in raw form.
            bn::bg_blocks_manager::update_and_delay_commit();
            return ks::background_ptr(*this, _regular->create_bg(x, y));
        }

        if (is_affine()) {
            return ks::background_ptr(*this, _affine->create_bg(x, y));
        }

        if (is_huge()) {
            return ks::background_ptr(*this, _huge->create_bg(x, y));
        }

        BN_ERROR("Unknown background type");
    }

    [[nodiscard]] bn::optional<ks::background_ptr> background_item::create_bg_optional() {
        return create_bg_optional(0, 0);
    }

    [[nodiscard]] bn::optional<ks::background_ptr> background_item::create_bg_optional(bn::fixed x, bn::fixed y) {
        BN_ASSERT(has_value(), "Background item is empty");

        if (is_regular()) {
            // Symmetric to `create_bg` above — see that function's
            // comment for the rationale on order and on
            // `update_and_delay_commit`. The only difference here
            // is we propagate butano's allocation-failure path: if
            // create_bg_optional comes back empty we free the
            // EWRAM buffers immediately so they don't leak.
            if (_regular_needs_decompression(*_regular)) {
                void *tiles_ewram = nullptr;
                void *map_ewram = nullptr;
                void *palette_ewram = nullptr;
                bn::regular_bg_item dec = ks::background_ptr::decompress_to_ewram(
                        *_regular, tiles_ewram, map_ewram, palette_ewram);
                bn::bg_blocks_manager::update_and_delay_commit();
                if (auto optional = dec.create_bg_optional(x, y); optional.has_value()) {
                    return ks::background_ptr(*this, *optional,
                                              tiles_ewram, map_ewram, palette_ewram);
                }
                if (tiles_ewram) bn::memory::ewram_free(tiles_ewram);
                if (map_ewram) bn::memory::ewram_free(map_ewram);
                if (palette_ewram) bn::memory::ewram_free(palette_ewram);
                return bn::nullopt;
            }
            bn::bg_blocks_manager::update_and_delay_commit();
            if (auto optional = _regular->create_bg_optional(x, y); optional.has_value()) {
                return ks::background_ptr(*this, *optional);
            }
        }

        if (is_affine()) {
            if (auto optional = _affine->create_bg_optional(x, y); optional.has_value()) {
                return ks::background_ptr(*this, *optional);
            }
        }

        if (is_huge()) {
            BN_ERROR("HUGE Background doesn't support optional creation");
        }

        return bn::nullopt;
    }
}
