#ifndef KS_SCENEMANAGER_H
#define KS_SCENEMANAGER_H


#include "bn_regular_bg_item.h"
#include "bn_affine_bg_item.h"
#include "character.h"
#include <bn_blending_transparency_attributes_hbe_ptr.h>
#include <bn_regular_bg_ptr.h>
#include <bn_affine_bg_ptr.h>
#include <bn_unique_ptr.h>

#include "background_item.h"
#include "background_meta.h"
#include "background_ptr.h"
#include "bn_rect_window.h"
#include "dialog_box.h"
#include "gba_base.h"
#include "gba_types.h"
#include "savefile/save_file.h"
#include "ext_bg_blocks_manager.h"
#include "displayable_meta.h"
#include "smart_characters_manager.h"
#include "vfx_meta.h"
#include "events/custom_event.h"
#include "shaders/vram_dma_shader.h"

#include "smart_character_bg.h"  // for ks::smart_characters::variant


#define SKIP_IF_LOAD_ANOTHER_SCENE(val)           \
if (ks::is_loading) {                             \
    if (ks::progress.metadata.script != val) {    \
        return;                                   \
    }                                             \
}

namespace ks {

struct background_visuals_ptr
{
    bn::optional<background_ptr> visible_bg_item;
    bn::optional<background_ptr> visible_fg_item;
    bn::optional<background_item> bg_item;
    bn::optional<bn::color> fill_color;
    bn::fixed alpha;
    bool will_show;
    bool will_hide;
    int position_x;
    int position_y;
    int dissolve_time;
    bool dissolve_on_top;
    bn::optional<bn::unique_ptr<CustomEvent>> active_event;
    scene_transition_t transition;
    palette_variant_t palette_variant;
};

/// Per-character logical state tracked by `SceneManager`. The actual BG /
/// OBJ resources live inside `ks::smart_characters_manager`; this struct
/// keeps just enough metadata for save thumbnails, smooth-move tweens,
/// and the show/hide flow.
///
/// Position is stored in **Ren'Py-style normalised coords** — `xpos` /
/// `ypos` are fractions of the screen size (0.0 = left/top edge,
/// 1.0 = right/bottom edge), and `xanchor` / `yanchor` are fractions of
/// the *displayable's own* size (0.0 = left/top edge, 1.0 = right/bottom
/// edge of the visible body bbox). The runtime translates this to a
/// screen-centre-relative pixel offset every time the slot is applied
/// to the smart-character manager, using the *current* variant's actual
/// `body.vis_*` bbox — so a body change automatically re-anchors. This
/// is the fundamental fix for the converter-side
/// "sprite_width = 128 px" hard-coding (see `tools/converter/src/utils.py`
/// pre-migration): real bodies vary from ~64..120 px wide and the old
/// pixel-baked positioning made characters with `xalign 1.03` collide
/// with siblings at `xalign 0.7`. Default = `(0.5, 0.5, 1.0, 1.0)` —
/// horizontally centred, bottom edge anchored to the bottom of the
/// screen, matching the implicit Ren'Py default for `image` displayables
/// in KS.
struct character_visuals_ptr
{
    character_t character;
    palette_variant_t palette_variant;

    /// Latest `ks::smart_characters::variant` shown for this slot.
    /// Required because `set_character_position` can fire before any
    /// re-`show_character` does (e.g. xpos/ypos on the line *after* the
    /// `show`); we re-apply this variant if the smart-manager somehow
    /// dropped the char between the two.
    const ks::smart_characters::variant* variant_ptr;

    /// Stable group hash (mirrored from `variant_ptr->hash`). Stored
    /// directly so save metadata can copy it without dereferencing the
    /// variant pointer (which may dangle across saves).
    unsigned short variant_hash;

    /// Ren'Py-style normalised position (see struct doc). `xpos` /
    /// `ypos` are screen-relative; `xanchor` / `yanchor` are body-
    /// relative. Smooth-move tweens run in pixel space inside the smart
    /// manager — these stay logical and are re-resolved on demand.
    bn::fixed xpos;
    bn::fixed xanchor;
    bn::fixed ypos;
    bn::fixed yanchor;

