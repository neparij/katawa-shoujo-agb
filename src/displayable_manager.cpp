#include "displayable_manager.h"

#include "displayable_asset.h"
#include "bn_common.h"
#include "bn_bg_palette_items_pal_char_bg.h"
#include "bn_bg_palette_ptr.h"
#include "bn_bg_tiles.h"
#include "bn_regular_bg_builder.h"
#include "bn_regular_bg_map_cell.h"
#include "bn_regular_bg_map_item.h"
#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_tiles_ptr.h"
#include "bn_tile.h"
#include "globals.h"
#include "shaders/paletted_color_shader.h"
#include "smart_characters_manager.h"

namespace ks::displayable_manager {

namespace {

constexpr int SCREEN_W_PX = 240;
constexpr int SCREEN_H_PX = 160;
constexpr int MAP_W_CELLS = 32;
constexpr int MAP_H_CELLS = 32;
constexpr int MAP_CELL_COUNT = MAP_W_CELLS * MAP_H_CELLS;
constexpr int TILES_PER_VISUAL = 2;
constexpr int TILES_PER_SLAB = 1024;
/// Upper bound for per-frame unique tiles (snapshot in the V-Blank queue).
constexpr int MAX_UPLOAD_TILES = 256;

// ---------------------------------------------------------------------------
// BIOS RLE map reader (same format as smart_characters_manager).
// ---------------------------------------------------------------------------

class rle_byte_reader
{
public:
    explicit rle_byte_reader(const unsigned char* compressed)
        : _p(compressed + 4)  // skip BIOS header (0x30 | size_le24), same as smart_characters
    {
    }

    unsigned char next()
    {
        if(_run_remaining == 0) _refill();
        --_run_remaining;
        if(_run_compressed) return _run_byte;
        return *_p++;
    }

