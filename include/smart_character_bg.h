#ifndef KS_SMART_CHARACTER_BG_H
#define KS_SMART_CHARACTER_BG_H

/**
 * Smart character data — converter-emitted ROM descriptors.
 *
 * Hybrid BG + OBJ layout produced by tools/converter/.../smart_character_converter.py:
 *
 *   - The character *body* is a regular BG. One `body` is shared by every
 *     emotion in a (pose × outfit × close) group: the BG bitmap is rendered
 *     from the group's `base_emotion` PNG with the face cells stamped
 *     transparent. Body tiles are deduplicated across the whole tileset
 *     and split into ≤1024-tile slabs.
 *
 *   - The face emotion is a sprite (`bn::sprite_item`). One sprite per
 *     emotion, positioned by `face_offset_*_cells` to fill the body's
 *     transparent face hole. The sprite item lives in the artist
 *     pipeline's `graphics/sprites/` and is referenced by name
 *     (`bn::sprite_items::<character>_spr_*`).
 *
 * The runtime composes the two: the manager hosts the bodies in shared BGs
 * (with overlap-avoidance / bucket packing based on `body::vis_*`), and
 * each character carries its own `bn::sprite_ptr` for the current emotion.
 *
 * Switching emotions inside a group is a fast path: the body is identical,
 * so no BG tile re-upload, no map rewrite — only the face sprite item is
 * swapped.
 */

#include <cstdint>

#include "bn_bg_palette_item.h"
#include "bn_regular_bg_tiles_item.h"
#include "bn_sprite_tiles_item.h"

