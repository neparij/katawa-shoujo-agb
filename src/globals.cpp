#include "globals.h"

#include "bn_bg_maps.h"
#include "bn_bg_palettes.h"
#include "bn_bg_tiles.h"
#include "bn_sprite_tiles.h"
#include "bn_sprite_palettes.h"

#include "bn_core.h"
#include "bn_memory.h"
#include "fonts/fonts_common.h"
#include "translations/en.cpp"
#include "translations/es.cpp"
#include "translations/ru.cpp"
#include "translations/jp.cpp"
#include "ingametimer.h"
#include "scenemanager.h"
#include "sound_manager.h"
#include "ks_huge_bgs_manager.h"
#include "sound/sound_mixer.h"
#include "utils/scenario_reader.h"

namespace ks::globals {
    void update_system_stats()  {
        system_stats.last_used_cpu = static_cast<uint32_t>((bn::core::last_cpu_usage() * 100).ceil_integer());
        system_stats.ewram_used = static_cast<uint32_t>(bn::memory::used_static_ewram() + bn::memory::used_alloc_ewram());
        system_stats.bg_tiles_used = static_cast<uint16_t>(bn::bg_tiles::used_tiles_count());
        system_stats.bg_maps_used = static_cast<uint16_t>(bn::bg_maps::used_cells_count());
        system_stats.bg_palettes_used = static_cast<uint16_t>(bn::bg_palettes::used_colors_count());
        system_stats.sprite_tiles_used = static_cast<uint16_t>(bn::sprite_tiles::used_tiles_count());
        system_stats.sprite_palettes_used = static_cast<uint16_t>(bn::sprite_palettes::used_colors_count());
    }

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

        update_system_stats();
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
        ks::text_generator_small.reset();

        ks::progress_icon_sprites.clear();
        ks::static_text_sprites.clear();
        ks::animated_text_sprites.clear();
    }

    void release_engine() {
        release_resources();
        i18n.reset();
    }

    void set_language(const language_t tl) {
        settings.language = tl;

        if (settings.language == LANG_ENGLISH) {
            // i18n = new(translation_buffer) TranslationEn();
            i18n = bn::make_unique<TranslationEn>(TranslationEn());
        } else if (settings.language == LANG_SPANISH) {
            i18n = bn::make_unique<TranslationEs>(TranslationEs());
        } else if (settings.language == LANG_RUSSIAN) {
            i18n = bn::make_unique<TranslationRu>(TranslationRu());
        } else if (settings.language == LANG_JAPAN) {
            i18n = bn::make_unique<TranslationJp>(TranslationJp());
        } else {
            BN_ERROR("Language is not implemented");
        }
        init_text_generators();

        textdb::init_spm_table(i18n->locale());
    }

    void init_text_generators(const language_t tl) {
        text_generator.reset();
        text_generator_small.reset();

        text_generator = bn::sprite_text_generator(font_default_common_sprite_font);
        text_generator_small = bn::sprite_text_generator(font_small_common_sprite_font);
        text_generator->set_bg_priority(1);
        text_generator->set_z_order(-10);
        text_generator_small->set_bg_priority(1);
        text_generator_small->set_z_order(-10);
    }

    void init_text_generators() {
        init_text_generators(i18n->type());
    }

    void accessibility_apply() {
        bn::bg_palettes::set_brightness(bn::fixed(settings.brightness).division(1023));
        bn::sprite_palettes::set_brightness(bn::fixed(settings.brightness).division(1023));
        bn::bg_palettes::set_contrast(bn::fixed(settings.high_contrast ? 0.1 : 0));
        bn::sprite_palettes::set_contrast(bn::fixed(settings.high_contrast ? 0.1 : 0));
    }

    [[nodiscard]] bn::fixed transparency_alpha() {
        return settings.high_contrast ? 1.0 : 0.85;
    }
}
