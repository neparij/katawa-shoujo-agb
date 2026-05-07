// Implementation of ks::smart_characters_manager — see header for an
// overview of the auto-packing scheme and constraints.
//
// Hybrid BG + OBJ layout
// ======================
// Each on-screen character is composed of two converter-emitted assets:
//
//   * A *body*: a regular BG bitmap stamped with a transparent rectangle
//     where the face goes. One body is shared by every emotion in a
//     (pose × outfit × close) group.
//   * A *face* OBJ sprite: per-emotion artwork that fills the body's
//     transparent face hole. Lives in OBJ VRAM, not the BG tile pool.
//
// The manager hosts the body in a packed shared BG (with overlap-avoidance
// by `body::vis_*`), and tracks one `bn::sprite_ptr` per character for
// the active emotion. Same-group emotion swaps are O(1): only the sprite
// item is replaced — the body is untouched, no tile re-upload, no map
// rewrite, no repack.
//
// VRAM strategy (BG side)
// =======================
// All bodies share a *single, fixed-size* BG tile pool, allocated once
// in `init()`. Per-BG `regular_bg_map_ptr`s reference this shared pool,
// so BG tile VRAM is never reallocated at runtime — adding / changing /
// removing characters just rewrites map cells and re-uploads body tile
// data into the shared pool. This eliminates the BG-block fragmentation
// that would otherwise hit us when multiple BGs are created/resized in
// quick succession (Butano can only reclaim a `to_remove` allocation on
// the next V-Blank, *after* our rebuild loop has already failed to find
// contiguous free space).
//
// Memory layout
// -------------
// Per character: a contiguous segment in the shared pool, sized to the
// body's working set. `_global_layout` packs alive characters in slot
// order; offsets shift only when an upstream char is added / removed /
// gets a different body (group switch), in which case the affected chars
// are queued for V-Blank re-upload. Map cells in every hosting BG embed
// `seg_off + local_id`, where `local_id` is taken from the body map.
//
// Limits
// ------
//   - shared tile pool ≤ 1024 (10-bit map cell tile index).
//   - MAX_BGS  : at most 4 active BGs (only the maps consume per-BG VRAM).
//   - MAX_CHARS: pool size; can be tuned in the public header.

#include "smart_characters_manager.h"

#include <cstdint>
#include <cstring>

#include "bn_array.h"
#include "bn_assert.h"
#include "bn_bg_palette_item.h"
#include "bn_bg_palette_ptr.h"
#include "bn_core.h"
#include "bn_display.h"
#include "bn_log.h"
#include "bn_memory.h"
#include "bn_optional.h"
#include "bn_regular_bg_builder.h"
#include "bn_regular_bg_item.h"
#include "bn_regular_bg_map_cell.h"
#include "bn_regular_bg_map_item.h"
#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_tiles_item.h"
#include "bn_regular_bg_tiles_ptr.h"
#include "bn_bg_maps.h"
#include "bn_bg_tiles.h"
#include "bn_size.h"
#include "bn_span.h"
#include "bn_sprite_builder.h"
#include "bn_sprite_item.h"
#include "bn_sprite_palette_item.h"
#include "bn_sprite_palette_ptr.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_shape_size.h"
#include "bn_sprite_tiles_item.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_tile.h"

#include "bn_sprite_palette_items_pal_char_obj.h"

#include "shaders/paletted_color_shader.h"

namespace ks::smart_characters_manager {

namespace {

// ---------------------------------------------------------------------------
// Constants
// ---------------------------------------------------------------------------

constexpr int MAP_W_CELLS = 32;
constexpr int MAP_H_CELLS = 32;
constexpr int CELL_PX     = 8;
constexpr int BG_W_PX     = MAP_W_CELLS * CELL_PX;   // 256
constexpr int BG_H_PX     = MAP_H_CELLS * CELL_PX;   // 256
constexpr int TILES_PER_VISUAL = 2;  // 8bpp uses 2 bn::tile per visual tile

/// Maximum size of the shared BG tile pool in 8bpp visual tiles. Each character
/// only consumes its *visible* body tiles (the unique tile set referenced
/// by the on-screen portion of its body — see `_compute_char_trim`), not
/// the full body, so this can stay well under the worst-case sum of
/// `body::used_count` over all alive characters: tiles for body cells
/// outside the BG canvas (a character placed near the screen edges) and
/// for cells beyond the on-screen visibility window (the canvas is
/// 256 px while the screen is only 240 × 160 px) are never uploaded.
///
/// 8bpp visual tiles → each tile = 64 B → 32 tiles per 2 KB BG VRAM block.
/// 480 visual tiles = 960 `bn::tile` structs = 15 blocks (30 KB). That
/// leaves 17 blocks (34 KB) for: up to MAX_BGS (3) map blocks (6 KB) and
/// any backdrop BG (e.g. school_scienceroom uses ~10 blocks at 4bpp +
/// 1 map block). Capped at 1024 (the 10-bit map cell tile index).
// constexpr int SHARED_TILES_CAPACITY = 480;
// constexpr int SHARED_TILES_CAPACITY = 512;
constexpr int SHARED_TILES_CAPACITY_MAX = 18 * 32; // 576 8bpp tiles, 18 blocks.

/// Worst-case body tile-set size we plan for. Used to size per-char
/// scratch arrays (compact remap, visible tile list). The largest body
/// emitted by the converter today is `nomiya` at 272 tiles.
constexpr int MAX_BODY_TILES_PER_CHAR = 384;

/// Maximum number of unique body tiles that can be visible for one
/// character at once. Bounded by the visible-cell count of a 30×21
/// on-screen window (= 630 cells); 384 covers every realistic case
/// since most cells repeat tiles via dedup.
constexpr int MAX_VISIBLE_TILES_PER_CHAR = MAX_BODY_TILES_PER_CHAR;

// ---------------------------------------------------------------------------
// Math helpers
// ---------------------------------------------------------------------------

inline int _imin(int a, int b) { return a < b ? a : b; }
inline int _imax(int a, int b) { return a > b ? a : b; }

inline int _floor_div(int a, int b)
{
    int q = a / b;
    int r = a % b;
    if(r != 0 && ((r < 0) != (b < 0))) --q;
    return q;
}

inline int _ceil_div(int a, int b)
{
    int q = a / b;
    int r = a % b;
    if(r != 0 && ((r < 0) == (b < 0))) ++q;
    return q;
}

inline int _floor_mod(int a, int m)
{
    int r = a % m;
    return r < 0 ? r + m : r;
}

inline bool _bbox_overlap(int ax0, int ax1, int ay0, int ay1,
                          int bx0, int bx1, int by0, int by1)
{
    return !(ax1 <= bx0 || bx1 <= ax0 || ay1 <= by0 || by1 <= ay0);
}

// ---------------------------------------------------------------------------
// Per-BG EWRAM staging slot (only the cell map; tile data lives in the
// global shared pool and never needs CPU-side staging).
// ---------------------------------------------------------------------------

struct bg_staging
{
    alignas(int) bn::regular_bg_map_cell cells[MAP_W_CELLS * MAP_H_CELLS];
};

BN_DATA_EWRAM_BSS bg_staging g_bg_staging[MAX_BGS];

// ---------------------------------------------------------------------------
// Logical character.
// ---------------------------------------------------------------------------

struct char_state
{
    bool                              alive       = false;
    /// Stable Ren'Py-derived tag (e.g. `CHARACTER_KENJI`). Used by the
    /// `character_t`-based public API to map a high-level handle back to
    /// the internal `g_chars[]` slot. `CHARACTER_NONE` while the slot
    /// is dead or untagged (the legacy `id_t`-only `create` path leaves
    /// it at `CHARACTER_NONE`).
    character_t                       character   = CHARACTER_NONE;
    const smart_characters::variant*  var         = nullptr;
    bn::fixed                         x           = 0;
    bn::fixed                         y           = 0;
    int                               x_int       = 0;
    int                               y_int       = 0;
    int                               bg_idx      = -1;   // -1 = unhosted

    /// Offset of this character's *body* working set inside the shared
    /// tile pool (in 8bpp visual tiles). Reassigned by `_global_layout`
    /// whenever the alive-char pack changes shape. Different emotions of
    /// the same group share a body, so the offset is keyed on the body
    /// (group), not the variant.
    int                               tile_off    = 0;

    /// "Body tile data needs to be re-uploaded into the shared pool at
    /// the next V-Blank". Set when the character's *body* changes (group
    /// switch) or its `tile_off` shifts; cleared by `commit()` once the
    /// upload is queued. Same-group emotion swaps don't set this — the
    /// body bytes don't change, only the face sprite item does.
    bool                              tiles_dirty = false;

    /// Face emotion sprite (one OBJ per character). Created on attach,
    /// re-created on body (group) change, hidden when the char is
    /// homeless (no host BG), dropped on destroy.
    bn::optional<bn::sprite_ptr>      face;

    /// The variant whose face data is currently realised in `face`.
    /// `_sync_face_sprites` compares this with `var` and refreshes the
    /// sprite (set_tiles or full reset+create when the face shape
    /// differs across groups). Critically, we do *not* touch `face`
    /// from `set_variant` itself — body change and face refresh are
    /// otherwise non-atomic across `commit()` and the user briefly
    /// sees the old body with no face / new body before the face
    /// catches up.
    const smart_characters::variant*  face_var_applied = nullptr;

    /// BG priority (0..3, lower = closer to viewer). Two characters can
    /// only share a host BG if their priorities match — otherwise the
    /// BG can't pick a single hardware priority for both. Set at create
    /// time and persists across emotion / position changes; a runtime
    /// priority change goes through `set_priority(id, p)`.
    int                               priority    = 0;

    /// Whether this character is currently in a blending fade
    /// (alpha in/out via the global `bn::blending::set_transparency_alpha`
    /// register). Two characters with different `blending_enabled` cannot
    /// share a host BG — see `bg_slot::blending_enabled`. Toggled by
    /// `set_blending_enabled(character_t, bool)`, which detaches and
    /// re-packs the character to honour the bucket key change.
    bool                              blending_enabled = false;

    /// Number of unique body local tile indices the visible part of
    /// this character actually references. The list itself
    /// (`g_char_trim[idx].visible_tiles`) and the inverse map
    /// (`g_char_trim[idx].compact_remap`) live in EWRAM (see
    /// `char_trim_buffers`) so this IWRAM-resident state stays small.
    /// Recomputed by `_compute_char_trim` on every commit; a change in
    /// the trimmed set raises `tiles_dirty` so the next V-Blank
    /// re-uploads the visible tile data into the shared pool.
    int       visible_tile_count = 0;

