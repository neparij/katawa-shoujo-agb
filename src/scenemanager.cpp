#include "scenemanager.h"

#include <bn_regular_bg_items_kslogo_heart.h>
#include <bn_regular_bg_items_kslogo_words.h>
#include <bn_affine_bg_actions.h>
#include <bn_affine_bg_items_test_delayblinds.h>
#include <bn_affine_bg_items_test_eyes.h>
#include <bn_affine_bg_items_test_flashback.h>
#include <bn_affine_bg_items_test_handsdissolve.h>
#include <bn_affine_bg_items_test_dots_col.h>
#include <bn_affine_bg_items_test_clockwipe.h>
#include <bn_affine_bg_tiles_ptr.h>
#include <bn_bg_palette_ptr.h>
#include <bn_log.h>
#include <gba_systemcalls.h>
#include <gba_video.h>

#include "bn_bg_tiles.h"
#include "bn_bg_maps.h"

#include "bn_bg_palettes.h"
#include "bn_blending_actions.h"
#include "bn_blending_transparency_attributes.h"
#include "bn_blending_transparency_attributes_hbe_ptr.h"
#include "bn_core.h"
#include "bn_format.h"
#include "bn_memory.h"
#include "bn_regular_bg_actions.h"
#include "bn_regular_bg_item.h"
#include "bn_regular_bg_items_ui_backdrop_dots.h"
#include "bn_regular_bg_items_scene_black.h"
#include "bn_sprite_actions.h"
// #include "bn_sprite_items_ui_ingame_menu_ne.h"
// #include "bn_sprite_items_ui_ingame_menu_nw.h"
// #include "bn_sprite_items_ui_ingame_menu_se.h"
// #include "bn_sprite_items_ui_ingame_menu_sw.h"
#include "bn_sprite_palettes.h"
#include "globals.h"
#include "ingametimer.h"
#include "sound_manager.h"
#include "translation.h"
#include <video_4ls_ulcv.h>
#include "video_tc_act2_emi_ulcv.h"
#include "video_tc_act2_emi_ulcv.h"
#include "video_tc_act2_hanako_ulcv.h"
#include "video_tc_act2_lilly_ulcv.h"
#include "video_tc_act2_rin_ulcv.h"
#include "video_tc_act2_shizune_ulcv.h"


#include "bn_affine_bg_map_ptr.h"
#include "bn_sprite_palette_ptr.h"
#include "dialog_box.h"
#include "../../butano/butano/hw/include/bn_hw_irq.h"
#include "../../butano/butano/src/bn_bgs_manager.h"
#include "../../butano/butano/src/bn_display_manager.h"
#include "savefile/save_file.h"
#include "shaders/vram_dma_shader.h"
#include "smart_characters_manager.h"
#include "utils/lz77.h"
#include "utils/scenario_reader.h"
#include "videoplayer/video_player.h"

#include "menu/menu_ingame_pause.cpp.h"
#include "menu/menu_options.cpp.h"
#include "menu/menu_options_accessibility.cpp.h"
#include "menu/menu_saves.cpp.h"
#include "openings/act1.cpp.h"
#include "openings/act2_emi.cpp.h"
#include "openings/act2_hanako.cpp.h"
#include "openings/act2_lilly.cpp.h"
#include "openings/act2_rin.cpp.h"
#include "openings/act2_shizune.cpp.h"
#include "openings/act3_emi.cpp.h"
#include "openings/act3_hanako.cpp.h"
#include "openings/act3_lilly.cpp.h"
#include "openings/act3_rin.cpp.h"
#include "openings/act3_shizune.cpp.h"
#include "openings/act4_emi.cpp.h"
#include "openings/act4_hanako.cpp.h"
#include "openings/act4_lilly.cpp.h"
#include "openings/act4_rin.cpp.h"
#include "openings/act4_shizune.cpp.h"
#include "openings/op1.h"
#include "shaders/paletted_color_shader.h"
#include "sound/sound_mixer.h"
#include "utils/string_utils.h"

