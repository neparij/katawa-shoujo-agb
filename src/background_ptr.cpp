#include "background_item.h"
#include "background_ptr.h"

#include "bn_bg_palette_ptr.h"
#include "bn_memory.h"
#include "bn_compression_type.h"
#include "bn_span.h"
#include "bn_tile.h"
#include "bn_color.h"
#include "bn_regular_bg_map_cell.h"
#include "bn_size.h"
#include "ext_bg_blocks_manager.h"

namespace ks {

    bn::regular_bg_item background_ptr::decompress_to_ewram(const bn::regular_bg_item &src,
                                                             void *&tiles_ewram, void *&map_ewram,
                                                             void *&palette_ewram) {
        tiles_ewram = nullptr;
        map_ewram = nullptr;
        palette_ewram = nullptr;

        const bn::regular_bg_tiles_item &tiles_item = src.tiles_item();
        const bn::bg_palette_item &palette_item = src.palette_item();
        const bn::regular_bg_map_item &map_item = src.map_item();

        // Start from copies of the source items; only swap in the
        // EWRAM-backed versions for the components that actually
        // needed decompression. Each per-item `decompress` call is a
        // no-op for already-uncompressed data, but butano's
        // size-check assert fires before that no-op, so we *must*
        // skip the call (not just allocate a dummy buffer) for
        // uncompressed components.
        bn::regular_bg_tiles_item dec_tiles = tiles_item;
        bn::bg_palette_item dec_palette = palette_item;
        bn::regular_bg_map_item dec_map = map_item;

        if (tiles_item.compression() != bn::compression_type::NONE) {
            int n = tiles_item.tiles_ref().size();
            int bytes = n * int(sizeof(bn::tile));
            tiles_ewram = bn::memory::ewram_alloc(bytes);
            BN_ASSERT(tiles_ewram, "ewram_alloc failed for BG tiles decompression: ", bytes);
            bn::span<bn::tile> dst(static_cast<bn::tile *>(tiles_ewram), n);
            dec_tiles = tiles_item.decompress(dst);
        }

        if (palette_item.compression() != bn::compression_type::NONE) {
            int n = palette_item.colors_ref().size();
            int bytes = n * int(sizeof(bn::color));
            palette_ewram = bn::memory::ewram_alloc(bytes);
            BN_ASSERT(palette_ewram, "ewram_alloc failed for BG palette decompression: ", bytes);
            bn::span<bn::color> dst(static_cast<bn::color *>(palette_ewram), n);
            dec_palette = palette_item.decompress(dst);
        }

        if (map_item.compression() != bn::compression_type::NONE) {
            bn::size dims = map_item.dimensions();
            int n = dims.width() * dims.height();
            int bytes = n * int(sizeof(bn::regular_bg_map_cell));
            map_ewram = bn::memory::ewram_alloc(bytes);
            BN_ASSERT(map_ewram, "ewram_alloc failed for BG map decompression: ", bytes);
            bn::span<bn::regular_bg_map_cell> dst(static_cast<bn::regular_bg_map_cell *>(map_ewram), n);
            dec_map = map_item.decompress(dst);
        }

        return bn::regular_bg_item(dec_tiles, dec_palette, dec_map);
    }

    background_ptr::background_ptr(background_ptr &&other) noexcept
        : _item(bn::move(other._item)),
          _regular_ptr(bn::move(other._regular_ptr)),
          _affine_ptr(bn::move(other._affine_ptr)),
          _huge_ptr(bn::move(other._huge_ptr)),
          _tiles_ewram(other._tiles_ewram),
          _map_ewram(other._map_ewram),
          _palette_ewram(other._palette_ewram) {
        // Zero out the moved-from pointers so the source's destructor
        // is a no-op and the buffers aren't double-freed when the
        // moved-from object goes out of scope.
        other._tiles_ewram = nullptr;
        other._map_ewram = nullptr;
        other._palette_ewram = nullptr;
    }