    /// Smooth-move animation state. While `anim_frames_left > 0`, each
    /// `tick()` linearly interpolates the integer pixel position from
    /// the current `(x_int, y_int)` toward `(anim_target_x, anim_target_y)`.
    /// Sub-cell sub-pixel precision is dropped on `set_position` anyway,
    /// so we just store whole-pixel targets.
    int       anim_target_x      = 0;
    int       anim_target_y      = 0;
    int       anim_frames_left   = 0;
};

/// EWRAM-resident scratch / cache buffers per character — kept out of
/// IWRAM (where `g_chars` lives) because at MAX_CHARS = 6 these arrays
/// would otherwise blow the 32 KB IWRAM budget.
struct char_trim_buffers
{
    /// Body local tile indices, in compact-id order (i.e. the order the
    /// shared-pool VRAM segment for this char is laid out in). Only
    /// entries 0..`visible_tile_count` are valid.
    uint16_t visible_tiles[MAX_VISIBLE_TILES_PER_CHAR];

    /// Reverse map: `compact_remap[body_local] = compact_id` for visible
    /// tiles, 0xFFFF for non-visible ones. Used by `_refresh_bg_cells`
    /// to translate body map cell tile ids into shared-pool tile ids.
    uint16_t compact_remap[MAX_BODY_TILES_PER_CHAR];
};

// ---------------------------------------------------------------------------
// Physical BG hosting one or more characters.
// ---------------------------------------------------------------------------

struct bg_slot
{
    bool                              active       = false;
    bool                              dirty        = false;

    // The BG always sits screen-centered at the *bucket* position, i.e.
    // a fixed sub-cell shift in the 0..7 px range (= the `% 8` residue
    // of every hosted character's integer pixel position). That makes
    // the BG canvas a screen-fixed 32×32 cell window stretching from
    // ~(-128, -128) to (+128, +128) regardless of where the characters
    // happen to live. Two characters can share this BG iff their
    // `(x_int mod 8, y_int mod 8)` match the bucket and their body
    // bboxes don't overlap inside the canvas.
    //
    // Compared to the previous "anchor = first char" model, this gives
    // strictly better packing: a character placed far to one side no
    // longer drags the canvas off-screen and shrinks the room available
    // for everybody else. The downside is that intra-cell smoothness
    // can only be obtained by stepping the bucket itself (i.e. moving
    // the entire BG and every character in it together).
    int                               bucket_x     = 0;   // 0..7 px
    int                               bucket_y     = 0;   // 0..7 px

    /// All chars hosted by a BG share its hardware priority. Set when
    /// the first char is attached; subsequent chars must match.
    int                               priority     = DEFAULT_BG_PRIORITY;

    /// All chars hosted by a BG also share its blending-enabled state.
    /// Two characters with different `blending_enabled` cannot live on
    /// the same hardware BG (the GBA blending registers operate per-BG,
    /// not per-cell), so the packer treats it as another bucket key
    /// alongside priority and the (mod 8) sub-cell offset. Set when the
    /// first char is attached; subsequent chars must match. Flipped
    /// per-BG by `_apply_blending_to_bg` after a commit.
    bool                              blending_enabled = false;

    bn::fixed                         pos_x        = 0;   // = bucket_x
    bn::fixed                         pos_y        = 0;   // = bucket_y

    int                               char_count   = 0;
    bn::array<int, MAX_CHARS>         char_indices;
    bn::array<int, MAX_CHARS>         char_dx_cells;   // = floor_div(x_int, 8)
    bn::array<int, MAX_CHARS>         char_dy_cells;

    int                               staging_slot = -1;

    // Cached visible cell window for `_refresh_visible_window`.
    int                               cached_first_col = -1;
    int                               cached_last_col  = -1;
    int                               cached_first_row = -1;
    int                               cached_last_row  = -1;

