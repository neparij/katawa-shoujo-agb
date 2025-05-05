#ifndef KS_SCENEMANAGER_H
#define KS_SCENEMANAGER_H


#include "bn_regular_bg_item.h"
#include "bn_affine_bg_item.h"
#include "character.h"
#include "dialogbox.cpp.h"
#include <bn_blending_transparency_attributes_hbe_ptr.h>
#include <bn_regular_bg_ptr.h>
#include <bn_affine_bg_ptr.h>
#include <bn_unique_ptr.h>

#include "background_meta.h"
#include "character_sprite_meta.h"
#include "gba_base.h"
#include "gba_types.h"
#include "savefile/save_file.h"
#include "ext_bg_blocks_manager.h"
#include "events/custom_event.h"
#include "shaders/vram_dma_shader.h"


#define IF_NOT_EXIT(step)                         \
if (ks::globals::exit_scenario) {                 \
    return;                                       \
}                                                 \
step;

#define SKIP_IF_LOAD_ANOTHER_SCENE(val)           \
if (ks::is_loading) {                             \
    if (ks::progress.metadata.script != val) {    \
        return;                                   \
    }                                             \
}

namespace ks {

struct background_visuals_ptr
{
    bn::optional<bn::regular_bg_item> visible_bg_item;
    bn::optional<bn::regular_bg_item> bg_item;
    bn::optional<bn::color> fill_color;
    bn::fixed alpha;
    bool will_show;
    bool will_hide;
    int position_x;
    int position_y;
    int dissolve_time;
    bool dissolve_on_top;
    scene_transition_t transition;
};

struct character_restoration_data {
    character_t character;
    bn::regular_bg_item& bg_item;
    bn::sprite_item& sprite_item;
    character_sprite_meta& sprite_meta;
    int position_x;
    int position_y;
};

struct character_visuals_ptr
{
    int index;
    character_t character;
    bn::optional<bn::regular_bg_item> visible_bg_item;
    bn::optional<bn::sprite_item> visible_sprite_item;
    bn::optional<bn::regular_bg_item> bg_item;
    bn::optional<bn::sprite_item> sprite_item;
    bn::optional<ks::character_sprite_meta> sprite_meta;

    bn::optional<bn::regular_bg_ptr> background;
    bn::optional<bn::sprite_ptr> sprite;
    bn::fixed alpha;
    bool will_show;
    bool will_hide;
    int position_x;
    int position_y;
    int tiles_x;
    int tiles_y;
    int offset_x;
    int offset_y;
};

struct answer_ptr
{
    const unsigned char index;
    const unsigned int tl_key;
};

class SceneManager {
public:
    constexpr SceneManager(const char* scenario, const char* locale, const unsigned int* translations)
        : _scenario(scenario), _locale(locale), _script_tl_index(translations) {}
    constexpr ~SceneManager() = default;


    static void free_resources();
    static void set(const ks::SceneManager instance);
    static void init_savedata(ks::saves::SaveSlotProgressData &value);
    static void set_script(const script_t script);
    static void set_label(const label_t label);
    static void set_line_hash(const unsigned int line_hash);
    static void autosave();
    static void save(unsigned short slot_index);
    static void prepare_save_metadata();

    // Acions

    static void set_background(const background_meta& bg,
                           const int position_x,
                           const int position_y,
                           scene_transition_t transition,
                           const int dissolve_time);
    static void hide_background(scene_transition_t transition, int dissolve_time);
    static void set_background_position(const int position_x,
                                       const int position_y);
    static void set_background_transition(scene_transition_t transition);
    static void enable_fill(bn::color color);
    static void disable_fill();

    static void set_event(const background_meta& bg,
                          const CustomEvent& event,
                          scene_transition_t transition,
                          int dissolve_time);

