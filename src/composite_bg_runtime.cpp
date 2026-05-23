#include "composite_bg_runtime.h"

#include "regular_composite_bg_item.h"
#include "ext_bg_blocks_manager.h"
#include "utils/scenario_reader.h"
#include "globals.h"

#include "bn_bg_palette_ptr.h"
#include "bn_compression_type.h"
#include "bn_log.h"
#include "bn_memory.h"
#include "bn_bg_maps.h"
#include "bn_bg_tiles.h"
#include "bn_regular_bg_tiles_item.h"
#include "bn_regular_bg_builder.h"
#include "bn_regular_bg_map_item.h"
#include "bn_size.h"
#include "bn_span.h"
#include "bn_tile.h"

namespace ks::composite_bg_runtime {

namespace {

constexpr int TILES_PER_SLAB = 1024;

void _log_create_failure(const char* step, int pool_tiles)
{
    BN_LOG("composite create_regular_bg FAIL [", step, "] pool=", pool_tiles,
           " ewram=", bn::memory::available_alloc_ewram(),
           " bg_tiles_free=", bn::bg_tiles::available_tiles_count(),
           " (", bn::bg_tiles::available_blocks_count(), " blocks)",
           " bg_tiles_used=", bn::bg_tiles::used_tiles_count(),
           " (", bn::bg_tiles::used_blocks_count(), " blocks)",
           " bg_maps_free=", bn::bg_maps::available_cells_count(),
           " (", bn::bg_maps::available_blocks_count(), " blocks)");
}

int _decompressed_ewram_bytes(const composite_tileset& ts)
{
    int bytes = 0;
    for(int slab = 0; slab < ts.slab_count; ++slab) {
        const bn::regular_bg_tiles_item& item = *ts.slabs[slab];
        if(item.compression() != bn::compression_type::NONE) {
            bytes += item.tiles_ref().size() * int(sizeof(bn::tile));
        }
    }
    return bytes;
}

constexpr int MAX_ACTIVE_STATES = 4;
composite_bg_state* g_active_states[MAX_ACTIVE_STATES] = {};

class rle_byte_reader
{
public:
    explicit rle_byte_reader(const unsigned char* compressed)
        : _p(compressed + 4)
    {
    }