    bn::optional<bn::regular_bg_map_ptr> map;
    bn::optional<bn::regular_bg_ptr>     bg;
};

// ---------------------------------------------------------------------------
// Globals
// ---------------------------------------------------------------------------

bool                                 g_initialized = false;
bn::array<char_state, MAX_CHARS>     g_chars;
bn::array<bg_slot,    MAX_BGS>       g_bgs;

BN_DATA_EWRAM_BSS char_trim_buffers  g_char_trim[MAX_CHARS];

bn::optional<bn::regular_bg_tiles_ptr> g_shared_tiles;
bn::optional<bn::bg_palette_ptr>       g_shared_palette;

/// True once `_ensure_global_transparent` has stamped pool slot 0 with
/// an all-zeros (transparent) tile. Reset by `init()`.
bool                                   g_transparent_ready = false;

/// Current shared pool size in 8bpp visual tiles. Chosen at allocation time
/// based on available BG VRAM blocks (leaving room for character maps).
int                                    g_shared_capacity_visual_tiles = 0;

/// Sticky scene-wide palette variant. Applied to the shared body palette
/// in VRAM and to every face sprite's OBJ palette. New characters /
/// re-created face sprites pick this up automatically.
palette_variant_t                      g_palette_variant   = PALETTE_VARIANT_DEFAULT;

inline int _face_bg_priority_from_bg_priority(int bg_priority)
{
    // Face sprite must always be behind its body BG in hardware priority:
    // bg prio P, face sprite prio P+1.
    // The project scene setup keeps character BG priorities in 0..2.
    BN_ASSERT(bg_priority >= 0 && bg_priority <= 2,
              "face bg priority requires character BG priority in [0..2], got ",
              bg_priority);
    return bg_priority + 1;
}

// Re-stamp the shared body palette (VRAM) with the colours from
// `pal_item` recoloured through `g_palette_variant`. No-op if the variant
// is `DEFAULT` and the palette was never recoloured.
void _apply_palette_variant_to_shared_bg(const bn::bg_palette_item* pal_item)
{
    if(! g_shared_palette || ! pal_item) return;
    bn::span<const bn::color> colours = pal_item->colors_ref();
    if(g_palette_variant == PALETTE_VARIANT_DEFAULT)
    {
        // Restore originals.
        int i = 0;
        for(const bn::color& c : colours) g_shared_palette->set_color(i++, c);
        return;
    }
    int i = 0;
    for(const bn::color& c : colours)
    {
        g_shared_palette->set_color(i++,
                                    get_paletted_color(c, g_palette_variant));
    }
}

// Every face sprite shares one OBJ palette (`pal_char_obj`, palette-typed
// clone of `pal_char_bg`). Butano deduplicates `bn::sprite_palette_ptr`
// instances by underlying item, so all faces created with the same item
// resolve to the same VRAM palette slot — recolouring it once via this
// helper updates every face sprite in the scene atomically. Cheaper
// than the previous per-face palette and avoids per-face palette VRAM
// fragmentation.
void _apply_palette_variant_to_faces()
{
    auto pal_opt = bn::sprite_palette_ptr::find(
        bn::sprite_palette_items::pal_char_obj);
    if(! pal_opt) return;
    bn::sprite_palette_ptr pal = *pal_opt;
    bn::span<const bn::color> colours =
        bn::sprite_palette_items::pal_char_obj.colors_ref();
    if(g_palette_variant == PALETTE_VARIANT_DEFAULT)
    {
        int i = 0;
        for(const bn::color& c : colours) pal.set_color(i++, c);
        return;
    }
    int i = 0;
    for(const bn::color& c : colours)
    {
        pal.set_color(i++, get_paletted_color(c, g_palette_variant));
    }
}

// ---------------------------------------------------------------------------
// V-Blank deferred tile upload queue (per character).
//
// One slot per logical character — when the character's working-set
// content or position in the shared pool changes, `commit()` enqueues it
// here; the V-Blank handler drains the queue and copies the variant
// tiles from ROM slabs into `g_shared_tiles` VRAM.
//
// Race-free design: every slot is a *self-contained snapshot* of the
// state needed to produce the upload (body pointer, tile_off, count,
// visible-tile indices). The snapshot is taken at `_enqueue_char_upload`
// time — the same `commit()` pass that writes the matching map cells to
// `stg.cells`. This guarantees the V-Blank that drains the queue uploads
// tile data consistent with the map cells butano commits at the *same*
// V-Blank, even if user code mutates `ch.var` between this commit() and
// the next V-Blank (e.g. a back-to-back `set_variant` swapping pose
// groups across two `update_visuals` calls without an intervening
// frame). Without the snapshot, the V-Blank handler would read the
// freshly-mutated `ch.var` against the *previous* commit's stale
// `g_char_trim`, producing garbage tile uploads while butano commits
// the previous map — the classic "map references tile X, tile X is
// garbage" desync.
//
// `visible[]` is dimensioned at MAX_VISIBLE_TILES_PER_CHAR (=384) so
// each slot is ~784 bytes; the queue lives in EWRAM_BSS.
// ---------------------------------------------------------------------------

struct pending_upload
{
    /// `-1` when the slot is empty / consumed. Written *last* in the
    /// snapshot publish sequence so the V-Blank IRQ — which reads this
    /// field first — can never observe a half-written snapshot:
    /// either it sees `-1` (skip) or a fully-published one.
    int                                   char_idx = -1;
    const smart_characters::body*         body     = nullptr;
    int                                   tile_off = 0;
    int                                   count    = 0;
    uint16_t                              visible[MAX_VISIBLE_TILES_PER_CHAR];
};

BN_DATA_EWRAM_BSS pending_upload g_pending[MAX_CHARS];

void _do_copy_char(const pending_upload& snap);

void process_pending_uploads()
{
    for(pending_upload& p : g_pending)
    {
        if(p.char_idx < 0) continue;
        _do_copy_char(p);
        p.char_idx = -1;
    }
}

// Brief IRQ-disable guard via REG_IME. Used around the snapshot publish
// in `_enqueue_char_upload` so the V-Blank handler can't observe the
// queue mid-rewrite (we reuse a slot when the same char is re-queued
// before its previous snapshot drained — this is the multi-commit-per-
// frame case). The guarded section copies at most ~784 bytes; well
// inside any frame budget so we never miss a V-Blank.
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

void _enqueue_char_upload(int char_idx)
{
    const char_state&         ch = g_chars[char_idx];
    const char_trim_buffers&  tb = g_char_trim[char_idx];

    pending_upload* slot = nullptr;
    for(pending_upload& p : g_pending)
        if(p.char_idx == char_idx) { slot = &p; break; }
    if(! slot)
    {
        for(pending_upload& p : g_pending)
            if(p.char_idx < 0) { slot = &p; break; }
    }
    if(! slot)
    {
        BN_ERROR("smart_characters_manager: V-Blank upload queue full");
        return;
    }

    // Atomic snapshot publish. The IRQ guard prevents the V-Blank
    // handler from draining a half-rewritten slot when this same char
    // is enqueued twice in one frame (multi-commit before a V-Blank).
    _scoped_irq_disable guard;

    slot->char_idx = -1;
    asm volatile("" ::: "memory");

    slot->body     = ch.var->body;
    slot->tile_off = ch.tile_off;
    slot->count    = ch.visible_tile_count;
    const int n    = slot->count;
    for(int i = 0; i < n; ++i)
        slot->visible[i] = tb.visible_tiles[i];

    asm volatile("" ::: "memory");
    slot->char_idx = char_idx;
}

void _cancel_char_upload(int char_idx)
{
    for(pending_upload& p : g_pending)
        if(p.char_idx == char_idx) p.char_idx = -1;
}

inline void _mark_dirty(bg_slot& bg) { bg.dirty = true; }

// ---------------------------------------------------------------------------
// Body tile copy: ROM slabs → shared-pool VRAM at `ch.tile_off`.
//
// Only body tiles are managed here. Face emotion tiles are OBJ sprites,
// allocated and uploaded by Butano via `bn::sprite_ptr` and live in OBJ
// VRAM, not the shared BG pool.
//
// Per-character trim: only the tiles referenced by the on-screen visible
// portion of the body are uploaded — `ch.visible_tiles[i]` (i = compact
// index in [0, ch.visible_tile_count)) names the body local tile index
// that goes to VRAM at `tile_off + i`. Cells outside the visible window
// or off the BG canvas don't contribute, so a body whose bbox spills off
// the screen edge consumes far fewer slots than its full
// `body::used_count`.
// ---------------------------------------------------------------------------

// One-time stamp of the global transparent tile into pool slot 0. Every
// "transparent" cell in every BG (including the `memset(0)` background
// behind characters and the per-body transparent cells whose local id is
// 0) points here, so this slot must contain an all-zero tile. Re-stamped
// every time `g_shared_tiles` is (re-)allocated — the manager releases
// shared VRAM whenever no character is alive (so backdrops can claim
// those palette / tile slots) and rebuilds it on the next `show`.
void _ensure_global_transparent()
{
    if(g_transparent_ready || ! g_shared_tiles) return;
    bn::optional<bn::span<bn::tile>> vram_opt = g_shared_tiles->vram();
    if(! vram_opt) return;
    bn::span<bn::tile>& vram = *vram_opt;
    // 8bpp visual tile occupies 2 `bn::tile` slots (= 64 bytes).
    bn::tile zero{};
    vram[0] = zero;
    vram[1] = zero;
    g_transparent_ready = true;
}

// True iff at least one character slot is in use. Drives lazy
// alloc/release of the shared BG palette + shared tile pool.
bool _any_char_alive()
{
    for(int i = 0; i < MAX_CHARS; ++i)
        if(g_chars[i].alive) return true;
    return false;
}

// Allocate the shared BG tile pool + the shared 8bpp body palette if
// they aren't live yet. Called every commit while at least one character
// is alive — once the manager has shed every character (between scenes,
// while a transition runs over a black screen, etc.) `_release_shared_
// resources` drops both, so the next 4bpp backdrop is free to claim
// the freshly-released palette / tile blocks.
void _ensure_shared_resources()
{
    if(! g_shared_tiles)
    {
        // The BG blocks manager is shared by tiles and maps. Creating up to
        // `MAX_BGS` character BGs later will require up to `MAX_BGS` 32×32
        // maps (1 block each). If we consume all free blocks for the shared
        // tile pool here, we can succeed now but crash later when maps are
        // created.
        //
        // Allocate as many tiles as possible while reserving map blocks.
        constexpr int BN_TILES_PER_BLOCK = 64; // 2KB / 32 bytes
        const int free_blocks_now = bn::bg_tiles::available_blocks_count();
        const int reserve_map_blocks = MAX_BGS;
        const int blocks_for_tiles = bn::max(0, free_blocks_now - reserve_map_blocks);

        const int max_bn_tiles_from_blocks = blocks_for_tiles * BN_TILES_PER_BLOCK;
        const int max_visual_tiles_from_blocks = max_bn_tiles_from_blocks / TILES_PER_VISUAL;
        const int visual_tiles_to_allocate =
            bn::min(SHARED_TILES_CAPACITY_MAX, max_visual_tiles_from_blocks);

        BN_LOG("free_blocks_now: ", free_blocks_now);
        BN_LOG("visual_tiles_to_allocate: ", visual_tiles_to_allocate);
        g_shared_capacity_visual_tiles = visual_tiles_to_allocate;
        g_shared_tiles = bn::regular_bg_tiles_ptr::allocate(
            g_shared_capacity_visual_tiles * TILES_PER_VISUAL, bn::bpp_mode::BPP_8);
        g_transparent_ready = false;
    }
    _ensure_global_transparent();

    if(! g_shared_palette)
    {
        for(int i = 0; i < MAX_CHARS; ++i)
        {
            if(g_chars[i].alive && g_chars[i].var)
            {
                const bn::bg_palette_item* pal_item =
                    g_chars[i].var->body->tileset->palette;
                g_shared_palette = pal_item->create_palette();
                // If the scene chose a non-default palette variant
                // before any character existed (or while we were
                // unloaded), apply it now that the live palette is
                // back in VRAM.
                if(g_palette_variant != PALETTE_VARIANT_DEFAULT)
                {
                    _apply_palette_variant_to_shared_bg(pal_item);
                }
                break;
            }
        }
    }
}

// Drop the shared palette + tile pool. Safe only when no character (and
// therefore no BG slot built on top of these handles) is alive — every
// caller checks `_any_char_alive` first. The `g_palette_variant` value
// is sticky on purpose: if the scene flagged "night" while characters
// were off-screen, the next `show` should re-tint the freshly-created
// palette without the writer having to re-issue `set_palette_variant`.
void _release_shared_resources()
{
    if(_any_char_alive()) return;
    g_shared_palette.reset();
    g_shared_tiles.reset();
    g_transparent_ready = false;
}

void _do_copy_char(const pending_upload& snap)
{
    if(! snap.body || ! g_shared_tiles) return;

    bn::optional<bn::span<bn::tile>> vram_opt = g_shared_tiles->vram();
    if(! vram_opt) return;
    bn::span<bn::tile>& vram = *vram_opt;

    // Self-contained: every field below is a snapshot taken at
    // `_enqueue_char_upload` time, so this routine doesn't read any
    // mutable per-char state and can't desync against `ch.var` /
    // `g_char_trim` mutations between enqueue and drain.
    const smart_characters::body&         body    = *snap.body;
    const smart_characters::tileset_data& ts      = *body.tileset;
    const int                             seg_off = snap.tile_off;
    const int                             count   = snap.count;
    const uint16_t*                       visible = snap.visible;

    for(int i = 0; i < count; ++i)
    {
        const int      local_in_body = visible[i];
        const uint16_t global  = body.used_tiles[local_in_body];
        const int      slab    = global >> 10;
        const int      local   = int(global & 0x3FFu);
        const bn::span<const bn::tile>& rom = ts.slabs[slab]->tiles_ref();
        const int      rom_off  = local         * TILES_PER_VISUAL;
        const int      vram_off = (seg_off + i) * TILES_PER_VISUAL;
        vram[vram_off + 0] = rom[rom_off + 0];
        vram[vram_off + 1] = rom[rom_off + 1];
    }
}

// ---------------------------------------------------------------------------
// Visibility window: clip the BG canvas to the on-screen window so we can
// limit cell writes (and per-char tile trims) to cells that will actually
// be rasterized. Pure compute; updates `bg.cached_first/last_col/row` and
// returns true if the window changed since the last call.
// ---------------------------------------------------------------------------

bool _compute_visible_window(bg_slot& bg)
{
    const int real_x = bg.pos_x.right_shift_integer();
    const int real_y = bg.pos_y.right_shift_integer();

    const int bg_screen_left_x  = BG_W_PX / 2 - bn::display::width()  / 2 - real_x;
    const int bg_screen_right_x = BG_W_PX / 2 + bn::display::width()  / 2 - real_x;
    const int bg_screen_left_y  = BG_H_PX / 2 - bn::display::height() / 2 - real_y;
    const int bg_screen_right_y = BG_H_PX / 2 + bn::display::height() / 2 - real_y;

    auto clamp_w = [](int v) { return _imax(_imin(v, MAP_W_CELLS), 0); };
    auto clamp_h = [](int v) { return _imax(_imin(v, MAP_H_CELLS), 0); };

    const int first_col = clamp_w(_floor_div(bg_screen_left_x,  CELL_PX));
    const int last_col  = clamp_w(_ceil_div (bg_screen_right_x, CELL_PX));
    const int first_row = clamp_h(_floor_div(bg_screen_left_y,  CELL_PX));
    const int last_row  = clamp_h(_ceil_div (bg_screen_right_y, CELL_PX));

    if(first_col == bg.cached_first_col && last_col == bg.cached_last_col &&
       first_row == bg.cached_first_row && last_row == bg.cached_last_row)
    {
        return false;
    }

    bg.cached_first_col = first_col;
    bg.cached_last_col  = last_col;
    bg.cached_first_row = first_row;
    bg.cached_last_row  = last_row;
    return true;
}

// ---------------------------------------------------------------------------
// Inline RLE map decoder.
//
// Bodies store their 32×32 map as a GBA BIOS-format RLE byte stream (see
// `smart_character_bg.h::body::map_compressed`). Both readers below walk
// that stream forward-only, with no scratch buffer — at ~16 bytes of
// stack state per active reader, this stays out of EWRAM entirely while
// preserving the body's row-major access pattern. `skip()` proceeds in
// run-sized strides so unread cells cost only a couple of integer ops.
//
// Format recap:
//   header (4B): 0x30 | (decompressed_size_bytes << 8)
//   chunks:
//     flag byte:
//       bit 7 = 1: compressed run, len = (flag & 0x7F) + 3, value byte
//       bit 7 = 0: literal run,    len = (flag & 0x7F) + 1, raw bytes
// ---------------------------------------------------------------------------

class rle_byte_reader
{
public:
    explicit rle_byte_reader(const unsigned char* compressed)
        : _p(compressed + 4)  // skip BIOS header
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
            n              -= take;
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
            _run_remaining  = int(flag & 0x7F) + 3;
            _run_byte       = *_p++;
        }
        else
        {
            _run_compressed = false;
            _run_remaining  = int(flag & 0x7F) + 1;
        }
    }

    const unsigned char* _p;
    int                  _run_remaining = 0;
    unsigned char        _run_byte      = 0;
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

    void skip(int cells) { _r.skip(cells * 2); }

private:
    rle_byte_reader _r;
};

// ---------------------------------------------------------------------------
// Per-character visibility trim.
//
// Walks the cells of the character's body that fall inside both the body
// bbox and the host BG's visible window, collecting the unique body-local
// tile indices into `ch.visible_tiles[]` (in compact-id order) and a
// reverse `ch.compact_remap[local] = compact_idx` map for the cell-write
// pass (`_refresh_bg_cells`).
//
// Cells outside the visible window contribute nothing, so a body placed
// near a screen edge (or off-canvas — `_try_compute_offset` allows the
// bbox to overflow the canvas; off-canvas cells just aren't referenced
// here) only consumes shared-pool capacity for the tiles its on-screen
// portion actually uses.
//
// Sets `ch.tiles_dirty` if the trimmed set differs from the previous
// commit (different size or different content) so `_do_copy_char` will
// re-upload the visible tile data on the next V-Blank.
// ---------------------------------------------------------------------------

