#include "globals.h"

#include "bn_bg_palettes.h"
#include "bn_core.h"
#include "bn_memory.h"
#include "translation_en.cpp"
#include "translation_ru.cpp"
// #include "translation_en.cpp"
#include "bn_sprite_palettes.h"
#include "bn_sprite_ptr.h"
#include "gba_systemcalls.h"
#include "gba_video.h"
#include "ingametimer.h"
#include "scenemanager.h"
#include "sound_manager.h"
#include "fonts_info.h"
#include "gsmplayer/player_8ad.h"
#include "gsmplayer/player_gsm.h"

namespace ks {
    namespace globals {
        gameState_t state = GS_INIT;
        bool exit_scenario = false;
        bn::unique_ptr<Translation> i18n;
        saves::SaveSettingsData settings = saves::SaveSettingsData();

        void main_update() {
            if (is_loading) {
                BN_LOG("[WARN] Main update while loading!");
            }
            SceneManager::update();
            bn::core::update();
            sound_manager::update();
        }

        void BN_CODE_IWRAM ISR_VBlank() {
            if (!is_loading) {
                sound_manager::on_vblank();
                timer::update();
            }
        }

        // Updates the sound only, while waiting for V-Blank.
        // Used on expensive operations to reduce sound-flickering.
        void BN_CODE_IWRAM sound_update() {
            if (is_loading) {
                BN_LOG("[WARN] Sound update while loading!");
            }
            if (REG_VCOUNT == 159) {
                while (REG_VCOUNT == 159) {
                }
            } else {
                VBlankIntrWait();
            }
            sound_manager::update();
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

            ks::progress_icon_sprites.clear();
            ks::static_text_sprites.clear();
            ks::animated_text_sprites.clear();
            ks::text_generator = bn::sprite_text_generator(font_playtime_sprite_font);
            ks::text_generator_bold = bn::sprite_text_generator(font_playtime_bold_sprite_font);
            text_generator->set_bg_priority(1);
            text_generator->set_z_order(-10);
            text_generator_bold->set_bg_priority(1);
            text_generator_bold->set_z_order(-10);

            ks::dialog = new ks::DialogBox(ks::text_generator.value(), ks::text_generator_bold.value(), ks::static_text_sprites, ks::animated_text_sprites);

            ks::globals::accessibility_apply();
        }

        void init_engine() {
            init_engine(bn::nullopt);
        }

        void release_engine() {
            ks::primary_background.reset();
            ks::secondary_background.reset();
            ks::transition_bg.reset();
            ks::text_generator.reset();
            ks::text_generator_bold.reset();

            ks::progress_icon_sprites.clear();
            ks::static_text_sprites.clear();
            ks::animated_text_sprites.clear();
            // ks::scene.reset();

            // delete &ks::text_db;
            // delete ks::globals::i18n;

            bn::memory::log_alloc_ewram_status();

            delete ks::dialog;
            i18n.reset();

            // bn::memory::log_alloc_ewram_status();

            playerGSM_unload();
            player8AD_unload();
        }

        void set_language(language_t tl) {
            settings.language = tl;

            if (settings.language == LANG_ENGLISH) {
                // i18n = new(translation_buffer) TranslationEn();
                i18n = bn::make_unique<TranslationEn>(TranslationEn());
            } else if (settings.language == LANG_RUSSIAN) {
                i18n = bn::make_unique<TranslationRu>(TranslationRu());
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
    }
}