    unsigned char next()
    {
        if(_run_remaining == 0) {
            _refill();
        }
        --_run_remaining;
        if(_run_compressed) {
            return _run_byte;
        }
        return *_p++;
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

private:
    rle_byte_reader _r;
};

struct _scoped_irq_disable
{
    uint16_t saved;
    _scoped_irq_disable()
    {
        auto ime = reinterpret_cast<volatile uint16_t*>(0x04000208);
        saved = *ime;
        *ime = 0;
    }
    ~_scoped_irq_disable()
    {
        *reinterpret_cast<volatile uint16_t*>(0x04000208) = saved;
    }
};

bn::bg_palette_ptr _asset_palette(const composite_bg_asset& asset)
{
    bn::optional<bn::bg_palette_ptr> found = bn::bg_palette_ptr::find(*asset.palette);
    if(found) {
        return *found;
    }
    return asset.palette->create_palette();
}

void _decompress_variant_map(composite_bg_state& state, const composite_variant& variant)
{
    const composite_bg_asset& asset = *state.asset;
    const int map_w_cells = asset.map_w_px / 8;
    const int map_h_cells = asset.map_h_px / 8;
    state.map_cells_count = map_w_cells * map_h_cells;

    rle_cell_reader rd(variant.map_compressed);
    for(int i = 0; i < state.map_cells_count; ++i) {
        state.cells[i] = rd.next();
    }
}

void _stamp_transparent_tile(composite_bg_state& state)
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

void _free_decompressed_slabs(composite_bg_state& state)
{
    for(int i = 0; i < composite_bg_state::max_decompressed_slabs; ++i) {
        if(state.decompressed_slabs_ewram[i]) {
            bn::memory::ewram_free(state.decompressed_slabs_ewram[i]);
            state.decompressed_slabs_ewram[i] = nullptr;
        }
        state.decompressed_slab_tile_count[i] = 0;
    }
    state.decompressed_tileset = nullptr;
}

bool _ensure_decompressed_tileset(composite_bg_state& state)
{
    const composite_bg_asset& asset = *state.asset;
    const composite_tileset& ts = *asset.tileset;

    if(state.decompressed_tileset == &ts) {
        return true;
    }

    _free_decompressed_slabs(state);
    BN_ASSERT(ts.slab_count <= composite_bg_state::max_decompressed_slabs,
              "composite tileset has ", ts.slab_count, " slabs; bump max_decompressed_slabs");

    for(int slab = 0; slab < ts.slab_count; ++slab) {
        const bn::regular_bg_tiles_item& item = *ts.slabs[slab];
        const int tile_count = item.tiles_ref().size();
        state.decompressed_slab_tile_count[slab] = tile_count;

        if(item.compression() == bn::compression_type::NONE) {
            state.decompressed_slabs_ewram[slab] = nullptr;
            continue;
        }

        const int bytes = tile_count * int(sizeof(bn::tile));
        void* mem = bn::memory::ewram_alloc(bytes);
        if(! mem) {
            _free_decompressed_slabs(state);
            return false;
        }

        bn::span<bn::tile> dst(static_cast<bn::tile*>(mem), tile_count);
        item.decompress(dst);
        state.decompressed_slabs_ewram[slab] = mem;
    }

    state.decompressed_tileset = &ts;
    return true;
}

bool _ensure_decompressed_with_textdb_fallback(composite_bg_state& state)
{
    const composite_tileset& ts = *state.asset->tileset;
    const int needed = _decompressed_ewram_bytes(ts);
    const bool release_textdb = ks::globals::ALWAYS_REDUCE_TEXTDB
            || (needed > 0 && bn::memory::available_alloc_ewram() < needed);

    if(release_textdb) {
        ks::textdb::request_release();
    }

    return _ensure_decompressed_tileset(state);
}

bn::span<const bn::tile> _slab_tiles(const composite_tileset& ts, int slab,
                                      const composite_bg_state& state)
{
    BN_ASSERT(slab >= 0 && slab < ts.slab_count);
    if(state.decompressed_slabs_ewram[slab]) {
        return bn::span<const bn::tile>(
                static_cast<const bn::tile*>(state.decompressed_slabs_ewram[slab]),
                state.decompressed_slab_tile_count[slab]);
    }
    return ts.slabs[slab]->tiles_ref();
}

void _do_copy_tiles(const composite_pending_tile_upload& snap, composite_bg_state& state)
{
    if(! snap.ready || ! snap.tileset || ! state.vram_tiles) {
        return;
    }

    bn::optional<bn::span<bn::tile>> vram_opt = state.vram_tiles->vram();
    if(! vram_opt) {
        return;
    }

    bn::span<bn::tile>& vram = *vram_opt;
    const composite_tileset& ts = *snap.tileset;
    const int count = snap.count;

    for(int i = 0; i < count; ++i) {
        const uint16_t global = snap.used_tiles[i];
        const int slab = global >> 10;
        const int local = int(global & 0x3FFu);
        BN_ASSERT(slab >= 0 && slab < ts.slab_count);
        const bn::span<const bn::tile>& src = _slab_tiles(ts, slab, state);
        BN_ASSERT(local >= 0 && local < src.size(), "composite tile index OOB: ", local,
                  " / ", src.size(), " slab ", slab);
        vram[i] = src[local];
    }

    state.tiles_copied_to_vram = true;
}

void _enqueue_tile_upload(composite_bg_state& state, const composite_variant& variant)
{
    const int count = variant.used_count;
    BN_ASSERT(count <= composite_pending_tile_upload::max_tiles,
              "composite variant uses ", count,
              " tiles; bump max_tiles");

    _scoped_irq_disable guard;

    state.upload.ready = 0;
    asm volatile("" ::: "memory");

    state.upload.tileset = state.asset->tileset;
    state.upload.count = count;
    for(int i = 0; i < count; ++i) {
        state.upload.used_tiles[i] = variant.used_tiles[i];
    }

    asm volatile("" ::: "memory");
    state.upload.ready = 1;
}

}  // namespace

void init()
{
    for(composite_bg_state*& state : g_active_states) {
        state = nullptr;
    }
}

composite_bg_state* alloc_state()
{
    void* mem = bn::memory::ewram_alloc(int(sizeof(composite_bg_state)));
    BN_ASSERT(mem, "ewram_alloc failed for composite_bg_state");
    return new(mem) composite_bg_state();
}

void free_state(composite_bg_state* state)
{
    if(! state) {
        return;
    }
    unregister_state(state);
    _free_decompressed_slabs(*state);
    state->~composite_bg_state();
    bn::memory::ewram_free(state);
}

void register_state(composite_bg_state* state)
{
    if(! state) {
        return;
    }
    for(composite_bg_state*& slot : g_active_states) {
        if(slot == nullptr) {
            slot = state;
            return;
        }
    }
    BN_ERROR("composite_bg_runtime: too many active composite backgrounds");
}

void unregister_state(composite_bg_state* state)
{
    if(! state) {
        return;
    }
    state->upload.ready = 0;
    for(composite_bg_state*& slot : g_active_states) {
        if(slot == state) {
            slot = nullptr;
            return;
        }
    }
}

void process_pending_uploads()
{
    for(composite_bg_state* state : g_active_states) {
        if(! state || ! state->upload.ready) {
            continue;
        }

        composite_pending_tile_upload snap = state->upload;
        state->upload.ready = 0;
        _do_copy_tiles(snap, *state);
    }
}

void release_decompressed_ewram_if_committed(composite_bg_state& state)
{
    if(! state.tiles_copied_to_vram || ! state.vram_tiles) {
        return;
    }

    if(bn::bg_blocks_manager::must_commit(state.vram_tiles->handle())) {
        return;
    }

    _free_decompressed_slabs(state);
    state.tiles_copied_to_vram = false;
}

void switch_variant(composite_bg_state& state, int variant_index)
{
    BN_ASSERT(state.asset, "composite state has no asset");
    BN_ASSERT(variant_index >= 0 && variant_index < state.asset->variant_count,
              "composite variant out of range: ", variant_index, " / ",
              state.asset->variant_count);
    if(state.variant_index == variant_index) {
        return;
    }

    state.variant_index = variant_index;
    const composite_variant& variant = state.asset->variants[variant_index];
    _decompress_variant_map(state, variant);
    if(state.map) {
        state.map->reload_cells_ref();
    }

    // Tile slabs may have been freed from EWRAM after the previous variant
    // was committed; re-decompress before queuing the V-Blank upload.
    BN_ASSERT(_ensure_decompressed_tileset(state),
              "switch_variant: failed to decompress composite tileset");
    _enqueue_tile_upload(state, variant);
    state.tiles_copied_to_vram = false;
}

bn::optional<bn::regular_bg_ptr> create_regular_bg(
        const regular_composite_bg_item& item, bn::fixed x, bn::fixed y,
        composite_bg_state& state)
{
    const composite_bg_asset& asset = item.asset();
    const int variant_index = item.variant_index();

    BN_ASSERT(variant_index >= 0 && variant_index < asset.variant_count,
              "composite variant out of range: ", variant_index, " / ", asset.variant_count);

    state.asset = &asset;
    state.variant_index = variant_index;
    state.map.reset();
    state.vram_tiles.reset();
    state.upload = composite_pending_tile_upload{};
    state.tiles_copied_to_vram = false;

    const composite_variant& variant = asset.variants[variant_index];
    _decompress_variant_map(state, variant);

    const int pool_tiles = variant.used_count;
    BN_ASSERT(pool_tiles > 0 && pool_tiles <= asset.max_vram_tiles,
              "variant used_count out of range: ", pool_tiles);

    if(! _ensure_decompressed_with_textdb_fallback(state)) {
        _log_create_failure("decompress", pool_tiles);
        return bn::nullopt;
    }

    // Flush pending frees. Do NOT call update_and_delay_commit() here —
    // allocate() fails while delay_commit is armed (_allocate_impl returns -1).
    bn::bg_blocks_manager::update();

    if(bn::bg_tiles::available_tiles_count() < pool_tiles) {
        _log_create_failure("available_tiles", pool_tiles);
        return bn::nullopt;
    }

    state.vram_tiles = bn::regular_bg_tiles_ptr::allocate_optional(pool_tiles, bn::bpp_mode::BPP_4);
    if(! state.vram_tiles) {
        _log_create_failure("allocate_optional", pool_tiles);
        return bn::nullopt;
    }
    _stamp_transparent_tile(state);

    const bn::size map_dimensions(asset.map_w_px / 8, asset.map_h_px / 8);
    const bn::regular_bg_map_item map_item(state.cells[0], map_dimensions);
    bn::bg_palette_ptr palette = _asset_palette(asset);

    bn::bg_blocks_manager::update_and_delay_commit();

    state.map = map_item.create_map(*state.vram_tiles, palette);
    _enqueue_tile_upload(state, variant);

    bn::regular_bg_builder builder(*state.map);
    builder.set_position(x, y);
    builder.set_priority(3);
    builder.set_z_order(10);
    return builder.build();
}

}  // namespace ks::composite_bg_runtime