void _compute_char_trim(int idx)
{
    char_state& ch = g_chars[idx];
    if(! ch.alive || ! ch.var)
    {
        if(ch.visible_tile_count != 0) ch.tiles_dirty = true;
        ch.visible_tile_count = 0;
        return;
    }
    if(ch.bg_idx < 0)
    {
        // Homeless — release the char's slice of the shared pool so
        // other characters can use it. The next attach re-trims against
        // the new host BG anyway.
        if(ch.visible_tile_count != 0) ch.tiles_dirty = true;
        ch.visible_tile_count = 0;
        return;
    }

    const bg_slot&                bg   = g_bgs[ch.bg_idx];
    const smart_characters::body& body = *ch.var->body;

    BN_ASSERT(body.used_count <= MAX_BODY_TILES_PER_CHAR,
              "smart_characters_manager: body.used_count exceeds "
              "MAX_BODY_TILES_PER_CHAR; bump the constant.");

    int slot = -1;
    for(int k = 0; k < bg.char_count; ++k)
        if(bg.char_indices[k] == idx) { slot = k; break; }
    BN_ASSERT(slot >= 0,
              "_compute_char_trim: char not found in its host BG");

    const int dx = bg.char_dx_cells[slot];
    const int dy = bg.char_dy_cells[slot];

    const int gx_lo = _imax(body.vis_x0 + dx, bg.cached_first_col);
    const int gx_hi = _imin(body.vis_x1 + dx, bg.cached_last_col);
    const int gy_lo = _imax(body.vis_y0 + dy, bg.cached_first_row);
    const int gy_hi = _imin(body.vis_y1 + dy, bg.cached_last_row);

    char_trim_buffers& tb = g_char_trim[idx];
    uint16_t* compact = tb.compact_remap;
    uint16_t* visible = tb.visible_tiles;
    for(int i = 0; i < body.used_count; ++i) compact[i] = 0xFFFFu;

    int new_count = 0;
    bool changed  = false;
    if(gx_lo < gx_hi && gy_lo < gy_hi)
    {
        // Fast-forward the RLE stream to the first visible cell of the
        // first visible row, then walk the trim window row-by-row,
        // skipping the lead/trail bands per row. Stream is read once;
        // no scratch buffer.
        rle_cell_reader rd(body.map_compressed);
        const int row_skip_lead  = gx_lo - dx;
        const int row_take       = gx_hi - gx_lo;
        const int row_skip_trail = MAP_W_CELLS - (gx_hi - dx);
        rd.skip((gy_lo - dy) * MAP_W_CELLS + row_skip_lead);

        for(int gy = gy_lo; gy < gy_hi; ++gy)
        {
            for(int i = 0; i < row_take; ++i)
            {
                const int local = rd.next() & 0x3FFu;
                // Local 0 is the per-body transparent (see converter's
                // `dedupe_tiles`). It maps to the *global* transparent
                // at pool slot 0 — never allocate a per-character slot
                // for it, and don't queue it for upload.
                if(local == 0) continue;
                if(compact[local] != 0xFFFFu) continue;

                compact[local] = uint16_t(new_count);
                BN_ASSERT(new_count < MAX_VISIBLE_TILES_PER_CHAR,
                          "smart_characters_manager: visible tile count "
                          "exceeds MAX_VISIBLE_TILES_PER_CHAR; bump it.");

                if(new_count >= ch.visible_tile_count ||
                   visible[new_count] != local)
                {
                    visible[new_count] = uint16_t(local);
                    changed = true;
                }
                ++new_count;
            }
            if(gy + 1 < gy_hi) rd.skip(row_skip_trail + row_skip_lead);
        }
    }
    if(new_count != ch.visible_tile_count)
    {
        ch.visible_tile_count = new_count;
        changed = true;
    }
    if(changed) ch.tiles_dirty = true;
}

// ---------------------------------------------------------------------------
// BG cell rewrite: stamp the staging cells of `bg` from each tenant's
// body map, mapping the body's local tile id through the per-char compact
// remap and adding the char's `tile_off` (the start of its segment in the
// shared pool). Assumes `_compute_visible_window(bg)` and
// `_compute_char_trim` have run for every tenant since the last layout.
// ---------------------------------------------------------------------------

void _refresh_bg_cells(bg_slot& bg)
{
    bg_staging& stg = g_bg_staging[bg.staging_slot];
    bn::regular_bg_map_cell* cells = stg.cells;
    std::memset(cells, 0,
                MAP_W_CELLS * MAP_H_CELLS * sizeof(bn::regular_bg_map_cell));

    const int first_col = bg.cached_first_col;
    const int last_col  = bg.cached_last_col;
    const int first_row = bg.cached_first_row;
    const int last_row  = bg.cached_last_row;

    for(int s = 0; s < bg.char_count; ++s)
    {
        const int                      ci   = bg.char_indices[s];
        const char_state&              ch   = g_chars[ci];
        const smart_characters::body&  body = *ch.var->body;
        const int dx      = bg.char_dx_cells[s];
        const int dy      = bg.char_dy_cells[s];
        const int seg_off = ch.tile_off;
        const uint16_t* compact_remap = g_char_trim[ci].compact_remap;

        const int gx_lo = _imax(body.vis_x0 + dx, first_col);
        const int gx_hi = _imin(body.vis_x1 + dx, last_col);
        const int gy_lo = _imax(body.vis_y0 + dy, first_row);
        const int gy_hi = _imin(body.vis_y1 + dy, last_row);
        if(gx_lo >= gx_hi || gy_lo >= gy_hi) continue;

        // Stream the body's RLE-compressed map row-by-row, skipping
        // cells outside the trim window. No scratch buffer — same logic
        // as `_compute_char_trim` above.
        rle_cell_reader rd(body.map_compressed);
        const int row_skip_lead  = gx_lo - dx;
        const int row_take       = gx_hi - gx_lo;
        const int row_skip_trail = MAP_W_CELLS - (gx_hi - dx);
        rd.skip((gy_lo - dy) * MAP_W_CELLS + row_skip_lead);

        for(int gy = gy_lo; gy < gy_hi; ++gy)
        {
            const int grow = gy * MAP_W_CELLS;
            int gx = gx_lo;
            for(int i = 0; i < row_take; ++i, ++gx)
            {
                const bn::regular_bg_map_cell src = rd.next();
                const int local   = src & 0x3FFu;
                // Per-body transparent → leave the cell at the memset
                // default (tile id 0 = pool slot 0 = global transparent
                // initialised by `_ensure_global_transparent`).
                if(local == 0) continue;
                const int compact = compact_remap[local];
                BN_ASSERT(compact != 0xFFFF,
                          "_refresh_bg_cells: visible cell references a "
                          "non-trimmed tile; trim went stale.");
                cells[grow + gx] =
                    bn::regular_bg_map_cell((src & 0xFC00u) | (seg_off + compact));
            }
            if(gy + 1 < gy_hi) rd.skip(row_skip_trail + row_skip_lead);
        }
    }
}

// ---------------------------------------------------------------------------
// Build / rebuild a BG slot.
// ---------------------------------------------------------------------------

void _create_bg_objects(bg_slot& bg)
{
    BN_ASSERT(bg.char_count > 0, "_create_bg_objects: empty BG");
    BN_ASSERT(g_shared_tiles && g_shared_palette,
              "_create_bg_objects: shared resources not initialized");

    bg.cached_first_col = bg.cached_last_col = -1;
    bg.cached_first_row = bg.cached_last_row = -1;
    _compute_visible_window(bg);
    _refresh_bg_cells(bg);

    bg_staging& stg = g_bg_staging[bg.staging_slot];
    bn::regular_bg_map_item map_item(stg.cells[0],
                                     bn::size(MAP_W_CELLS, MAP_H_CELLS));
    bg.map = map_item.create_map(*g_shared_tiles, *g_shared_palette);

    bn::regular_bg_builder builder(*bg.map);
    builder.set_position(bg.pos_x, bg.pos_y);
    builder.set_priority(bg.priority);
    builder.set_blending_enabled(bg.blending_enabled);
    bg.bg = builder.release_build();
}

void _rebuild_bg_full(bg_slot& bg)
{
    if(! bg.bg)
    {
        BN_LOG("_rebuild_bg_full");
        _create_bg_objects(bg);
        return;
    }

    // Pick up any change to the logical position (e.g. a rebase when the
    // last roommate moved out — see `_detach_and_mark`) before we rewrite.
    bg.bg->set_position(bg.pos_x, bg.pos_y);
    // Belt & braces: the blending flag is already maintained on the
    // bg_ptr by `set_blending_enabled` (solo path), but a multi-tenant
    // detach + bucket-rebase can land us here for a BG whose blending
    // intent diverged from the underlying ptr. Re-asserting it on every
    // rebuild is free and keeps `bg.blending_enabled` and the actual
    // BLDCNT bit in lockstep — critical for the dialog fade afterwards
    // not pulling these chars into its alpha curve.
    bg.bg->set_blending_enabled(bg.blending_enabled);
    bg.bg->set_priority(bg.priority);

    bg.cached_first_col = bg.cached_last_col = -1;
    bg.cached_first_row = bg.cached_last_row = -1;
    _compute_visible_window(bg);
    _refresh_bg_cells(bg);
    bg.map->reload_cells_ref();
}

// ---------------------------------------------------------------------------
// Re-layout the shared tile pool: pack alive chars in slot order. Any
// char whose `tile_off` shifted (or whose variant changed) is marked
// `tiles_dirty` and its host BG is marked dirty.
// ---------------------------------------------------------------------------

void _global_layout()
{
    // Slot 0 of the shared pool is reserved for the *global transparent*
    // tile (initialised once in `_ensure_global_transparent`). Empty BG
    // cells (`memset(0)` left them at tile id 0) and body cells whose
    // local id is 0 (the per-body transparent reserved by the converter
    // — see `dedupe_tiles` in smart_character_converter.py) point here,
    // so we don't pay a per-character pool slot just to host another
    // copy of the transparent tile.
    int off = 1;
    for(int i = 0; i < MAX_CHARS; ++i)
    {
        char_state& ch = g_chars[i];
        if(! ch.alive) continue;
        const int new_count = ch.visible_tile_count;
        BN_ASSERT(off + new_count <= g_shared_capacity_visual_tiles,
                  "smart_characters_manager: shared tile pool overflow ",
                  off + new_count, " / cap ", g_shared_capacity_visual_tiles);
        if(ch.tile_off != off)
        {
            ch.tile_off    = off;
            ch.tiles_dirty = true;
            if(ch.bg_idx >= 0) g_bgs[ch.bg_idx].dirty = true;
        }
        off += new_count;
    }
}

// ---------------------------------------------------------------------------
// BG slot lifecycle
// ---------------------------------------------------------------------------

int _allocate_bg_slot()
{
    for(int i = 0; i < MAX_BGS; ++i)
    {
        if(! g_bgs[i].active)
        {
            g_bgs[i] = bg_slot{};
            g_bgs[i].active       = true;
            g_bgs[i].staging_slot = i;
            for(int s = 0; s < MAX_CHARS; ++s) g_bgs[i].char_indices[s] = -1;
            return i;
        }
    }
    return -1;
}

