#include "background_item.h"
#include "background_ptr.h"

#include "globals.h"
#include "utils/scenario_reader.h"

#include "bn_bg_palette_ptr.h"
#include "bn_memory.h"
#include "bn_compression_type.h"
#include "bn_span.h"
#include "bn_tile.h"
#include "bn_color.h"
#include "bn_regular_bg_map_cell.h"
#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_tiles_ptr.h"
#include "bn_size.h"
#include "ext_bg_blocks_manager.h"

namespace ks {

    namespace {
        void _release_composite_state(composite_bg_state*& state)
        {
            if(state) {
                composite_bg_runtime::free_state(state);
                state = nullptr;
            }
        }

        void _release_composite_huge_state(composite_huge_bg_state*& state)
        {
            if(state) {
                composite_huge_bg_runtime::free_state(state);
                state = nullptr;
            }
        }
    }

    namespace {

        void _free_partial_decompress(void* tiles_ewram, void* map_ewram, void* palette_ewram)
        {
            if(tiles_ewram) {
                bn::memory::ewram_free(tiles_ewram);
            }
            if(map_ewram) {
                bn::memory::ewram_free(map_ewram);
            }
            if(palette_ewram) {
                bn::memory::ewram_free(palette_ewram);
            }
        }

        int _decompress_ewram_bytes_needed(const bn::regular_bg_item& src)
        {
            int bytes = 0;
            const bn::regular_bg_tiles_item& tiles_item = src.tiles_item();
            if(tiles_item.compression() != bn::compression_type::NONE) {
                bytes += tiles_item.tiles_ref().size() * int(sizeof(bn::tile));
            }
            const bn::bg_palette_item& palette_item = src.palette_item();
            if(palette_item.compression() != bn::compression_type::NONE) {
                bytes += palette_item.colors_ref().size() * int(sizeof(bn::color));
            }
            const bn::regular_bg_map_item& map_item = src.map_item();
            if(map_item.compression() != bn::compression_type::NONE) {
                const bn::size dims = map_item.dimensions();
                bytes += dims.width() * dims.height() * int(sizeof(bn::regular_bg_map_cell));
            }
            return bytes;
        }

    }  // namespace

    bn::optional<bn::regular_bg_item> background_ptr::try_decompress_to_ewram(
            const bn::regular_bg_item &src,
            void *&tiles_ewram, void *&map_ewram, void *&palette_ewram) {
        tiles_ewram = nullptr;
        map_ewram = nullptr;
        palette_ewram = nullptr;

        const int needed = _decompress_ewram_bytes_needed(src);
        const bool release_textdb = ks::globals::ALWAYS_REDUCE_TEXTDB
                || (needed > 0 && bn::memory::available_alloc_ewram() < needed);
        if(release_textdb) {
            ks::textdb::request_release();
        }

        const bn::regular_bg_tiles_item &tiles_item = src.tiles_item();
        const bn::bg_palette_item &palette_item = src.palette_item();
        const bn::regular_bg_map_item &map_item = src.map_item();

        bn::regular_bg_tiles_item dec_tiles = tiles_item;
        bn::bg_palette_item dec_palette = palette_item;
        bn::regular_bg_map_item dec_map = map_item;

        if (tiles_item.compression() != bn::compression_type::NONE) {
            int n = tiles_item.tiles_ref().size();
            int bytes = n * int(sizeof(bn::tile));
            tiles_ewram = bn::memory::ewram_alloc(bytes);
            if(! tiles_ewram) {
                return bn::nullopt;
            }
            bn::span<bn::tile> dst(static_cast<bn::tile *>(tiles_ewram), n);
            dec_tiles = tiles_item.decompress(dst);
        }

        if (palette_item.compression() != bn::compression_type::NONE) {
            int n = palette_item.colors_ref().size();
            int bytes = n * int(sizeof(bn::color));
            palette_ewram = bn::memory::ewram_alloc(bytes);
            if(! palette_ewram) {
                _free_partial_decompress(tiles_ewram, nullptr, nullptr);
                tiles_ewram = nullptr;
                return bn::nullopt;
            }
            bn::span<bn::color> dst(static_cast<bn::color *>(palette_ewram), n);
            dec_palette = palette_item.decompress(dst);
        }

        if (map_item.compression() != bn::compression_type::NONE) {
            bn::size dims = map_item.dimensions();
            int n = dims.width() * dims.height();
            int bytes = n * int(sizeof(bn::regular_bg_map_cell));
            map_ewram = bn::memory::ewram_alloc(bytes);
            if(! map_ewram) {
                _free_partial_decompress(tiles_ewram, nullptr, palette_ewram);
                tiles_ewram = nullptr;
                palette_ewram = nullptr;
                return bn::nullopt;
            }
            bn::span<bn::regular_bg_map_cell> dst(static_cast<bn::regular_bg_map_cell *>(map_ewram), n);
            dec_map = map_item.decompress(dst);
        }

        return bn::regular_bg_item(dec_tiles, dec_palette, dec_map);
    }

