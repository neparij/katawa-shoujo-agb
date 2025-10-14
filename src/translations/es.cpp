#include "translation.h"
#include "es_definitions_labels.h"

namespace ks {

class TranslationEs final : public Translation {
public:
    language_t type() override {
        return LANG_SPANISH;
    }
    const char* locale() override {return "es";}
    const char* language() override {return language_es();}
    #include "es_definitions_commons.inc"

    const char* menu_start() override {return "Inicio";}
    const char* menu_saves() override {return "Cargar";}
    const char* menu_extras() override {return "Extras";}
    const char* menu_options() override {return "Opciones";}
    const char* menu_language() override {return "Idioma";}
    const char* menu_accessibility() override {return "Accesibilidad";}

    const char* menu_options_general() override {return "General";}
    const char* menu_options_sound() override {return "Sonido";}
    const char* menu_options_hdisabled() override {return "Deshabilitar contenido adulto";}
    const char* menu_options_language() override {return "Selección de idioma…";}
    const char* menu_options_accessibility() override {return "Accesibilidad…";}
    const char* menu_options_music_volume() override {return "Volumen de música";}
    const char* menu_options_sfx_volume() override {return "Volumen SFX";}

    const char* menu_options_accessibility_display() override {return "Pantalla";}
    const char* menu_options_accessibility_text_speed() override {return "Velocidad del texto";}
    const char* menu_options_accessibility_brightness() override {return "Brillo";}
    const char* menu_options_accessibility_high_contrast() override {return "Alto contraste";}
    const char* menu_options_accessibility_mental() override {return "Salud mental";}
    bn::array<const char*, 4> menu_options_accessibility_disable_disturbing_content() override {
        return {"Omitir escenas adultas ofensivas"};
    }

    const char* menu_extras_jukebox() override {return "Rocola";}
    const char* menu_extras_gallery() override {return "Galería";}
    const char* menu_extras_library() override {return "Biblioteca";}
    const char* menu_extras_cinema() override {return "Cine";}

    unsigned int menu_extras_jukebox_xoffset() override {return 4;}
    unsigned int menu_extras_gallery_xoffset() override {return 0;}
    unsigned int menu_extras_library_xoffset() override {return 0;}
    unsigned int menu_extras_cinema_xoffset() override {return 0;}
    unsigned int menu_extras_return_xoffset() override {return 0;}

    const char* menu_back() override {return "Atrás";}
    const char* menu_page() override {return "Página";}

    const char* screens_return() override {return "Regresar";}
    const char* screens_history() override {return "Historial (n/a)";}
    const char* screens_options() override {return "Opciones";}
    const char* screens_saves_menu() override {return "Cargar";}
    const char* screens_main_menu() override {return "Menú principal";}

    const char* textbutton_save() override {return "Guardar";}
    const char* saves_auto_suffix() override {return "(auto)";}

    const char* screens_playtime() override {return "Tiempo de juego";}
    const char* screens_current_scene() override {return "Escena";}
    const char* screens_current_track() override {return "Pista de música";}
    const char* screens_now_playing() override {return "Reproduciendo";}

    const char* label(const label_t label) override {
        if (const char* tl = get_label_es_translation(label); tl != nullptr) {
            return tl;
        }
        return definitions_no_scene();
    }

    opening_text opening_text_act1() override {return {"Act 1:", "Life Expectancy"};}
    opening_text opening_text_act2_emi() override {return {"Act 2:", "Form"};}
    opening_text opening_text_act2_hanako() override {return {"Act 2:", "Hide and Seek"};}
    opening_text opening_text_act2_lilly() override {return {"Act 2:", "Past"};}
    opening_text opening_text_act2_rin() override {return {"Act 2:", "Disconnect"};}
    opening_text opening_text_act2_shizune() override {return {"Act 2:", "Learning to Read"};}
    opening_text opening_text_act3_emi() override {return {"Act 3:", "Perspective"};}
    opening_text opening_text_act3_hanako() override {return {"Act 3:", "Castling"};}
    opening_text opening_text_act3_lilly() override {return {"Act 3:", "Present"};}
    opening_text opening_text_act3_rin() override {return {"Act 3:", "Distance"};}
    opening_text opening_text_act3_shizune() override {return {"Act 3:", "Sleight of Hand"};}
    opening_text opening_text_act4_emi() override {return {"Act 4:", "Motion"};}
    opening_text opening_text_act4_hanako() override {return {"Act 4:", "Scars"};}
    opening_text opening_text_act4_lilly() override {return {"Act 4:", "Future"};}
    opening_text opening_text_act4_rin() override {return {"Act 4:", "Dream"};}
    opening_text opening_text_act4_shizune() override {return {"Act 4:", "To My Other Self"};}
};
}
