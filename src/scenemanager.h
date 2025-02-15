#ifndef KS_SCENEMANAGER_H
#define KS_SCENEMANAGER_H


#include "bn_regular_bg_item.h"
#include "character.h"
#include "dialogbox.cpp.h"
#include <bn_blending_transparency_attributes_hbe_ptr.h>
#include <bn_regular_bg_ptr.h>
#include "character_sprite_meta.h"
#include "gba_base.h"
#include "gba_types.h"
#include "savefile/save_file.h"


#define IF_NOT_EXIT(step)                         \
step;                                             \
if (ks::globals::exit_scenario) {                 \
    return;                                       \
}

namespace ks {

struct background_visuals_ptr
{
    bn::optional<bn::regular_bg_item> bg_item;
    bn::regular_bg_ptr* background;
    bn::fixed alpha;
    bool will_show;
    bool will_hide;
    int position_x;
    int position_y;
    int dissolve_time;
    bool dissolve_on_top;
};

struct character_visuals_ptr
{
    int index;
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

    // Acions
    static void free_resources();
    static void set(const ks::SceneManager instance);
    static void set_initial_progress(const ks::saves::SaveSlotProgressData& value);
    // static void set_background(const bn::regular_bg_item& bg);
    static void set_background(const bn::regular_bg_item& bg,
                               const int position_x,
                               const int position_y,
                               const int dissolve_time);
    static void set_background_position(const int position_x,
                                       const int position_y);
    static void show_dialog(const ks::character_definition& actor, int tl_key);
    static void show_dialog(const char* actor_name, int tl_key);
    static void show_dialog_question(bn::vector<ks::answer_ptr, 5> answers);
    static int get_dialog_question_answer();
    static void show_character(const int character_index,
                               const bn::regular_bg_item& bg,
                               const bn::sprite_item& sprite,
                               const ks::character_sprite_meta& sprite_meta);
    static void show_character(const int character_index,
                               const bn::regular_bg_item& bg,
                               const bn::sprite_item& sprite,
                               const ks::character_sprite_meta& sprite_meta,
                               const int position_x,
                               const int position_y);
    static void show_character(const int character_index,
                               const bn::regular_bg_item& bg,
                               const bn::sprite_item& sprite,
                               const ks::character_sprite_meta& sprite_meta,
                               const int position_x,
                               const int position_y,
                               const bool position_change,
                               const bool restoring);
    static void set_character_position(const int character_index,
                                       // const ks::character_sprite_meta& sprite_meta,
                                       const int position_x,
                                       const int position_y);
    // static void set_character_window_visibility(bn::regular_bg_ptr bg, bn::fixed target_x, bn::fixed target_y);
    static void set_character_window_visibility(bn::regular_bg_ptr bg);
    static void hide_character(const int character_index);
    static void hide_character(const int character_index, const bool need_update);
    static void update_visuals();
    static void music_play(const char *filename);
    static void music_play(const char *filename, bn::fixed fade);
    static void music_stop();
    static void sfx_play(const char *filename);
    static void sfx_play(const char *filename, bn::fixed fade);
    static void sfx_stop();

    static void show_video(const uint8_t* agmv_file, size_t agmv_size, const char* audio_file, bn::color clear);
    static void show_video(const uint8_t* agmv_file, size_t agmv_size, const char* audio_file);

    static void open_ingame_menu();
    static void close_ingame_menu();
    static void exit_scenario_from_ingame_menu();

    static void pause(const int ticks);

    static void fade_in(const bn::color &color, const int steps);
    static void fade_out(const bn::color &color, const int steps);
    static void fade_in(const bn::color &color);
    static void fade_out(const bn::color &color);
    static void fade_reset();

    constexpr const char* scenario() const { return _scenario; }
    constexpr const char* locale() const { return _locale; }
    constexpr const unsigned int* translation_index() const { return _script_tl_index; }

private:
    const char* _scenario;
    const char* _locale;
    const unsigned int* _script_tl_index;

    static ks::character_definition _cached_actor;  // Cache for actor (used by ingame pause)
    static int _cached_tl_key;       // Cache for tl_key (used by ingame pause)
};

// alignas(4) extern u8* text_db;
// alignas(4) extern EWRAM_DATA u8* text_db;
// alignas(4) extern EWRAM_DATA u8 text_db[131072];
extern EWRAM_DATA u8 text_db[131072];
// alignas(4) extern EWRAM_DATA u8 text_db[65536];
extern u32 text_db_size;

extern bn::optional<ks::SceneManager> scene;
extern bn::sprite_text_generator* text_generator;
extern ks::DialogBox* dialog;
extern bn::optional<bn::regular_bg_ptr> main_background;
extern bn::optional<bn::regular_bg_ptr> secondary_background;
extern bn::optional<bn::regular_bg_ptr> tertiary_background;
extern bn::vector<character_visuals_ptr, 8> character_visuals;
extern background_visuals_ptr background_visual;
extern bn::rect_window left_window;
extern bn::rect_window right_window;

extern bn::array<bn::blending_transparency_attributes, 160> transparency_attributes;
extern bn::optional<bn::blending_transparency_attributes_hbe_ptr> transparency_attributes_hbe;

extern bn::vector<unsigned char, 5> answers_index_map;
extern ks::saves::SaveSlotProgressData progress;
extern ks::saves::SaveSlotProgressData initial_progress;
extern bool in_replay;

extern bn::vector<bn::sprite_ptr, 18>* progress_icon_sprites;
extern bn::vector<bn::sprite_ptr, 64>* static_text_sprites;
extern bn::vector<bn::sprite_ptr, 128>* animated_text_sprites;

} // namespace ks

#endif // KS_SCENEMANAGER_H