    background_ptr &background_ptr::operator=(background_ptr &&other) noexcept {
        if (this != &other) {
            // Drop our own bg_ptrs *before* freeing our EWRAM, mirroring
            // the destructor's invariant: butano's bg_blocks_manager
            // dereferences `item.data` (which points into our EWRAM)
            // both at allocation time and during the next vblank's
            // `commit_uncompressed`. Releasing the bg_ptr triggers
            // `decrease_usages` → moves the bg_blocks item to
            // `to_remove`; only after the *next* `update()` is the
            // pointer truly orphaned. We can't wait for that here, so
            // we rely on the per-item `data` pointer being last-touched
            // during the synchronous `_commit_item` call inside the
            // bg_ptr's destruction path before this assignment returns.
            _regular_ptr.reset();
            _affine_ptr.reset();
            _huge_ptr.reset();
            _free_ewram();

            _item = bn::move(other._item);
            _regular_ptr = bn::move(other._regular_ptr);
            _affine_ptr = bn::move(other._affine_ptr);
            _huge_ptr = bn::move(other._huge_ptr);
            _tiles_ewram = other._tiles_ewram;
            _map_ewram = other._map_ewram;
            _palette_ewram = other._palette_ewram;
            other._tiles_ewram = nullptr;
            other._map_ewram = nullptr;
            other._palette_ewram = nullptr;
        }
        return *this;
    }

    bn::bg_palette_ptr background_ptr::palette() const {
        if (_regular_ptr.has_value()) {
            return _regular_ptr->palette();
        }
        if (_affine_ptr.has_value()) {
            return _affine_ptr->palette();
        }
        if (_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().palette();
        }
        BN_ERROR("palette: Background pointer has no value");
    }

    background_ptr::~background_ptr() {
        // Order matters: drop the bg_ptr first so butano releases its
        // hold on the EWRAM data (the bg_blocks item transitions to
        // TO_REMOVE here; the `data` pointer is no longer dereferenced
        // by the live commit path). Only then is it safe to
        // `ewram_free` the underlying buffers.
        _regular_ptr.reset();
        _affine_ptr.reset();
        _huge_ptr.reset();
        _free_ewram();
    }

    void background_ptr::_free_ewram() {
        if (_tiles_ewram) {
            bn::memory::ewram_free(_tiles_ewram);
            _tiles_ewram = nullptr;
        }
        if (_map_ewram) {
            bn::memory::ewram_free(_map_ewram);
            _map_ewram = nullptr;
        }
        if (_palette_ewram) {
            bn::memory::ewram_free(_palette_ewram);
            _palette_ewram = nullptr;
        }
    }

    void background_ptr::force_create_regular_ptr(const bn::regular_bg_item &create_bg) {
        BN_ASSERT(!_huge_ptr.has_value(), "force_create_regular_ptr: Background pointer is huge, cannot emplace regular pointer");
        BN_ASSERT(!_affine_ptr.has_value(), "force_create_regular_ptr: Background pointer is affine, cannot emplace regular pointer");

        // Mirrors `background_item::create_bg`'s strategy — see
        // that function's long comment for the full rationale.
        // Order: decompress the new asset into EWRAM first, drop
        // the previous bg_ptr and its EWRAM buffers (now the old
        // bg_blocks entry is TO_REMOVE), call
        // `update_and_delay_commit()` so the next allocation lands
        // at the lowest free slot AND commits at vblank, then
        // create the bg_ptr from the uncompressed item.
        //
        // Holding two BGs' worth of EWRAM during the brief window
        // between decompression and `_regular_ptr.reset()` is fine:
        // each LZ77/RLE-unpacked BG is ~22 KB, well within EWRAM's
        // remaining budget after butano's own dynamic allocations.
        void *new_tiles = nullptr;
        void *new_map = nullptr;
        void *new_palette = nullptr;
        bn::regular_bg_item dec_item = decompress_to_ewram(create_bg, new_tiles, new_map, new_palette);

        _regular_ptr.reset();
        _free_ewram();

        bn::bg_blocks_manager::update_and_delay_commit();

        _tiles_ewram = new_tiles;
        _map_ewram = new_map;
        _palette_ewram = new_palette;
        _regular_ptr = dec_item.create_bg();
    }

    const ks::background_item& background_ptr::item() const {
        return _item;
    }

    const bn::regular_bg_ptr background_ptr::regular_ptr() const {
        if (_regular_ptr.has_value()) {
            return *_regular_ptr;
        }
        if (_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr();
        }
        BN_ERROR("regular_ptr: Background pointer is not regular");
    }

