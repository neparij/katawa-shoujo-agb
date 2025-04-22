#include "globals.h"
#include "bn_bg_palettes.h"
#include "bn_core.h"
#include "bn_memory.h"
#include "translation_en.cpp"
#include "translation_ru.cpp"
// #include "translation_en.cpp"
#include "bn_sprite_ptr.h"
#include "gba_systemcalls.h"
#include "gba_video.h"
#include "gsmplayer/player_gsm.h"
#include "gsmplayer/player_8ad.h"
#include "scenemanager.h"
#include "variable_16x16_sprite_font.h"
#include "videoplayer/video_player.h"

#include "bn_bg_palettes.h"
#include "bn_sprite_palettes.h"
#include "ingametimer.h"
#include "sound_manager.h"

#include "common_variable_8x8_sprite_font.h"
// #include <variable_16x16_sprite_font.h>

#include "bn_sprite_items_variable_16x16_font_hi_pal.h"
#include "bn_sprite_items_variable_16x16_font_ha_pal.h"
#include "bn_sprite_items_variable_16x16_font_emi_pal.h"
#include "bn_sprite_items_variable_16x16_font_rin_pal.h"
#include "bn_sprite_items_variable_16x16_font_li_pal.h"
#include "bn_sprite_items_variable_16x16_font_shi_pal.h"
#include "bn_sprite_items_variable_16x16_font_mi_pal.h"
#include "bn_sprite_items_variable_16x16_font_ke_pal.h"
#include "bn_sprite_items_variable_16x16_font_mu_pal.h"
#include "bn_sprite_items_variable_16x16_font_nk_pal.h"
#include "bn_sprite_items_variable_16x16_font_no_pal.h"
#include "bn_sprite_items_variable_16x16_font_yu_pal.h"
#include "bn_sprite_items_variable_16x16_font_sa_pal.h"
#include "bn_sprite_items_variable_16x16_font_aki_pal.h"
#include "bn_sprite_items_variable_16x16_font_hh_pal.h"
#include "bn_sprite_items_variable_16x16_font_hx_pal.h"
#include "bn_sprite_items_variable_16x16_font_emm_pal.h"
#include "bn_sprite_items_variable_16x16_font_sk_pal.h"
#include "bn_sprite_items_variable_16x16_font_mk_pal.h"

namespace ks {
    namespace globals {
        bool exit_scenario = false;
        ks::Translation *i18n; // = new TranslationEn();
        ks::saves::SaveSettingsData settings = ks::saves::SaveSettingsData();

        void main_update() {
            ks::SceneManager::update();
            bn::core::update();
            ks::sound_manager::update();
        }

        void BN_CODE_IWRAM ISR_VBlank() {
            ks::sound_manager::on_vblank();
            timer::update();
        }

        // Updates the sound only, while waiting for V-Blank.
        // Used on expensive operations to reduce sound-flickering.
        void BN_CODE_IWRAM sound_update() {
            if (REG_VCOUNT == 159) {
                while (REG_VCOUNT == 159) {
                }
            } else {
                VBlankIntrWait();
            }
            ks::sound_manager::update();
        }

        void init_engine(const bn::optional<bn::color> &clear_color) {
            bn::core::init(clear_color, bn::string_view(), ks::globals::ISR_VBlank);
            // BN_LOG("PLA", player_sfx_isPlaying());
            ks::sound_manager::init();
            set_language(settings.language);

            if (clear_color.has_value()) {
                bn::bg_palettes::set_transparent_color(clear_color);
            } else {
                bn::bg_palettes::set_transparent_color(colors::BLACK);
            }

            ks::progress_icon_sprites = new bn::vector<bn::sprite_ptr, 18>();
            ks::static_text_sprites = new bn::vector<bn::sprite_ptr, 64>();
            ks::animated_text_sprites = new bn::vector<bn::sprite_ptr, 128>();
            ks::text_generator = new bn::sprite_text_generator(variable_16x16_sprite_font);
            ks::dialog = new ks::DialogBox(ks::text_generator, ks::static_text_sprites, ks::animated_text_sprites);
            ks::progress_icon_sprites->clear();
            ks::static_text_sprites->clear();
            ks::animated_text_sprites->clear();

            ks::globals::accessibility_apply();
        }

        void init_engine() {
            init_engine(bn::nullopt);
        }

        void release_engine() {
            ks::main_background.reset();
            ks::secondary_background.reset();
            ks::transition_bg.reset();
            // ks::scene.reset();

            // delete &ks::text_db;
            // delete ks::globals::i18n;

            bn::memory::log_alloc_ewram_status();

            delete ks::progress_icon_sprites;
            delete ks::static_text_sprites;
            delete ks::animated_text_sprites;
            delete ks::text_generator;
            delete ks::dialog;
            delete ks::globals::i18n;

            // bn::memory::log_alloc_ewram_status();

            playerGSM_unload();
            player8AD_unload();
        }

        void set_language(language_t tl) {
            settings.language = tl;

            if (settings.language == LANG_ENGLISH) {
                i18n = new(translation_buffer) TranslationEn();
            } else if (settings.language == LANG_RUSSIAN) {
                i18n = new(translation_buffer) TranslationRu();
            } else {
                BN_ERROR("Unkown language");
            }
        }

        void accessibility_apply() {
            bn::bg_palettes::set_contrast(bn::fixed(settings.high_contrast ? 0.2 : 0));
            bn::sprite_palettes::set_contrast(bn::fixed(settings.high_contrast ? 0.2 : 0));
        }

        namespace colors {
            constexpr bn::color BLACK = bn::color(0, 0, 0);
            constexpr bn::color WHITE = bn::color(31, 31, 31);
            constexpr bn::color RED = bn::color(31, 0, 0);
        }

        namespace text_palettes {
            // constexpr bn::sprite_palette_item original = bn::sprite_items::variable_16x16_font.palette_item();
            constexpr bn::sprite_palette_item beige = bn::sprite_items::variable_16x16_font_beige_pal.palette_item();
            constexpr bn::sprite_palette_item beige_selected = bn::sprite_items::variable_16x16_font_beige_selected_pal.palette_item();
        }
    }
}