void _release_bg_slot(int bg_idx)
{
    BN_LOG("_release_bg_slot: ", bg_idx);
    bg_slot& bg = g_bgs[bg_idx];
    bg.bg .reset();
    bg.map.reset();
    bg.active     = false;
    bg.dirty      = false;
    bg.char_count = 0;
}

// ---------------------------------------------------------------------------
// Compatibility checks for inserting a character into an existing BG.
// (No per-BG VRAM check: tile budget is enforced globally at layout time.)
// ---------------------------------------------------------------------------

bool _bucket_compatible(const bg_slot& bg, int x_int, int y_int,
                        int priority, bool blending_enabled)
{
    return bg.priority == priority &&
           bg.blending_enabled == blending_enabled &&
           _floor_mod(x_int, CELL_PX) == bg.bucket_x &&
           _floor_mod(y_int, CELL_PX) == bg.bucket_y;
}

// Cell-snapped position of a character on the screen-centered BG canvas.
// (See `bg_slot` doc.) Independent of any other character in the BG.
inline int _char_dx_cells(int x_int) { return _floor_div(x_int, CELL_PX); }
inline int _char_dy_cells(int y_int) { return _floor_div(y_int, CELL_PX); }

bool _try_compute_offset(const bg_slot& bg,
                         const smart_characters::variant& var,
                         int x_int, int y_int, int priority,
                         bool blending_enabled,
                         int& out_dx_cells, int& out_dy_cells,
                         int ignore_slot = -1)
{
    if(! _bucket_compatible(bg, x_int, y_int, priority, blending_enabled))
        return false;

    const int dx_cells = _char_dx_cells(x_int);
    const int dy_cells = _char_dy_cells(y_int);

    const smart_characters::body& body = *var.body;
    const int gx0 = body.vis_x0 + dx_cells;
    const int gx1 = body.vis_x1 + dx_cells;
    const int gy0 = body.vis_y0 + dy_cells;
    const int gy1 = body.vis_y1 + dy_cells;

    // Body bbox may overflow the canvas — `_refresh_visible_window`
    // clips the off-canvas portion at render time, and off-canvas cells
    // map to off-screen pixels anyway (the visible viewport sits inside
    // the canvas). Reject only if the bbox is *entirely* off-canvas
    // (nothing to host).
    if(gx1 <= 0 || gx0 >= MAP_W_CELLS) return false;
    if(gy1 <= 0 || gy0 >= MAP_H_CELLS) return false;

    for(int s = 0; s < bg.char_count; ++s)
    {
        if(s == ignore_slot) continue;
        const char_state&             other = g_chars[bg.char_indices[s]];
        const smart_characters::body& ob    = *other.var->body;
        const int o_dx = bg.char_dx_cells[s];
        const int o_dy = bg.char_dy_cells[s];
        if(_bbox_overlap(gx0, gx1, gy0, gy1,
                         ob.vis_x0 + o_dx, ob.vis_x1 + o_dx,
                         ob.vis_y0 + o_dy, ob.vis_y1 + o_dy))
        {
            return false;
        }
    }

    out_dx_cells = dx_cells;
    out_dy_cells = dy_cells;
    return true;
}

void _bg_insert_char(int bg_idx, int char_idx, int dx_cells, int dy_cells)
{
    bg_slot& bg = g_bgs[bg_idx];
    BN_ASSERT(bg.char_count < MAX_CHARS, "_bg_insert_char: BG slot full");
    const int s = bg.char_count++;
    bg.char_indices[s]  = char_idx;
    bg.char_dx_cells[s] = dx_cells;
    bg.char_dy_cells[s] = dy_cells;
    g_chars[char_idx].bg_idx = bg_idx;
}

void _bg_remove_char(int bg_idx, int char_idx)
{
    bg_slot& bg = g_bgs[bg_idx];
    int s = -1;
    for(int i = 0; i < bg.char_count; ++i)
        if(bg.char_indices[i] == char_idx) { s = i; break; }
    BN_ASSERT(s >= 0, "_bg_remove_char: char not in BG");
    const int last = bg.char_count - 1;
    if(s != last)
    {
        bg.char_indices[s]  = bg.char_indices[last];
        bg.char_dx_cells[s] = bg.char_dx_cells[last];
        bg.char_dy_cells[s] = bg.char_dy_cells[last];
    }
    bg.char_count = last;
    g_chars[char_idx].bg_idx = -1;
}

// ---------------------------------------------------------------------------
// Auto-pack: find a host BG (existing or new) for a character.
// Returns BG index (and writes computed offset), or -1 on failure.
// ---------------------------------------------------------------------------

// Look for an existing active BG (other than `avoid_bg`) that can host the
// character at its current position. Picks the most populated compatible
// candidate so we keep collapsing solo BGs back into shared hosts.
bool _try_find_existing_host(int char_idx, int avoid_bg,
                             int& out_bg, int& out_dx, int& out_dy)
{
    const char_state& ch = g_chars[char_idx];
    int best_bg = -1, best_count = -1, best_dx = 0, best_dy = 0;
    for(int i = 0; i < MAX_BGS; ++i)
    {
        if(i == avoid_bg) continue;
        if(! g_bgs[i].active) continue;
        int dx, dy;
        if(_try_compute_offset(g_bgs[i], *ch.var, ch.x_int, ch.y_int,
                               ch.priority, ch.blending_enabled, dx, dy))
        {
            if(g_bgs[i].char_count > best_count)
            {
                best_bg    = i;
                best_count = g_bgs[i].char_count;
                best_dx    = dx;
                best_dy    = dy;
            }
        }
    }
    if(best_bg < 0) return false;
    out_bg = best_bg;
    out_dx = best_dx;
    out_dy = best_dy;
    return true;
}

int _auto_pack(int char_idx, int& out_dx_cells, int& out_dy_cells)
{
    int target;
    if(_try_find_existing_host(char_idx, -1, target, out_dx_cells, out_dy_cells))
    {
        return target;
    }

    const int new_bg = _allocate_bg_slot();
    if(new_bg < 0) return -1;

    const char_state& ch = g_chars[char_idx];
    bg_slot& bg = g_bgs[new_bg];
    // The BG sits at the bucket — a fixed sub-cell offset on the screen
    // centered canvas. Cell-snapped char position is independent of the
    // bucket, so the dx/dy here are simply `floor_div(x_int, 8)`.
    bg.bucket_x         = _floor_mod(ch.x_int, CELL_PX);
    bg.bucket_y         = _floor_mod(ch.y_int, CELL_PX);
    bg.priority         = ch.priority;
    bg.blending_enabled = ch.blending_enabled;
    bg.pos_x            = bn::fixed(bg.bucket_x);
    bg.pos_y            = bn::fixed(bg.bucket_y);
    out_dx_cells = _char_dx_cells(ch.x_int);
    out_dy_cells = _char_dy_cells(ch.y_int);
    return new_bg;
}

// ---------------------------------------------------------------------------
// Helpers shared by set_variant / set_position
// ---------------------------------------------------------------------------

void _detach_and_mark(int char_idx)
{
    char_state& ch = g_chars[char_idx];
    if(ch.bg_idx < 0) return;
    const int old_bg = ch.bg_idx;
    _bg_remove_char(old_bg, char_idx);

    bg_slot& bg = g_bgs[old_bg];
    if(bg.char_count == 0)
    {
        _release_bg_slot(old_bg);
    }
    else
    {
        // No "rebase" needed: BG position is locked to the bucket
        // (a 0..7 px sub-cell offset), not to any specific character,
        // so removing one tenant doesn't invalidate the others' dx/dy.
        _mark_dirty(bg);
    }
}

bool _attach_to_some_bg(int char_idx)
{
    int dx, dy;
    const int bg_idx = _auto_pack(char_idx, dx, dy);
    if(bg_idx < 0) return false;

    _bg_insert_char(bg_idx, char_idx, dx, dy);
    _mark_dirty(g_bgs[bg_idx]);
    return true;
}

// ---------------------------------------------------------------------------
// Face-sprite sync.
//
// Each character has its emotion rendered as an OBJ sprite that overlays
// the transparent face hole stamped into the body BG. This pass — called
// once per `commit()` after BG geometry is settled — keeps every
// character's sprite in lockstep with its host BG: lazy-creates the
// sprite on first attach, recreates it after a body (group) change,
// hides it when the char is alive but unhosted, and updates its screen
// position from the BG's current `pos_x/pos_y` and the char's offset
// inside that BG.
//
// The sprite *item* swap on a same-group emotion change is handled
// synchronously by `set_variant` (fast path); this function only deals
// with structure / positioning.
// ---------------------------------------------------------------------------

// Translate the face cell rect into the sprite's *center* position in
// screen coordinates.
//
// BG center is at (bg.pos_x, bg.pos_y) — the bucket position, in the
// 0..7 px range — so BG canvas top-left is at (bg.pos_x - 128,
// bg.pos_y - 128). The face hole stamped into the body BG occupies
// cells [face_offset, face_offset + face_size) — i.e. pixels
// [face_offset * 8, face_offset * 8 + face_size * 8) — measured from
// the body's *own* canvas top-left. The body is drawn shifted by
// `(dx_cells, dy_cells) * 8` pixels inside the shared BG canvas, so
// the face hole on the shared canvas lives at
// `(dx + face_offset) * 8`. Butano sprites are placed by their
// center, so we add half the face size in pixels once.
inline bn::fixed _face_sprite_x(const bg_slot& bg, int dx_cells,
                                const smart_characters::variant& var)
{
    const int rel_px = (dx_cells + var.face_offset_x_cells) * CELL_PX
                     + var.face_size_x_cells * (CELL_PX / 2)
                     - BG_W_PX / 2;
    return bg.pos_x + rel_px;
}

inline bn::fixed _face_sprite_y(const bg_slot& bg, int dy_cells,
                                const smart_characters::variant& var)
{
    const int rel_px = (dy_cells + var.face_offset_y_cells) * CELL_PX
                     + var.face_size_y_cells * (CELL_PX / 2)
                     - BG_H_PX / 2;
    return bg.pos_y + rel_px;
}

