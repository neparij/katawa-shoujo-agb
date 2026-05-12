#ifndef KS_SMART_CHARACTERS_MANAGER_H
#define KS_SMART_CHARACTERS_MANAGER_H

/**
 * Smart-character manager.
 *
 * The GBA has at most four regular BGs (and only ~two are usable in a typical
 * scene once a backdrop / blending is in play), but a Katawa scene may need
 * up to *six* characters on screen at once. This manager packs multiple
 * characters into a *single* regular BG when their on-screen layout allows
 * it.
 *
 * VRAM model
 * ----------
 * All characters share a *single*, fixed-size BG tile pool, allocated once
 * in `init()`. Per-BG `regular_bg_map_ptr`s reference this shared pool, so
 * tile VRAM is *never* reallocated at runtime — adding / changing /
 * removing characters just rewrites map cells and re-uploads tile data
 * into the shared pool. This avoids the BG-block fragmentation that would
 * otherwise hit us when several BGs are created or resized in quick
 * succession, and gives every character a stable place in VRAM regardless
 * of how many physical BGs the scene currently uses.
 *
 * Two characters can share a *physical* BG when:
 *   - they share the same `(x_int mod 8, y_int mod 8)` bucket — that
 *     bucket *is* the BG's screen position (in the 0..7 px range), so
 *     a single hardware scroll register places both characters,
 *   - their body cell bounding boxes (`body::vis_x0/x1/y0/y1`, snapped
 *     to the screen-centered 32×32 canvas) do not overlap.
 * (No per-BG tile budget — that's a global concern.)
 *
 * Character positions are integer-pixel: the fractional part of the
 * `bn::fixed` arguments is dropped (`right_shift_integer`). Sub-cell
 * smoothness only happens when the bucket itself moves, i.e. all
 * characters in a BG step together.
 *
 * Each character also owns one OBJ sprite for its current emotion (the
 * face cut-out area in the body BG). Same-group emotion swaps are
 * cheap: only the sprite item is replaced; the body stays put.
 *
 * Public API: opaque `id_t` handles for logical characters. The manager
 * owns the underlying Butano objects; clients only interact via handles.
 *
 * Lifecycle:
 *   ks::smart_characters_manager::init();
 *   auto a = ks::smart_characters_manager::create(akira_emotions[0], -90, 0);
 *   auto m = ks::smart_characters_manager::create(meiko_emotions[0], -30, 0);
 *   ks::smart_characters_manager::commit();    // first frame
 *   ks::smart_characters_manager::set_variant(a, akira_emotions[1]);
 *   ks::smart_characters_manager::set_position(m, +30, 0);
 *   ks::smart_characters_manager::commit();    // before each bn::core::update()
 *   ks::smart_characters_manager::destroy(a);
 */

#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_optional.h"

#include "definitions.h"          // character_t, palette_variant_t
#include "smart_character_bg.h"   // for ks::smart_characters::variant

namespace ks::smart_characters_manager {

/// Maximum number of *logical* characters that can exist simultaneously.
/// (One Katawa scene needs at most six concurrent speakers.)
inline constexpr int MAX_CHARS = 6;

/// Maximum number of *physical* regular BGs the manager may consume.
/// Set this to your scene's character-BG budget (i.e. 4 minus the BGs you
/// reserve for backdrops / blending). The hardware limit is 4. The
/// manager will aggressively re-merge sole-occupant BGs back into shared
/// hosts on every movement, so 3 is comfortable for a typical 4-speaker
/// scene as long as characters drift back to compatible buckets.
inline constexpr int MAX_BGS = 3;

inline constexpr int DEFAULT_BG_PRIORITY = 2;

/// Opaque handle to a character. Default-constructed handles are invalid.
class id_t
{
public:
    id_t() = default;

    [[nodiscard]] bool valid() const { return _idx >= 0; }

    /// Internal use by the manager only.
    [[nodiscard]] int _index() const { return _idx; }

