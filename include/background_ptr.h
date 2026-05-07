#ifndef BACKGROUND_PTR_H
#define BACKGROUND_PTR_H

#include "background_item.h"
#include "bn_optional.h"
#include "bn_regular_bg_ptr.h"
#include "bn_affine_bg_ptr.h"
#include "ks_huge_bg.h"

namespace ks {

    class background_ptr {
    public:
        // Constructor for a regular BG that is constructed from *uncompressed*
        // data (either the source asset was uncompressed to begin with, or
        // `background_item::create_bg` already decompressed it into its own
        // EWRAM-owned buffers — in the latter case the buffer pointers are
        // passed via the other constructor below so this ptr takes
        // ownership of the lifetime).
        explicit background_ptr(const ks::background_item &item, const bn::regular_bg_ptr &regular_ptr)
            : _item(item),
              _regular_ptr(regular_ptr),
              _affine_ptr(bn::nullopt),
              _huge_ptr(bn::nullopt) {
        }

        // Constructor that additionally takes ownership of one or more
        // dynamically-allocated EWRAM buffers used to hold the
        // decompressed tile / map / palette data referenced by the
        // underlying `bn::regular_bg_ptr`. Butano keeps a *pointer*
        // (not a copy) into these buffers for the entire lifetime of
        // the bg_ptr — both for the initial commit and for any later
        // re-commit (e.g. `reload_tiles_ref`). The ptr's destructor
        // therefore drops the bg_ptr **first** and only then frees
        // the buffers, guaranteeing butano never reads freed memory.
        //
        // Any of `tiles_ewram`, `map_ewram`, `palette_ewram` may be
        // null when only a subset of the source asset's parts were
        // compressed — the destructor is null-safe.
        //
        // Why decompress to EWRAM at all instead of letting butano's
        // built-in compressed-commit path handle it: butano's
        // `commit_compressed` only runs once per frame and spreads
        // the work across multiple vblanks. With our anti-fragmentation
        // patch (`bn_bg_blocks_manager.cpp` `_create_impl` flushing
        // `to_remove` before the FREE-fit search) the new BG lands
        // at slot 0 with `delay_commit = true`, so the compressed
        // commit *would* run on the very next vblank — but visibly
        // unpacks over several frames as the gradient of a still-
        // partly-uncommitted BG is drawn through. Decompressing
        // eagerly to EWRAM lets us pass `compression_type::NONE`
        // to butano, which in turn enables the synchronous-uncompressed
        // commit path and yields a single-frame, glitch-free swap.
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

        explicit background_ptr(const ks::background_item &item, huge_bg huge_ptr)
            : _item(item),
              _regular_ptr(bn::nullopt),
              _affine_ptr(bn::nullopt),
              _huge_ptr(bn::move(huge_ptr)) {
        }

        // Move-only: the EWRAM buffers below are *exclusively* owned
        // by exactly one `background_ptr` at a time. Copying the ptr
        // would make two destructors race to `ewram_free` the same
        // pointer — a heap-corrupting double-free. Move transfers
        // ownership and zeros the source so the moved-from ptr's
        // destructor is a no-op.
        background_ptr(background_ptr &&other) noexcept;
        background_ptr &operator=(background_ptr &&other) noexcept;

        background_ptr(const background_ptr &) = delete;
        background_ptr &operator=(const background_ptr &) = delete;

        ~background_ptr();

        // Atomically replace the underlying regular bg_ptr with a fresh
        // one from `create_bg`. Used by single-shot effects (e.g. the
        // hanako fireworks flash sequence) that swap the current BG's
        // tile data on every frame without going through the scene
        // manager's CHANGE BACKGROUND pipeline. Handles compressed
        // source assets by decompressing into freshly-allocated EWRAM
        // and freeing the previous decompression buffers, mirroring
        // the normal `create_bg` path.
        void force_create_regular_ptr(const bn::regular_bg_item &create_bg);

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

        // Decompress every compressed component of `src` (tiles, map,
        // palette) into freshly `bn::memory::ewram_alloc`'d buffers
        // and return a regular_bg_item that references the
        // decompressed data with `compression_type::NONE` for every
        // component. Components that were already uncompressed are
        // passed through unchanged and their corresponding output
        // buffer pointer is left as `nullptr`.
        //
        // On return, ownership of the (possibly-null) buffer pointers
        // is transferred to the caller, which is responsible for
        // moving them into a `background_ptr` so they get freed once
        // the resulting bg_ptr is dropped — see the
        // `background_ptr(item, regular_ptr, tiles, map, palette)`
        // constructor.
        //
        // Used by both the normal `background_item::create_bg` path
        // and the in-place `force_create_regular_ptr` path so they
        // share the same decompression contract and EWRAM ownership
        // semantics.
        [[nodiscard]] static bn::regular_bg_item decompress_to_ewram(const bn::regular_bg_item &src,
                                                                      void *&tiles_ewram, void *&map_ewram,
                                                                      void *&palette_ewram);

    private:
        // Free the EWRAM-owned decompression buffers, if any. Must be
        // called *after* the underlying bg_ptr has been reset, so
        // butano's bg_blocks_manager has stopped referencing the
        // buffers (its `item.data` pointer is updated in
        // `decrease_usages` → `_remove_adjacent_item` flow before
        // the call returns). Null-safe per buffer.
        void _free_ewram();

        ks::background_item _item;
        bn::optional<bn::regular_bg_ptr> _regular_ptr;
        bn::optional<bn::affine_bg_ptr> _affine_ptr;
        bn::optional<ks::huge_bg> _huge_ptr;

        void *_tiles_ewram = nullptr;
        void *_map_ewram = nullptr;
        void *_palette_ewram = nullptr;
    };
}

#endif //BACKGROUND_PTR_H