void _sync_face_sprites()
{
    for(int i = 0; i < MAX_CHARS; ++i)
    {
        char_state& ch = g_chars[i];
        if(! ch.alive)
        {
            ch.face.reset();
            ch.face_var_applied = nullptr;
            continue;
        }
        if(ch.bg_idx < 0)
        {
            // Homeless — keep the sprite (so we don't churn its OBJ tile
            // VRAM allocation) but hide it. It'll come back when the
            // char gets re-attached.
            if(ch.face) ch.face->set_visible(false);
            continue;
        }

        const bg_slot& bg = g_bgs[ch.bg_idx];
        int slot = -1;
        for(int k = 0; k < bg.char_count; ++k)
            if(bg.char_indices[k] == i) { slot = k; break; }
        BN_ASSERT(slot >= 0, "_sync_face_sprites: char not in its BG");

        const int dx = bg.char_dx_cells[slot];
        const int dy = bg.char_dy_cells[slot];
        const smart_characters::variant& var = *ch.var;
        const bn::fixed sx = _face_sprite_x(bg, dx, var);
        const bn::fixed sy = _face_sprite_y(bg, dy, var);

        // Decide between three paths, based on the diff between the
        // variant currently realised on the sprite (`face_var_applied`)
        // and the variant the manager wants on screen (`ch.var`):
        //
        //   1. No sprite yet -> create from scratch.
        //   2. Sprite exists, face shape differs (cross-group switch
        //      with a different `face_size_*_cells`) -> reset + create.
        //   3. Sprite exists, shape matches, but variant changed (same
        //      group / different emotion, or different body with the
        //      same face footprint) -> set_tiles in place. Cheapest
        //      hot path; `set_tiles` doesn't churn the OBJ palette
        //      (which is `pal_char_obj`, shared across every face).
        //
        // The reset itself happens here, never in `set_variant`, so
        // user-visible state stays atomic with the body BG refresh
        // earlier in this same `commit()` call.
        const int face_w_px = var.face_size_x_cells * CELL_PX;
        const int face_h_px = var.face_size_y_cells * CELL_PX;
        const bn::sprite_shape_size want_shape(face_w_px, face_h_px);
        if(ch.face && ch.face->shape_size() != want_shape)
        {
            ch.face.reset();
            ch.face_var_applied = nullptr;
        }
        if(! ch.face)
        {
            // The converter no longer emits a `bn::sprite_item` per
            // face; we compose one inline from (shape, face_tiles,
            // shared palette item). Butano dedupes the palette ptr by
            // item so every face in the scene resolves to one VRAM
            // palette slot — see `_apply_palette_variant_to_faces`.
            const bn::sprite_item face_item(
                want_shape, *var.face_tiles,
                bn::sprite_palette_items::pal_char_obj);
            ch.face = face_item.create_sprite(sx, sy);
            ch.face_var_applied = &var;
            // Apply the scene-wide palette variant to the (possibly
            // freshly-allocated) shared OBJ palette. No-op for
            // DEFAULT once we've already done it, but creating the
            // first face after a non-DEFAULT variant was set is the
            // exact moment Butano just initialised the palette from
            // its item — re-tint it before the next vblank.
            _apply_palette_variant_to_faces();
        }
        else
        {
            if(ch.face_var_applied != &var)
            {
                ch.face->set_tiles(*var.face_tiles);
                ch.face_var_applied = &var;
            }
            ch.face->set_position(sx, sy);
            ch.face->set_visible(true);
        }
        // Face sprite is always one layer behind its body BG:
        // BG priority P, face sprite priority P+1.
        // The body has a cut-out hole, so the face is visible through
        // it but remains hidden by any foreground BG (smaller priority).
        const int face_bg_priority = _face_bg_priority_from_bg_priority(bg.priority);
        ch.face->set_bg_priority(face_bg_priority);
        // Keep sprite tie-break z in sync with the host BG z.
        if(bg.bg)
        {
            ch.face->set_z_order(bg.bg->z_order());
        }
        // Mirror the BG's blending state onto the face sprite. Both
        // body BG and face OBJ are alpha-blended together by the global
        // `bn::blending::set_transparency_alpha`, so they have to share
        // the enabled flag — the packer guarantees every char on a BG
        // agrees on it.
        ch.face->set_blending_enabled(ch.blending_enabled);
    }
}

// Run the full deferred work: refresh visibility windows, trim per-char
// tile sets, repack the shared pool, rebuild every dirty BG, queue
// per-char body tile uploads, then resync face sprites. Called from
// `commit()`.
void _process_pending_work()
{
    // Best-effort: try to home any char that was left without a host on
    // a previous tick (every BG slot was full / incompatible at the time).
    // The layout may have changed since then — a slot may now be free, or
    // an existing BG may have shifted into a compatible bucket.
    for(int i = 0; i < MAX_CHARS; ++i)
    {
        char_state& ch = g_chars[i];
        if(ch.alive && ch.bg_idx < 0) _attach_to_some_bg(i);
    }

    // Refresh the visibility window for every active BG. If the window
    // shifted (the BG was re-bucketed in place, or a new BG just popped
    // up), mark it dirty so it gets a full cell rewrite below — the
    // tenants' trims will be recomputed against the new window first.
    for(bg_slot& bg : g_bgs)
    {
        if(! bg.active) continue;
        if(_compute_visible_window(bg)) bg.dirty = true;
    }

    // Per-char trim against the freshly computed windows. The trim
    // populates `ch.visible_tiles[]`, `ch.compact_remap[]` and
    // `ch.visible_tile_count`, and flips `ch.tiles_dirty` whenever the
    // visible set differs from the previous commit (size or content).
    for(int i = 0; i < MAX_CHARS; ++i)
    {
        char_state& ch = g_chars[i];
        if(ch.alive && ch.bg_idx >= 0) _compute_char_trim(i);
    }

    // Pack trimmed sets into the shared pool. Any char whose `tile_off`
    // shifts is marked dirty (its host BG too) so cells get rewritten.
    _global_layout();

    for(bg_slot& bg : g_bgs)
    {
        if(bg.active && bg.dirty)
        {
            _rebuild_bg_full(bg);
            bg.dirty = false;
        }
    }

    for(int i = 0; i < MAX_CHARS; ++i)
    {
        char_state& ch = g_chars[i];
        if(! ch.alive) continue;
        if(ch.tiles_dirty)
        {
            _enqueue_char_upload(i);
            ch.tiles_dirty = false;
        }
    }

    _sync_face_sprites();
}

}  // anonymous namespace

// ---------------------------------------------------------------------------
// Public API
// ---------------------------------------------------------------------------

void init()
{
    // V-Blank callback re-registration must happen on *every* `init()`
    // call, not just the first. The save/load flow tears butano down
    // (`globals::release_engine` → `bn::core::init` zeroes the callback
    // table) and then re-`init`s the engine before the scenario re-enters
    // and triggers our `init()` via `SceneManager::set`. If we early-
    // returned on `g_initialized`, the new butano instance would never
    // know about `process_pending_uploads` — character tile data would
    // never reach VRAM after the second load, leaving the user staring
    // at a screenful of map cells pointing at uninitialised tile slots.
    // The actual register write is one MMIO store, so re-running it is
    // essentially free.
    bn::core::set_vblank_callback(&process_pending_uploads);

    if(g_initialized) return;
    g_initialized = true;

    for(char_state& c : g_chars) c = char_state{};
    for(bg_slot&    b : g_bgs)   b = bg_slot{};
    for(pending_upload& p : g_pending) p = pending_upload{};
    g_transparent_ready = false;
    g_palette_variant   = PALETTE_VARIANT_DEFAULT;

    // Shared tile pool + body palette are allocated lazily by the next
    // `commit` once a character actually exists, and released as soon
    // as the last character is destroyed. Keeping them resident across
    // empty stretches of the scene would lock palette slots 0..N at
    // 8bpp, which prevents any subsequent 4bpp backdrop from claiming
    // those slots — the engine doesn't relocate live palettes.
}

void commit()
{
    if(! g_initialized) return;

    if(_any_char_alive())
    {
        _ensure_shared_resources();
    }
    else
    {
        // No tenants → drop shared VRAM so the next 4bpp backdrop can
        // claim those palette / tile slots.
        _release_shared_resources();
        return;
    }

    _process_pending_work();
}

id_t create(const smart_characters::variant& var, bn::fixed x, bn::fixed y,
            int priority)
{
    BN_ASSERT(g_initialized, "smart_characters_manager::init() not called");
    BN_ASSERT(priority >= 0 && priority <= 2,
              "smart_characters_manager::create: priority must be 0..2, got ",
              priority);

    int slot = -1;
    for(int i = 0; i < MAX_CHARS; ++i)
        if(! g_chars[i].alive) { slot = i; break; }
    if(slot < 0) return id_t{};

    char_state& ch = g_chars[slot];
    ch.alive       = true;
    ch.character   = CHARACTER_NONE;
    ch.var         = &var;
    ch.x           = x;
    ch.y           = y;
    ch.x_int       = x.right_shift_integer();
    ch.y_int       = y.right_shift_integer();
    ch.bg_idx      = -1;
    ch.tile_off    = -1;     // forces _global_layout to mark this dirty
    ch.tiles_dirty = true;
    ch.priority    = priority;

    if(! _attach_to_some_bg(slot))
    {
        ch.alive = false;
        return id_t{};
    }
    return id_t::_from_index(slot);
}

void destroy(id_t id)
{
    if(! id.valid()) return;
    const int idx = id._index();
    char_state& ch = g_chars[idx];
    if(! ch.alive) return;

    _cancel_char_upload(idx);
    _detach_and_mark(idx);
    ch = char_state{};
    // Other chars whose tile_off shifted will get marked dirty by
    // `_global_layout` at the next commit.

    // If this was the last character, drop the shared palette + tile
    // pool so any 4bpp backdrop the next scene puts up can claim those
    // VRAM / palette slots. The next `show_character` will allocate
    // them again from scratch.
    _release_shared_resources();
}

void set_variant(id_t id, const smart_characters::variant& var)
{
    BN_ASSERT(id.valid(), "smart_characters_manager::set_variant: invalid id");
    const int idx = id._index();
    char_state& ch = g_chars[idx];
    BN_ASSERT(ch.alive, "set_variant: dead char");

    // Fast path: same-group emotion swap.
    //
    // All emotions in a group share one `body` (and therefore the same
    // body tile working set, the same body map cells, and the same face
    // size/offset). Only the face *tiles* differ — `_sync_face_sprites`
    // will pick up the new `var` next commit and `set_tiles` in place
    // (no OBJ palette churn, no shape change, no recreate).
    if(ch.var && ch.var->body == var.body)
    {
        ch.var = &var;
        return;
    }

    // Body (group) changed. Do NOT reset `ch.face` here: the body BG
    // hasn't been rebuilt yet (that happens in `commit()` →
    // `_refresh_bg_cells`), so dropping the face synchronously would
    // leave the user looking at the *old* pose without a face for one
    // or more frames. Instead, leave the existing face on top of the
    // existing body until `_sync_face_sprites` reapplies everything
    // atomically together with the body refresh. Face shape mismatch
    // (different group) is handled there via reset + recreate.
    const int old_bg = ch.bg_idx;
    ch.var         = &var;
    ch.tiles_dirty = true;

    if(old_bg >= 0)
    {
        bg_slot& bg = g_bgs[old_bg];
        int s = -1;
        for(int i = 0; i < bg.char_count; ++i)
            if(bg.char_indices[i] == idx) { s = i; break; }
        BN_ASSERT(s >= 0, "set_variant: char not in its BG");

        int dx, dy;
        if(_try_compute_offset(bg, var, ch.x_int, ch.y_int,
                               ch.priority, ch.blending_enabled, dx, dy, s))
        {
            BN_ASSERT(dx == bg.char_dx_cells[s] && dy == bg.char_dy_cells[s],
                      "set_variant: unexpected offset shift");
            _mark_dirty(bg);
            return;
        }
    }

    _detach_and_mark(idx);
    if(! _attach_to_some_bg(idx))
    {
        // No host BG available right now (every slot full, no compatible
        // existing one). Keep the char alive but unattached: a subsequent
        // `set_position` / `set_variant` may find a fit when the layout
        // changes. Logical state stays consistent — only the visual
        // disappears for now.
        BN_LOG("smart_characters_manager: char ", idx,
               " homeless after set_variant (no compatible BG / slot)");
    }
}