    static void show_dialog(const ks::character_definition& actor, int tl_key);
    static void show_dialog(const char* actor_name, int tl_key);
    static void show_dialog_question(bn::vector<ks::answer_ptr, 5> answers);
    static int get_dialog_question_answer();
    static void show_character(const character_t character,
                               const ks::character_sprite_meta& sprite_meta,
                               const bn::regular_bg_item& bg,
                               const bn::sprite_item& sprite);
    static void show_character(const character_t character,
                               const ks::character_sprite_meta& sprite_meta,
                               const bn::regular_bg_item& bg,
                               const bn::sprite_item& sprite,
                               const int position_x,
                               const int position_y);
    static void show_character(const character_t character,
                               const ks::character_sprite_meta& sprite_meta,
                               const bn::regular_bg_item& bg,
                               const bn::sprite_item& sprite,
                               const int position_x,
                               const int position_y,
                               const bool position_change);
    static void set_character_position(const character_t character,
                                       const int position_x,
                                       const int position_y);
    // static void set_character_window_visibility(bn::regular_bg_ptr bg, bn::fixed target_x, bn::fixed target_y);
    static void set_character_window_visibility(bn::regular_bg_ptr bg);
    static void hide_character(const character_t character);
    static void hide_character(const character_t character, const bool need_update, bool remove);

    static void perform_transition(scene_transition_t transition, const bn::optional<bn::regular_bg_item>& to);
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

    static void show_video(const uint8_t* agmv_file, size_t agmv_size, const char* audio_file, bn::color clear);
    static void show_video(const uint8_t* agmv_file, size_t agmv_size, const char* audio_file);

    static void exit_scenario_from_ingame_menu();

    static void pause(const int ticks);

    static void timeskip();

    static void fade_in(const bn::color &color, const int steps);
    static void fade_out(const bn::color &color, const int steps);
    static void fade_in(const bn::color &color);
    static void fade_out(const bn::color &color);
    static void fade_reset();

    static inline shader_data init_transition_shader(const bn::affine_bg_item &transition_item, bool use_buffer);
    static void transition_fadein(const bn::affine_bg_item &transition_item, int speed, bool reverse);
    static void transition_fadeout(const bn::affine_bg_item &transition_item, int speed, bool reverse);

    constexpr const char* scenario() const { return _scenario; }
    constexpr const char* locale() const { return _locale; }
    constexpr const unsigned int* translation_index() const { return _script_tl_index; }

private:
    static int get_character_visual_index(character_t character, bool create_if_not_found = true);
    const char* _scenario;
    const char* _locale;
    const unsigned int* _script_tl_index;
};

extern u8* text_db;
extern u32 text_db_size;
extern bool text_db_allocated;
extern bn::string<1024> message;
extern bn::vector<bn::string<128>, 5> answers_messages;

extern bn::optional<ks::SceneManager> scene;
extern bn::optional<bn::sprite_text_generator> text_generator;
extern bn::optional<bn::sprite_text_generator> text_generator_bold;
extern bn::optional<bn::sprite_text_generator> text_generator_small;
extern ks::DialogBox* dialog;
extern bn::optional<bn::regular_bg_ptr> primary_background;
extern bn::optional<bn::regular_bg_ptr> secondary_background;
extern bn::optional<bn::affine_bg_ptr> transition_bg;
extern bn::optional<bn::color> fill_color;
extern bn::optional<bn::unique_ptr<CustomEvent>> custom_event;
extern bn::vector<character_visuals_ptr, 4> character_visuals;
extern bn::vector<character_restoration_data, 4> character_restoration;
extern background_visuals_ptr background_visual;
extern bn::rect_window left_window;
extern bn::rect_window right_window;

extern bn::vector<unsigned char, 5> answers_index_map;
extern ks::saves::SaveSlotProgressData progress;
extern ks::saves::SaveSlotProgressData savedata_progress;
extern bool in_game;
extern bool in_replay;
extern bool is_loading;
extern bool is_paused;
extern unsigned char savedata_answer_index;

extern bn::vector<bn::sprite_ptr, 18> progress_icon_sprites;
extern bn::vector<bn::sprite_ptr, 64> static_text_sprites;
extern bn::vector<bn::sprite_ptr, 128> animated_text_sprites;

} // namespace ks

#endif // KS_SCENEMANAGER_H