    /// Show / hide latches consumed by `update_visuals`. `will_show` is
    /// raised by `show_character` and lowered after the smart-manager
    /// has reflected the change; `will_hide` is raised by
    /// `hide_character` and lowered after the manager destroyed it.
    bool will_show;
    bool will_hide;
};

/// Scene-layer VFX (crowd, …). Hardware lives in `displayable_manager`.
struct displayable_visuals_ptr
{
    const displayable_meta* meta;
    palette_variant_t       palette_variant;
    bn::fixed               xpos;
    bn::fixed               xanchor;
    bn::fixed               ypos;
    bn::fixed               yanchor;
    int                     frame_index;
    bool                    animate;
    bool                    active;
    bool                    will_show;
    bool                    will_hide;
};

inline displayable_visuals_ptr make_default_displayable_visual()
{
    displayable_visuals_ptr v{};
    v.meta            = nullptr;
    v.palette_variant = PALETTE_VARIANT_DEFAULT;
    v.xpos            = bn::fixed(0.5);
    v.xanchor         = bn::fixed(0.5);
    v.ypos            = bn::fixed(1.0);
    v.yanchor         = bn::fixed(1.0);
    v.frame_index     = 0;
    v.animate         = true;
    v.active          = false;
    v.will_show       = false;
    v.will_hide       = false;
    return v;
}

struct answer_ptr
{
    const unsigned char index;
    const unsigned int tl_key;
};

class SceneManager {
public:
    constexpr explicit SceneManager(const char* scenario) : _scenario(scenario) {
    }
    constexpr ~SceneManager() = default;


    static void free_resources();
    static void set(const ks::SceneManager instance);
    static void set_textdb(const uint8_t* db);
    static void reload_textdb();
    static void init_savedata(ks::saves::SaveSlotProgressData &value);
    static void set_script(const script_t script);
    static void set_label(const label_t label);
    static void set_line_hash(const unsigned int line_hash);
    static void autosave();
    static void save(unsigned short slot_index);
    static void save_states();

    // Acions

    static void reset_backgrounds_visuals();
    static void set_background(const background_meta& bg,
                           const int position_x,
                           const int position_y,
                           scene_transition_t transition,
                           const int dissolve_time,
                           const palette_variant_t palette_variant);
    static void set_huge_background(const huge_background_meta& bg,
                       int position_x,
                       int position_y,
                       scene_transition_t transition,
                       int dissolve_time,
                       const palette_variant_t palette_variant);
    static void hide_background(scene_transition_t transition, int dissolve_time);
    static void set_background_position(const int position_x,
                                       const int position_y);
    static void set_background_transition(scene_transition_t transition);
    static void enable_fill(bn::color color);
    static void disable_fill();

    static void set_foreground(const vfx_meta& fg,
                           const int position_x,
                           const int position_y,
                           const int dissolve_time);

    static void hide_foreground(int dissolve_time);

    static void process_menu_states(const gameState_t &state);

    static void set_event(const background_meta& bg,
                          const CustomEvent& event,
                          scene_transition_t transition,
                          int dissolve_time);

    static void set_event(const huge_background_meta& bg,
                      const CustomEvent& event,
                      scene_transition_t transition,
                      int dissolve_time);

    static void set_event_state(int state);

    static void show_dialog(unsigned int line_hash, const ks::character_definition& actor, unsigned int tl_key);
    static void show_dialog(unsigned int line_hash, unsigned int actor_tl_key, unsigned int tl_key);
    static void show_doublespeak(unsigned int line_hash, const ks::character_definition& actor_left,
                                 unsigned int tl_key_left, const ks::character_definition& actor_right,
                                 unsigned int tl_key_right);
    static void show_dialog_question(const bn::vector<ks::answer_ptr, 5>& answers);
    static int get_dialog_question_answer();
    static void nvl_clear();
    static void nvl_hide();
    static void nvl_show(unsigned int line_hash, unsigned int tl_key);
    /// Show / change a character. The variant carries the `body` (BG) and
    /// `face` (OBJ) pair plus the group hash used by save thumbnails.
    /// The 3-arg overload preserves the slot's current position (Ren'Py
    /// `show <char>` with no transform); the positioned overload
    /// updates it. Position is given in **Ren'Py-style normalised
    /// coords**: `xpos`/`ypos` are screen-relative (0..1), `xanchor`/
    /// `yanchor` are body-relative (0..1). The runtime resolves these
    /// to pixels using the *current* variant's `body.vis_*` bbox — so
    /// `xalign 1.03` always lands the body's right edge at 103 % of
    /// the screen regardless of how wide the actual sprite is. Default
    /// for a fresh slot is `(0.5, 0.5, 1.0, 1.0)`. The palette variant
    /// is applied scene-wide via
    /// `smart_characters_manager::set_palette_variant` (every character
    /// carries the same variant — see migration notes).
    static void show_character(character_t character,
                               const ks::smart_characters::variant& var,
                               palette_variant_t palette_variant);
    static void show_character(character_t character,
                               const ks::smart_characters::variant& var,
                               palette_variant_t palette_variant,
                               bn::fixed xpos,
                               bn::fixed xanchor,
                               bn::fixed ypos,
                               bn::fixed yanchor);

    /// Move an existing character to a new on-screen position, given in
    /// Ren'Py-style normalised coords (see `show_character` doc). If
    /// the resolved pixel position equals the current one the call is a
    /// no-op. Otherwise the move smooth-tweens over
    /// `SMART_CHARACTER_MOVE_FRAMES` frames (same length as the first-show
    /// fade-in), including same-block `show` + transform lines so motion
    /// and alpha blend run together.
    static void set_character_position(character_t character,
                                       bn::fixed xpos,
                                       bn::fixed xanchor,
                                       bn::fixed ypos,
                                       bn::fixed yanchor);