    static id_t _from_index(int idx)
    {
        id_t r;
        r._idx = idx;
        return r;
    }

private:
    int _idx = -1;
};

/// One-time global setup: zero-initialises pools, installs the V-Blank
/// callback used for deferred tile uploads, and allocates the shared BG
/// tile pool that every character will live inside. Safe to call multiple
/// times (subsequent calls are no-ops).
void init();

/// Flush any pending changes that have been marked dirty since the last
/// call. Mutating ops (`create`, `destroy`, `set_variant`, `set_position`)
/// only update logical state — the actual map cell rewrites and V-Blank
/// tile-upload queueing happens here, batched at most once per BG / once
/// per character per call. Call this once per main-loop iteration, after
/// any batch of mutating calls and before the next `bn::core::update()`.
/// Without it the scene will still render, but the most recent changes
/// won't be visible.
void commit();

/// Advance one frame of running per-character animations (only smooth
/// position tweens for now — see `set_position(id, x, y, frames)`).
/// Each running animation steps its source `x`/`y` toward its target by
/// `1 / frames_remaining` of the remaining distance, applying the new
/// position via `set_position`. No-op if no animations are running.
/// Call once per rendered frame, *before* `commit()` so any geometry
/// changes from this tick get flushed in the same frame.
void tick();

/// Add a new character to the scene. Returns an invalid handle if all
/// `MAX_CHARS` slots are taken or no compatible BG can host the new
/// character.
///
/// `priority` is the GBA BG priority (0..2, lower = closer to viewer)
/// the character requests. Two characters can share a host BG only if
/// they request the same priority. Use this to layer some characters
/// behind others — e.g. `show muto behind shizu` becomes muto with
/// priority 1 alongside shizu/etc. with priority 0.
[[nodiscard]] id_t create(const smart_characters::variant& var,
                          bn::fixed x = 0, bn::fixed y = 0,
                          int priority = DEFAULT_BG_PRIORITY);

/// Remove a character. Frees its slot in the hosting BG; that BG is
/// destroyed entirely if it now has zero characters.
void destroy(id_t id);

/// Hot-swap the variant of an existing character. May trigger a re-pack of
/// the hosting BG (or a move to a different BG) if the new variant doesn't
/// fit alongside the others (overlap or VRAM exhaustion).
void set_variant(id_t id, const smart_characters::variant& var);

/// Move a character to a new on-screen position. The fractional part of
/// `x`/`y` is dropped — see the file header. May trigger a re-pack to
/// a different host BG if the new position changes bucket
/// (`(x_int mod 8, y_int mod 8)`) and the current host has roommates,
/// or if the new position overlaps another character's body bbox in
/// the same BG. A sole-occupant BG is re-bucketed in place: it follows
/// the character without churn.
void set_position(id_t id, bn::fixed x, bn::fixed y);

/// Smoothly move the character to (`target_x`, `target_y`) over the
/// next `frames` calls of `tick()` (one tick = one rendered frame).
/// `frames == 0` snaps instantly. The animation interpolates the integer
/// pixel position linearly: the body BG only repaints / the host BG only
/// re-buckets when the integer-pixel position actually ticks, so most
/// in-between frames are essentially free.
void set_position(id_t id, bn::fixed target_x, bn::fixed target_y, int frames);

[[nodiscard]] bn::fixed_point position(id_t id);

[[nodiscard]] const smart_characters::variant* variant_ptr(id_t id);

/// Set the BG priority of every BG that hosts at least one character.
/// Convenience for scenes where every character should sit at the same
/// depth — equivalent to calling `set_priority(id, priority)` for each
/// alive id.
void set_priority(int priority);

/// Re-set the priority of one character. May trigger a re-pack: the
/// char detaches from its current host BG (if its priority no longer
/// matches the host's) and re-attaches to a compatible BG with the new
/// priority (creating a new BG if none exists).
void set_priority(id_t id, int priority);

/// id_t-form mirror of `set_blending_enabled(character_t, bool)`.
/// See the `character_t` overload for behaviour.
void set_blending_enabled(id_t id, bool enabled);

// ---------------------------------------------------------------------------
// character_t-based API.
//
// Higher-level callers (the `SceneManager`, generated scenario code) refer
// to characters by their stable Ren'Py-derived `character_t` enum value.
// The manager keeps a `character_t -> id_t` mapping internally so callers
// don't have to track the opaque handles themselves. All mutating ops have
// a `character_t` overload below; behaviour matches the `id_t` version.
// ---------------------------------------------------------------------------

/// True if a live character with the given `character_t` exists.
[[nodiscard]] bool exists(character_t character);

/// Find the handle for a character. Returns an invalid `id_t` if no
/// character with that `character_t` is currently alive.
[[nodiscard]] id_t find(character_t character);

/// Create a character with a stable `character_t` tag. Asserts that no
/// other live character already uses this tag.
[[nodiscard]] id_t create(character_t character,
                          const smart_characters::variant& var,
                          bn::fixed x = 0, bn::fixed y = 0,
                          int priority = DEFAULT_BG_PRIORITY);

/// No-op if no character with this tag is alive.
void destroy(character_t character);

void set_variant(character_t character, const smart_characters::variant& var);
void set_position(character_t character, bn::fixed x, bn::fixed y);

/// Toggle alpha blending on a character's body BG + face sprite. Used
/// by the scene manager to drive show/hide fade transitions: the
/// caller raises the flag, then animates the global
/// `bn::blending::set_transparency_alpha`. Two characters with
/// different `blending_enabled` cannot share a host BG (the GBA
/// blending registers operate per-BG, not per-cell), so flipping the
/// flag may force a re-pack — equivalent to a priority change in
/// terms of cost. Lower the flag once the fade is done so the
/// character can be merged back into a shared host BG.
void set_blending_enabled(character_t character, bool enabled);

/// Force-disable alpha blending on every alive character (body BG +
/// face sprite + the underlying packer state). Used by the scene
/// manager at the tail end of a fade-in: the GBA only has *one*
/// global blending alpha register, so any BG that's still flagged
/// `blending_enabled = true` after the fade would be dragged into
/// the next blendable surface's animation (e.g. the dialog box's own
/// 0 → 0.85 fade-in). Cheaper than walking all of `character_t`
/// from the scene manager and idempotent: chars with blending
/// already off are skipped.
///
/// `commit()` afterwards to materialise any re-packing the flag
/// changes triggered.
void disable_blending_all();
void set_position(character_t character, bn::fixed x, bn::fixed y, int frames);
void set_priority(character_t character, int priority);

[[nodiscard]] bn::fixed_point position(character_t character);
[[nodiscard]] const smart_characters::variant* variant_ptr(character_t character);

/// Destroy every alive character at once. Releases every host BG.
/// Used by `SceneManager` on `set_background` with a transition / dissolve
/// (every char is logically gone) and by `free_resources` when the scene
/// shuts down.
void destroy_all();

/// Apply a `palette_variant_t` (night, sunset, rain, …) to every hosted
/// character at once. Bodies share a single BG palette in VRAM, so this
/// is a single-shader pass for them; face sprites each carry their own
/// OBJ palette and are recoloured individually.
///
/// The chosen variant is sticky: newly created characters and freshly
/// re-created face sprites will pick it up automatically until another
/// `set_palette_variant` call (or `destroy_all` + a fresh `init`) resets
/// the state.
void set_palette_variant(palette_variant_t variant);

/// Currently active palette variant (defaults to `PALETTE_VARIANT_DEFAULT`
/// after `init` / `destroy_all`).
[[nodiscard]] palette_variant_t current_palette_variant();

/// True if any character has a smooth-move tween in flight (i.e. its
/// position is not yet at the target requested by the most recent
/// `set_position(id, x, y, frames)` / `set_position(character, x, y, frames)`
/// call). Use this as the loop condition for a per-frame
/// `tick() + commit() + bn::core::update()` cycle when you need to
/// block on a move animation.
[[nodiscard]] bool is_animating();

/// Diagnostics: how many physical BGs are currently active.
[[nodiscard]] int active_bgs_count();

/// Diagnostics: combined working-set size (in 8bpp visual tiles) of every
/// character hosted by the *i*-th active BG.
[[nodiscard]] int active_bg_tile_count(int active_bg_index);

/// Diagnostics: total body tiles currently in use across the shared pool
/// (i.e. the sum of `body::used_count` over every alive character).
/// Face sprite tiles live in OBJ VRAM and are not counted here.
[[nodiscard]] int shared_pool_tile_count();

/// Diagnostics: the fixed capacity of the shared pool, in 8bpp visual tiles.
[[nodiscard]] int shared_pool_capacity();

/// Evict all smart-character BG VRAM state (shared tile pool + host BG maps)
/// while keeping the *logical* characters alive.
///
/// This is a backdrop-priority escape hatch: Butano's BG blocks manager is a
/// unified pool for tiles and maps. If the shared 8bpp pool is allocated
/// before a new backdrop is created, the backdrop may be forced into higher
/// blocks (or fail entirely) even though the scene would prefer the backdrop
/// to occupy the lowest VRAM range.
///
/// After calling this, the next `commit()` will lazily re-allocate the shared
/// pool and rebuild all character BGs in the new VRAM layout.
void evict_vram_for_backdrop();

}  // namespace ks::smart_characters_manager

#endif  // KS_SMART_CHARACTERS_MANAGER_H
