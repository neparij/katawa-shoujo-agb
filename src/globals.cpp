#include "globals.h"

#include "bn_bg_palettes.h"
#include "bn_core.h"
#include "bn_memory.h"
#include "translations/en.cpp"
#include "translations/ru.cpp"
#include "bn_sprite_palettes.h"
#include "ingametimer.h"
#include "scenemanager.h"
#include "sound_manager.h"
#include "fonts_info.h"
#include "ks_huge_bgs_manager.h"
#include "sound/sound_mixer.h"

namespace ks::globals {
    void init_filesystem() {
        BN_LOG("Initializing filesystem...");
        filesystem = find_first_gbfs_file(nullptr);
        if (filesystem == nullptr) {
            BN_ERROR("GBFS filesystem not found or ROM is corrupted!");
        } else {
            BN_LOG("GBFS found: ", filesystem->total_len, " bytes");
        }
    }

    void main_update() {
        if (is_loading) {
            BN_LOG("[WARN] Main update while loading!");
        }
        huge_bgs_manager::update();
        SceneManager::update();
        bn::core::update();
        sound_manager::update();
        update_konami_code();
    }

    void BN_CODE_IWRAM ISR_VBlank() {
        if (!is_loading) {
            timer::update();
        }
    }

    void init_engine(const bn::optional<bn::color> &clear_color) {
        bn::core::init(clear_color, bn::string_view(), ISR_VBlank, sound_mixer::update);
        sound_manager::init();

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
        ks::text_generator_small = bn::sprite_text_generator(font_playtime_small_sprite_font);
        text_generator->set_bg_priority(1);
        text_generator->set_z_order(-10);
        text_generator_bold->set_bg_priority(1);
        text_generator_bold->set_z_order(-10);
        text_generator_small->set_bg_priority(1);
        text_generator_small->set_z_order(-10);

        ks::dialog = new ks::DialogBox(ks::text_generator.value(), ks::text_generator_bold.value(),
                                       ks::static_text_sprites, ks::animated_text_sprites);

        ks::globals::accessibility_apply();
    }

    void init_engine() {
        init_engine(bn::nullopt);
    }

    void release_resources() {
        ks::huge_background.reset();
        ks::primary_background.reset();
        ks::secondary_background.reset();
        ks::transition_bg.reset();
        ks::text_generator.reset();
        ks::text_generator_bold.reset();
        ks::text_generator_small.reset();

        ks::progress_icon_sprites.clear();
        ks::static_text_sprites.clear();
        ks::animated_text_sprites.clear();
    }

    void release_engine() {
        release_resources();

        delete ks::dialog;
        i18n.reset();
    }

    void set_language(const language_t tl) {
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
}