    const bn::affine_bg_ptr background_ptr::affine_ptr() const {
        if (_affine_ptr.has_value()) {
            return *_affine_ptr;
        }
        BN_ERROR("affine_ptr: Background pointer is not affine");
    }

    bn::fixed_point background_ptr::position() const {
        if (_regular_ptr.has_value()) {
            return _regular_ptr->position();
        }

        if (_affine_ptr.has_value()) {
            return _affine_ptr->position();
        }

        if (_huge_ptr.has_value()) {
            return _huge_ptr->position();
        }

        BN_ERROR("position: Background pointer has no value");
    }

    void background_ptr::set_position(bn::fixed x, bn::fixed y) {
        if (_regular_ptr.has_value()) {
            return _regular_ptr->set_position(x, y);
        }

        if (_affine_ptr.has_value()) {
            return _affine_ptr->set_position(x, y);
        }

        if (_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().set_top_left_position(x, y);
        }

        BN_ERROR("set_position: Background pointer has no value");
    }

    bool background_ptr::visible() {
        if (_regular_ptr.has_value()) {
            return _regular_ptr->visible();
        }

        if (_affine_ptr.has_value()) {
            return _affine_ptr->visible();
        }

        if (_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().visible();
        }

        BN_ERROR("visible: Background pointer has no value");
        return false;
    }

    void background_ptr::set_visible(bool visible) {
        if (_regular_ptr.has_value()) {
            return _regular_ptr->set_visible(visible);
        }

        if (_affine_ptr.has_value()) {
            return _affine_ptr->set_visible(visible);
        }

        if (_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().set_visible(visible);
        }

        BN_ERROR("set_visible: Background pointer has no value");
    }

    int background_ptr::priority() {
        if (_regular_ptr.has_value()) {
            return _regular_ptr->priority();
        }

        if (_affine_ptr.has_value()) {
            return _affine_ptr->priority();
        }

        if (_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().priority();
        }

        BN_ERROR("priority: Background pointer has no value");
        return 0;
    }

    void background_ptr::set_priority(int priority) {
        if (_regular_ptr.has_value()) {
            return _regular_ptr->set_priority(priority);
        }

        if (_affine_ptr.has_value()) {
            return _affine_ptr->set_priority(priority);
        }

        if (_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().set_priority(priority);
        }

        BN_ERROR("set_priority: Background pointer has no value");
    }

    int background_ptr::z_order() {
        if (_regular_ptr.has_value()) {
            return _regular_ptr->z_order();
        }

        if (_affine_ptr.has_value()) {
            return _affine_ptr->z_order();
        }

        if (_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().z_order();
        }

        BN_ERROR("z_order: Background pointer has no value");
        return 0;
    }

    void background_ptr::set_z_order(int order) {
        if (_regular_ptr.has_value()) {
            return _regular_ptr->set_z_order(order);
        }

        if (_affine_ptr.has_value()) {
            return _affine_ptr->set_z_order(order);
        }

        if (_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().set_z_order(order);
        }

        BN_ERROR("set_z_order: Background pointer has no value");
    }

    bool background_ptr::blending_enabled() {
        if (_regular_ptr.has_value()) {
            return _regular_ptr->blending_enabled();
        }

        if (_affine_ptr.has_value()) {
            return _affine_ptr->blending_enabled();
        }

        if (_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().blending_enabled();
        }

        BN_ERROR("blending_enabled: Background pointer has no value");
        return false;
    }

    void background_ptr::set_blending_enabled(bool enabled) {
        if (_regular_ptr.has_value()) {
            return _regular_ptr->set_blending_enabled(enabled);
        }

        if (_affine_ptr.has_value()) {
            return _affine_ptr->set_blending_enabled(enabled);
        }

        if (_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().set_blending_enabled(enabled);
        }

        BN_ERROR("set_blending_enabled: Background pointer has no value");
    }

    void background_ptr::set_palette(const bn::bg_palette_ptr &bg_palette) {
        if (_regular_ptr.has_value()) {
            return _regular_ptr->set_palette(bg_palette);
        }

        if (_affine_ptr.has_value()) {
            return _affine_ptr->set_palette(bg_palette);
        }

        if (_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().set_palette(bg_palette);
        }

        BN_ERROR("set_palette: Background pointer is not regular or huge");
    }
}
