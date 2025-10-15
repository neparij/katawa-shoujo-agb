#include "translation.h"
#include "jp_definitions_labels.h"

namespace ks {

class TranslationJp final : public Translation {
public:
    language_t type() override {
        return LANG_JAPAN;
    }
    const char* locale() override {return "jp";}
    const char* language() override {return language_jp();}
    #include "jp_definitions_commons.inc"

    const char* menu_start() override {return "はじめから";}
    const char* menu_saves() override {return "セーブ";}
    const char* menu_extras() override {return "おまけ";}
    const char* menu_options() override {return "環境設定";}
    const char* menu_language() override {return "言語選択";}
    const char* menu_accessibility() override {return "アクセシビリティ";}

    const char* menu_options_general() override {return "一般";}
    const char* menu_options_sound() override {return "サウンド";}
    const char* menu_options_hdisabled() override {return "成人向けコンテンツ無効";}
    const char* menu_options_language() override {return "言語選択…";}
    const char* menu_options_accessibility() override {return "アクセシビリティ…";}
    const char* menu_options_music_volume() override {return "BGM音量";}
    const char* menu_options_sfx_volume() override {return "SE音量";}

    const char* menu_options_accessibility_display() override {return "ディスプレイ";}
    const char* menu_options_accessibility_text_speed() override {return "テキスト表示速度";}
    const char* menu_options_accessibility_brightness() override {return "明るさ";}
    const char* menu_options_accessibility_high_contrast() override {return "高コントラスト";}
    const char* menu_options_accessibility_mental() override {return "メンタルヘルス";}
    bn::array<const char*, 4> menu_options_accessibility_disable_disturbing_content() override {
        return {"傷つくような大人向けのシーンを", "スキップする"};
    }

    const char* menu_extras_jukebox() override {return "音楽室";}
    const char* menu_extras_gallery() override {return "美術室";}
    const char* menu_extras_library() override {return "図書室";}
    const char* menu_extras_cinema() override {return "視聴覚室";}

    unsigned int menu_extras_jukebox_xoffset() override {return 0;}
    unsigned int menu_extras_gallery_xoffset() override {return 0;}
    unsigned int menu_extras_library_xoffset() override {return 0;}
    unsigned int menu_extras_cinema_xoffset() override {return 0;}
    unsigned int menu_extras_return_xoffset() override {return 0;}

    const char* menu_back() override {return "戻る";}
    const char* menu_page() override {return "ページ";}

    const char* screens_return() override {return "戻る";}
    const char* screens_history() override {return "テキストログ (n/a)";}
    const char* screens_options() override {return "環境設定";}
    const char* screens_saves_menu() override {return "セーブ";}
    const char* screens_main_menu() override {return "タイトル";}

    const char* textbutton_save() override {return "セーブ";}
    const char* saves_auto_suffix() override {return "(auto)";}

    const char* screens_playtime() override {return "経過時間";}
    const char* screens_current_scene() override {return "シーン";}
    const char* screens_current_track() override {return "BGM";}
    const char* screens_now_playing() override {return "演奏中";}

    const char* label(const label_t label) override {
        if (const char* tl = get_label_jp_translation(label); tl != nullptr) {
            return tl;
        }
        return definitions_no_scene();
    }

    opening_text opening_text_act1() override {return {"Act 1:", "推定寿命"};}
    opening_text opening_text_act2_emi() override {return {"Act 2:", "フォーム"};}
    opening_text opening_text_act2_hanako() override {return {"Act 2:", "かくれんぼ"};}
    opening_text opening_text_act2_lilly() override {return {"Act 2:", "過去"};}
    opening_text opening_text_act2_rin() override {return {"Act 2:", "すれ違い"};}
    opening_text opening_text_act2_shizune() override {return {"Act 2:", "読む練習"};}
    opening_text opening_text_act3_emi() override {return {"Act 3:", "パースペクティブ"};}
    opening_text opening_text_act3_hanako() override {return {"Act 3:", "キャスリング"};}
    opening_text opening_text_act3_lilly() override {return {"Act 3:", "現在"};}
    opening_text opening_text_act3_rin() override {return {"Act 3:", "溝"};}
    opening_text opening_text_act3_shizune() override {return {"Act 3:", "器用な手つき"};}
    opening_text opening_text_act4_emi() override {return {"Act 4:", "モーション"};}
    opening_text opening_text_act4_hanako() override {return {"Act 4:", "キズアト"};}
    opening_text opening_text_act4_lilly() override {return {"Act 4:", "未来"};}
    opening_text opening_text_act4_rin() override {return {"Act 4:", "夢"};}
    opening_text opening_text_act4_shizune() override {return {"Act 4:", "もう一人の私へ"};}
};
}
