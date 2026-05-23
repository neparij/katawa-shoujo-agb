#include "composite_huge_bg_runtime.h"

#include "background_item.h"
#include "background_ptr.h"
#include "composite_huge_bg_item.h"
#include "ext_bg_blocks_manager.h"
#include "ks_huge_bg.h"

#include "bn_bg_palette_ptr.h"
#include "bn_memory.h"
#include "bn_bg_tiles.h"
#include "bn_regular_bg_tiles_item.h"
#include "bn_regular_bg_map_ptr.h"
#include "bn_size.h"
#include "bn_span.h"
#include "bn_tile.h"
#include "bn_math.h"
#include "gba_math.h"

namespace ks::composite_huge_bg_runtime {

namespace detail {

inline int tile_offset_for_axis(const int bg_px, const int previous_bg_px, const bool initialized)
{
    return huge_bg_tile_offset_for_axis(bg_px, previous_bg_px, initialized);
}

class rle_byte_reader
{
public:
    explicit rle_byte_reader(const unsigned char* compressed) : _p(compressed + 4) {}

    unsigned char next()
    {
        if(_run_remaining == 0) {
            _refill();
        }
        --_run_remaining;
        return _run_compressed ? _run_byte : *_p++;
    }

    void skip(int bytes)
    {
        while(bytes > 0) {
            if(_run_remaining == 0) {
                _refill();
            }
            const int take = _run_remaining < bytes ? _run_remaining : bytes;
            _run_remaining -= take;
            bytes -= take;
            if(! _run_compressed) {
                _p += take;
            }
        }
    }

private:
    void _refill()
    {
        const unsigned char flag = *_p++;
        if(flag & 0x80) {
            _run_compressed = true;
            _run_remaining = int(flag & 0x7F) + 3;
            _run_byte = *_p++;
        } else {
            _run_compressed = false;
            _run_remaining = int(flag & 0x7F) + 1;
        }
    }

    const unsigned char* _p;
    int                  _run_remaining = 0;
    unsigned char        _run_byte = 0;
    bool                 _run_compressed = false;
};

class rle_cell_reader
{
public:
    explicit rle_cell_reader(const unsigned char* compressed) : _r(compressed) {}

    bn::regular_bg_map_cell next()
    {
        const unsigned int lo = _r.next();
        const unsigned int hi = _r.next();
        return bn::regular_bg_map_cell(lo | (hi << 8));
    }