namespace ks {

BN_DATA_EWRAM bn::string<4096> message;
BN_DATA_EWRAM bn::string<128> message_doublespeak_a;
BN_DATA_EWRAM bn::string<128> message_doublespeak_b;
BN_DATA_EWRAM bn::vector<bn::string<128>, 5> answers_messages;

bn::optional<ks::SceneManager> scene;
bn::optional<bn::sprite_text_generator> text_generator;
bn::optional<bn::sprite_text_generator> text_generator_small;

BN_CODE_EWRAM dialog_box_default dialog_default = dialog_box_default(&message, text_generator);
BN_CODE_EWRAM dialog_box_doublespeak dialog_doublespeak = dialog_box_doublespeak(&message_doublespeak_a, &message_doublespeak_b, text_generator_small);
BN_CODE_EWRAM dialog_box_novel dialog_novel = dialog_box_novel(&message, text_generator);

bn::optional<huge_bg> huge_background;
bn::optional<bn::regular_bg_ptr> primary_background;
bn::optional<bn::regular_bg_ptr> secondary_background;
bn::optional<bn::affine_bg_ptr> transition_bg;
bn::optional<bn::color> fill_color;

bn::optional<bn::unique_ptr<CustomEvent>> next_event;
EWRAM_BSS bn::vector<character_visuals_ptr, smart_characters_manager::MAX_CHARS> character_visuals;
EWRAM_BSS background_visuals_ptr background_visual;

bn::rect_window left_window = bn::rect_window::external();
bn::rect_window right_window = bn::rect_window::internal();

EWRAM_BSS ks::saves::SaveSlotProgressData progress;
EWRAM_BSS ks::saves::SaveSlotProgressData savedata_progress;
bool in_replay = false;
bool is_loading = false;
bool is_paused = false;
bool is_returned_from_pause = false;
unsigned char savedata_answer_index = 0;

EWRAM_BSS bn::vector<bn::sprite_ptr, 18> progress_icon_sprites;
EWRAM_BSS bn::vector<bn::sprite_ptr, 64> static_text_sprites;
EWRAM_BSS bn::vector<bn::sprite_ptr, 128> animated_text_sprites;

// Forward-declare so the post-load materialisation in `set_line_hash`
// can reach it (the definition lives further down with the rest of the
// `show_character` family helpers).
static void _apply_smart_character(character_visuals_ptr& slot);

void SceneManager::free_resources() {
    BN_LOG("Free resources...");
    background_visual.active_event.reset();
    background_visual.bg_item.reset();
    background_visual.visible_bg_item.reset();
    background_visual.visible_fg_item.reset();
    huge_background.reset();
    primary_background.reset();
    secondary_background.reset();
    static_text_sprites.clear();
    animated_text_sprites.clear();
    progress_icon_sprites.clear();
    next_event.reset();

    // Tear down every smart-managed character (BG packs, OBJ faces, the
    // shared-pool slots they occupy). Subsequent `show_character` calls
    // will re-create them inside the same shared VRAM pool.
    smart_characters_manager::destroy_all();
    for (auto &visual : character_visuals) {
        visual.character        = CHARACTER_NONE;
        visual.variant_ptr      = nullptr;
        visual.variant_hash     = 0;
        visual.palette_variant  = PALETTE_VARIANT_DEFAULT;
        // Ren'Py default for sprite displayables in KS: centred
        // horizontally, bottom edge anchored to the screen bottom.
        visual.xpos             = bn::fixed(0.5);
        visual.xanchor          = bn::fixed(0.5);
        visual.ypos             = bn::fixed(1.0);
        visual.yanchor          = bn::fixed(1.0);
        visual.will_show        = false;
        visual.will_hide        = false;
    }
    character_visuals.clear();

    ks::textdb::free();
}

void SceneManager::set(const ks::SceneManager instance) {
    free_resources();
    while (character_visuals.size() < character_visuals.max_size()) {
        character_visuals.push_back(character_visuals_ptr());
    }

    // The shared BG tile pool, V-Blank upload queue, and EWRAM staging
    // arrays the smart-character system uses are allocated once here.
    // Idempotent — `init()` is a no-op on repeat calls.
    smart_characters_manager::init();

    BN_LOG("RESET SCENE");
    scene.reset();
    BN_LOG("Set SM Instance");
    scene = instance;

    BN_LOG("SceneManager init done!");
}

void SceneManager::set_textdb(const uint8_t *db) {
    textdb::set(db);
    if (!is_loading) {
        textdb::free();
        textdb::allocate();
    }
}

void SceneManager::reload_textdb() {
    set_textdb(textdb::get_chunk());
}

void SceneManager::init_savedata(ks::saves::SaveSlotProgressData &value) {
    if (!is_loading) {
        value.reproduction.answer_indices.fill(0);
        value.reproduction.line_hash = 0;
    }
    savedata_progress = value;
    savedata_answer_index = 0;
}

void SceneManager::set_script(const script_t script) {
    progress.metadata.script = script;
}

void SceneManager::set_label(const label_t label) {
    progress.metadata.label = label;
}

void SceneManager::set_line_hash(const unsigned int line_hash) {
    if (is_loading) {
        if (savedata_progress.reproduction.line_hash == line_hash || savedata_progress.reproduction.line_hash == 0) {
            is_loading = false;
            ks::sound_manager::restore_after_loading();
            sound_mixer::unmute();
            textdb::free();
            textdb::allocate();

            // Materialise every recorded character into the smart
            // manager *before* `update_visuals` runs. During the replay
            // we kept `show_character` / `set_character_position`
            // record-only (slot metadata only — no manager traffic) so
            // the MAX_CHARS pool wouldn't saturate. The first
            // `update_visuals` after load expects the manager state to
            // already mirror the slot state; otherwise it'd render an
            // empty scene for one frame, then on a *subsequent*
            // user-driven show_character the manager would finally pick
            // up the missing pieces — too late.
            //
            // No fade-in (legacy parity): loaded scenes pop in instant.
            // `_apply_smart_character` resolves the slot's Ren'Py-style
            // `xpos / xanchor / ypos / yanchor` against the variant's
            // body and creates the manager handle there directly; we
            // explicitly clear `will_show` so the SHOW CHARACTERS phase
            // below skips the alpha animation.
            for (auto& slot : character_visuals) {
                if (slot.character != CHARACTER_NONE && slot.variant_ptr != nullptr) {
                    _apply_smart_character(slot);
                    slot.will_show = false;
                    slot.will_hide = false;
                }
            }

            update_visuals();
        }
    }
    progress.reproduction.line_hash = line_hash;

    BN_LOG("Set line hash: ", string_utils::hashcode_to_string(line_hash));
}

void SceneManager::autosave() {
    if (is_loading) {
        return;
    }
    savedata_progress.metadata = progress.metadata;
    savedata_progress.reproduction = progress.reproduction;
    BN_LOG("Savedata progress linehash: ", savedata_progress.reproduction.line_hash);
    BN_LOG("Savedata progress answers count: ", savedata_progress.reproduction.answer_indices.size());
    ks::saves::writeAutosave(savedata_progress);
    save_states();
}

void SceneManager::save(const unsigned short slot_index) {
    savedata_progress.metadata = progress.metadata;
    savedata_progress.reproduction = progress.reproduction;
    BN_LOG("Savedata progress linehash: ", savedata_progress.reproduction.line_hash);
    BN_LOG("Savedata progress answers count: ", savedata_progress.reproduction.answer_indices.size());
    ks::saves::writeSaveSlot(slot_index, savedata_progress);
    save_states();
}

void SceneManager::save_states() {
    ks::saves::writeStates(globals::states);
}

void SceneManager::reset_backgrounds_visuals() {
    background_visual.bg_item.reset();
}

void SceneManager::set_background(const background_meta& bg, const int position_x, const int position_y, const scene_transition_t transition, const int dissolve_time, const palette_variant_t palette_variant) {
    next_event.reset();
    reset_backgrounds_visuals();

    if (bg.seen_bitmask != DISPLAYABLE_BITMASK_NONE && globals::in_game) {
        globals::states.set_seen_displayable(bg.seen_bitmask, true);
    }

    disable_fill();
    progress.metadata.thumbnail_hash = bg.hash;
    background_visual.bg_item = background_item(bg.bg);
    background_visual.position_x = position_x;
    background_visual.position_y = position_y;
    background_visual.dissolve_time = dissolve_time;
    background_visual.palette_variant = palette_variant;
    set_background_transition(transition);


    if (dissolve_time != 0 || transition != SCENE_TRANSITION_NONE) {
        // TODO: Check that we need to hide characters only on dissolves!
        for (const auto& visual : character_visuals) {
            if (visual.character != CHARACTER_NONE) {
                hide_character(visual.character, false, true);
            }
        }
    }
}

void SceneManager::set_huge_background(const huge_background_meta& bg, const int position_x, const int position_y, const scene_transition_t transition, const int dissolve_time, const palette_variant_t palette_variant) {
    // TODO: Check the duplicated code with set_background
    next_event.reset();
    reset_backgrounds_visuals();

    disable_fill();
    progress.metadata.thumbnail_hash = bg.hash;
    background_visual.bg_item = background_item(bg.bg);
    background_visual.position_x = position_x;
    background_visual.position_y = position_y;
    background_visual.dissolve_time = dissolve_time;
    background_visual.palette_variant = palette_variant;
    set_background_transition(transition);


    if (dissolve_time != 0 || transition != SCENE_TRANSITION_NONE) {
        // TODO: Check that we need to hide characters only on dissolves!
        for (const auto& visual : character_visuals) {
            if (visual.character != CHARACTER_NONE) {
                hide_character(visual.character, false, true);
            }
        }
    }
}

void SceneManager::hide_background(const scene_transition_t transition, const int dissolve_time) {
    reset_backgrounds_visuals();
    background_visual.palette_variant = PALETTE_VARIANT_DEFAULT;
    if (transition == SCENE_TRANSITION_LOCATIONCHANGE) {
        background_visual.transition = SCENE_TRANSITION_NONE;
        background_visual.dissolve_time = 60;
        return;
    }
    background_visual.transition = transition;
    background_visual.dissolve_time = dissolve_time;
}

void SceneManager::set_background_position(const int position_x, const int position_y) {
    background_visual.position_x = position_x;
    background_visual.position_y = position_y;
}

void SceneManager::set_background_transition(const scene_transition_t transition) {
    if (is_loading) {
        return;
    }
    if (transition == SCENE_TRANSITION_PASSOUTOP1) {
        hide_background(transition, 0);
        return;
    }
    if (transition == SCENE_TRANSITION_LOCATIONCHANGE) {
        background_visual.transition = SCENE_TRANSITION_NONE;
        background_visual.dissolve_time = 60;
        return;
    }
    if (transition == SCENE_TRANSITION_LOCATIONSKIP) {
        background_visual.dissolve_time = 30;
        background_visual.transition = SCENE_TRANSITION_NONE;
        return;
    }
    BN_LOG("SET BG TRANSITION [", transition, "]");
    background_visual.transition = transition;
}

void SceneManager::enable_fill(const bn::color color) {
    background_visual.fill_color = color;
}

void SceneManager::disable_fill() {
    background_visual.fill_color.reset();
}

void SceneManager::set_foreground(const vfx_meta& fg, const int position_x, const int position_y, const int dissolve_time) {
    reset_backgrounds_visuals(); // TODO: remove this line

    if (fg.seen_bitmask != DISPLAYABLE_BITMASK_NONE && globals::in_game) {
        globals::states.set_seen_displayable(fg.seen_bitmask, true);
    }

    // TODO: Support foregrounds (currently using in gallery only for items)
    background_visual.bg_item = background_item(fg.bg);
    background_visual.position_x = position_x;
    background_visual.position_y = position_y;
    background_visual.dissolve_time = dissolve_time;
}

void SceneManager::hide_foreground(const int dissolve_time) {
    // TODO: Support foregrounds (currently using in gallery only for items)
    reset_backgrounds_visuals();
    background_visual.dissolve_time = dissolve_time;
    background_visual.palette_variant = PALETTE_VARIANT_DEFAULT;
}

inline void SceneManager::process_menu_states(const gameState_t &state) {
    switch (state) {
        case GS_GAME_MENU:
            ks::MenuIngamePause().run();
            break;
        case GS_GAME_MENU_SAVES:
            ks::MenuSaves().run();
            break;
        case GS_GAME_MENU_OPTIONS:
            ks::MenuOptions().run();
            break;
        case GS_GAME_MENU_OPTIONS_ACCESSIBILITY:
            ks::MenuOptionsAccessibility().run();
            break;
        default:
            BN_ERROR("Wrong state: ", ks::globals::state);
    }
}


void SceneManager::set_event(const background_meta& bg, const CustomEvent& event, const scene_transition_t transition, const int dissolve_time) {
    set_background(bg, 0, 0, transition, dissolve_time, PALETTE_VARIANT_DEFAULT);
    for (const auto& visual : character_visuals) {
        if (visual.character != CHARACTER_NONE) {
            hide_character(visual.character, false, true);
        }
    }

    next_event = event.create();
}

void SceneManager::set_event(const huge_background_meta& bg, const CustomEvent& event, const scene_transition_t transition, const int dissolve_time) {
    set_huge_background(bg, 0, 0, transition, dissolve_time, PALETTE_VARIANT_DEFAULT);
    for (const auto& visual : character_visuals) {
        if (visual.character != CHARACTER_NONE) {
            hide_character(visual.character, false, true);
        }
    }
    next_event = event.create();
}

void SceneManager::set_event_state(const int state) {
    BN_ASSERT(background_visual.active_event.has_value(), "No active event to set state");
    (*background_visual.active_event)->set_state(state);
}

void SceneManager::show_dialog(const character_definition& actor, const unsigned int tl_key) {
    if (is_loading) {
        return;
    }

    while (!ks::globals::exit_scenario) {
        if (globals::state == GS_GAME) {
            ks::textdb::get_tl(tl_key, message);
            dialog_default.set_actor(actor);
            dialog_default.proceed_message();

            dialog_novel.hide(true);
            dialog_doublespeak.hide(true);
            dialog_default.show(true);

            while (!dialog_default.is_finished() && !bn::keypad::start_pressed()) {
                dialog_default.update();
                ks::globals::main_update();
            }

            if (bn::keypad::start_pressed()) {
                globals::state = GS_GAME_MENU;
                is_paused = true;
                update_visuals();
            }
        } else {
            process_menu_states(globals::state);
        }
        if (dialog_default.is_finished()) {
            break;
        }
    }
}

void SceneManager::show_dialog(const unsigned int actor_tl_key, const unsigned int tl_key) {
    // TODO: Fix the bug with language change with custom actor name
    if (is_loading) {
        return;
    }
    bn::string<64> char_name;
    textdb::get_tl(actor_tl_key, char_name);
    const character_definition current = definitions::base.with_name(char_name.c_str());
    return show_dialog(current, tl_key);
}

void SceneManager::show_doublespeak(const character_definition &actor_left, unsigned int tl_key_left, const character_definition &actor_right, unsigned int tl_key_right) {
    if (is_loading) {
        return;
    }

    while (!ks::globals::exit_scenario) {
        if (globals::state ==  GS_GAME) {
            ks::textdb::get_tl(tl_key_left, message_doublespeak_a);
            ks::textdb::get_tl(tl_key_right, message_doublespeak_b);

            dialog_doublespeak.set_actors(actor_left, actor_right);
            dialog_doublespeak.proceed_messages();

            dialog_novel.hide(true);
            dialog_default.hide(true);
            dialog_doublespeak.show(true);

            while (!dialog_doublespeak.is_finished() && !bn::keypad::start_pressed()) {
                dialog_doublespeak.update();
                ks::globals::main_update();
            }

            if (bn::keypad::start_pressed()) {
                globals::state = GS_GAME_MENU;
                is_paused = true;
                update_visuals();
            }
        } else {
            process_menu_states(globals::state);
        }
        if (dialog_doublespeak.is_finished()) {
            break;
        }
    }
}

void SceneManager::show_dialog_question(const bn::vector<ks::answer_ptr, 5>& answers) {
    if (is_loading) {
        return;
    }

    bool redisplay_dialog = false;  // Prevents re-showing dialog unnecessarily

    while (!ks::globals::exit_scenario) {
        if (globals::state == GS_GAME) {
            // Phase 1: Redisplay the dialog box with the message (optional)
            if (redisplay_dialog) {
                dialog_default.show(true);
                while (!dialog_default.is_finished() && !bn::keypad::start_pressed()) {
                    dialog_default.update();
                    globals::main_update();
                }
            }

            // Phase 2: Display the question dialog
            answers_messages.clear();
            for (const auto& answer : answers) {
                answers_messages.push_back(bn::string<128>(""));
                textdb::get_tl(answer.tl_key, answers_messages.back());
            }
            dialog_default.show_answers(answers_messages);

            while (!dialog_default.is_finished() && !bn::keypad::start_pressed()) {
                dialog_default.update();
                globals::main_update();
            }
            dialog_default.reset_answers();

            if (bn::keypad::start_pressed()) {
                redisplay_dialog = true;
                globals::state = GS_GAME_MENU;
                is_paused = true;
                update_visuals();
            }
        } else {
            process_menu_states(globals::state);
        }
        if (dialog_default.is_finished()) {
            break;
        }
    }
}

int SceneManager::get_dialog_question_answer() {
    if (is_loading) {
        return savedata_progress.reproduction.answer_indices.at(savedata_answer_index++);
    }
    const unsigned char answer = dialog_default.get_answer_index();
    progress.reproduction.answer_indices[savedata_answer_index++] = answer;
    return answer;
}

void SceneManager::nvl_clear() {
    dialog_novel.clear_messages();
}

void SceneManager::nvl_hide() {
    if (is_loading) {
        return;
    }
    dialog_novel.hide(true);
}

void SceneManager::nvl_show(const unsigned int tl_key) {
    if (is_loading) {
        return;
    }

    dialog_novel.add_tl_key(tl_key);

    while (!ks::globals::exit_scenario) {
        if (globals::state == GS_GAME) {
            if(smart_characters_manager::active_bgs_count() > 0)
            {
                smart_characters_manager::evict_vram_for_backdrop();
            }
            dialog_default.hide(true);
            dialog_doublespeak.hide(true);
            dialog_novel.show(true);

            while (!dialog_novel.is_finished() && !bn::keypad::start_pressed()) {
                dialog_novel.update();
                ks::globals::main_update();
            }

            if (bn::keypad::start_pressed()) {
                globals::state = GS_GAME_MENU;
                is_paused = true;
                update_visuals();
            }
        } else {
            process_menu_states(globals::state);
        }
        if (dialog_novel.is_finished()) {
            break;
        }
    }
}

// Smooth-move duration applied by `set_character_position`. Mirrors the
// 20-frame tween used by the previous `regular_bg_move_to_action`-based
// pipeline so the on-screen feel matches the old build.
namespace {
constexpr int SMART_CHARACTER_MOVE_FRAMES = 20;

// Ren'Py-style position → smart-manager pixel offset.
//
// Inputs are normalised (0..1):
//   xpos / ypos       — fraction of *screen* size, where the anchor lands.
//   xanchor / yanchor — fraction of the *displayable's own* size,
//                       picking which point on the body lines up with
//                       `xpos / ypos`.
//
// Output is the screen-centre-relative pixel offset that
// `smart_characters_manager::create / set_position` accepts: a value
// of (0,0) means the body's *displayable* centre coincides with the
// screen centre. The body's displayable is the rendered, scaled source
// PNG before any face-cutout / transparent-margin stripping — see
// `body::render_w_px` / `render_h_px` for the precise definition and
// the converter side that emits them.
//
// Why `render_*_px` instead of `vis_x*`:
//
//   The visible bbox shifts by several pixels when the artist swaps
//   poses (idle pose → arms-out pose), and back when re-emoting. Using
//   it as the displayable width meant the runtime resolved the same
//   `xpos / xanchor` to *different* pixel positions across pose
//   changes — characters jumped sideways every time you tweaked an
//   emotion, and `set_position` then re-bucketed the BG slot, which
//   re-uploads tiles and produces a one-frame body/face desync flicker.
//   `render_*_px` is computed from the source PNG dimensions and the
//   converter's scale factor, both of which are pose-stable, so every
//   variant in the same group resolves identically — and across poses
//   for the same character they're typically identical too (same source
//   PNG aspect ratio, same `y_offset`).
//
// Why no per-body canvas-offset subtraction:
//
//   The converter pastes the rendered displayable canvas-centred onto
//   the 256×256 BG canvas, so the displayable's centre coincides
//   exactly with the canvas centre by construction. There's nothing to
//   compensate for — the manager position is the screen offset of the
//   displayable centre, full stop.
//
// Math (x axis; y is symmetric):
//
//   manager_position_px = (xpos - 0.5) * SCREEN_W
//                       + (0.5 - xanchor) * body.render_w_px
//
// Worked examples for `xpos = xanchor = 1.03` (Ren'Py `xalign 1.03`)
// against a `render_w_px = 96` body:
//
//   = (1.03 - 0.5) * 240 + (0.5 - 1.03) * 96
//   = 127.2          + (-50.88)
//   = 76 px right of screen centre — body's right edge sticks 3 % of
//     screen width past the right edge, regardless of which emotion /
//     pose is currently rendered.
constexpr int SCREEN_W_PX = 240;
constexpr int SCREEN_H_PX = 160;
struct pixel_position { int x; int y; };

static pixel_position _resolve_pixel_position(
    const ks::smart_characters::variant& var,
    const bn::fixed xpos, const bn::fixed xanchor,
    const bn::fixed ypos, const bn::fixed yanchor) {
    const ks::smart_characters::body& body = *var.body;
    const bn::fixed displayable_centre_x =
        (xpos - bn::fixed(0.5)) * SCREEN_W_PX
        + (bn::fixed(0.5) - xanchor) * body.render_w_px;
    const bn::fixed displayable_centre_y =
        (ypos - bn::fixed(0.5)) * SCREEN_H_PX
        + (bn::fixed(0.5) - yanchor) * body.render_h_px;


    // return pixel_position{
    //     displayable_centre_x.right_shift_integer(),
    //     displayable_centre_y.right_shift_integer(),
    // };
    // TODO: Check.

    // // Use Snapped to 8 px positions. Use bitshift.
    // return pixel_position{
    //     displayable_centre_x.right_shift_integer() & ~7,
    //     displayable_centre_y.right_shift_integer() & ~7,
    // };

    // Use Snapped to 8 px positions. Use rounding.
    return pixel_position{
        (displayable_centre_x.division(8).round_integer() * 8),
        (displayable_centre_y.division(8).round_integer() * 8),
    };
}

// Save-thumbnail x-offset packs the resolved pixel position into a
// `short` divided by 5 (legacy format — preserved verbatim so old saves
// keep round-tripping). Inline so call sites stay readable.
static inline short _thumb_offset_x(const pixel_position& px) {
    return static_cast<short>(px.x / 5);
}
}  // namespace

// Internal helper: apply the slot's current state to the smart manager
// (create-or-set_variant + set_position + scene-wide palette variant).
// The actual VRAM work happens later inside `update_visuals` via
// `smart_characters_manager::commit()`. Idempotent: calling it twice in
// a row (e.g. show + show same emotion) is a no-op for the manager.
static void _apply_smart_character(character_visuals_ptr& slot) {
    if (slot.character == CHARACTER_NONE || !slot.variant_ptr) return;

    if (smart_characters_manager::current_palette_variant() != slot.palette_variant) {
        smart_characters_manager::set_palette_variant(slot.palette_variant);
    }

    // Resolve Ren'Py-style coords *now*, against the variant about to be
    // applied — a same-call body change (different group, different
    // visible width) will re-anchor automatically. Snapping here is
    // intentional: this helper runs from `show_character`, where the
    // user's expectation is "go to this pose, at this position, this
    // frame".
    const pixel_position px = _resolve_pixel_position(*slot.variant_ptr,
                                                       slot.xpos, slot.xanchor,
                                                       slot.ypos, slot.yanchor);
    if (smart_characters_manager::exists(slot.character)) {
        smart_characters_manager::set_variant(slot.character, *slot.variant_ptr);
        // No smooth-move on an emotion-only show — instant snap. Scenario
        // writers express moves separately via `set_character_position`.
        smart_characters_manager::set_position(slot.character,
                                               bn::fixed(px.x),
                                               bn::fixed(px.y));
    } else {
        // First-time show: priority DEFAULT_BG_PRIORITY = back layer. `behind <other>`
        // overrides this elsewhere (not yet wired into the writer).
        smart_characters_manager::create(slot.character,
                                         *slot.variant_ptr,
                                         bn::fixed(px.x),
                                         bn::fixed(px.y));
    }
}

void SceneManager::show_character(const character_t character,
                                  const ks::smart_characters::variant& var,
                                  const palette_variant_t palette_variant,
                                  const bn::fixed xpos,
                                  const bn::fixed xanchor,
                                  const bn::fixed ypos,
                                  const bn::fixed yanchor) {
    BN_LOG("Show character: ", character,
           " xpos: ", xpos, " xanchor: ", xanchor,
           " ypos: ", ypos, " yanchor: ", yanchor);
    const auto character_index = get_character_visual_index(character, true);

    auto& slot = character_visuals.at(character_index);

    // Loading replay: record-only path. The fast scenario fast-forward
    // calls `show_character` / `hide_character` thousands of times on
    // the way to the saved line — touching the smart manager here would
    // pile up create/destroy traffic with no `update_visuals` to drain
    // it (loading suppresses the function), eventually overflowing the
    // `MAX_CHARS` slot pool with manager handles that no `commit()` ever
    // sees. We just track the *target* slot state; the post-load
    // materialisation pass (driven from `set_line_hash` when
    // `is_loading` flips false) walks every alive slot and creates the
    // matching manager handle in one shot, with no fade.
    if (is_loading) {
        slot.character        = character;
        slot.variant_ptr      = &var;
        slot.variant_hash     = var.hash;
        slot.palette_variant  = palette_variant;
        slot.xpos             = xpos;
        slot.xanchor          = xanchor;
        slot.ypos             = ypos;
        slot.yanchor          = yanchor;
        slot.will_show        = false;
        slot.will_hide        = false;
        progress.metadata.thumbnail_characters[character_index].thumbnail_hash = var.hash;
        progress.metadata.thumbnail_characters[character_index].offset_x =
            _thumb_offset_x(_resolve_pixel_position(var, xpos, xanchor, ypos, yanchor));
        return;
    }

    // Only the *first visual* show of a slot triggers the alpha fade-in.
    // Pose / emotion swaps (character already alive) are instantaneous,
    // matching the old pipeline where re-show on an existing slot only
    // swapped `bg_item` / `sprite_item` without re-blending.
    //
    // `variant_ptr == nullptr` is the canonical "not yet visually shown"
    // marker: it covers both the cold path (slot fresh, character was
    // CHARACTER_NONE) and the phantom path (slot pre-allocated by an
    // earlier `set_character_position` — character already set, but the
    // manager has no live handle yet). Keying off `slot.character`
    // alone would silently swallow the fade-in for the phantom case.
    const bool was_new = (slot.variant_ptr == nullptr);
    slot.character        = character;
    // Below: variant_ptr will be assigned, so `was_new` is captured first.
    slot.variant_ptr      = &var;
    slot.variant_hash     = var.hash;
    slot.palette_variant  = palette_variant;
    slot.xpos             = xpos;
    slot.xanchor          = xanchor;
    slot.ypos             = ypos;
    slot.yanchor          = yanchor;
    // Sticky latch: once raised by a first-show this frame, a follow-up
    // `show_character` (e.g. emotion swap on the same slot before
    // `update_visuals` runs) must NOT lower it — the SHOW CHARACTERS
    // phase is the sole consumer that clears `will_show` after the
    // fade-in plays. Overwriting unconditionally would silently drop
    // the fade in `show A; show A_smile; update_visuals` patterns.
    if (was_new) slot.will_show = true;
    slot.will_hide        = false;

    // Apply immediately so a follow-up `set_character_position` sees a
    // live manager handle (Ren'Py emits position transforms on the line
    // *after* the `show`, between which there is no `update_visuals`).
    _apply_smart_character(slot);

    // Fresh character — raise the BG blending flag so `update_visuals`
    // can drive the global alpha register against it (alpha 0 -> 1) on
    // the next pass. The packer treats `blending_enabled` as another
    // bucket key, so this isolates the new char on its own host BG (or
    // co-locates it with another fresh char) for the duration of the
    // fade. The fade-out phase below lowers the flag again, allowing
    // the char to merge back into a shared BG.
    if (was_new) {
        smart_characters_manager::set_blending_enabled(character, true);
    }

    progress.metadata.thumbnail_characters[character_index].thumbnail_hash = var.hash;
    progress.metadata.thumbnail_characters[character_index].offset_x =
        _thumb_offset_x(_resolve_pixel_position(var, xpos, xanchor, ypos, yanchor));
}

void SceneManager::show_character(const character_t character,
                                  const ks::smart_characters::variant& var,
                                  const palette_variant_t palette_variant) {
    BN_LOG("Show character: ", character, " (no position change)");
    const auto character_index = get_character_visual_index(character, true);

    auto& slot = character_visuals.at(character_index);

    // Loading replay: record-only path (see the positioned overload's
    // comment for the full reasoning). Keep slot metadata current so
    // post-load materialisation can recreate the live handle.
    if (is_loading) {
        slot.character        = character;
        slot.variant_ptr      = &var;
        slot.variant_hash     = var.hash;
        slot.palette_variant  = palette_variant;
        slot.will_show        = false;
        slot.will_hide        = false;
        progress.metadata.thumbnail_characters[character_index].thumbnail_hash = var.hash;
        progress.metadata.thumbnail_characters[character_index].offset_x =
            _thumb_offset_x(_resolve_pixel_position(var,
                                                   slot.xpos, slot.xanchor,
                                                   slot.ypos, slot.yanchor));
        return;
    }

    // Same `variant_ptr == nullptr` rule as the positioned overload —
    // see the comment there. Keys "first visual show" off the manager
    // handle, not the slot reservation, so a phantom slot pre-allocated
    // by `set_character_position` keeps its position on this show.
    //
    // No explicit position reset here: the HIDE CHARACTERS cleanup
    // already restores the Ren'Py default `(0.5, 0.5, 1.0, 1.0)` when a
    // slot is torn down, so a fresh slot lands centre-bottom by
    // default, and a phantom slot keeps the position the writer set via
    // `set_character_position`.
    const bool is_first_show = (slot.variant_ptr == nullptr);
    slot.character        = character;
    slot.variant_ptr      = &var;
    slot.variant_hash     = var.hash;
    slot.palette_variant  = palette_variant;
    // First *visual* show triggers the alpha fade-in just like the
    // positioned overload. Sticky latch: only ever raised here, only
    // ever lowered by the SHOW CHARACTERS phase — same reasoning as
    // the positioned overload above.
    if (is_first_show) slot.will_show = true;
    slot.will_hide        = false;

    _apply_smart_character(slot);

    // Mirror the positioned overload: raise the BG blending flag for a
    // freshly-materialised character so `update_visuals`'s SHOW phase
    // can drive the global alpha register against it. Without this the
    // `will_show` latch is a no-op (the alpha animation runs but no BG
    // is enrolled to render it visually).
    if (is_first_show) {
        smart_characters_manager::set_blending_enabled(character, true);
    }

    progress.metadata.thumbnail_characters[character_index].thumbnail_hash = var.hash;
    progress.metadata.thumbnail_characters[character_index].offset_x =
        _thumb_offset_x(_resolve_pixel_position(var,
                                               slot.xpos, slot.xanchor,
                                               slot.ypos, slot.yanchor));
}

void SceneManager::set_character_position(const character_t character,
                                          const bn::fixed xpos,
                                          const bn::fixed xanchor,
                                          const bn::fixed ypos,
                                          const bn::fixed yanchor) {
    BN_LOG("Set character position: ", character,
           " xpos: ", xpos, " xanchor: ", xanchor,
           " ypos: ", ypos, " yanchor: ", yanchor);
    // Pre-allocate the slot if this is the first reference to `character`.
    // Ren'Py-style scripts can emit `xpos/ypos <char>` *before* `show <char>`
    // (the writer keeps transforms attached to the character regardless of
    // visibility); without create_if_not_found=true that path errored out
    // at `get_character_visual_index`. The slot stays in "phantom" state
    // (variant_ptr == nullptr → `_apply_smart_character` short-circuits)
    // until a subsequent `show_character` materialises it; on that show
    // `was_new` is keyed off `variant_ptr == nullptr`, so the fade-in
    // still triggers for the *visual* first-show even though the slot
    // was logically reserved earlier.
    const auto character_index = get_character_visual_index(character, true);

    auto& slot = character_visuals.at(character_index);
    if (slot.character == CHARACTER_NONE) {
        slot.character = character;
    }
    slot.xpos    = xpos;
    slot.xanchor = xanchor;
    slot.ypos    = ypos;
    slot.yanchor = yanchor;

    // Save thumbnail mirror only updates when we have a body to resolve
    // against; phantom slots (no variant yet) defer this to the
    // upcoming `show_character`.
    if (slot.variant_ptr) {
        progress.metadata.thumbnail_characters[character_index].offset_x =
            _thumb_offset_x(_resolve_pixel_position(*slot.variant_ptr,
                                                   xpos, xanchor, ypos, yanchor));
    }

    // Loading replay: the manager has no live handle for this character
    // (we kept `show_character` record-only). Just store the position on
    // the slot — post-load materialisation will create the handle at
    // these coordinates. Falling through to the `exists()` branch is
    // also safe (it would short-circuit to false), but bailing here
    // skips a redundant lookup and makes the contract explicit.
    if (is_loading) {
        return;
    }

    // Two cases here, both Ren'Py-driven:
    //
    //  (a) Same-block `show_character` + transforms (`will_show == true`):
    //      the handle exists at the pose's initial slot position; the
    //      writer's `xpos`/`ypos` lines may target a different pixel rect.
    //      Run the same 20-frame smooth move as the SHOW fade-in so
    //      movement and alpha blend happen together (Ren'Py / original KS).
    //      The SHOW CHARACTERS loop calls `tick`+`commit` each frame
    //      alongside the global alpha ramp.
    //
    //  (b) Already-visible moves: same tween; ticks run in the SHOW fade
    //      loop when any `will_show` char is active, otherwise in the
    //      tail `while (is_animating)` loop in `update_visuals`.
    //
    // Phantom slots (`set_character_position` *before* `show_character`):
    // `exists() == false` — only the slot is updated until
    // `show_character`'s `_apply_smart_character` creates the handle at
    // the stored coordinates.
    if (smart_characters_manager::exists(character) && slot.variant_ptr) {
        const pixel_position px =
            _resolve_pixel_position(*slot.variant_ptr,
                                    xpos, xanchor, ypos, yanchor);
        smart_characters_manager::set_position(character,
                                               bn::fixed(px.x),
                                               bn::fixed(px.y),
                                               SMART_CHARACTER_MOVE_FRAMES);
    }
}

void SceneManager::hide_character(const character_t character, const bool need_update, const bool remove) {
    BN_LOG("Hide character : ", character);
    const auto character_index = get_character_visual_index(character, false);
    if (character_index < 0) {
        return;  // unknown character — was never shown, nothing to do
    }

    if (remove) {
        progress.metadata.thumbnail_characters[character_index].thumbnail_hash = 0;
        progress.metadata.thumbnail_characters[character_index].offset_x = 0;
    }

    auto& slot = character_visuals.at(character_index);
    if (slot.character == CHARACTER_NONE) {
        return;  // already hidden — nothing to fade out
    }

    // Loading replay: the manager has no live handle, so there is no
    // fade-out to schedule and no `destroy` to defer. Just *fully*
    // release the slot so a later `show_character` (in the same replay
    // pass) for a different character can land in this index. Without
    // this clear, the slot pool would saturate at MAX_CHARS while the
    // replay walks tens of show/hide pairs on the path to the target
    // line — eventually tripping `Maximum displayable characters
    // exceeded` even though the *target* state has just one character.
    if (is_loading) {
        slot.character        = CHARACTER_NONE;
        slot.variant_ptr      = nullptr;
        slot.variant_hash     = 0;
        slot.palette_variant  = PALETTE_VARIANT_DEFAULT;
        slot.xpos             = bn::fixed(0.5);
        slot.xanchor          = bn::fixed(0.5);
        slot.ypos             = bn::fixed(1.0);
        slot.yanchor          = bn::fixed(1.0);
        slot.will_show        = false;
        slot.will_hide        = false;
        return;
    }

    // Defer the manager `destroy` *and* the BG blending flag to
    // `update_visuals`'s HIDE CHARACTERS phase. We must NOT raise
    // `set_blending_enabled(true)` here: between this `hide_character`
    // call and the HIDE CHARACTERS fade, `update_visuals` first runs
    // its HIDE DIALOGS block — `dialog.hide(true)` drives the global
    // alpha register from 0.85 down to 0 over 10 frames. The GBA has
    // one and only one alpha register, so any BG flagged
    // `blending_enabled = true` at that point gets fade-pulled along
    // with the dialog, *and then* the HIDE CHARACTERS phase fades it
    // again 1 → 0. The user-visible artefact is "characters fade to
    // zero twice in a row, locked to the dialog".
    //
    // Strict state machine: chars stay blending=false right up until
    // the moment HIDE CHARACTERS owns the alpha register, which is
    // where the flag is finally raised. The packer is free to keep
    // them merged into a shared (blending=false) host BG until that
    // point — exactly mirroring the legacy pipeline.
    slot.will_show = false;
    slot.will_hide = true;

    if (need_update && !is_loading) {
        ks::globals::main_update();
    }
}

void SceneManager::hide_character(const character_t character) {
    hide_character(character, true, true);
}

void SceneManager::perform_transition(const scene_transition_t transition, const bn::optional<background_item>& to) {
    bn::blending::set_transparency_alpha(1.0);
    // while (!bn::keypad::start_pressed()) {
    //     bn::core::update();
    // }
    if (transition == SCENE_TRANSITION_PASSOUTOP1) {
        transition_fadeout(bn::affine_bg_items::test_flashback, 1,  false);
        return;
    }
    if (transition == SCENE_TRANSITION_FLASHBACK) {
        // TODO: Correct version of flashback transition
        if (to.has_value()) {
            BN_LOG("TO: HAS VALUE");
            background_visual.visible_bg_item.reset();
            ks::globals::main_update();
            background_visual.visible_bg_item = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
            background_visual.visible_bg_item->set_priority(3);
            background_visual.visible_bg_item->set_z_order(10);
            apply_palette_variant(background_visual.visible_bg_item.value(), background_visual.bg_item->palette_item().colors_ref(), background_visual.palette_variant);
            if (next_event.has_value()) {
                (*next_event)->init();
            }
        }
        transition_fadein(bn::affine_bg_items::test_flashback, 1,  false);
        return;
    }
    if (transition == SCENE_TRANSITION_SHUTEYE || transition == SCENE_TRANSITION_SHUTEYEFAST) {
        transition_fadeout(bn::affine_bg_items::test_eyes, transition == SCENE_TRANSITION_SHUTEYE ? 2 : 20,  false);
        // background_visual.bg_item.reset();
        background_visual.visible_bg_item.reset();
        return;
    }
    if (transition == SCENE_TRANSITION_OPENEYE || transition == SCENE_TRANSITION_OPENEYEFAST || transition == SCENE_TRANSITION_OPENEYE_SHOCK) {
        if (to.has_value()) {
            BN_LOG("TO: HAS VALUE");
            background_visual.visible_bg_item.reset();
            ks::globals::main_update();
            background_visual.visible_bg_item = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
            background_visual.visible_bg_item->set_priority(3);
            background_visual.visible_bg_item->set_z_order(10);
            apply_palette_variant(background_visual.visible_bg_item.value(), background_visual.bg_item->palette_item().colors_ref(), background_visual.palette_variant);
            if (next_event.has_value()) {
                (*next_event)->init();
            }
        }
        // Default: 2.0 sec
        int transition_speed = 2;
        if (transition == SCENE_TRANSITION_OPENEYEFAST) {
            // fast: 0.5 sec
            transition_speed = 8;
        } else if (transition == SCENE_TRANSITION_OPENEYE_SHOCK) {
            // shock: 0.8 sec
            transition_speed = 12;
        }
        transition_fadein(bn::affine_bg_items::test_eyes, transition_speed,  false);
        return;
    }
    if (transition == SCENE_TRANSITION_HANDS_IN) {
        transition_fadeout(bn::affine_bg_items::test_handsdissolve, 16,  false);
        // background_visual.bg_item.reset();
        background_visual.visible_bg_item.reset();
        return;
    }
    if (transition == SCENE_TRANSITION_HANDS_OUT) {
        if (to.has_value()) {
            BN_LOG("TO: HAS VALUE");
            background_visual.visible_bg_item.reset();
            ks::globals::main_update();
            background_visual.visible_bg_item = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
            background_visual.visible_bg_item->set_priority(3);
            background_visual.visible_bg_item->set_z_order(10);
            apply_palette_variant(background_visual.visible_bg_item.value(), background_visual.bg_item->palette_item().colors_ref(), background_visual.palette_variant);
            if (next_event.has_value()) {
                (*next_event)->init();
            }
        }
        transition_fadein(bn::affine_bg_items::test_handsdissolve, 8,  false);
        return;
    }
    if (transition == SCENE_TRANSITION_SHORTTIMESKIP || transition == SCENE_TRANSITION_SHORTTIMESKIPSILENT) {
        if (transition == SCENE_TRANSITION_SHORTTIMESKIP) {
            sfx_play("sfx_time.8ad", SOUND_CHANNEL_SOUND);
        }
        transition_fadeout(bn::affine_bg_items::test_delayblinds, 4, true);
        if (to.has_value()) {
            BN_LOG("TO: HAS VALUE");
            background_visual.visible_bg_item.reset();
            ks::globals::main_update();
            background_visual.visible_bg_item = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
            background_visual.visible_bg_item->set_priority(3);
            background_visual.visible_bg_item->set_z_order(10);
            apply_palette_variant(background_visual.visible_bg_item.value(), background_visual.bg_item->palette_item().colors_ref(), background_visual.palette_variant);
            if (next_event.has_value()) {
                (*next_event)->init();
            }
        }
        transition_fadein(bn::affine_bg_items::test_delayblinds, 4, false);
        return;
    }
    if (transition == SCENE_TRANSITION_FLASH || transition == SCENE_TRANSITION_SILENTFLASH) {
        if (transition == SCENE_TRANSITION_FLASH) {
            sfx_play("sfx_flash.8ad", SOUND_CHANNEL_SOUND);
        }
        fade_out(ks::globals::colors::WHITE, 15);
        if (to.has_value()) {
            background_visual.visible_bg_item.reset();
            ks::globals::main_update();
            background_visual.visible_bg_item = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
            background_visual.visible_bg_item->set_priority(3);
            background_visual.visible_bg_item->set_z_order(10);
            apply_palette_variant(background_visual.visible_bg_item.value(), background_visual.bg_item->palette_item().colors_ref(), background_visual.palette_variant);
            if (next_event.has_value()) {
                (*next_event)->init();
            }
        }
        fade_in(ks::globals::colors::WHITE, 45);
        fade_reset();
        return;
    }
    if (transition == SCENE_TRANSITION_SHOWDOWN_THUNDER_LONG || transition == SCENE_TRANSITION_SHOWDOWN_THUNDER_SHORT) {
        fade_out(ks::globals::colors::WHITE, 15);
        if (to.has_value()) {
            background_visual.visible_bg_item.reset();
            ks::globals::main_update();
            background_visual.visible_bg_item = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
            background_visual.visible_bg_item->set_priority(3);
            background_visual.visible_bg_item->set_z_order(10);
            apply_palette_variant(background_visual.visible_bg_item.value(), background_visual.bg_item->palette_item().colors_ref(), background_visual.palette_variant);
            if (next_event.has_value()) {
                (*next_event)->init();
            }
        }
        fade_in(ks::globals::colors::WHITE, transition == SCENE_TRANSITION_SHOWDOWN_THUNDER_LONG ? 180 : 90);
        fade_reset();
        return;
    }
    if (transition == SCENE_TRANSITION_CLOCKWIPE_IN) {
        BN_ASSERT(!to.has_value(), "Clockwipe transition MUST have a value");
        background_visual.visible_bg_item.reset();
        ks::globals::main_update();
        background_visual.visible_bg_item = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
        background_visual.visible_bg_item->set_priority(3);
        background_visual.visible_bg_item->set_z_order(10);
        apply_palette_variant(background_visual.visible_bg_item.value(), background_visual.bg_item->palette_item().colors_ref(), background_visual.palette_variant);
        transition_fadein(bn::affine_bg_items::test_clockwipe, 2, false);
        return;
    }
    if (transition == SCENE_TRANSITION_CLOCKWIPE_OUT) {
        transition_fadeout(bn::affine_bg_items::test_clockwipe, 2, true);
        background_visual.visible_bg_item.reset();
        return;

    }
    if (transition == SCENE_TRANSITION_WHITEOUT || transition == SCENE_TRANSITION_SILENTWHITEOUT) {
        if (transition == SCENE_TRANSITION_WHITEOUT) {
            sfx_play("sfx_whiteout.8ad", SOUND_CHANNEL_SOUND);
        }
        fade_out(ks::globals::colors::WHITE, 60);
        if (to.has_value()) {
            background_visual.visible_bg_item.reset();
            ks::globals::main_update();
            background_visual.visible_bg_item = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
            background_visual.visible_bg_item->set_priority(3);
            background_visual.visible_bg_item->set_z_order(10);
            apply_palette_variant(background_visual.visible_bg_item.value(), background_visual.bg_item->palette_item().colors_ref(), background_visual.palette_variant);
            if (next_event.has_value()) {
                (*next_event)->init();
            }
        }
        fade_in(ks::globals::colors::WHITE, 60);
        fade_reset();
        return;
    }
    // BN_ERROR("Transition not implemented: ", transition);
    BN_LOG("Transition not implemented: ", transition);
}

void SceneManager::perform_transition(const scene_transition_t transition) {
    perform_transition(transition, bn::nullopt);
}

void SceneManager::update() {
    if (background_visual.active_event.has_value()) {
        (*background_visual.active_event)->update();
    }
}

void SceneManager::update_transitions() {
    if (background_visual.active_event.has_value()) {
        (*background_visual.active_event)->update();
    }
    ks::globals::main_update();
}


void SceneManager::update_visuals() {
    if (is_loading) {
        // Do not apply transitions while in loading
        background_visual.transition = SCENE_TRANSITION_NONE;
        return;
    }

    BN_LOG("Update visuals process started");

    if (background_visual.fill_color.has_value()) {
        BN_LOG("Set fill color to: ",
            background_visual.fill_color->red(), ", ",
            background_visual.fill_color->green(), ", ",
            background_visual.fill_color->blue(), ", "
        );
        fill_color = background_visual.fill_color;
        bn::bg_palettes::set_transparent_color(fill_color);
    }

    //
    // // TODO: Example of palette changes!!!!
    // // auto palette = primary_background->palette()
    // if (primary_background.has_value()) {
    //     // auto new_pal = bn::bg_palette_ptr::create(background_visual.visible_bg_item->palette_item());
    //     // primary_background->set_palette(new_pal);
    //     // globals::main_update();
    //
    //     bn::bg_palette_ptr new_pal = primary_background->palette();
    //
    //     // new_pal.set_fade(globals::colors::RED, 0.5);
    //
    //     // new_pal.set_fade(globals::colors::FADE_SPRITE_SUNSET, 0.5);
    //     auto color_idx = 0;
    //     for (auto &color: new_pal.colors()) {
    //         // Python equivalent:
    //         // return Transform(image, matrixcolor=TintMatrix(Color(rgb=(1.02, 0.95, 0.9))) * SaturationMatrix(1.1) * BrightnessMatrix(0.05))
    //
    //         float r = static_cast<float>(color.red()) / 31.0f;
    //         float g = static_cast<float>(color.green()) / 31.0f;
    //         float b = static_cast<float>(color.blue()) / 31.0f;
    //
    //         // Tinting:
    //         r *= 1.02f;
    //         g *= 0.95f;
    //         b *= 0.90f;
    //
    //         // Saturation:
    //         float gray = (r + g + b) / 3.0f;
    //         r = gray + (r - gray) * 1.1f;
    //         g = gray + (g - gray) * 1.1f;
    //         b = gray + (b - gray) * 1.1f;
    //
    //
    //         // Clamp
    //         r = clampf(r, 0.0f, 1.0f);
    //         g = clampf(g, 0.0f, 1.0f);
    //         b = clampf(b, 0.0f, 1.0f);
    //
    //         bn::color new_color = bn::color(static_cast<int>(r * 31),
    //                                         static_cast<int>(g * 31),
    //                                         static_cast<int>(b * 31));
    //         // bn::color new_color =
    //         new_pal.set_color(color_idx, new_color);
    //         color_idx++;
    //     }
    //
    //     // primary_background->set_palette(new_pal);
    // }

    bn::vector<bn::regular_bg_move_to_action, 5> bg_moves;
    bn::vector<bn::sprite_move_to_action, 4> spr_moves;
    bn::optional<bn::blending_transparency_alpha_to_action> blend_action;
    bool in_progress = false;

    /// COLLECT INFO
    // if (!primary_background.has_value()) {
    //     background_visual.visible_bg_item.reset();
    // }

    bool is_scene_visible = !background_visual.fill_color.has_value();
    BN_LOG("Is scene visible: ", is_scene_visible);
    BN_LOG("Is paused: ", is_paused);

    BN_LOG("VISIBLE BG HAS VALUE: ", background_visual.visible_bg_item.has_value());
    BN_LOG("BG HAS VALUE: ", background_visual.bg_item.has_value());

    const bool background_want_change = background_visual.visible_bg_item.has_value() && background_visual.bg_item.has_value() &&
                                  background_visual.visible_bg_item->item() != background_visual.bg_item.value() && is_scene_visible;
    const bool background_want_hide = background_visual.visible_bg_item.has_value() && (!background_visual.bg_item.has_value() || !is_scene_visible);
    const bool background_want_show = !background_visual.visible_bg_item.has_value() && background_visual.bg_item.has_value() && is_scene_visible;
    const bool background_want_transition = background_visual.transition != SCENE_TRANSITION_NONE;
    const bool background_want_dissolve = background_visual.dissolve_time != 0 && (background_want_change || background_want_hide || background_want_show) && !background_want_transition;
    const bool background_want_move = !background_want_change && !background_want_hide && !background_want_show && !background_visual.active_event.has_value() &&
                                background_visual.visible_bg_item.has_value() &&
                                (background_visual.position_x != background_visual.visible_bg_item->position().x() ||
                                background_visual.position_y != background_visual.visible_bg_item->position().y());
    const bool next_event_is_blendable = next_event.has_value() && (*next_event)->is_blendable();

    // Force-hide every still-alive character if the scene-level state
    // demands it: a running BG transition, a fill-color screen, or the
    // paused/in-game menu. `show_character` / `hide_character` already
    // applied themselves to the smart manager directly, so we only need
    // a tear-down pass for the scene-level overrides.
    //
    // Pause is special: we still run the same fade-out + `destroy` path
    // so sprites disappear under the menu, but we **must not** clear
    // `character_visuals` (see HIDE CHARACTERS branch on `is_paused`)
    // — otherwise there is nothing to re-materialise when the player
    // picks "Return" (legacy KS behaviour).
    bool characters_want_hide = false;
    for (auto &visual : character_visuals) {
        if (visual.character == CHARACTER_NONE) {
            visual.will_show = false;
            visual.will_hide = false;
            continue;
        }
        // Scene-level force-hide:
        //   * always when scene is not visible or paused,
        //   * on BG transition only for chars that are already on-screen.
        //
        // IMPORTANT: if a script does:
        //     set_background(..., transition != NONE)
        //     show_character(...)
        //     update_visuals()
        // then `show_character` has just raised `will_show=true`.
        // Treating that slot as force-hidden here causes a fake
        // hide->show ping-pong in one update pass (visible in logs as
        // a second character fade 1->0). We keep freshly-shown slots
        // out of the force-hide path so they appear *after* the
        // background transition in the same `update_visuals` call.
        const bool force_hide =
            !is_scene_visible || is_paused ||
            (background_want_transition && !visual.will_show);
        if (force_hide) {
            visual.will_show = false;
            visual.will_hide = true;
        }
        characters_want_hide = characters_want_hide || visual.will_hide;
    }

    // Returning from the in-game pause menu: re-create smart-manager
    // handles from the preserved `character_visuals` slots *before* we
    // compute `characters_want_show`, so the same-pass SHOW CHARACTERS
    // phase can drive the fade-in (matches pre-smart-characters
    // behaviour).
    if (is_returned_from_pause && !is_paused) {
        if (background_visual.active_event.has_value()) {
            if ((*background_visual.active_event)->is_blendable()) {
                (*background_visual.active_event)->after_show(globals::main_update);
            }
        }
        for (auto& slot : character_visuals) {
            if (slot.character == CHARACTER_NONE || !slot.variant_ptr) {
                continue;
            }
            if (!smart_characters_manager::exists(slot.character)) {
                _apply_smart_character(slot);
                smart_characters_manager::set_blending_enabled(slot.character, true);
                slot.will_show = true;
            }
        }
        is_returned_from_pause = false;
    }

    // Fade-in pass: every slot whose `will_show` was raised by
    // `show_character` (i.e. went from CHARACTER_NONE -> live this
    // frame). Pose / emotion swaps don't set `will_show` and therefore
    // pass through this loop without a blend.
    bool characters_want_show = false;
    for (const auto &visual : character_visuals) {
        if (visual.will_show && visual.character != CHARACTER_NONE) {
            characters_want_show = true;
            break;
        }
    }

    /// HIDE DIALOGS (WITH DISSOLVE)
    if (background_want_dissolve || background_want_transition || characters_want_show || characters_want_hide ||
        is_paused || (background_want_show && next_event_is_blendable)) {
        BN_LOG("Update visuals: Hide dialogbox");
        dialog_novel.hide(true);
        dialog_default.hide(true);
        dialog_doublespeak.hide(true);
    }

    /// HIDE CHARACTERS (WITH ALPHA FADE)
    /// Mirrors the legacy pipeline. Critical ordering — the GBA only
    /// has one global alpha register, so we have to walk the steps in
    /// exactly this sequence to avoid a one-frame opacity glitch *and*
    /// to make sure the chars don't keep eating the alpha register
    /// once the dialog box is back on screen:
    ///   1. raise `set_blending_enabled(true)` on every will_hide char
    ///      (idempotent — `hide_character` already did so via the entry
    ///      point; force-hide chars flagged above need it here).
    ///   2. seed the alpha register at 1 (fully opaque) *before*
    ///      committing the manager so the just-built BGs render at
    ///      their starting opacity instead of inheriting whatever the
    ///      previous phase left in the register.
    ///   3. commit + render one frame to materialise the blending=true
    ///      packer state and let the user see the chars at full
    ///      opacity for one instant before the fade starts.
    ///   4. animate the register down to 0 over 20 frames.
    ///   5. `destroy` and usually clear slot metadata; reset the register +
    ///      commit so the packer's released slots and the cleared
    ///      blending flags are in VRAM before the dialog phase.
    ///      Pause is the exception — metadata is kept so resume can
    ///      re-show (see `is_returned_from_pause` above).
    if (characters_want_hide) {
        bool any_to_hide = false;
        for (auto &visual : character_visuals) {
            if (!visual.will_hide) continue;
            if (visual.character != CHARACTER_NONE) {
                smart_characters_manager::set_blending_enabled(visual.character, true);
                any_to_hide = true;
            }
        }
        if (any_to_hide) {
            bn::blending::set_transparency_alpha(bn::fixed(1));
            smart_characters_manager::commit();
            ks::globals::main_update();
            blend_action = bn::blending_transparency_alpha_to_action(20, bn::fixed(0));
            while (!blend_action->done()) {
                blend_action->update();
                globals::main_update();
            }
            blend_action.reset();
        }
        for (auto &visual : character_visuals) {
            if (!visual.will_hide) continue;
            if (visual.character != CHARACTER_NONE) {
                smart_characters_manager::destroy(visual.character);
            }
            if (is_paused) {
                // In-game pause: VRAM/manager is torn down like a normal
                // hide, but logical slot state survives for resume.
                visual.will_hide = false;
                visual.will_show = false;
                continue;
            }
            visual.character        = CHARACTER_NONE;
            visual.variant_ptr      = nullptr;
            visual.variant_hash     = 0;
            visual.will_hide        = false;
            visual.will_show        = false;
            // Restore the Ren'Py default transform so a later re-show
            // without an explicit `at` (and without a fresh
            // `set_character_position` pre-roll) lands centre-bottom,
            // matching `image` displayables in KS. A scene that *wants*
            // a non-default re-entry calls `set_character_position`
            // first, which re-allocates the slot as a phantom and
            // overwrites these defaults.
            visual.xpos             = bn::fixed(0.5);
            visual.xanchor          = bn::fixed(0.5);
            visual.ypos             = bn::fixed(1.0);
            visual.yanchor          = bn::fixed(1.0);
        }
        if (any_to_hide) {
            // Restore the alpha register and flush the post-destroy
            // packer state. The register has to be 1 again (opaque)
            // before any subsequent surface (BG dissolve, dialog box)
            // touches blending — there's only one register on the GBA
            // and a leftover 0 here would render the next blendable
            // surface invisible for one frame.
            bn::blending::set_transparency_alpha(bn::fixed(1));
            smart_characters_manager::commit();
            ks::globals::main_update();
        }
    }

    /// HIDE BACKGROUNDS (WITH DISSOLVE)
    if (background_want_hide) {
        if (background_visual.active_event.has_value()) {
            if ((*background_visual.active_event)->is_blendable()) {
                dialog_novel.hide(true);
                dialog_default.hide(true);
                dialog_doublespeak.hide(true);
            }
            (*background_visual.active_event)->before_hide(globals::main_update);
            background_visual.active_event.reset();
        }

        if (background_want_dissolve) {
            BN_LOG("Update visuals: Hide background with dissolve");
            background_visual.visible_bg_item->set_blending_enabled(true);
            bn::blending::set_transparency_alpha(bn::fixed(1));
            blend_action = bn::blending_transparency_alpha_to_action(background_visual.dissolve_time, 0.0);
            while (!blend_action->done()) {
                blend_action->update();
                globals::main_update();
            }
        }

        if (background_want_transition) {
            BN_LOG("Update visuals: Hide background with transition ", background_visual.transition);
            perform_transition(background_visual.transition);
            background_visual.transition = SCENE_TRANSITION_NONE;
        }

        background_visual.visible_bg_item.reset();
        blend_action.reset();
    }

    ks::globals::main_update();

    /// CHANGE BACKGROUNDS (WITH DISSOLVE)
    if (background_want_change) {
        BN_LOG(" >>> WANT CHANGE BG");
        bool background_change_fallback = false;

        if (background_visual.active_event.has_value()) {
            if ((*background_visual.active_event)->is_blendable()) {
                dialog_novel.hide(true);
                dialog_default.hide(true);
                dialog_doublespeak.hide(true);
            }
            (*background_visual.active_event)->before_hide(globals::main_update);
            background_visual.active_event.reset();
        }

        if (background_want_dissolve) {
            BN_LOG("Update visuals: Change background with dissolve");

            background_visual.visible_fg_item.reset();
            if(smart_characters_manager::active_bgs_count() > 0)
            {
                smart_characters_manager::evict_vram_for_backdrop();
            }
            background_visual.visible_fg_item = background_visual.bg_item->create_bg_optional(background_visual.position_x, background_visual.position_y);
            // background_visual.visible_fg_item = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
            if (background_visual.visible_fg_item.has_value()) {
                background_visual.visible_fg_item->set_priority(3);
                background_visual.visible_fg_item->set_z_order(9);
                background_visual.visible_fg_item->set_blending_enabled(true);
                apply_palette_variant(background_visual.visible_fg_item.value(), background_visual.bg_item->palette_item().colors_ref(), background_visual.palette_variant);
                bn::blending::set_transparency_alpha(bn::fixed(0));
                blend_action = bn::blending_transparency_alpha_to_action(background_visual.dissolve_time, 1.0);
                while (!blend_action->done()) {
                    blend_action->update();
                    globals::main_update();
                }

                background_visual.visible_bg_item.reset();
                background_visual.visible_fg_item.reset();

                if(smart_characters_manager::active_bgs_count() > 0)
                {
                    smart_characters_manager::evict_vram_for_backdrop();
                }
                background_visual.visible_bg_item = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
                background_visual.visible_bg_item->set_priority(3);
                background_visual.visible_bg_item->set_z_order(10);
                ks::globals::main_update();
                apply_palette_variant(background_visual.visible_bg_item.value(), background_visual.bg_item->palette_item().colors_ref(), background_visual.palette_variant);
                if (next_event.has_value()) {
                    background_visual.active_event = bn::move(next_event);
                    (*background_visual.active_event)->init();
                    next_event.reset();
                }
                blend_action.reset();
            } else {
                BN_LOG("   <<< Unable to create secondary background! Fallback to change without dissolve");
                background_change_fallback = true;
            }
        }

        // TODO: Transition without background change!!!! (See `a1_wednesday_detour_ahead` scene with bg `suburb_shanghaiint`)
        if (background_want_transition) {
            BN_LOG("Update visuals: Change background with transition ", background_visual.transition);
            perform_transition(background_visual.transition, background_visual.bg_item);
            background_visual.transition = SCENE_TRANSITION_NONE;
        } else if (!background_want_dissolve || background_change_fallback) {
            BN_LOG("Update visuals: Change background instantly");
            background_visual.visible_bg_item.reset();
            if(smart_characters_manager::active_bgs_count() > 0)
            {
                smart_characters_manager::evict_vram_for_backdrop();
            }
            background_visual.visible_bg_item = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
            background_visual.visible_bg_item->set_priority(3);
            background_visual.visible_bg_item->set_z_order(10);
            apply_palette_variant(background_visual.visible_bg_item.value(), background_visual.bg_item->palette_item().colors_ref(), background_visual.palette_variant);
            if (next_event.has_value()) {
                background_visual.active_event = bn::move(next_event);
                (*background_visual.active_event)->init();
                next_event.reset();
            }
        }

        if (background_visual.active_event.has_value()) {
            (*background_visual.active_event)->after_show(globals::main_update);
        }

        // background_visual.visible_bg_item = background_visual.bg_item;
    }

    /// SHOW BACKGROUNDS (WITH DISSOLVE)
    if (background_want_show) {
        BN_LOG("Update visuals: Show background");
        if(smart_characters_manager::active_bgs_count() > 0)
        {
            smart_characters_manager::evict_vram_for_backdrop();
        }
        background_visual.visible_bg_item.reset();
        background_visual.visible_bg_item = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
        background_visual.visible_bg_item->set_priority(3);
        background_visual.visible_bg_item->set_z_order(10);
        apply_palette_variant(background_visual.visible_bg_item.value(), background_visual.bg_item->palette_item().colors_ref(), background_visual.palette_variant);
        if (next_event.has_value()) {
            background_visual.active_event = bn::move(next_event);
            (*background_visual.active_event)->init();
            next_event.reset();
        }

        if (background_want_transition) {
            BN_LOG("                with transition ", background_visual.transition);
            perform_transition(background_visual.transition);
            background_visual.transition = SCENE_TRANSITION_NONE;
        }

        if (background_want_dissolve) {
            BN_LOG("                with dissolve");
            background_visual.visible_bg_item->set_blending_enabled(true);
            bn::blending::set_transparency_alpha(bn::fixed(0));
            blend_action = bn::blending_transparency_alpha_to_action(background_visual.dissolve_time, 1.0);
            while (!blend_action->done()) {
                blend_action->update();
                globals::main_update();
            }
            background_visual.visible_bg_item->set_blending_enabled(false);
            blend_action.reset();
        }

        if (background_visual.active_event.has_value()) {
            (*background_visual.active_event)->after_show(globals::main_update);
        }

        // background_visual.visible_bg_item = background_visual.bg_item;
    }

    /// STILL HAVE TRANSITIONS? PERFORM IT ANYWAY (example: PASSOUTP1)
    if (background_want_transition && background_visual.transition != SCENE_TRANSITION_NONE) {
        BN_LOG("Update visuals: Still have transition ", background_visual.transition);
        perform_transition(background_visual.transition);
    }
    background_visual.transition = SCENE_TRANSITION_NONE;

    /// If we have actually same background but different event - we should initialize it anyway!
    if (next_event.has_value()) {
        background_visual.active_event = bn::move(next_event);
        (*background_visual.active_event)->init();
        next_event.reset();

        if ((*background_visual.active_event)->is_blendable()) {
            dialog_novel.hide(true);
            dialog_default.hide(true);
            dialog_doublespeak.hide(true);
            (*background_visual.active_event)->after_show(globals::main_update);
        }
    }

    if (is_paused && background_visual.active_event.has_value()) {
        if ((*background_visual.active_event)->is_blendable()) {
            (*background_visual.active_event)->before_hide(globals::main_update);
            (*background_visual.active_event)->destroy();
            next_event = (*background_visual.active_event)->create();
            background_visual.active_event.reset();
        }
    }
    ks::globals::main_update();

    /// SHOW CHARACTERS (WITH ALPHA FADE)
    /// `show_character` already created the manager handle and raised
    /// the BG blending flag for every fresh char; here we drive the
    /// global alpha register from 0 up to 1, then *immediately* lower
    /// the flag again so the chars stop participating in the global
    /// blending register before the dialog box (or any other blendable
    /// surface that follows) touches it. Pose / emotion swaps don't
    /// get `will_show=true`, so they pass through this phase unblended
    /// — matching the old behaviour.
    ///
    /// Strict ordering, same reasoning as the HIDE phase above:
    ///   1. seed the register at 0 (invisible) *before* committing,
    ///      so the freshly-materialised BGs render at the start of the
    ///      fade-in instead of flashing fully opaque for one frame.
    ///   2. commit + render one frame so the `blending=true` packer
    ///      state is live before the action starts driving the alpha.
    ///   3. animate the register up to 1 over 20 frames.
    ///   4. lower `set_blending_enabled` for every will_show char and
    ///      commit again — the chars must release the global blending
    ///      register here, otherwise the dialog box will pull them
    ///      back into its own fade. Reset the register to 1 in the
    ///      same go for the same reason as the HIDE phase.
    {
        bool any_to_show = false;
        for (auto &visual : character_visuals) {
            if (visual.will_show && visual.character != CHARACTER_NONE) {
                any_to_show = true;
                break;
            }
        }
        if (any_to_show) {
            bn::blending::set_transparency_alpha(bn::fixed(0));
            smart_characters_manager::commit();
            ks::globals::main_update();
            blend_action = bn::blending_transparency_alpha_to_action(20, bn::fixed(1));
            while (!blend_action->done()) {
                blend_action->update();
                smart_characters_manager::tick();
                smart_characters_manager::commit();
                globals::main_update();
            }
            blend_action.reset();

            for (auto &visual : character_visuals) {
                visual.will_show = false;
            }
            // Force-disable blending on EVERY alive character, not
            // just the ones we faded in. The GBA has only one global
            // alpha register; if any char's BG/face still has its
            // blending bit set when the dialog box's own fade-in runs
            // a moment later (alpha 0 → 0.85 over 10 frames), every
            // such char gets dragged along the same curve and ends up
            // semi-transparent at 0.85. The user-facing rule the
            // scene manager promises here is simple: "fade is over →
            // *no* character is in the blending register".
            //
            // `disable_blending_all` does the manager-side rebucket
            // (multi-tenant chars detach + reattach onto a now
            // blending=false host); the explicit `commit()` after it
            // materialises that rebucket plus the bg_ptr flag flip
            // before any subsequent render — same reason as the HIDE
            // phase post-destroy commit above.
            smart_characters_manager::disable_blending_all();
            bn::blending::set_transparency_alpha(bn::fixed(1));
            smart_characters_manager::commit();
        }
    }

    ks::globals::main_update();
    if (background_want_move) {
        BN_LOG("Update visuals: Move background");
        // TODO: affine moves if necessary
        bg_moves.push_back(bn::regular_bg_move_to_action(background_visual.visible_bg_item->regular_ptr(),
                                                         20,
                                                         background_visual.position_x,
                                                         background_visual.position_y));
    }

    /// Push every pending change (BG packs, faces, palette) into VRAM
    /// once now, before we start any blocking animation loop. Without
    /// this, a character that was just `create`d wouldn't have its host
    /// BG built yet, and the first tick below would have nothing to
    /// drive. Cheap when nothing is dirty.
    ///
    /// `main_update()` right after this commit is *required* even when
    /// the animation loop below short-circuits (no in-flight tweens —
    /// the common case for an emotion swap with no fade): otherwise
    /// the manager's just-queued map cells (in `stg.cells`, marked
    /// dirty via `reload_cells_ref`) and tile-upload snapshots would
    /// hang in the queue until the next `update_visuals` call, and a
    /// back-to-back `show_character` between the two could mutate
    /// `ch.var` before the V-Blank that drains them — producing one
    /// to two frames of "new map cells + old/garbage tile data" desync.
    /// The snapshot in `_enqueue_char_upload` already neutralises the
    /// tile-side race, but flushing here keeps `update_visuals` self-
    /// contained: when it returns, every change it queued is on screen.
    smart_characters_manager::commit();
    ks::globals::main_update();

    /// Drive in-flight animations: bg move, dissolve blend, character
    /// smooth-move tweens. Each frame: advance each running action,
    /// then `globals::main_update()` to render & let V-Blank tile
    /// uploads land. Loop until nothing's running.
    in_progress = true;
    while (in_progress && (blend_action.has_value() || !bg_moves.empty()
                           || smart_characters_manager::is_animating())) {
        in_progress = false;
        if (blend_action.has_value() && !blend_action->done()) {
            blend_action->update();
            in_progress = true;
        }
        for (auto& action : bg_moves) {
            if (!action.done()) {
                action.update();
                in_progress = true;
            }
        }
        if (smart_characters_manager::is_animating()) {
            smart_characters_manager::tick();
            smart_characters_manager::commit();
            in_progress = true;
        }
        globals::main_update();
    }
    blend_action.reset();

    if (!background_visual.fill_color.has_value()) {
        BN_LOG("Reset fill color");
        fill_color.reset();
        bn::bg_palettes::set_transparent_color(globals::colors::BLACK);
    }

    /// discard: SHOW DIALOGS (WITH DISSOLVE)
}

void SceneManager::music_play(const music_t music) {
    music_play(music, 0);
}

void SceneManager::music_play(const music_t music, const int fade) {
    BN_LOG("Play Music ", ks::sound_manager::get_music_filename(music), " with fade ", fade);
    ks::sound_manager::stop<SOUND_CHANNEL_MUSIC>();
    ks::sound_manager::play(music);
    if (fade > 0 && !is_loading) {
        ks::sound_manager::set_fadein_action<SOUND_CHANNEL_MUSIC>(fade);
    }

    if (!is_loading) {
        ks::globals::main_update();
    }
}

void SceneManager::music_stop() {
    music_stop(0);
}

void SceneManager::music_stop(const int fade) {
    BN_LOG("Stop GSM with fade ", fade);
    if (fade > 0 && !is_loading) {
        ks::sound_manager::set_fadeout_action<SOUND_CHANNEL_MUSIC>(fade);
    } else {
        ks::sound_manager::stop<SOUND_CHANNEL_MUSIC>();
    }
}

void SceneManager::sfx_play(const char* filename, const sound_channel_t channel) {
    sfx_play(filename, channel, 0);
}

void SceneManager::sfx_play(const char* filename, const sound_channel_t channel, const int fade) {
    BN_LOG("Play SFX ", filename, " on channel ", channel, " with fade ", fade);
    if (channel == SOUND_CHANNEL_SOUND) {
        ks::sound_manager::stop<SOUND_CHANNEL_SOUND>();
        ks::sound_manager::play<SOUND_CHANNEL_SOUND>(filename);
        if (fade > 0 && !is_loading) {
            ks::sound_manager::set_fadein_action<SOUND_CHANNEL_SOUND>(fade);
        }
    } else if (channel == SOUND_CHANNEL_AMBIENT) {
        ks::sound_manager::stop<SOUND_CHANNEL_AMBIENT>();
        ks::sound_manager::play<SOUND_CHANNEL_AMBIENT>(filename);
        if (fade > 0 && !is_loading) {
            ks::sound_manager::set_fadein_action<SOUND_CHANNEL_AMBIENT>(fade);
        }
    } else {
        BN_ERROR("Attempt to play SFX on invalid channel ", channel);
    }
}

void SceneManager::sfx_stop(const sound_channel_t channel) {
    sfx_stop(channel, 0);
}

void SceneManager::sfx_stop(const sound_channel_t channel, const int fade) {
    BN_LOG("Stop SFX on channel ", channel, " with fade ", fade);
    if (channel == SOUND_CHANNEL_SOUND) {
        if (fade > 0 && !is_loading) {
            ks::sound_manager::set_fadeout_action<SOUND_CHANNEL_SOUND>(fade);
        } else {
            ks::sound_manager::stop<SOUND_CHANNEL_SOUND>();
        }
    } else if (channel == SOUND_CHANNEL_AMBIENT) {
        if (fade > 0 && !is_loading) {
            ks::sound_manager::set_fadeout_action<SOUND_CHANNEL_AMBIENT>(fade);
        } else {
            ks::sound_manager::stop<SOUND_CHANNEL_AMBIENT>();
        }
    } else {
        BN_ERROR("Attempt to stop SFX on invalid channel ", channel);
    }
}

void SceneManager::show_title(const title_card_t tc) {
    if (is_loading) {
        return;
    }

    BN_LOG("SHOW TITLE CARD: ", tc);

    dialog_novel.hide(true);
    dialog_default.hide(true);
    dialog_doublespeak.hide(true);


    ks::timer::pause_ingame_timer();

    perform_act_fadeout();
    free_resources();

    pause(60);

    bn::blending::restore();

    switch (tc) {
        case TC_ACT1:
            ActOpening1().run();
            break;
        case TC_ACT2_EMI:
            perform_render_video(video_tc_act2_emi_ulcv, "video_tc_act2_emi.ulc", globals::colors::WHITE);
            ActOpening2Emi().run();
            break;
        case TC_ACT3_EMI:
            ActOpening3Emi().run();
            break;
        case TC_ACT4_EMI:
            ActOpening4Emi().run();
            break;
        case TC_ACT2_HANAKO:
            perform_render_video(video_tc_act2_hanako_ulcv, "video_tc_act2_hanako.ulc", globals::colors::WHITE);
            ActOpening2Hanako().run();
            break;
        case TC_ACT3_HANAKO:
            ActOpening3Hanako().run();
            break;
        case TC_ACT4_HANAKO:
            ActOpening4Hanako().run();
            break;
        case TC_ACT2_LILLY:
            perform_render_video(video_tc_act2_lilly_ulcv, "video_tc_act2_lilly.ulc", globals::colors::WHITE);
            ActOpening2Lilly().run();
            break;
        case TC_ACT3_LILLY:
            ActOpening3Lilly().run();
            break;
        case TC_ACT4_LILLY:
            ActOpening4Lilly().run();
            break;
        case TC_ACT2_RIN:
            perform_render_video(video_tc_act2_rin_ulcv, "video_tc_act2_rin.ulc", globals::colors::WHITE);
            ActOpening2Rin().run();
            break;
        case TC_ACT3_RIN:
            ActOpening3Rin().run();
            break;
        case TC_ACT4_RIN:
            ActOpening4Rin().run();
            break;
        case TC_ACT2_SHIZUNE:
            perform_render_video(video_tc_act2_shizune_ulcv, "video_tc_act2_shizune.ulc", globals::colors::WHITE);
            ActOpening2Shizune().run();
            break;
        case TC_ACT3_SHIZUNE:
            ActOpening3Shizune().run();
            break;
        case TC_ACT4_SHIZUNE:
            ActOpening4Shizune().run();
            break;
        default: BN_ERROR("Unknown title card: ", tc); break;
    }

    bn::bg_palettes::set_transparent_color(globals::colors::WHITE);
    fade_reset();

    ks::timer::resume_ingame_timer();
}

void SceneManager::show_op1() {
    if (is_loading) {
        return;
    }

    BN_LOG("SHOW OPENING 1");

    dialog_novel.hide(true);
    dialog_default.hide(true);
    dialog_doublespeak.hide(true);

    ks::timer::pause_ingame_timer();

    perform_op1_fadeout();
    free_resources();
    bn::blending::restore();

    // Free last sound chunks
    ks::sound_manager::stop<SOUND_CHANNEL_VIDEO>();
    ks::sound_manager::stop<SOUND_CHANNEL_MUSIC>();
    ks::sound_manager::stop<SOUND_CHANNEL_SOUND>();
    ks::sound_manager::stop<SOUND_CHANNEL_AMBIENT>();
    globals::main_update();

    GameOpening().run();

    bn::bg_palettes::set_transparent_color(globals::colors::BLACK);
    fade_reset();

    globals::init_text_generators();
    ks::timer::resume_ingame_timer();
}

void SceneManager::show_video(const uint8_t* video_file, const char* audio_file) {
    if (is_loading) {
        return;
    }

    if (!video_file) {
        BN_ERROR("show_video: null video stream");
        return;
    }
    bool force_white = false;
    if (video_file == video_4ls_ulcv) {
        force_white = true;
    }

    ks::timer::pause_ingame_timer();
    perform_render_video(video_file, audio_file, ks::globals::colors::BLACK, force_white);
    ks::timer::resume_ingame_timer();
}

void SceneManager::exit_scenario_from_ingame_menu() {
    if (!in_replay) {
        autosave();
    }

    static_text_sprites.clear();
    animated_text_sprites.clear();
    secondary_background.reset();

    for(int alpha = 16; alpha <= 32; ++alpha) {
        bn::bg_palettes::set_fade(globals::colors::BLACK, bn::fixed(alpha) / 32);
        bn::sprite_palettes::set_fade(globals::colors::BLACK, bn::fixed(alpha) / 32);
        ks::globals::main_update();
    }

    free_resources();
}

void SceneManager::pause(const int ticks) {
    if (is_loading) {
        return;
    }
    if (is_paused) {
        return;
    }
    for(int tick = 0; tick <= ticks; ++tick) {
        ks::globals::main_update();
    }
}

void SceneManager::timeskip() {
    if (background_visual.visible_bg_item.has_value()) {
        // BN_ERROR("All BGS should be disabled at the timeskip event!!!");
        // TODO: Also check for hiding characters!!!
        IF_NOT_EXIT(ks::SceneManager::hide_background(SCENE_TRANSITION_NONE, 60));
        IF_NOT_EXIT(ks::SceneManager::enable_fill(ks::globals::colors::BLACK));
        IF_NOT_EXIT(ks::SceneManager::update_visuals());
    }

    if (is_loading) {
        return;
    }
    BN_LOG("Timeskip...");

    music_stop(120);
    sfx_stop(SOUND_CHANNEL_SOUND, 120);
    sfx_stop(SOUND_CHANNEL_AMBIENT, 120);
    pause(120);

    music_play(MUSIC_TIMESKIP);

    set_background(background_metas::kslogo_heart, 0, 0, SCENE_TRANSITION_CLOCKWIPE_IN, 0, PALETTE_VARIANT_DEFAULT);
    // set_background_transition(SCENE_TRANSITION_CLOCKWIPE);
    update_visuals();

    set_background(background_metas::kslogo_words, 0, 0, SCENE_TRANSITION_NONE, 108, PALETTE_VARIANT_DEFAULT);
    // set_background_transition(SCENE_TRANSITION_CLOCKWIPE);
    update_visuals();

    pause(120);

    music_stop(120);

    hide_background(SCENE_TRANSITION_CLOCKWIPE_OUT, 0);
    update_visuals();

    pause(112);
}

void SceneManager::apply_palette_variant(const background_ptr &bg,
                                         const bn::span<const bn::color> &original_palette,
                                         const palette_variant_t palette_variant) {
    if (palette_variant == PALETTE_VARIANT_DEFAULT) {
        return; // No changes needed
    }
    bn::bg_palette_ptr new_pal = bg.palette();
    auto color_idx = 0;
    for (auto &color: original_palette) {
        const auto new_color = get_paletted_color(color, palette_variant);
        new_pal.set_color(color_idx, new_color);
        color_idx++;
    }
}

void SceneManager::apply_palette_variant(const bn::sprite_ptr &spr,
                                         const bn::span<const bn::color> &original_palette,
                                         const palette_variant_t palette_variant) {
    if (palette_variant == PALETTE_VARIANT_DEFAULT) {
        return; // No changes needed
    }
    bn::sprite_palette_ptr new_pal = spr.palette();
    auto color_idx = 0;
    for (auto &color: original_palette) {
        const auto new_color = get_paletted_color(color, palette_variant);
        new_pal.set_color(color_idx, new_color);
        color_idx++;
    }
}

void SceneManager::fade_in(const bn::color &color, const int steps) {
    bn::bg_palettes::set_fade(color, bn::fixed(1));
    bn::sprite_palettes::set_fade(color, bn::fixed(1));
    for(int alpha = steps; alpha >= 0; --alpha) {

        bn::bg_palettes::set_fade(color, bn::fixed(alpha) / steps);
        bn::sprite_palettes::set_fade(color, bn::fixed(alpha) / steps);
        ks::globals::main_update();
    }
}

void SceneManager::fade_out(const bn::color &color, const int steps) {
    for(int alpha = 0; alpha <= steps; ++alpha) {
        bn::bg_palettes::set_fade(color, bn::fixed(alpha) / steps);
        bn::sprite_palettes::set_fade(color, bn::fixed(alpha) / steps);
        ks::globals::main_update();
    }
}

void SceneManager::fade_in(const bn::color &color) {
    fade_in(color, 32);
}

void SceneManager::fade_out(const bn::color &color) {
    fade_out(color, 32);
}

void SceneManager::fade_reset() {
    bn::bg_palettes::set_fade_intensity(bn::fixed(0));
    bn::sprite_palettes::set_fade_intensity(bn::fixed(0));
}

inline shader_data SceneManager::init_transition_shader(const bn::affine_bg_item &transition_item, const bool use_buffer) {
    BN_LOG("Init transition shader, use_buffer: ", use_buffer);
    shader_data data{};

    // Transitions are small (tens of tiles) but can be requested in the
    // heaviest VRAM moments (big backdrop + characters + dialog). Forcing
    // `allow_tiles_offset=false` makes allocation require whole contiguous
    // blocks and can fail even when there is enough total free space.
    //
    // Keep offsets allowed so the allocator can use fragmented VRAM.
    const bool allow_offset = bn::bg_blocks_manager::allow_tiles_offset();
    bn::bg_blocks_manager::set_allow_tiles_offset(true);

    BN_LOG("BG tiles free blocks: ", bn::bg_tiles::available_blocks_count(),
           " | BG maps free blocks: ", bn::bg_maps::available_blocks_count());
    ks::transition_bg = transition_item.create_bg_optional(0, 0);
    if (!ks::transition_bg.has_value()) {
        // BN_ERROR("Failed to allocate transition BG");
        BN_LOG("Failed to allocate transition BG");
        data.vram_ptr = nullptr;
        return data;
    }
    bn::bg_blocks_manager::set_allow_tiles_offset(allow_offset);


    ks::transition_bg->set_priority(1);
    ks::transition_bg->set_wrapping_enabled(false);
    ks::transition_bg->set_scale(2.0, 2.0);
    ks::transition_bg->set_blending_enabled(true);
    bn::blending::set_fade_color(bn::blending::fade_color_type::BLACK);
    bn::blending::set_fade_alpha(1.0);

    auto tiles_cbb = ks::transition_bg->tiles().cbb();
    auto tiles_handle = ks::transition_bg->tiles().handle();
    auto tiles_count = ks::transition_bg->tiles().tiles_count();
    auto tiles_offset = ks::transition_bg->map().tiles_offset();
    BN_LOG("Tiles count: ", tiles_count);
    BN_LOG("Tiles offset: ", tiles_offset);
    BN_LOG("Tiles Handle: ", tiles_handle);
    BN_LOG("Tiles CBB: ", tiles_cbb);
    // BN_LOG("Tiles HWID: ", ks::transition_bg->hw_id().value());

    auto cbb_addr = CHAR_BASE_BLOCK(tiles_cbb);
    BN_LOG("Tiles CBB ADDR: ", cbb_addr);

    // When tiles offset is enabled, Butano may allocate the tile chunk with a
    // non-zero base offset inside the chosen CBB. Our shader must read/write
    // exactly the allocated range, not the whole CBB from tile 0.
    data.vram_ptr = static_cast<uint32_t *>(cbb_addr) + (tiles_offset * 16);
    data.dwords = tiles_count * 8;

    if (use_buffer) {
        BN_LOG("EWRAM BEFORE ", bn::memory::available_alloc_ewram());
        BN_LOG("Allocating ", data.dwords * 4, " bytes in EWRAM");
        data.tiles_buffer = static_cast<uint32_t*>(bn::memory::ewram_alloc(data.dwords * 4));  // EWRAM allocation
        BN_LOG("EWRAM AFTER ", bn::memory::available_alloc_ewram());
        BN_LOG("IWRAM static bytes used: ", bn::memory::used_static_iwram());
        BN_LOG("IWRAM stack bytes used: ", bn::memory::used_stack_iwram());
        BN_LOG("IWRAM free bytes: ", 32 * 1024 - bn::memory::used_static_iwram() - bn::memory::used_stack_iwram());
        BN_LOG("Start DMA copy");
        dmaCopy(data.vram_ptr, data.tiles_buffer, data.dwords * 4);
        BN_LOG("DMA copy finished");
    }

    return data;
}

void SceneManager::transition_fadein(const bn::affine_bg_item &transition_item, const int speed, const bool reverse) {
    const auto shader = init_transition_shader(transition_item, false);
    VBlankIntrWait();

    if (shader.vram_ptr == nullptr) {
        // BN_ERROR("Failed to allocate transition shader");
        return;
    }
    BN_LOG("Start Transition Fadein");

    if (reverse) {
        for (int dissolve_i = 0; dissolve_i < 128; dissolve_i += speed) {
            shader_dissolve_in_inverted(shader.dwords, dissolve_i, shader.vram_ptr, update_transitions);
            ks::globals::main_update();
        }
    } else {
        for (int dissolve_i = 128; dissolve_i > 0; dissolve_i -= speed) {
            shader_dissolve_in(shader.dwords, dissolve_i, shader.vram_ptr, update_transitions);
            ks::globals::main_update();
        }
    }

    bn::blending::set_fade_alpha(0.0);
    ks::transition_bg.reset();
}

void SceneManager::transition_fadeout(const bn::affine_bg_item &transition_item, const int speed, const bool reverse) {
    const auto shader = init_transition_shader(transition_item, true);
    VBlankIntrWait();

    if (shader.vram_ptr == nullptr) {
        // BN_ERROR("Failed to allocate transition shader");
        return;
    }
    BN_LOG("Start Transition Fadeout");

    if (reverse) {
        for (int dissolve_i = 128; dissolve_i >= 0; dissolve_i -= speed) {
            shader_dissolve_out_inverted(shader.dwords, dissolve_i, shader.tiles_buffer, shader.vram_ptr, update_transitions);
            ks::globals::main_update();
        }
    } else {
        for (int dissolve_i = 0; dissolve_i <= 128; dissolve_i += speed) {
            shader_dissolve_out(shader.dwords, dissolve_i, shader.tiles_buffer, shader.vram_ptr, update_transitions);
            ks::globals::main_update();
        }
    }

    bn::memory::ewram_free(shader.tiles_buffer);
    BN_LOG("EWRAM AFTER FREE: ", bn::memory::available_alloc_ewram());


    bn::blending::set_fade_alpha(0.0);
    ks::transition_bg.reset();
}

void SceneManager::perform_op1_fadeout() {
    ks::sound_manager::set_fadeout_action<SOUND_CHANNEL_MUSIC>(120);
    ks::sound_manager::set_fadeout_action<SOUND_CHANNEL_SOUND>(120);
    ks::sound_manager::set_fadeout_action<SOUND_CHANNEL_AMBIENT>(120);
    fade_out(globals::colors::BLACK, 120);
}

void SceneManager::perform_act_fadeout() {
    ks::sound_manager::set_fadeout_action<SOUND_CHANNEL_MUSIC>(120);
    ks::sound_manager::set_fadeout_action<SOUND_CHANNEL_SOUND>(120);
    ks::sound_manager::set_fadeout_action<SOUND_CHANNEL_AMBIENT>(120);
    fade_out(globals::colors::WHITE, 120);
}

void SceneManager::perform_render_video(const uint8_t* video_file, const char* audio_file, const bn::color clear) {
    perform_render_video(video_file, audio_file, clear, clear == globals::colors::WHITE);
}

void SceneManager::perform_render_video(const uint8_t* video_file, const char* audio_file, const bn::color clear, const bool force_white_end) {
    bn::blending::restore();
    sound_mixer::mute();

    // Free last sound chunks
    ks::sound_manager::stop<SOUND_CHANNEL_MUSIC>();
    ks::sound_manager::stop<SOUND_CHANNEL_SOUND>();
    ks::sound_manager::stop<SOUND_CHANNEL_AMBIENT>();

    free_resources();
    ks::globals::release_engine();
    bn::core::update();

    videoplayer_init(video_file, audio_file, clear.red(), clear.green(), clear.blue());
    videoplayer_play(force_white_end);
    videoplayer_clean();

    ks::globals::init_engine();
    // sound_mixer::unmute();
    BN_LOG("Init engine done!");
}

int SceneManager::get_character_visual_index(const character_t character, const bool create_if_not_found) {
    BN_LOG("get_character_visual_index: ", character, " create_if_not_found: ", create_if_not_found);
    for (int i = 0; i < smart_characters_manager::MAX_CHARS; i++) {
        BN_LOG("Character at index ", i, ":");
        BN_LOG("                      character: ", character_visuals.at(i).character);
        if (character_visuals.at(i).character == character) {
            return i;
        }
    }
    if (create_if_not_found) {
        for (int i = 0; i < smart_characters_manager::MAX_CHARS; i++) {
            if (character_visuals.at(i).character == CHARACTER_NONE) {
                return i;
            }
        }
        BN_ERROR("Maximum displayable characters exceeded");
        return -1;
    }
    BN_ERROR("Character not found: ", character);
    return -1;
}
} // namespace ks