void set_position(id_t id, bn::fixed x, bn::fixed y)
{
    BN_ASSERT(id.valid(), "smart_characters_manager::set_position: invalid id");
    const int idx = id._index();
    char_state& ch = g_chars[idx];
    BN_ASSERT(ch.alive, "set_position: dead char");

    // Snapping `set_position` cancels any in-flight smooth-move tween: the
    // caller asked for a definitive position, so we no longer interpolate
    // toward the previous target.
    ch.anim_frames_left = 0;

    // Sub-cell positioning is intentionally not supported: characters
    // move on the integer pixel grid, and the bucket (mod-8) component
    // is realised as a fixed BG scroll. Anything finer is dropped here.
    const int new_x_int = x.right_shift_integer();
    const int new_y_int = y.right_shift_integer();

    // Fast path: integer-pixel position is unchanged. Sub-pixel `bn::fixed`
    // arguments are stored verbatim (so position queries still report what
    // the caller passed) but the visual stays put — no repack, no map
    // rewrite. This makes per-frame smooth-move tweens (lerp from start to
    // target every frame) cheap: most frames skip all the heavy work
    // because the int position only ticks every ~few frames.
    if(ch.alive && ch.x_int == new_x_int && ch.y_int == new_y_int)
    {
        ch.x = x;
        ch.y = y;
        return;
    }

    ch.x = x;  ch.y = y;
    ch.x_int = new_x_int;  ch.y_int = new_y_int;

    const int new_bucket_x = _floor_mod(new_x_int, CELL_PX);
    const int new_bucket_y = _floor_mod(new_y_int, CELL_PX);
    const int new_dx       = _char_dx_cells(new_x_int);
    const int new_dy       = _char_dy_cells(new_y_int);

    const int old_bg = ch.bg_idx;
    if(old_bg >= 0)
    {
        bg_slot& bg = g_bgs[old_bg];
        int s = -1;
        for(int i = 0; i < bg.char_count; ++i)
            if(bg.char_indices[i] == idx) { s = i; break; }
        BN_ASSERT(s >= 0, "set_position: char not in its BG");

        if(bg.char_count == 1)
        {
            // Sole occupant: try to merge into a compatible shared BG
            // first (so the scene can collapse back to its packed form
            // after a transient detach).
            {
                int target_bg, dx, dy;
                if(_try_find_existing_host(idx, old_bg, target_bg, dx, dy))
                {
                    _bg_remove_char(old_bg, idx);
                    _release_bg_slot(old_bg);
                    _bg_insert_char(target_bg, idx, dx, dy);
                    _mark_dirty(g_bgs[target_bg]);
                    return;
                }
            }

            // No merge target → re-bucket the BG in place. The body
            // bbox is allowed to overflow the canvas (off-canvas cells
            // are clipped during render and would be off-screen
            // anyway); reject only if the bbox is entirely off-canvas.
            const smart_characters::body& body = *ch.var->body;
            const int gx0 = body.vis_x0 + new_dx;
            const int gx1 = body.vis_x1 + new_dx;
            const int gy0 = body.vis_y0 + new_dy;
            const int gy1 = body.vis_y1 + new_dy;
            const bool fits = (gx1 > 0 && gx0 < MAP_W_CELLS &&
                               gy1 > 0 && gy0 < MAP_H_CELLS);

            if(fits)
            {
                const bool bucket_changed = (bg.bucket_x != new_bucket_x ||
                                             bg.bucket_y != new_bucket_y);
                bg.bucket_x         = new_bucket_x;
                bg.bucket_y         = new_bucket_y;
                bg.pos_x            = bn::fixed(new_bucket_x);
                bg.pos_y            = bn::fixed(new_bucket_y);
                bg.char_dx_cells[s] = new_dx;
                bg.char_dy_cells[s] = new_dy;

                // Defer the actual cell rewrite + trim recompute to the
                // next commit so a single `_process_pending_work` pass
                // sees the final BG window and can update every tenant's
                // trim consistently. Just flagging dirty is enough.
                _mark_dirty(bg);
                if(bg.bg && bucket_changed)
                {
                    bg.bg->set_position(bg.pos_x, bg.pos_y);
                }
                return;
            }
            // Body bbox no longer fits the canvas at this position →
            // fall through to detach + re-attach (a fresh BG with a
            // fresh bucket is allocated for the char).
        }
        else
        {
            // Multi-tenant: try to keep this char in the same BG with
            // a new offset (still bucket-compatible & non-overlapping).
            int dx, dy;
            if(_try_compute_offset(bg, *ch.var, new_x_int, new_y_int,
                                   ch.priority, ch.blending_enabled, dx, dy, s))
            {
                bg.char_dx_cells[s] = dx;
                bg.char_dy_cells[s] = dy;
                _mark_dirty(bg);
                return;
            }
        }
    }

    _detach_and_mark(idx);
    if(! _attach_to_some_bg(idx))
    {
        // Same homeless-but-alive treatment as `set_variant` above. The
        // char's `ch.x` / `ch.y` are already updated; next time the layout
        // shifts (another char moves, a variant changes, etc.) we'll try
        // attaching again.
        BN_LOG("smart_characters_manager: char ", idx,
               " homeless after set_position (no compatible BG / slot)");
    }
}

void set_position(id_t id, bn::fixed target_x, bn::fixed target_y, int frames)
{
    BN_ASSERT(id.valid(), "smart_characters_manager::set_position(animated): invalid id");
    BN_ASSERT(frames >= 0,
              "smart_characters_manager::set_position(animated): frames must be >= 0");
    if(frames <= 1)
    {
        set_position(id, target_x, target_y);
        return;
    }
    const int idx = id._index();
    char_state& ch = g_chars[idx];
    BN_ASSERT(ch.alive, "set_position(animated): dead char");

    // Animation runs purely against integer pixels. `tick()` advances the
    // current `(x_int, y_int)` toward the target by `1 / frames_left` of
    // the remaining distance every frame, so the trajectory ends exactly
    // on the requested integer position even with truncating divides.
    ch.anim_target_x    = target_x.right_shift_integer();
    ch.anim_target_y    = target_y.right_shift_integer();
    ch.anim_frames_left = frames;
}

void tick()
{
    if(! g_initialized) return;

    for(int i = 0; i < MAX_CHARS; ++i)
    {
        char_state& ch = g_chars[i];
        if(! ch.alive || ch.anim_frames_left <= 0) continue;

        const int dx = ch.anim_target_x - ch.x_int;
        const int dy = ch.anim_target_y - ch.y_int;
        const int frames_left = ch.anim_frames_left;
        // Step toward the target by `1 / frames_left` of the remaining
        // pixel distance: integer truncation guarantees we land exactly on
        // the target by the time `frames_left` hits zero (the final step
        // collapses any leftover dx/dy because the divisor is 1).
        const int step_x = (dx >= 0) ? (dx + frames_left - 1) / frames_left
                                     : -(((-dx) + frames_left - 1) / frames_left);
        const int step_y = (dy >= 0) ? (dy + frames_left - 1) / frames_left
                                     : -(((-dy) + frames_left - 1) / frames_left);
        const int new_x_int = ch.x_int + step_x;
        const int new_y_int = ch.y_int + step_y;

        // Re-use the public `set_position` so the bucket / repack /
        // overlap-rejection logic stays in one place. `set_position`
        // resets `anim_frames_left` to 0 — restore it after the call.
        const int saved_frames = ch.anim_frames_left - 1;
        const int saved_tx     = ch.anim_target_x;
        const int saved_ty     = ch.anim_target_y;
        set_position(id_t::_from_index(i), bn::fixed(new_x_int), bn::fixed(new_y_int));
        ch.anim_frames_left = saved_frames;
        ch.anim_target_x    = saved_tx;
        ch.anim_target_y    = saved_ty;
    }
}

bn::fixed_point position(id_t id)
{
    if(! id.valid()) return bn::fixed_point(0, 0);
    const char_state& ch = g_chars[id._index()];
    return bn::fixed_point(ch.x, ch.y);
}

const smart_characters::variant* variant_ptr(id_t id)
{
    if(! id.valid()) return nullptr;
    return g_chars[id._index()].var;
}

void set_priority(int priority)
{
    BN_ASSERT(priority >= 0 && priority <= 2,
              "set_priority: priority must be 0..2, got ", priority);
    for(char_state& ch : g_chars)
    {
        if(! ch.alive) continue;
        ch.priority = priority;
        // Refresh the face's bg priority immediately so it doesn't lag
        // a frame behind the body BG when the user toggles z-order
        // (any not-yet-created face will pick the new value up on its
        // first `_sync_face_sprites` pass).
        if(ch.face)
        {
            const int host_priority =
                ch.bg_idx >= 0 ? g_bgs[ch.bg_idx].priority : priority;
            ch.face->set_bg_priority(_face_bg_priority_from_bg_priority(host_priority));
            if(ch.bg_idx >= 0 && g_bgs[ch.bg_idx].bg)
            {
                ch.face->set_z_order(g_bgs[ch.bg_idx].bg->z_order());
            }
        }
    }
    for(bg_slot& bg : g_bgs)
    {
        if(bg.active)
        {
            bg.priority = priority;
            if(bg.bg) bg.bg->set_priority(priority);
        }
    }
}

void set_priority(id_t id, int priority)
{
    BN_ASSERT(id.valid(), "set_priority(id, p): invalid id");
    BN_ASSERT(priority >= 0 && priority <= 2,
              "set_priority: priority must be 0..2, got ", priority);
    const int idx = id._index();
    char_state& ch = g_chars[idx];
    BN_ASSERT(ch.alive, "set_priority(id, p): dead char");

    if(ch.priority == priority) return;
    ch.priority = priority;

    // The face sprite's bg priority must mirror the char's priority so
    // it stays sandwiched between its own body BG (same priority — the
    // sprite wins on ties and renders on top of it) and any front BG
    // (lower priority value — the BG wins, hiding the face). Update
    // immediately rather than waiting for the next commit's
    // `_sync_face_sprites` so a hot priority change doesn't leave the
    // face floating at its previous z-layer for a frame.
    if(ch.face)
    {
        const int host_priority =
            ch.bg_idx >= 0 ? g_bgs[ch.bg_idx].priority : priority;
        ch.face->set_bg_priority(_face_bg_priority_from_bg_priority(host_priority));
        if(ch.bg_idx >= 0 && g_bgs[ch.bg_idx].bg)
        {
            ch.face->set_z_order(g_bgs[ch.bg_idx].bg->z_order());
        }
    }

    // If the char's host BG is no longer compatible (its priority differs
    // from the char's), or hosts other chars whose priorities still match
    // the BG, we need to detach and re-pack. Otherwise we can update the
    // BG's priority in place.
    const int old_bg = ch.bg_idx;
    if(old_bg >= 0)
    {
        bg_slot& bg = g_bgs[old_bg];
        if(bg.char_count == 1)
        {
            bg.priority = priority;
            if(bg.bg) bg.bg->set_priority(priority);
            return;
        }
        // Multi-tenant: split off this char.
        _detach_and_mark(idx);
    }
    if(! _attach_to_some_bg(idx))
    {
        BN_LOG("smart_characters_manager: char ", idx,
               " homeless after set_priority (no compatible BG / slot)");
    }
}