    void skip(int cells)
    {
        _r.skip(cells * 2);
    }

private:
    rle_byte_reader _r;
};

constexpr int MAX_ACTIVE_BGS = 4;
composite_huge_bg* g_active_bgs[MAX_ACTIVE_BGS] = {};

bn::bg_palette_ptr asset_palette(const composite_bg_asset& asset)
{
    bn::optional<bn::bg_palette_ptr> found = bn::bg_palette_ptr::find(*asset.palette);
    if(found) {
        return *found;
    }
    return asset.palette->create_palette();
}

bn::span<const bn::tile> slab_tiles(const composite_tileset& ts, int slab)
{
    BN_ASSERT(slab >= 0 && slab < ts.slab_count);
    return ts.slabs[slab]->tiles_ref();
}

void decode_map_window(composite_huge_bg_state& state, const composite_variant& variant)
{
    const composite_bg_asset& asset = *state.asset;
    const int map_w = asset.map_w_px / 8;
    const int map_h = asset.map_h_px / 8;
    const int window_w = composite_huge_bg_state::map_window_w;
    const int window_h = composite_huge_bg_state::map_window_h;
    const int origin_x = state.x_offset % map_w;
    const int origin_y = state.y_offset % map_h;

    for(int yy = 0; yy < window_h; ++yy) {
        const int map_y = (origin_y + yy) % map_h;
        const int seg1 = map_w - origin_x;
        const int w1 = seg1 < window_w ? seg1 : window_w;
        const int w2 = window_w - w1;

        rle_cell_reader rd(variant.map_compressed);
        rd.skip(map_y * map_w + origin_x);
        for(int xx = 0; xx < w1; ++xx) {
            state.map_window[yy * window_w + xx] = rd.next();
        }

        if(w2 > 0) {
            rle_cell_reader rd_wrap(variant.map_compressed);
            rd_wrap.skip(map_y * map_w);
            for(int xx = 0; xx < w2; ++xx) {
                state.map_window[yy * window_w + w1 + xx] = rd_wrap.next();
            }
        }
    }
}

void stamp_transparent_tile(composite_huge_bg_state& state)
{
    if(! state.vram_tiles) {
        return;
    }
    bn::optional<bn::span<bn::tile>> vram_opt = state.vram_tiles->vram();
    if(! vram_opt) {
        return;
    }
    bn::tile zero{};
    (*vram_opt)[0] = zero;
}

}  // namespace detail

void init()
{
    for(composite_huge_bg*& bg : detail::g_active_bgs) {
        bg = nullptr;
    }
}

composite_huge_bg_state* alloc_state()
{
    void* mem = bn::memory::ewram_alloc(int(sizeof(composite_huge_bg_state)));
    BN_ASSERT(mem, "ewram_alloc failed for composite_huge_bg_state");
    return new(mem) composite_huge_bg_state();
}

void free_state(composite_huge_bg_state* state)
{
    if(! state) {
        return;
    }
    state->~composite_huge_bg_state();
    bn::memory::ewram_free(state);
}

void register_bg(composite_huge_bg* bg)
{
    if(! bg) {
        return;
    }
    for(composite_huge_bg*& slot : detail::g_active_bgs) {
        if(slot == bg) {
            return;
        }
    }
    for(composite_huge_bg*& slot : detail::g_active_bgs) {
        if(slot == nullptr) {
            slot = bg;
            return;
        }
    }
    BN_ERROR("composite_huge_bg_runtime: too many active composite huge backgrounds");
}

void unregister_bg(composite_huge_bg* bg)
{
    if(! bg) {
        return;
    }
    for(composite_huge_bg*& slot : detail::g_active_bgs) {
        if(slot == bg) {
            slot = nullptr;
            return;
        }
    }
}

void switch_variant(composite_huge_bg_state& state, int variant_index)
{
    BN_ASSERT(state.asset, "composite huge state has no asset");
    BN_ASSERT(variant_index >= 0 && variant_index < state.asset->variant_count,
              "composite huge variant out of range");
    state.variant_index = variant_index;
    state.initialized = false;
    state.previous_bg_x = 0;
    state.previous_bg_y = 0;
}

void update_all()
{
    for(composite_huge_bg* bg : detail::g_active_bgs) {
        if(bg) {
            bg->update();
        }
    }
}

}  // namespace ks::composite_huge_bg_runtime

