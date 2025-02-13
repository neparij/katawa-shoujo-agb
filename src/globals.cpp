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
#include "gsmplayer/player.h"
#include "gsmplayer/player_sfx.h"
#include "scenemanager.h"
#include "variable_16x16_sprite_font.h"
#include "videoplayer/video_player.h"

// #include <variable_16x16_sprite_font.h>

namespace ks {
    namespace globals {
        bool exit_scenario = false;
        ks::Translation* i18n;// = new TranslationEn();
        ks::TranslationType language = ks::TranslationType::EN;

        void main_update() {

            bn::core::update();
            // REG_BG0HOFS = -80;
            // REG_BG1HOFS = -80;
            // REG_BG2HOFS = 120;
            // REG_BG3HOFS = 120;

            // REG_BG0CNT |= BG_16_COLOR;
            // REG_BG1CNT |= BG_16_COLOR;
            // REG_BG2CNT |= BG_16_COLOR;
            // REG_BG3CNT |= BG_16_COLOR;

            // REG_BG2CNT |= BG_SIZE_3;
            // REG_BG3CNT |= BG_SIZE_3;

            // if (buffer == g_front_buffer) {
            //     REG_DISPCNT &= ~SHOW_BACKBUFFER;
            //     return g_back_buffer;
            // } else {
            //     REG_DISPCNT |= SHOW_BACKBUFFER;
            //     return g_front_buffer;
            // }

            player_update(0, [](unsigned current) {});
            player_sfx_update();
        };

        void BN_CODE_IWRAM ISR_VBlank() {
            player_onVBlank();
            player_sfx_onVBlank();
        }

        // Updates the sound only, while waiting for V-Blank.
        // Used on expensive operations to reduce sound-flickering.
        void BN_CODE_IWRAM sound_update() {
            if(REG_VCOUNT == 159)
            {
                while(REG_VCOUNT == 159)
                {
                }
            }
            else
            {
                VBlankIntrWait();
            }
            player_update(0, [](unsigned current) {});
            player_sfx_update();
        }

        void init_engine(const bn::optional<bn::color> &clear_color) {
            bn::core::init(clear_color, bn::string_view(), ks::globals::ISR_VBlank);
            // BN_LOG("PLA", player_sfx_isPlaying());
            player_init();
            player_sfx_init();
            set_language(language);

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
        }

        void init_engine() {
            init_engine(bn::nullopt);
        }

        void release_engine() {
            ks::main_background.reset();
            ks::secondary_background.reset();
            ks::tertiary_background.reset();
            // ks::scene.reset();

            // delete &ks::text_db;
            // delete ks::globals::i18n;
            delete ks::progress_icon_sprites;
            delete ks::static_text_sprites;
            delete ks::animated_text_sprites;
            delete ks::text_generator;
            delete ks::dialog;
            delete ks::globals::i18n;

            player_unload();
            player_sfx_unload();
        }

        void set_language(ks::TranslationType tl) {
            language = tl;

            if (language == ks::TranslationType::EN) {
                // ks::globals::i18n = ks::globals::translations::en;
                // ks::globals::i18n = &ks::TranslationEn::i18n;
                // ks::globals::i18n = new ks::TranslationEn();
                ks::globals::i18n = new (translation_buffer) ks::TranslationEn();
            } else if (language == ks::TranslationType::RU) {
                // ks::globals::i18n = ks::globals::translations::ru;
                // ks::globals::i18n = &ks::TranslationRu::i18n;
                // ks::globals::i18n = new ks::TranslationRu();
                ks::globals::i18n = new (translation_buffer) ks::TranslationRu();
            } else {
                BN_ERROR("Unkown language");
            }

        }


        namespace colors {
            constexpr bn::color BLACK = bn::color(0,0,0);
            constexpr bn::color WHITE = bn::color(31,31,31);
            constexpr bn::color RED = bn::color(31,0,0);
        }
    }
}