void set_blending_enabled(id_t id, bool enabled)
{
    BN_ASSERT(id.valid(), "set_blending_enabled(id, b): invalid id");
    const int idx = id._index();
    char_state& ch = g_chars[idx];
    BN_ASSERT(ch.alive, "set_blending_enabled(id, b): dead char");

    if(ch.blending_enabled == enabled) return;
    ch.blending_enabled = enabled;

    // Apply to the existing face sprite immediately. Toggling
    // `set_blending_enabled` on `bn::sprite_ptr` is a write to its OBJ
    // attribute and doesn't churn VRAM, so the bookkeeping cost is on
    // par with `set_visible`.
    if(ch.face) ch.face->set_blending_enabled(enabled);

    // Bucket key changed: the char no longer matches its host BG (or
    // wasn't a perfect fit anyway). Rebucket like `set_priority` — a
    // multi-tenant BG splits this char off and re-packs. A *solo* host
    // still flips its ptr flag in place when raising blending (fade-in
    // isolation). When *lowering* blending to false, also detach + rerun
    // `_attach_to_some_bg`: otherwise every first-show ends on its own BG
    // and `disable_blending_all` never collapses them into one atlas.
    const int old_bg = ch.bg_idx;
    if(old_bg >= 0)
    {
        bg_slot& bg = g_bgs[old_bg];
        if(bg.char_count == 1)
        {
            bg.blending_enabled = enabled;
            if(bg.bg) bg.bg->set_blending_enabled(enabled);
            if(! enabled)
            {
                _detach_and_mark(idx);
                if(! _attach_to_some_bg(idx))
                {
                    BN_LOG("smart_characters_manager: char ", idx,
                           " homeless after set_blending_enabled(solo→false)");
                }
            }
            return;
        }
        _detach_and_mark(idx);
    }
    if(! _attach_to_some_bg(idx))
    {
        BN_LOG("smart_characters_manager: char ", idx,
               " homeless after set_blending_enabled (no compatible BG / slot)");
    }
}

bool is_animating()
{
    for(const char_state& ch : g_chars)
    {
        if(ch.alive && ch.anim_frames_left > 0) return true;
    }
    return false;
}

int active_bgs_count()
{
    int n = 0;
    for(const bg_slot& bg : g_bgs) if(bg.active) ++n;
    return n;
}

int active_bg_tile_count(int active_bg_index)
{
    int idx = 0;
    for(const bg_slot& bg : g_bgs)
    {
        if(! bg.active) continue;
        if(idx == active_bg_index)
        {
            int total = 0;
            for(int s = 0; s < bg.char_count; ++s)
                total += g_chars[bg.char_indices[s]].visible_tile_count;
            return total;
        }
        ++idx;
    }
    return 0;
}

int shared_pool_tile_count()
{
    int total = 0;
    for(const char_state& ch : g_chars)
        if(ch.alive) total += ch.visible_tile_count;
    return total;
}

int shared_pool_capacity()
{
    return g_shared_capacity_visual_tiles;
}

// ---------------------------------------------------------------------------
// character_t-tagged API (mirrors the id_t one).
// ---------------------------------------------------------------------------

namespace {

int _find_slot_by_character(character_t character)
{
    if(character == CHARACTER_NONE) return -1;
    for(int i = 0; i < MAX_CHARS; ++i)
    {
        if(g_chars[i].alive && g_chars[i].character == character) return i;
    }
    return -1;
}

}  // namespace

bool exists(character_t character)
{
    return _find_slot_by_character(character) >= 0;
}

id_t find(character_t character)
{
    const int slot = _find_slot_by_character(character);
    return slot >= 0 ? id_t::_from_index(slot) : id_t{};
}

id_t create(character_t character, const smart_characters::variant& var,
            bn::fixed x, bn::fixed y, int priority)
{
    BN_ASSERT(character != CHARACTER_NONE,
              "smart_characters_manager::create: CHARACTER_NONE is reserved");
    BN_ASSERT(_find_slot_by_character(character) < 0,
              "smart_characters_manager::create: character already alive");

    const id_t id = create(var, x, y, priority);
    if(! id.valid()) return id;
    g_chars[id._index()].character = character;
    return id;
}

void destroy(character_t character)
{
    const int slot = _find_slot_by_character(character);
    if(slot < 0) return;
    destroy(id_t::_from_index(slot));
}

void set_variant(character_t character, const smart_characters::variant& var)
{
    const int slot = _find_slot_by_character(character);
    BN_ASSERT(slot >= 0,
              "smart_characters_manager::set_variant: no live char with this tag");
    set_variant(id_t::_from_index(slot), var);
}

void set_position(character_t character, bn::fixed x, bn::fixed y)
{
    const int slot = _find_slot_by_character(character);
    BN_ASSERT(slot >= 0,
              "smart_characters_manager::set_position: no live char with this tag");
    set_position(id_t::_from_index(slot), x, y);
}

void set_position(character_t character, bn::fixed x, bn::fixed y, int frames)
{
    const int slot = _find_slot_by_character(character);
    BN_ASSERT(slot >= 0,
              "smart_characters_manager::set_position(animated): "
              "no live char with this tag");
    set_position(id_t::_from_index(slot), x, y, frames);
}

void set_priority(character_t character, int priority)
{
    const int slot = _find_slot_by_character(character);
    BN_ASSERT(slot >= 0,
              "smart_characters_manager::set_priority: no live char with this tag");
    set_priority(id_t::_from_index(slot), priority);
}

void set_blending_enabled(character_t character, bool enabled)
{
    const int slot = _find_slot_by_character(character);
    if(slot < 0) return;  // dead/missing char — silently ignored, mirrors `destroy`
    set_blending_enabled(id_t::_from_index(slot), enabled);
}

void disable_blending_all()
{
    if(! g_initialized) return;

    // `_bucket_compatible` / `_try_find_existing_host` require the host BG's
    // `blending_enabled` to match the attaching character's flag. If we only
    // lower blending per character in slot-index order, BG slots whose tenants
    // appear *later* in the array still read blending=true — earlier characters
    // fail every merge and each allocates a fresh BG (extra maps until VRAM is
    // exhausted). Push every active slot + hw ptr to false *before* repacking.
    for(int i = 0; i < MAX_BGS; ++i)
    {
        bg_slot& bg = g_bgs[i];
        if(! bg.active) continue;
        bg.blending_enabled = false;
        if(bg.bg) bg.bg->set_blending_enabled(false);
    }

    // Sweep every alive character in one pass. The per-char path
    // (`set_blending_enabled`) detach/re-attaches so solo occupants collapse
    // back into shared BGs once the blending bucket key matches everyone.
    for(int i = 0; i < MAX_CHARS; ++i)
    {
        if(! g_chars[i].alive) continue;
        set_blending_enabled(id_t::_from_index(i), false);
    }

    // Defensive sweep: `_detach_and_mark` may leave rare ptr/state skew.
    for(int i = 0; i < MAX_BGS; ++i)
    {
        bg_slot& bg = g_bgs[i];
        if(! bg.active) continue;
        bg.blending_enabled = false;
        if(bg.bg) bg.bg->set_blending_enabled(false);
    }

    // Sprite layer: face sprites carry their own OBJ blending bit.
    for(int i = 0; i < MAX_CHARS; ++i)
    {
        char_state& ch = g_chars[i];
        if(ch.alive && ch.face) ch.face->set_blending_enabled(false);
    }
}

bn::fixed_point position(character_t character)
{
    const int slot = _find_slot_by_character(character);
    if(slot < 0) return bn::fixed_point(0, 0);
    return position(id_t::_from_index(slot));
}

const smart_characters::variant* variant_ptr(character_t character)
{
    const int slot = _find_slot_by_character(character);
    if(slot < 0) return nullptr;
    return variant_ptr(id_t::_from_index(slot));
}

void destroy_all()
{
    if(! g_initialized) return;
    for(int i = 0; i < MAX_CHARS; ++i)
    {
        if(g_chars[i].alive) destroy(id_t::_from_index(i));
    }
    // Defensive: every per-char `destroy` already releases when it
    // empties the slate, but call once more to handle the no-op
    // case (e.g. `destroy_all` on an already-empty manager between
    // scenes — keeps the post-condition simple).
    _release_shared_resources();
}

void evict_vram_for_backdrop()
{
    if(! g_initialized) return;
    if(! _any_char_alive()) return;

    // Tear down every physical BG slot and drop shared resources, but keep
    // logical characters alive so the next `commit()` can rebuild them in a
    // new VRAM layout (after the backdrop claims low blocks).
    for(int bg_idx = 0; bg_idx < MAX_BGS; ++bg_idx)
    {
        bg_slot& bg = g_bgs[bg_idx];
        if(! bg.active) continue;
        bg.bg.reset();
        bg.map.reset();
        bg.active = false;
        bg.dirty = false;
        bg.char_count = 0;
        for(int s = 0; s < MAX_CHARS; ++s) bg.char_indices[s] = -1;
    }

    for(int i = 0; i < MAX_CHARS; ++i)
    {
        char_state& ch = g_chars[i];
        if(! ch.alive) continue;
        ch.bg_idx = -1;
        ch.tile_off = -1;
        ch.tiles_dirty = true;
        if(ch.face) ch.face->set_visible(false);
    }

    g_shared_palette.reset();
    g_shared_tiles.reset();
    g_transparent_ready = false;
}

void set_palette_variant(palette_variant_t variant)
{
    g_palette_variant = variant;

    // Recolour the shared body palette in place. Every variant emitted by
    // the converter references `pal_char_bg`, so picking the first alive
    // char's palette item is sufficient to find the originals.
    const bn::bg_palette_item* pal_item = nullptr;
    for(int i = 0; i < MAX_CHARS; ++i)
    {
        if(g_chars[i].alive && g_chars[i].var)
        {
            pal_item = g_chars[i].var->body->tileset->palette;
            break;
        }
    }
    _apply_palette_variant_to_shared_bg(pal_item);

    // All face sprites share one OBJ palette — recolour it once.
    // Newly-created face sprites pick the variant up via
    // `_sync_face_sprites` (calls `_apply_palette_variant_to_faces`
    // again right after `release_build` to overwrite the just-loaded
    // defaults).
    _apply_palette_variant_to_faces();
}

palette_variant_t current_palette_variant()
{
    return g_palette_variant;
}

}  // namespace ks::smart_characters_manager