    void skip(int n)
    {
        while(n > 0)
        {
            if(_run_remaining == 0) _refill();
            const int take = _run_remaining < n ? _run_remaining : n;
            _run_remaining -= take;
            n -= take;
            if(! _run_compressed) _p += take;
        }
    }

private:
    void _refill()
    {
        const unsigned char flag = *_p++;
        if(flag & 0x80)
        {
            _run_compressed = true;
            _run_remaining = int(flag & 0x7F) + 3;
            _run_byte = *_p++;
        }
        else
        {
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

struct slot_state
{
    bool                              active = false;
    const displayable_meta*           meta = nullptr;
    palette_variant_t                 palette = PALETTE_VARIANT_DEFAULT;
    bn::fixed                         xpos = 0.5;
    bn::fixed                         xanchor = 0.5;
    bn::fixed                         ypos = 1.0;
    bn::fixed                         yanchor = 1.0;
    int                               frame_index = 0;
    bool                              animate = true;
    int                               anim_tick = 0;
    int                               bg_priority = 2;
    bn::optional<bn::regular_bg_ptr>  bg;
    bn::optional<bn::regular_bg_tiles_ptr> vram_tiles;
    bn::optional<bn::regular_bg_map_ptr>   map;
    alignas(int) bn::regular_bg_map_cell  cells[MAP_CELL_COUNT];
    bool                              dirty = false;
    bool                              tiles_dirty = false;
    bool                              backdrop_evicted = false;
};

// ---------------------------------------------------------------------------
// V-Blank deferred tile upload (one slot — single displayable).
//
// Tiles must not be written to VRAM while the *previous* frame's map is still
// on screen. commit() updates staging + reload_cells_ref(); butano commits the
// map at V-Blank; this queue uploads matching tile pixels in the same V-Blank,
// after the map commit (see smart_characters_manager::process_pending_uploads).
// ---------------------------------------------------------------------------

struct pending_tile_upload
{
    int                   ready = 0;
    const displayable_tileset* tileset = nullptr;
    int                   count = 0;
    uint16_t              used_tiles[MAX_UPLOAD_TILES];
};

struct _scoped_irq_disable
{
    uint16_t saved;
    _scoped_irq_disable()
    {
        auto ime = reinterpret_cast<volatile uint16_t*>(0x04000208);
        saved = *ime;
        *ime  = 0;
    }
    ~_scoped_irq_disable()
    {
        *reinterpret_cast<volatile uint16_t*>(0x04000208) = saved;
    }
};

BN_DATA_EWRAM_BSS pending_tile_upload g_pending_upload;

// Map staging must live in EWRAM — 2 KiB in IWRAM .bss broke the 32 KiB budget.
BN_DATA_EWRAM_BSS slot_state g_slot;
bool g_initialized = false;

int _resolve_x_px(const displayable_meta& meta,
                  bn::fixed xpos, bn::fixed xanchor)
{
    const bn::fixed centre =
        (xpos - bn::fixed(0.5)) * SCREEN_W_PX
        + (bn::fixed(0.5) - xanchor) * meta.render_w_px;
    const bn::fixed snapped = centre.division(8).round_integer() * 8;
    return snapped.right_shift_integer();
}

int _resolve_y_px(const displayable_meta& meta,
                  bn::fixed ypos, bn::fixed yanchor)
{
    const bn::fixed centre =
        (ypos - bn::fixed(0.5)) * SCREEN_H_PX
        + (bn::fixed(0.5) - yanchor) * meta.render_h_px;
    const bn::fixed snapped = centre.division(8).round_integer() * 8;
    return snapped.right_shift_integer();
}

void _apply_palette(bn::regular_bg_ptr& bg, palette_variant_t variant)
{
    if(variant == PALETTE_VARIANT_DEFAULT)
    {
        return;
    }
    bn::bg_palette_ptr pal = bg.palette();
    const auto& original = bn::bg_palette_items::pal_char_bg.colors_ref();
    int color_idx = 0;
    for(const bn::color& color : original)
    {
        pal.set_color(color_idx++, get_paletted_color(color, variant));
    }
}

void _stamp_transparent_tile()
{
    if(! g_slot.vram_tiles) return;
    bn::optional<bn::span<bn::tile>> vram_opt = g_slot.vram_tiles->vram();
    if(! vram_opt) return;
    bn::tile zero{};
    (*vram_opt)[0] = zero;
    (*vram_opt)[1] = zero;
}

void _decompress_frame_map(const displayable_frame& frame)
{
    rle_cell_reader rd(frame.map_compressed);
    for(int i = 0; i < MAP_CELL_COUNT; ++i)
    {
        g_slot.cells[i] = rd.next();
    }
}

void _do_copy_tiles(const pending_tile_upload& snap)
{
    if(! snap.ready || ! snap.tileset || ! g_slot.vram_tiles) return;

    bn::optional<bn::span<bn::tile>> vram_opt = g_slot.vram_tiles->vram();
    if(! vram_opt) return;
    bn::span<bn::tile>& vram = *vram_opt;

    const displayable_tileset& ts = *snap.tileset;
    const int count = snap.count;
    for(int i = 0; i < count; ++i)
    {
        const uint16_t global = snap.used_tiles[i];
        const int slab = global >> 10;
        const int local = int(global & 0x3FFu);
        BN_ASSERT(slab >= 0 && slab < ts.slab_count);
        const bn::span<const bn::tile>& rom = ts.slabs[slab]->tiles_ref();
        const int rom_off = local * TILES_PER_VISUAL;
        const int vram_off = i * TILES_PER_VISUAL;
        vram[vram_off + 0] = rom[rom_off + 0];
        vram[vram_off + 1] = rom[rom_off + 1];
    }
}

void _enqueue_tile_upload(const displayable_tileset& ts, const displayable_frame& frame)
{
    const int count = frame.used_count;
    BN_ASSERT(count <= MAX_UPLOAD_TILES,
              "displayable frame uses ", count,
              " tiles; bump MAX_UPLOAD_TILES");

    _scoped_irq_disable guard;

    g_pending_upload.ready = 0;
    asm volatile("" ::: "memory");

    g_pending_upload.tileset = &ts;
    g_pending_upload.count = count;
    for(int i = 0; i < count; ++i)
    {
        g_pending_upload.used_tiles[i] = frame.used_tiles[i];
    }

    asm volatile("" ::: "memory");
    g_pending_upload.ready = 1;
}

bn::bg_palette_ptr _shared_palette()
{
    bn::optional<bn::bg_palette_ptr> found =
        bn::bg_palette_ptr::find(bn::bg_palette_items::pal_char_bg);
    if(found)
    {
        return *found;
    }
    return bn::bg_palette_items::pal_char_bg.create_palette();
}

bool _ensure_vram_tiles(const displayable_asset& asset)
{
    if(g_slot.vram_tiles)
    {
        return true;
    }

    const int visual = asset.max_vram_tiles;
    const int bn_needed = visual * TILES_PER_VISUAL;
    if(bn::bg_tiles::available_tiles_count() < bn_needed)
    {
        BN_ERROR("displayable_manager: need ", bn_needed,
                 " bn::tile slots, have ", bn::bg_tiles::available_tiles_count());
        return false;
    }

    g_slot.vram_tiles = bn::regular_bg_tiles_ptr::allocate(bn_needed, bn::bpp_mode::BPP_8);
    _stamp_transparent_tile();
    return true;
}

void _commit_streaming()
{
    const displayable_meta& meta = *g_slot.meta;
    BN_ASSERT(meta.asset);
    const displayable_asset& asset = *meta.asset;
    const int map_index = g_slot.frame_index % meta.frame_count;
    const displayable_frame& frame = asset.frames[map_index];
    const int px = _resolve_x_px(meta, g_slot.xpos, g_slot.xanchor);
    const int py = _resolve_y_px(meta, g_slot.ypos, g_slot.yanchor);

    if(! _ensure_vram_tiles(asset))
    {
        g_slot.bg.reset();
        return;
    }

    _decompress_frame_map(frame);

    const bn::regular_bg_map_item map_item(
        g_slot.cells[0], bn::size(MAP_W_CELLS, MAP_H_CELLS));

    if(! g_slot.map)
    {
        g_slot.map = map_item.create_map(*g_slot.vram_tiles, _shared_palette());
    }
    else
    {
        g_slot.map->set_cells_ref(map_item);
        g_slot.map->reload_cells_ref();
    }

    if(g_slot.tiles_dirty)
    {
        _enqueue_tile_upload(*asset.tileset, frame);
        g_slot.tiles_dirty = false;
    }

    if(g_slot.bg)
    {
        g_slot.bg->set_position(bn::fixed(px), bn::fixed(py));
        _apply_palette(*g_slot.bg, g_slot.palette);
    }
    else
    {
        bn::regular_bg_builder builder(*g_slot.map);
        builder.set_position(bn::fixed(px), bn::fixed(py));
        builder.set_priority(g_slot.bg_priority);
        builder.set_z_order(5);
        g_slot.bg = builder.release_build();
        _apply_palette(*g_slot.bg, g_slot.palette);
    }
}

void _commit_legacy_item()
{
    const displayable_meta& meta = *g_slot.meta;
    BN_ASSERT(meta.item);
    const bn::regular_bg_item& item = *meta.item;
    const int map_index = g_slot.frame_index % meta.frame_count;
    const int px = _resolve_x_px(meta, g_slot.xpos, g_slot.xanchor);
    const int py = _resolve_y_px(meta, g_slot.ypos, g_slot.yanchor);

    if(g_slot.bg)
    {
        g_slot.bg->set_position(bn::fixed(px), bn::fixed(py));
        g_slot.bg->set_map(item.map_item(), map_index);
        _apply_palette(*g_slot.bg, g_slot.palette);
    }
    else
    {
        g_slot.bg = item.create_bg(px, py, map_index);
        g_slot.bg->set_priority(g_slot.bg_priority);
        g_slot.bg->set_z_order(5);
        _apply_palette(*g_slot.bg, g_slot.palette);
    }
}

void _release_streaming_vram()
{
    g_slot.bg.reset();
    g_slot.map.reset();
    g_slot.vram_tiles.reset();
}

}  // namespace

int reserved_bg_count()
{
    return g_slot.active && g_slot.bg.has_value() ? 1 : 0;
}

int smart_characters_bg_budget()
{
    return smart_characters_manager::MAX_BGS - reserved_bg_count();
}

void init()
{
    g_initialized = true;
    destroy_all();
}

void destroy_all()
{
    _release_streaming_vram();
    g_slot = slot_state{};
    g_pending_upload = pending_tile_upload{};
}

void show(const displayable_meta& meta, palette_variant_t palette_variant,
          bn::fixed xpos, bn::fixed xanchor, bn::fixed ypos, bn::fixed yanchor,
          int frame_index, bool animate, int bg_priority)
{
    g_slot.active = true;
    g_slot.meta = &meta;
    g_slot.palette = palette_variant;
    g_slot.xpos = xpos;
    g_slot.xanchor = xanchor;
    g_slot.ypos = ypos;
    g_slot.yanchor = yanchor;
    g_slot.frame_index = frame_index;
    g_slot.animate = animate;
    g_slot.anim_tick = 0;
    g_slot.bg_priority = bg_priority;
    g_slot.dirty = true;
    g_slot.tiles_dirty = true;

    if(meta.seen_bitmask != DISPLAYABLE_BITMASK_NONE && globals::in_game)
    {
        globals::states.set_seen_displayable(meta.seen_bitmask, true);
    }
}

void hide()
{
    g_slot.dirty = true;
    g_slot.active = false;
}

void tick()
{
    if(! g_slot.active || ! g_slot.meta)
    {
        return;
    }
    if(! g_slot.animate)
    {
        return;
    }
    const displayable_meta& meta = *g_slot.meta;
    if(meta.frame_count <= 1 || meta.ticks_per_frame <= 0)
    {
        return;
    }
    ++g_slot.anim_tick;
    if(g_slot.anim_tick < meta.ticks_per_frame)
    {
        return;
    }
    g_slot.anim_tick = 0;
    const int next = (g_slot.frame_index + 1) % meta.frame_count;
    if(next != g_slot.frame_index)
    {
        g_slot.frame_index = next;
        g_slot.dirty = true;
        g_slot.tiles_dirty = true;
    }
}

void commit()
{
    if(! g_initialized)
    {
        return;
    }

    smart_characters_manager::set_physical_bg_budget(smart_characters_bg_budget());

    if(g_slot.backdrop_evicted)
    {
        return;
    }

    if(! g_slot.dirty)
    {
        return;
    }
    g_slot.dirty = false;

    if(! g_slot.active || ! g_slot.meta)
    {
        _release_streaming_vram();
        return;
    }

    const displayable_meta& meta = *g_slot.meta;
    BN_ASSERT(meta.frame_count > 0);

    if(meta.asset)
    {
        _commit_streaming();
    }
    else if(meta.item)
    {
        _commit_legacy_item();
    }
    else
    {
        BN_ERROR("displayable_manager: meta has neither asset nor item");
        _release_streaming_vram();
    }
}

void process_pending_tile_uploads()
{
    if(! g_pending_upload.ready) return;

    pending_tile_upload snap = g_pending_upload;
    g_pending_upload.ready = 0;
    _do_copy_tiles(snap);
}

void evict_vram()
{
    _release_streaming_vram();
    g_slot.backdrop_evicted = true;
    g_slot.dirty = false;
}

void restore_after_backdrop()
{
    g_slot.backdrop_evicted = false;
    if(g_slot.active)
    {
        g_slot.dirty = true;
        g_slot.tiles_dirty = true;
    }
}

bool is_active()
{
    return g_slot.active;
}

}  // namespace ks::displayable_manager