namespace ks::smart_characters {

/**
 * Shared ROM tileset for one tileset key (one or more characters whose
 * body BGs are deduplicated together, e.g. emi + emicas + eminude + emiwheel).
 *
 * The full tile set is stored across `slab_count` Butano `regular_bg_tiles_item`
 * objects, each holding up to 1024 visual tiles. `slabs` is a contiguous
 * pointer table the runtime indexes by `(global_index >> 10)`.
 */
struct tileset_data
{
    const bn::regular_bg_tiles_item* const* slabs;
    int                                     slab_count;
    const bn::bg_palette_item*              palette;
};

/// Number of tiles per slab (matches the BG hardware tile_id field width).
constexpr int tiles_per_slab = 1024;

/**
 * Per-group body BG descriptor stored in ROM.
 *
 * One `body` describes the shared BG for a whole (pose × outfit × close)
 * group: every emotion in that group references the same `body`, with the
 * face cells already stamped transparent so the runtime composites the
 * matching emotion sprite (`variant::face`) on top.
 *
 * `used_tiles[i]` is a *global* tile index into the shared tileset and is
 * decoded as `(slab, local) = (i >> 10, i & 0x3FF)` when copied into VRAM.
 *
 * `vis_x0..vis_y1` is the half-open cell bounding box of *non-transparent*
 * body cells inside `map`. The face cut-out cells are uniformly transparent
 * and therefore *not* part of the bbox — the manager uses this bbox to
 * pack multiple bodies into one regular BG without overlap.
 */
struct body
{
    const uint16_t*                       used_tiles;
    int                                   used_count;
    /// GBA BIOS-format RLE-compressed map (32×32 cells = 2048 raw bytes).
    /// Most cells are transparent (tile id 0 = pool slot 0 = global
    /// transparent), so the run-length-encoded stream typically lands
    /// well under 256 bytes per body. Decompressed by
    /// `bn::hw::decompress::rl_wram` (SWI 0x14) into a per-character
    /// EWRAM staging buffer on attach / variant change.
    /// Layout: 4-byte BIOS header (`0x30 | size_le24`) + flag-encoded
    /// payload, padded to a 4-byte boundary.
    const unsigned char*                  map_compressed;
    int                                   vis_x0;
    int                                   vis_x1;
    int                                   vis_y0;
    int                                   vis_y1;
    /// **Rendered displayable size** in BG-canvas pixels — the
    /// pose-stable analogue of `vis_x1 - vis_x0` / `vis_y1 - vis_y0`.
    ///
    /// `vis_*` is the *visible* bbox: it shrinks when the artist drew
    /// transparent margins (idle pose) and grows when they didn't
    /// (arms-out pose). Anchoring against `vis_*` therefore makes a
    /// character *jump* horizontally every time the user swaps poses
    /// inside the same `xpos / xanchor` transform — exactly the bug
    /// the converter side dodged by hard-coding `sprite_width = 128`.
    ///
    /// `render_*_px` is the size of the **rendered displayable** —
    /// the source PNG cropped to `(0, y_crop+y_offset)..(W, H+y_offset)`
    /// and scaled to a target height of 160 px (matching GBA screen
    /// height, see `ImageTools.resize_character_background` /
    /// `ImageTools.resize`). It only depends on the source PNG aspect
    /// ratio + `y_offset`, both of which are *per-group* metadata in
    /// the YAML — nothing to do with which cells happen to be
    /// transparent. Two poses of one character that share an artwork
    /// frame size therefore report the same `render_w_px`, the
    /// runtime resolves Ren'Py-style coordinates against the same
    /// width, and `xalign 1.03` lands the body's right edge at
    /// 103 % of the screen for *both* poses — body changes don't
    /// shift the on-screen anchor.
    ///
    /// Pixel-precise: `target_width = int(160 * source_w / cropped_h)`
    /// ranges roughly 80..130 px in practice. The body is pasted
    /// canvas-centred by `Image.paste`, so the displayable's centre
    /// coincides with the BG canvas centre — no per-body canvas
    /// offset needs to compensate.
    int                                   render_w_px;
    int                                   render_h_px;
    const tileset_data*                   tileset;
    /// 32×32 mini-portrait of the whole character body+face for save
    /// thumbnails. One thumbnail per (pose × outfit × close) group —
    /// emotion is intentionally *not* part of the asset because the
    /// 32×32 raster can't usefully discriminate emotions and the old
    /// pipeline made the same trade-off (so legacy save hashes still
    /// resolve, see `variant::hash`). Tiles only — paired at runtime
    /// with the shared `bn::sprite_palette_items::pal_char_obj`
    /// (sprite-typed clone of the BG palette the tiles were quantised
    /// against), so no per-thumbnail palette duplication.
    const bn::sprite_tiles_item*          thumbnail_tiles;
};

/**
 * Per-(group × emotion) variant: a body + face sprite pair plus the
 * cell-aligned face position on the BG canvas. The face cells (offset and
 * size) are constant across every variant inside a group — they're the
 * same hole the body BG was rendered with — but live on the variant for
 * convenience so the runtime can read them without dereferencing `body`.
 *
 * `hash` is a stable 16-bit identifier of the (pose × outfit × close)
 * group — it is identical for every variant inside one group. Save-game
 * thumbnails store this value at write time and resolve it back to a
 * face sprite via `ks::smart_characters::get_thumbnail_by_hash` on load.
 * The hash format mirrors the legacy `character_sprite_meta::hash`
 * (first 4 hex chars of `MD5("<char>_thumb_<pose>_<outfit>[_close]")`)
 * so previously written saves keep resolving.
 */
struct variant
{
    const ks::smart_characters::body*       body;
    /// Face OBJ tile data only (palette is the scene-wide
    /// `bn::sprite_palette_items::pal_char_obj` — same colours as
    /// `pal_char_bg`, just typed as a sprite palette). The runtime
    /// composes a `bn::sprite_item` on the fly from this pointer plus
    /// the face shape (derived from `face_size_*_cells`) and the
    /// shared palette. Eliminating ~256 B/face × ~400 faces of
    /// duplicated palette bytes shaved ~100 KB off the ROM.
    /// `nullptr` with zero `face_size_*_cells` means body-only
    const bn::sprite_tiles_item*            face_tiles;
    int                                     face_offset_x_cells;
    int                                     face_offset_y_cells;
    int                                     face_size_x_cells;
    int                                     face_size_y_cells;
    unsigned short                          hash;
};

}  // namespace ks::smart_characters

#endif  // KS_SMART_CHARACTER_BG_H
