#ifndef KS_SCENEMANAGER_H
#define KS_SCENEMANAGER_H


#include "bn_regular_bg_actions.h"
#include "bn_sprite_actions.h"
#include "bn_blending_actions.h"
#include "sequence/sequenceitem.h"
#include "dialogbox.cpp.h"
#include <bn_regular_bg_ptr.h>
#include "bn_sprite_palette_ptr.h"
#include "character_sprite_meta.h"

#include "gsmplayer/player.h"
#include "gsmplayer/player_sfx.h"
#include "utils/gbfs/gbfs.h"


namespace ks {

struct character_visuals_ptr
{
    const bn::regular_bg_item* background_item_ptr;
    bn::optional<bn::regular_bg_ptr> background;
    bn::optional<bn::sprite_ptr> sprite;
    bn::optional<bn::regular_bg_move_to_action> bg_move_action;
    bn::optional<bn::sprite_move_to_action> spr_move_action;
    bn::optional<bn::blending_transparency_alpha_to_action> spr_alpha_action;
    int position_x;
    int position_y;
    int tiles_x;
    int tiles_y;
    int offset_x;
    int offset_y;
};

extern bn::optional<bn::regular_bg_ptr> main_background;
extern bn::optional<bn::regular_bg_ptr> secondary_background;
extern bn::vector<character_visuals_ptr, 4> character_visuals;
extern bn::vector<bn::optional<bn::sprite_palette_ptr>, 2> character_palettes;

extern ks::DialogBox* dialog;

class SceneManager {
public:
    constexpr SceneManager(const char* scenario, const char* locale, const unsigned int* translations)
        : _scenario(scenario), _locale(locale), _script_tl_index(translations) {}
    constexpr ~SceneManager() = default;

    // Acions
    static void reset();
    static void set_background(const bn::regular_bg_item& bg);
    static void show_dialog(const ks::SceneManager* scene, bn::string<16> actor, int tl_key);
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
                               const bool position_change);
    static void set_character_position(const int character_index,
                                       // const ks::character_sprite_meta& sprite_meta,
                                       const int position_x,
                                       const int position_y);
    static void hide_character(const int character_index);
    static void hide_character(const int character_index, const bool need_update);
    static void music_play(const char *filename);
    static void music_play(const char *filename, bn::fixed fade);
    static void music_stop();

    constexpr const char* scenario() const { return _scenario; }
    constexpr const char* locale() const { return _locale; }
    constexpr const unsigned int* translation_index() const { return _script_tl_index; }

private:
    const char* _scenario;
    const char* _locale;
    const unsigned int* _script_tl_index;
};

} // namespace ks

#endif // KS_SCENEMANAGER_H
