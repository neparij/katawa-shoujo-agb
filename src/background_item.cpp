#include "background_item.h"
#include "background_ptr.h"
#include "bn_assert.h"
#include "bn_compression_type.h"
#include "bn_memory.h"
#include "ext_bg_blocks_manager.h"

namespace ks {

    namespace {
        inline bool _regular_needs_decompression(const bn::regular_bg_item &item) {
            return item.tiles_item().compression() != bn::compression_type::NONE
                || item.map_item().compression() != bn::compression_type::NONE
                || item.palette_item().compression() != bn::compression_type::NONE;
        }
    }

    bool background_item::has_value() const {
        asserts();
        return _regular.has_value() || _affine.has_value() || _huge.has_value()
            || _regular_composite.has_value() || _composite_huge.has_value();
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

    bool background_item::is_regular_composite() const {
        asserts();
        return _regular_composite.has_value();
    }

    bool background_item::is_composite_huge() const {
        asserts();
        return _composite_huge.has_value();
    }

    bool background_item::is_composite_huge_variant_switch(const background_item& other) const {
        asserts();
        other.asserts();
        if(!is_composite_huge() || !other.is_composite_huge()) {
            return false;
        }
        if(&_composite_huge->asset() != &other._composite_huge->asset()) {
            return false;
        }
        return _composite_huge->variant_index() != other._composite_huge->variant_index();
    }

    int background_item::composite_huge_variant_index() const {
        asserts();
        BN_ASSERT(is_composite_huge(), "composite_huge_variant_index on non-composite-huge item");
        return _composite_huge->variant_index();
    }

    bool background_item::is_composite_variant_switch(const background_item& other) const {
        if(is_composite_huge_variant_switch(other)) {
            return true;
        }
        asserts();
        other.asserts();
        if(!is_regular_composite() || !other.is_regular_composite()) {
            return false;
        }
        if(&_regular_composite->asset() != &other._regular_composite->asset()) {
            return false;
        }
        return _regular_composite->variant_index() != other._regular_composite->variant_index();
    }

    int background_item::composite_variant_index() const {
        asserts();
        if(is_composite_huge()) {
            return composite_huge_variant_index();
        }
        BN_ASSERT(is_regular_composite(), "composite_variant_index on non-composite item");
        return _regular_composite->variant_index();
    }

    [[nodiscard]] ks::background_ptr background_item::create_bg() {
        return create_bg(0, 0);
    }

    [[nodiscard]] ks::background_ptr background_item::create_bg(bn::fixed x, bn::fixed y) {
        BN_ASSERT(has_value(), "Background item is empty");

        if (is_regular()) {
            if (_regular_needs_decompression(*_regular)) {
                // Order is intentional and matters visually:
                //
                //   1. Decompress into EWRAM. CPU-only — the current frame
                //      on screen is unchanged while we unpack.
                //
                //   2. update_and_delay_commit() defragments VRAM and arms
                //      butano's delay_commit so the next create_bg lands at
                //      the lowest free slot.
                //
                //   3. Hand butano an uncompressed regular_bg_item (NONE
                //      compression) referencing our EWRAM buffers.
                //
                //   4. VRAM upload happens at the next `core::update()`
                //      vblank (map before tiles). EWRAM is freed after that
                //      in `globals::main_update()`.
                void *tiles_ewram = nullptr;
                void *map_ewram = nullptr;
                void *palette_ewram = nullptr;
                bn::regular_bg_item dec = ks::background_ptr::decompress_to_ewram(
                        *_regular, tiles_ewram, map_ewram, palette_ewram);
                bn::bg_blocks_manager::update_and_delay_commit();
                return ks::background_ptr(*this, dec.create_bg(x, y),
                                          tiles_ewram, map_ewram, palette_ewram);
            }

            bn::bg_blocks_manager::update_and_delay_commit();
            return ks::background_ptr(*this, _regular->create_bg(x, y));
        }

        if (is_affine()) {
            return ks::background_ptr(*this, _affine->create_bg(x, y));
        }

        if (is_huge()) {
            return ks::background_ptr(*this, _huge->create_bg(x, y));
        }

        if(is_regular_composite()) {
            if(auto optional = _regular_composite->create_background_ptr(*this, x, y); optional.has_value()) {
                return bn::move(*optional);
            }
            BN_ERROR("regular_composite create_bg failed");
        }

        if(is_composite_huge()) {
            if(auto optional = _composite_huge->create_background_ptr(*this, x, y); optional.has_value()) {
                return bn::move(*optional);
            }
            BN_ERROR("composite_huge create_bg failed");
        }
    }

    [[nodiscard]] bn::optional<ks::background_ptr> background_item::create_bg_optional() {
        return create_bg_optional(0, 0);
    }

    [[nodiscard]] bn::optional<ks::background_ptr> background_item::create_bg_optional(bn::fixed x, bn::fixed y) {
        BN_ASSERT(has_value(), "Background item is empty");

        if (is_regular()) {
            if (_regular_needs_decompression(*_regular)) {
                void *tiles_ewram = nullptr;
                void *map_ewram = nullptr;
                void *palette_ewram = nullptr;
                bn::optional<bn::regular_bg_item> dec =
                        ks::background_ptr::try_decompress_to_ewram(
                                *_regular, tiles_ewram, map_ewram, palette_ewram);
                if(! dec.has_value()) {
                    return bn::nullopt;
                }
                bn::bg_blocks_manager::update_and_delay_commit();
                if (auto optional = dec->create_bg_optional(x, y); optional.has_value()) {
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

        if(is_huge()) {
            return bn::nullopt;
        }

        if(is_composite_huge()) {
            if (auto optional = _composite_huge->create_background_ptr(*this, x, y); optional.has_value()) {
                return bn::move(*optional);
            }
            return bn::nullopt;
        }

        if(is_regular_composite()) {
            if (auto optional = _regular_composite->create_background_ptr(*this, x, y); optional.has_value()) {
                return bn::move(*optional);
            }
        }

        return bn::nullopt;
    }
}
