#ifndef BACKGROUND_PTR_H
#define BACKGROUND_PTR_H

#include "background_item.h"
#include "composite_bg_runtime.h"
#include "composite_huge_bg_runtime.h"
#include "bn_optional.h"
#include "bn_regular_bg_ptr.h"
#include "bn_affine_bg_ptr.h"
#include "ks_huge_bg.h"

namespace ks {

    class background_ptr {
    public:
        explicit background_ptr(const ks::background_item &item, const bn::regular_bg_ptr &regular_ptr)
            : _item(item),
              _regular_ptr(regular_ptr),
              _affine_ptr(bn::nullopt),
              _huge_ptr(bn::nullopt) {
        }

        explicit background_ptr(const ks::background_item &item, const bn::regular_bg_ptr &regular_ptr,
                                void *tiles_ewram, void *map_ewram, void *palette_ewram)
            : _item(item),
              _regular_ptr(regular_ptr),
              _affine_ptr(bn::nullopt),
              _huge_ptr(bn::nullopt),
              _tiles_ewram(tiles_ewram),
              _map_ewram(map_ewram),
              _palette_ewram(palette_ewram) {
        }

        explicit background_ptr(const ks::background_item &item, const bn::affine_bg_ptr &affine_ptr)
            : _item(item),
              _regular_ptr(bn::nullopt),
              _affine_ptr(affine_ptr),
              _huge_ptr(bn::nullopt) {
        }

        explicit background_ptr(const ks::background_item& item, ks::huge_bg huge_ptr)
            : _item(item),
              _regular_ptr(bn::nullopt),
              _affine_ptr(bn::nullopt),
              _huge_ptr(bn::move(huge_ptr)),
              _composite_huge_ptr(bn::nullopt) {
        }

        explicit background_ptr(const ks::background_item& item, composite_huge_bg huge_ptr,
                                  composite_huge_bg_state* composite_huge_state)
            : _item(item),
              _regular_ptr(bn::nullopt),
              _affine_ptr(bn::nullopt),
              _huge_ptr(bn::nullopt),
              _composite_huge_ptr(bn::move(huge_ptr)),
              _composite_huge_state(composite_huge_state) {
        }

        explicit background_ptr(const ks::background_item &item, const bn::regular_bg_ptr &regular_ptr,
                                composite_bg_state* composite_state)
            : _item(item),
              _regular_ptr(regular_ptr),
              _affine_ptr(bn::nullopt),
              _huge_ptr(bn::nullopt),
              _composite_state(composite_state) {
            if (_composite_state) {
                composite_bg_runtime::register_state(_composite_state);
            }
        }

        background_ptr(background_ptr &&other) noexcept;
        background_ptr &operator=(background_ptr &&other) noexcept;

        bn::bg_palette_ptr palette() const;

        background_ptr(const background_ptr &) = delete;
        background_ptr &operator=(const background_ptr &) = delete;

        ~background_ptr();

        void force_create_regular_ptr(const bn::regular_bg_item &create_bg);

        /// After `bn::core::update()` (vblank commit), drop EWRAM decompression
        /// buffers that are no longer referenced by bg_blocks_manager.
        void release_decompressed_ewram_if_committed();

        [[nodiscard]] const ks::background_item &item() const;
        [[nodiscard]] const bn::regular_bg_ptr regular_ptr() const;
        [[nodiscard]] const bn::affine_bg_ptr affine_ptr() const;

        [[nodiscard]] bn::fixed_point position() const;
        void set_position(bn::fixed x, bn::fixed y);

        [[nodiscard]] bool visible();
        void set_visible(bool visible);

        [[nodiscard]] int priority();
        void set_priority(int priority);

        [[nodiscard]] int z_order();
        void set_z_order(int order);

        [[nodiscard]] bool blending_enabled();
        void set_blending_enabled(bool enabled);
        void set_palette(const bn::bg_palette_ptr &bg_palette);

        [[nodiscard]] bool switch_composite_huge_variant(const background_item& new_item);

        [[nodiscard]] bool switch_composite_variant(const background_item& new_item);

        [[nodiscard]] static bn::regular_bg_item decompress_to_ewram(const bn::regular_bg_item &src,
                                                                      void *&tiles_ewram, void *&map_ewram,
                                                                      void *&palette_ewram);

        /// Like `decompress_to_ewram`, but returns nullopt (and frees partial
        /// allocations) when EWRAM is exhausted — used by `create_bg_optional`.
        [[nodiscard]] static bn::optional<bn::regular_bg_item> try_decompress_to_ewram(
                const bn::regular_bg_item &src,
                void *&tiles_ewram, void *&map_ewram, void *&palette_ewram);

    private:
        void _free_ewram();

        ks::background_item _item;
        bn::optional<bn::regular_bg_ptr> _regular_ptr;
        bn::optional<bn::affine_bg_ptr> _affine_ptr;
        bn::optional<ks::huge_bg> _huge_ptr;
        bn::optional<ks::composite_huge_bg> _composite_huge_ptr;

        void *_tiles_ewram = nullptr;
        void *_map_ewram = nullptr;
        void *_palette_ewram = nullptr;

        composite_bg_state* _composite_state = nullptr;
        composite_huge_bg_state* _composite_huge_state = nullptr;
    };
}

#endif //BACKGROUND_PTR_H