    bn::regular_bg_item background_ptr::decompress_to_ewram(const bn::regular_bg_item &src,
                                                             void *&tiles_ewram, void *&map_ewram,
                                                             void *&palette_ewram) {
        bn::optional<bn::regular_bg_item> out_item =
                try_decompress_to_ewram(src, tiles_ewram, map_ewram, palette_ewram);
        BN_ASSERT(out_item.has_value(), "ewram_alloc failed for BG decompression");
        return *out_item;
    }

    background_ptr::background_ptr(background_ptr &&other) noexcept
        : _item(bn::move(other._item)),
          _regular_ptr(bn::move(other._regular_ptr)),
          _affine_ptr(bn::move(other._affine_ptr)),
          _huge_ptr(bn::move(other._huge_ptr)),
          _composite_huge_ptr(bn::move(other._composite_huge_ptr)),
          _tiles_ewram(other._tiles_ewram),
          _map_ewram(other._map_ewram),
          _palette_ewram(other._palette_ewram),
          _composite_state(other._composite_state),
          _composite_huge_state(other._composite_huge_state) {
        other._tiles_ewram = nullptr;
        other._map_ewram = nullptr;
        other._palette_ewram = nullptr;
        other._composite_state = nullptr;
        other._composite_huge_state = nullptr;
    }