namespace ks {

composite_huge_bg::composite_huge_bg(bn::regular_bg_ptr handle,
                                     bn::size map_dimensions,
                                     composite_huge_bg_state* state,
                                     bn::span<unsigned short>::iterator map_vram,
                                     bn::span<bn::tile>::iterator tiles_vram)
    : _wrapped_bg_ptr(bn::move(handle)),
      _map_dimensions(map_dimensions),
      _state(state),
      _map_vram(map_vram),
      _tiles_vram(tiles_vram)
{
    composite_huge_bg_runtime::register_bg(this);
    update();
}

void composite_huge_bg::_refresh_vram_iterators()
{
    if(! _state || ! _state->map || ! _state->vram_tiles) {
        return;
    }
    bn::optional<bn::span<unsigned short>> map_vram = _state->map->vram();
    bn::optional<bn::span<bn::tile>> tiles_vram = _state->vram_tiles->vram();
    if(map_vram) {
        _map_vram = map_vram->begin();
    }
    if(tiles_vram) {
        _tiles_vram = tiles_vram->begin();
    }
}

composite_huge_bg::composite_huge_bg(composite_huge_bg&& other) noexcept
    : _wrapped_bg_ptr(bn::move(other._wrapped_bg_ptr)),
      _map_dimensions(other._map_dimensions),
      _state(other._state),
      _map_vram(other._map_vram),
      _tiles_vram(other._tiles_vram)
{
    composite_huge_bg_runtime::unregister_bg(&other);
    other._state = nullptr;
    _refresh_vram_iterators();
    composite_huge_bg_runtime::register_bg(this);
    update();
}

composite_huge_bg& composite_huge_bg::operator=(composite_huge_bg&& other) noexcept
{
    if(this != &other) {
        composite_huge_bg_runtime::unregister_bg(this);
        _wrapped_bg_ptr = bn::move(other._wrapped_bg_ptr);
        _map_dimensions = other._map_dimensions;
        _state = other._state;
        _map_vram = other._map_vram;
        _tiles_vram = other._tiles_vram;
        composite_huge_bg_runtime::unregister_bg(&other);
        other._state = nullptr;
        _refresh_vram_iterators();
        composite_huge_bg_runtime::register_bg(this);
        update();
    }
    return *this;
}

composite_huge_bg::~composite_huge_bg()
{
    composite_huge_bg_runtime::unregister_bg(this);
}

bn::optional<composite_huge_bg> composite_huge_bg::create(
        bn::fixed x, bn::fixed y,
        const composite_huge_bg_item& item,
        composite_huge_bg_state& state)
{
    const composite_bg_asset& asset = item.asset();
    const int variant_index = item.variant_index();
    BN_ASSERT(asset.huge, "composite_huge_bg requires asset.huge");
    BN_ASSERT(variant_index >= 0 && variant_index < asset.variant_count,
              "composite huge variant out of range");

    state.asset = &asset;
    state.variant_index = variant_index;
    state.map.reset();
    state.vram_tiles.reset();
    state.initialized = false;
    state.previous_bg_x = 0;
    state.previous_bg_y = 0;

    const composite_variant& variant = asset.variants[variant_index];

    // Sliding window like classic huge_bg: only TILES_COUNT VRAM slots, not the
    // full variant tile palette (used_count unique tiles across the whole map).
    const int pool_tiles = TILES_COUNT;
    BN_ASSERT(variant.used_count > 0 && variant.used_count <= asset.max_vram_tiles,
              "composite huge used_count out of range: ", variant.used_count);

    bn::bg_blocks_manager::update();

    if(bn::bg_tiles::available_tiles_count() < pool_tiles) {
        return bn::nullopt;
    }

    bn::optional<bn::regular_bg_tiles_ptr> vram_tiles =
            bn::regular_bg_tiles_ptr::allocate_optional(pool_tiles, bn::bpp_mode::BPP_4);
    if(! vram_tiles) {
        return bn::nullopt;
    }
    state.vram_tiles = bn::move(*vram_tiles);
    composite_huge_bg_runtime::detail::stamp_transparent_tile(state);

    auto bg_map = bn::regular_bg_map_ptr::allocate(
            bn::size(32, 32), *state.vram_tiles,
            composite_huge_bg_runtime::detail::asset_palette(asset));
    auto bg = bn::regular_bg_ptr::create(bn::move(bg_map));
    state.map = bg.map();
    bg.set_position(x, y);
    bg.set_priority(3);
    bg.set_z_order(10);

    const bn::size map_dimensions(asset.map_w_px / 8, asset.map_h_px / 8);
    return composite_huge_bg(
            bn::move(bg),
            map_dimensions,
            &state,
            state.map->vram()->begin(),
            state.vram_tiles->vram()->begin());
}

bn::fixed_point composite_huge_bg::position() const
{
    return _wrapped_bg_ptr.position();
}

void composite_huge_bg::update()
{
    if(! _state || ! _state->asset || ! _state->map || ! _state->vram_tiles) {
        return;
    }

    _refresh_vram_iterators();
    bn::optional<bn::span<unsigned short>> map_vram = _state->map->vram();
    bn::optional<bn::span<bn::tile>> tiles_vram = _state->vram_tiles->vram();
    if(! map_vram || ! tiles_vram) {
        return;
    }

    const composite_bg_asset& asset = *_state->asset;
    const composite_variant& variant = asset.variants[_state->variant_index];
    const composite_tileset& ts = *asset.tileset;

    const bn::fixed_point top_left = _wrapped_bg_ptr.top_left_position();
    const int bg_x = (-top_left.x()).right_shift_integer();
    const int bg_y = (-top_left.y()).right_shift_integer();
    const int map_width = _map_dimensions.width();
    const int map_height = _map_dimensions.height();
    const int window_w = composite_huge_bg_state::map_window_w;

    const int x_tile = composite_huge_bg_runtime::detail::tile_offset_for_axis(
            bg_x, _state->previous_bg_x, _state->initialized);
    const int y_tile = composite_huge_bg_runtime::detail::tile_offset_for_axis(
            bg_y, _state->previous_bg_y, _state->initialized);

    _state->x_offset = (x_tile % (map_width * (WIDTH_BLOCKS + 1))
                        + map_width * (WIDTH_BLOCKS + 1)) % (map_width * (WIDTH_BLOCKS + 1));
    _state->y_offset = (y_tile % (map_height * (HEIGHT_BLOCKS + 1))
                        + map_height * (HEIGHT_BLOCKS + 1)) % (map_height * (HEIGHT_BLOCKS + 1));

    _state->previous_bg_x = bg_x;
    _state->previous_bg_y = bg_y;

    if(_state->x_offset != _state->previous_x_offset
       || _state->y_offset != _state->previous_y_offset
       || ! _state->initialized)
    {
        composite_huge_bg_runtime::detail::decode_map_window(*_state, variant);

        const unsigned short xdiff = bn::abs(_state->x_offset - _state->previous_x_offset);
        const unsigned short ydiff = bn::abs(_state->y_offset - _state->previous_y_offset);
        _state->previous_x_offset = _state->x_offset;
        _state->previous_y_offset = _state->y_offset;

        for(int yy = 0; yy < HEIGHT_BLOCKS + 1; ++yy) {
            for(int xx = 0; xx < WIDTH_BLOCKS + 1; ++xx) {
                const bool upload_tile = ! _state->initialized || xx < xdiff || yy < ydiff
                        || xx > WIDTH_BLOCKS - xdiff || yy > HEIGHT_BLOCKS - ydiff;

                const bn::regular_bg_map_cell source_cell =
                        _state->map_window[yy * window_w + xx];
                const int local = int(source_cell) & 0xFFF;

                const int vram_tile_x = (_state->x_offset + xx) % (WIDTH_BLOCKS + 1);
                const int vram_tile_y = (_state->y_offset + yy) % (HEIGHT_BLOCKS + 1);
                const int vram_tile_index =
                        (vram_tile_y * (WIDTH_BLOCKS + 1) + vram_tile_x) % TILES_COUNT;

                uint16_t new_map_cell = 0;
                if(local != 0) {
                    if(upload_tile) {
                        const uint16_t global = variant.used_tiles[local];
                        const int slab = global >> 10;
                        const int local_tile = int(global & 0x3FFu);
                        const bn::span<const bn::tile>& src =
                                composite_huge_bg_runtime::detail::slab_tiles(ts, slab);
                        BN_ASSERT(local_tile >= 0 && local_tile < src.size());
                        (*tiles_vram)[vram_tile_index] = src[local_tile];
                    }

                    uint16_t palette = (int(source_cell) >> 12) & 0xF;
                    palette = (palette + _wrapped_bg_ptr.palette().id()) & 0xF;
                    const int tiles_offset = _state->map->tiles_offset();
                    new_map_cell = uint16_t(
                            (palette << 12)
                            | ((vram_tile_index + tiles_offset) & 0x3FF));
                }

                const int vram_map_x = (_state->x_offset + xx) % 32;
                const int vram_map_y = (_state->y_offset + yy) % 32;
                const int vram_map_index = vram_map_y * 32 + vram_map_x;
                (*map_vram)[vram_map_index] = new_map_cell;
                asm __volatile("nop");
                asm __volatile("nop");
            }
        }

        _state->initialized = true;
    }
}

bn::optional<background_ptr> composite_huge_bg_item::create_background_ptr(
        const background_item& owner, bn::fixed x, bn::fixed y) const
{
    composite_huge_bg_state* state = composite_huge_bg_runtime::alloc_state();
    bn::optional<composite_huge_bg> huge =
            composite_huge_bg::create(x, y, *this, *state);
    if(! huge) {
        composite_huge_bg_runtime::free_state(state);
        return bn::nullopt;
    }
    return background_ptr(owner, bn::move(*huge), state);
}

}  // namespace ks
