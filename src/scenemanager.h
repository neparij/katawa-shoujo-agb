#ifndef KS_SCENEMANAGER_H
#define KS_SCENEMANAGER_H


#include "bn_regular_bg_actions.h"
#include "bn_regular_bg_item.h"
#include "bn_sprite_actions.h"
#include "bn_blending_actions.h"
#include "dialogbox.cpp.h"
#include <bn_regular_bg_ptr.h>
#include "bn_sprite_palette_ptr.h"
#include "character_sprite_meta.h"
#include "savefile/save_file.h"

#include "bn_regular_bg_items_ui_ingame_menu_background_0.h"

namespace ks {

struct character_visuals_ptr
{
    int index;
    bn::optional<bn::regular_bg_item> bg_item;
    bn::optional<bn::sprite_item> sprite_item;
    bn::optional<ks::character_sprite_meta> sprite_meta;

    bn::optional<bn::regular_bg_ptr> background;
    bn::optional<bn::sprite_ptr> sprite;
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
    static void set_background(const bn::regular_bg_item& bg);
    static void show_dialog(bn::string<16> actor, int tl_key);
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
    static void hide_character(const int character_index);
    static void hide_character(const int character_index, const bool need_update);
    static void music_play(const char *filename);
    static void music_play(const char *filename, bn::fixed fade);
    static void music_stop();

    static void open_ingame_menu();
    static void close_ingame_menu();

    constexpr const char* scenario() const { return _scenario; }
    constexpr const char* locale() const { return _locale; }
    constexpr const unsigned int* translation_index() const { return _script_tl_index; }

private:
    const char* _scenario;
    const char* _locale;
    const unsigned int* _script_tl_index;
};

extern bn::optional<ks::SceneManager> scene;
extern bn::sprite_text_generator* text_generator;
extern ks::DialogBox* dialog;
extern bn::optional<bn::regular_bg_ptr> main_background;
extern bn::optional<bn::regular_bg_ptr> secondary_background;
extern bn::vector<character_visuals_ptr, 8> character_visuals;
extern bn::vector<unsigned char, 5> answers_index_map;
extern ks::saves::SaveSlotProgressData progress;
extern bool in_replay;

// extern bn::vector<bn::sprite_ptr, 64> menu_text_sprites;

} // namespace ks

#endif // KS_SCENEMANAGER_H