    static void hide_character(character_t character);
    static void hide_character(character_t character, bool need_update, bool remove);

    static void show_displayable(const displayable_meta& meta,
                                 palette_variant_t palette_variant,
                                 int frame_index = 0,
                                 bool animate = true);
    static void show_displayable(const displayable_meta& meta,
                                 palette_variant_t palette_variant,
                                 bn::fixed xpos,
                                 bn::fixed xanchor,
                                 bn::fixed ypos,
                                 bn::fixed yanchor,
                                 int frame_index = 0,
                                 bool animate = true);
    static void hide_displayable();
    static void set_displayable_position(bn::fixed xpos,
                                         bn::fixed xanchor,
                                         bn::fixed ypos,
                                         bn::fixed yanchor);

    static void perform_transition(scene_transition_t transition, const bn::optional<ks::background_item>& to);
    static void perform_transition(scene_transition_t transition);

    static void update();
    static void update_transitions();
    static void update_visuals();
    static void music_play(music_t music);
    static void music_play(music_t music, const int fade);
    static void music_stop();
    static void music_stop(const int fade);
    static void sfx_play(const char *filename, const sound_channel_t channel);
    static void sfx_play(const char *filename, const sound_channel_t channel, const int fade);
    static void sfx_stop(const sound_channel_t channel);
    static void sfx_stop(const sound_channel_t channel, const int fade);

    static void show_title(const title_card_t tc);
    static void show_op1();
    static void show_video(const uint8_t* video_file, const char* audio_file);

    static void exit_scenario_from_ingame_menu();

    static void pause(const int ticks);

    static void timeskip();

    static void apply_palette_variant(const background_ptr &bg,
                                      const bn::span<const bn::color> &original_palette,
                                      const palette_variant_t palette_variant);
    static void apply_palette_variant(const bn::sprite_ptr &spr,
                                      const bn::span<const bn::color> &original_palette,
                                      const palette_variant_t palette_variant);

    static void fade_in(const bn::color &color, const int steps);
    static void fade_out(const bn::color &color, const int steps);
    static void fade_in(const bn::color &color);
    static void fade_out(const bn::color &color);
    static void fade_reset();

    static inline shader_data init_transition_shader(const bn::affine_bg_item &transition_item, bool use_buffer);
    static void transition_fadein(const bn::affine_bg_item &transition_item, int speed, bool reverse);
    static void transition_fadeout(const bn::affine_bg_item &transition_item, int speed, bool reverse);

private:
    static void perform_op1_fadeout();
    static void perform_act_fadeout();
    static void perform_render_video(const uint8_t* video_file, const char* audio_file, bn::color clear);
    static void perform_render_video(const uint8_t* video_file, const char* audio_file, bn::color clear, bool force_white_end);
    static int get_character_visual_index(character_t character, bool create_if_not_found = true);
    const char* _scenario;
};

extern bn::string<4096> message;
extern bn::string<128> message_doublespeak_a;
extern bn::string<128> message_doublespeak_b;
extern bn::vector<bn::string<128>, 5> answers_messages;
extern dialog_box_default dialog_default;
extern dialog_box_doublespeak dialog_doublespeak;
extern dialog_box_novel dialog_novel;

extern bn::optional<ks::SceneManager> scene;
extern bn::optional<bn::sprite_text_generator> text_generator;
extern bn::optional<bn::sprite_text_generator> text_generator_small;
extern bn::optional<huge_bg> huge_background;
extern bn::optional<bn::regular_bg_ptr> primary_background;
extern bn::optional<bn::regular_bg_ptr> secondary_background;
extern bn::optional<bn::affine_bg_ptr> transition_bg;
extern bn::optional<bn::color> fill_color;
extern bn::optional<bn::unique_ptr<CustomEvent>> next_event;
extern bn::vector<character_visuals_ptr, smart_characters_manager::MAX_CHARS> character_visuals;
extern displayable_visuals_ptr displayable_visual;
extern background_visuals_ptr background_visual;
extern bn::rect_window left_window;
extern bn::rect_window right_window;

extern ks::saves::SaveSlotProgressData progress;
extern ks::saves::SaveSlotProgressData savedata_progress;
extern bool in_replay;
extern bool is_loading;
extern bool is_paused;
extern bool is_returned_from_pause;
extern unsigned char savedata_answer_index;

extern bn::vector<bn::sprite_ptr, 18> progress_icon_sprites;
extern bn::vector<bn::sprite_ptr, 64> static_text_sprites;
extern bn::vector<bn::sprite_ptr, 128> animated_text_sprites;

} // namespace ks

#endif // KS_SCENEMANAGER_H
