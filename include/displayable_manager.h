#ifndef KS_DISPLAYABLE_MANAGER_H
#define KS_DISPLAYABLE_MANAGER_H

#include "bn_fixed.h"
#include "bn_optional.h"
#include "bn_regular_bg_ptr.h"

#include "definitions.h"
#include "displayable_meta.h"

namespace ks::displayable_manager {

inline constexpr int MAX_SLOTS = 1;

/// Regular BG layers reserved by active displayables (reduces smart-char budget).
[[nodiscard]] int reserved_bg_count();

/// How many physical BG slots smart_characters may use this frame.
[[nodiscard]] int smart_characters_bg_budget();

void init();
void destroy_all();

/// Logical show — VRAM is allocated in `commit()` (call before smart chars).
void show(const displayable_meta& meta, palette_variant_t palette_variant,
          bn::fixed xpos, bn::fixed xanchor, bn::fixed ypos, bn::fixed yanchor,
          int frame_index = 0, bool animate = true, int bg_priority = 2);

void hide();

/// Advance animation; call each frame from `SceneManager::update` (then `commit`).
void tick();

/// Create/destroy hardware BGs and apply palette. Call before
/// `smart_characters_manager::commit()`.
void commit();

/// Drain per-frame tile uploads (called from the shared V-Blank handler).
void process_pending_tile_uploads();

/// Tear down VRAM for backdrop work; `commit()` is a no-op until restored.
void evict_vram();

/// Allow `commit()` again after `update_visuals` finishes backdrop phases.
void restore_after_backdrop();

[[nodiscard]] bool is_active();

}  // namespace ks::displayable_manager

#endif  // KS_DISPLAYABLE_MANAGER_H