    background_ptr &background_ptr::operator=(background_ptr &&other) noexcept {
        if (this != &other) {
            _regular_ptr.reset();
            _affine_ptr.reset();
            _huge_ptr.reset();
            _composite_huge_ptr.reset();
            _free_ewram();
            _release_composite_state(_composite_state);
            _release_composite_huge_state(_composite_huge_state);

            _item = bn::move(other._item);
            _regular_ptr = bn::move(other._regular_ptr);
            _affine_ptr = bn::move(other._affine_ptr);
            _huge_ptr = bn::move(other._huge_ptr);
            _composite_huge_ptr = bn::move(other._composite_huge_ptr);
            _tiles_ewram = other._tiles_ewram;
            _map_ewram = other._map_ewram;
            _palette_ewram = other._palette_ewram;
            _composite_state = other._composite_state;
            _composite_huge_state = other._composite_huge_state;
            other._tiles_ewram = nullptr;
            other._map_ewram = nullptr;
            other._palette_ewram = nullptr;
            other._composite_state = nullptr;
            other._composite_huge_state = nullptr;
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
        if(_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().palette();
        }
        if(_composite_huge_ptr.has_value()) {
            return _composite_huge_ptr->regular_bg_ptr().palette();
        }
        BN_ERROR("palette: Background pointer has no value");
    }

    background_ptr::~background_ptr() {
        _regular_ptr.reset();
        _affine_ptr.reset();
        _huge_ptr.reset();
        _composite_huge_ptr.reset();
        _free_ewram();
        _release_composite_state(_composite_state);
        _release_composite_huge_state(_composite_huge_state);
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

    void background_ptr::release_decompressed_ewram_if_committed() {
        if(_composite_state) {
            composite_bg_runtime::release_decompressed_ewram_if_committed(*_composite_state);
        }

        if (!_tiles_ewram && !_map_ewram && !_palette_ewram) {
            return;
        }

        if (!_regular_ptr.has_value()) {
            return;
        }

        const bn::regular_bg_tiles_ptr &tiles = _regular_ptr->tiles();
        const bn::regular_bg_map_ptr &map = _regular_ptr->map();

        if (_tiles_ewram && bn::bg_blocks_manager::must_commit(tiles.handle())) {
            return;
        }

        if (_map_ewram && bn::bg_blocks_manager::must_commit(map.handle())) {
            return;
        }

        if (_tiles_ewram) {
            bn::bg_blocks_manager::detach_source_data(tiles.handle());
        }

        if (_map_ewram) {
            bn::bg_blocks_manager::detach_source_data(map.handle());
        }

        _free_ewram();
    }

    void background_ptr::force_create_regular_ptr(const bn::regular_bg_item &create_bg) {
        BN_ASSERT(!_huge_ptr.has_value(), "force_create_regular_ptr: Background pointer is huge, cannot emplace regular pointer");
        BN_ASSERT(!_composite_huge_ptr.has_value(), "force_create_regular_ptr: Background pointer is composite huge, cannot emplace regular pointer");
        BN_ASSERT(!_affine_ptr.has_value(), "force_create_regular_ptr: Background pointer is affine, cannot emplace regular pointer");

        void *new_tiles = nullptr;
        void *new_map = nullptr;
        void *new_palette = nullptr;
        bn::regular_bg_item dec_item = decompress_to_ewram(create_bg, new_tiles, new_map, new_palette);

        _regular_ptr.reset();
        _free_ewram();
        _release_composite_state(_composite_state);

        bn::bg_blocks_manager::update_and_delay_commit();

        _tiles_ewram = new_tiles;
        _map_ewram = new_map;
        _palette_ewram = new_palette;
        _regular_ptr = dec_item.create_bg();
    }

    bool background_ptr::switch_composite_huge_variant(const background_item& new_item)
    {
        return switch_composite_variant(new_item);
    }

    bool background_ptr::switch_composite_variant(const background_item& new_item)
    {
        BN_ASSERT(_item.is_composite_variant_switch(new_item),
                  "switch_composite_variant: not a variant switch");

        if(_composite_huge_ptr.has_value()) {
            BN_ASSERT(_composite_huge_state, "switch_composite_variant: missing huge state");
            BN_ASSERT(new_item.is_composite_huge(), "switch_composite_variant: type mismatch (huge)");
            composite_huge_bg_runtime::switch_variant(
                *_composite_huge_state, new_item.composite_variant_index());
            _item = new_item;
            _composite_huge_ptr->update();
            return true;
        }

        BN_ASSERT(_composite_state, "switch_composite_variant: missing composite state");
        BN_ASSERT(_regular_ptr.has_value(), "switch_composite_variant: not composite regular");
        BN_ASSERT(new_item.is_regular_composite(), "switch_composite_variant: type mismatch (regular)");
        composite_bg_runtime::switch_variant(
            *_composite_state, new_item.composite_variant_index());
        _item = new_item;
        return true;
    }

    const ks::background_item& background_ptr::item() const {
        return _item;
    }

    const bn::regular_bg_ptr background_ptr::regular_ptr() const {
        if (_regular_ptr.has_value()) {
            return *_regular_ptr;
        }
        if(_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr();
        }
        if(_composite_huge_ptr.has_value()) {
            return _composite_huge_ptr->regular_bg_ptr();
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

        if(_huge_ptr.has_value()) {
            return _huge_ptr->position();
        }

        if(_composite_huge_ptr.has_value()) {
            return _composite_huge_ptr->position();
        }

        BN_ERROR("position: Background pointer has no value");
    }

    void background_ptr::set_position(bn::fixed x, bn::fixed y) {
        if(_regular_ptr.has_value()) {
            return _regular_ptr->set_position(x, y);
        }

        if(_affine_ptr.has_value()) {
            return _affine_ptr->set_position(x, y);
        }

        if(_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().set_position(x, y);
        }

        if(_composite_huge_ptr.has_value()) {
            return _composite_huge_ptr->regular_bg_ptr().set_position(x, y);
        }

        BN_ERROR("set_position: Background pointer has no value");
    }

    bool background_ptr::visible() {
        if(_regular_ptr.has_value()) {
            return _regular_ptr->visible();
        }

        if(_affine_ptr.has_value()) {
            return _affine_ptr->visible();
        }

        if(_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().visible();
        }

        if(_composite_huge_ptr.has_value()) {
            return _composite_huge_ptr->regular_bg_ptr().visible();
        }

        BN_ERROR("visible: Background pointer has no value");
        return false;
    }

    void background_ptr::set_visible(bool visible) {
        if(_regular_ptr.has_value()) {
            return _regular_ptr->set_visible(visible);
        }

        if(_affine_ptr.has_value()) {
            return _affine_ptr->set_visible(visible);
        }

        if(_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().set_visible(visible);
        }

        if(_composite_huge_ptr.has_value()) {
            return _composite_huge_ptr->regular_bg_ptr().set_visible(visible);
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

        if(_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().priority();
        }

        if(_composite_huge_ptr.has_value()) {
            return _composite_huge_ptr->regular_bg_ptr().priority();
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

        if(_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().set_priority(priority);
        }

        if(_composite_huge_ptr.has_value()) {
            return _composite_huge_ptr->regular_bg_ptr().set_priority(priority);
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

        if(_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().z_order();
        }

        if(_composite_huge_ptr.has_value()) {
            return _composite_huge_ptr->regular_bg_ptr().z_order();
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

        if(_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().set_z_order(order);
        }

        if(_composite_huge_ptr.has_value()) {
            return _composite_huge_ptr->regular_bg_ptr().set_z_order(order);
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

        if(_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().blending_enabled();
        }

        if(_composite_huge_ptr.has_value()) {
            return _composite_huge_ptr->regular_bg_ptr().blending_enabled();
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

        if(_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().set_blending_enabled(enabled);
        }

        if(_composite_huge_ptr.has_value()) {
            return _composite_huge_ptr->regular_bg_ptr().set_blending_enabled(enabled);
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

        if(_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().set_palette(bg_palette);
        }

        if(_composite_huge_ptr.has_value()) {
            return _composite_huge_ptr->regular_bg_ptr().set_palette(bg_palette);
        }

        BN_ERROR("set_palette: Background pointer is not regular or huge");
    }
}
