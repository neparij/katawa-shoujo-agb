#include "translation.h"

#include "act_opening.h"
#include "definitions_labels.h"

namespace ks::tl {

    language_t type() {
        return LANG_JAPAN;
    }
    const char* locale() {return "jp";}
    #include "definitions_commons.inc"

    const char* menu_start() {return "はじめから";}
    const char* menu_saves() {return "セーブ";}
    const char* menu_extras() {return "おまけ";}
    const char* menu_options() {return "環境設定";}
    const char* menu_accessibility() {return "アクセシビリティ";}

    const char* menu_options_general() {return "一般";}
    const char* menu_options_sound() {return "サウンド";}
    const char* menu_options_hdisabled() {return "成人向けコンテンツ無効";}
    const char* menu_options_language() {return "言語選択…";}
    const char* menu_options_accessibility() {return "アクセシビリティ…";}
    const char* menu_options_music_volume() {return "BGM音量";}
    const char* menu_options_sfx_volume() {return "SE音量";}

    const char* menu_options_accessibility_display() {return "ディスプレイ";}
    const char* menu_options_accessibility_text_speed() {return "テキスト表示速度";}
    const char* menu_options_accessibility_brightness() {return "明るさ";}
    const char* menu_options_accessibility_high_contrast() {return "高コントラスト";}
    const char* menu_options_accessibility_mental() {return "メンタルヘルス";}
    bn::array<const char*, 4> menu_options_accessibility_disable_disturbing_content() {
        return {"傷つくような大人向けのシーンを", "スキップする"};
    }

    const char* menu_extras_jukebox() {return "音楽室";}
    const char* menu_extras_gallery() {return "美術室";}
    const char* menu_extras_library() {return "図書室";}
    const char* menu_extras_cinema() {return "視聴覚室";}

    unsigned int menu_extras_jukebox_xoffset() {return 0;}
    unsigned int menu_extras_gallery_xoffset() {return 0;}
    unsigned int menu_extras_library_xoffset() {return 0;}
    unsigned int menu_extras_cinema_xoffset() {return 0;}
    unsigned int menu_extras_return_xoffset() {return 0;}

    const char* menu_back() {return "戻る";}
    const char* menu_page() {return "ページ";}

    const char* screens_return() {return "戻る";}
    const char* screens_history() {return "テキストログ (n/a)";}
    const char* screens_options() {return "環境設定";}
    const char* screens_saves_menu() {return "セーブ";}
    const char* screens_main_menu() {return "タイトル";}

    const char* textbutton_save() {return "セーブ";}
    const char* saves_auto_suffix() {return "(auto)";}

    const char* screens_playtime() {return "経過時間";}
    const char* screens_current_scene() {return "シーン";}
    const char* screens_current_track() {return "BGM";}
    const char* screens_now_playing() {return "演奏中";}

    const char* label(const label_t label) {
        if (const char* tl = get_label_translation(label); tl != nullptr) {
            return tl;
        }
        return definitions_no_scene();
    }

    opening_text opening_text_act1() {return {"Act 1:", "推定寿命"};}
    opening_text opening_text_act2_emi() {return {"Act 2:", "フォーム"};}
    opening_text opening_text_act2_hanako() {return {"Act 2:", "かくれんぼ"};}
    opening_text opening_text_act2_lilly() {return {"Act 2:", "過去"};}
    opening_text opening_text_act2_rin() {return {"Act 2:", "すれ違い"};}
    opening_text opening_text_act2_shizune() {return {"Act 2:", "読む練習"};}
    opening_text opening_text_act3_emi() {return {"Act 3:", "パースペクティブ"};}
    opening_text opening_text_act3_hanako() {return {"Act 3:", "キャスリング"};}
    opening_text opening_text_act3_lilly() {return {"Act 3:", "現在"};}
    opening_text opening_text_act3_rin() {return {"Act 3:", "溝"};}
    opening_text opening_text_act3_shizune() {return {"Act 3:", "器用な手つき"};}
    opening_text opening_text_act4_emi() {return {"Act 4:", "モーション"};}
    opening_text opening_text_act4_hanako() {return {"Act 4:", "キズアト"};}
    opening_text opening_text_act4_lilly() {return {"Act 4:", "未来"};}
    opening_text opening_text_act4_rin() {return {"Act 4:", "夢"};}
    opening_text opening_text_act4_shizune() {return {"Act 4:", "もう一人の私へ"};}
}
