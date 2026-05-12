#include "translation.h"

#include "act_opening.h"
#include "definitions_labels.h"

namespace ks::tl {
    language_t type() {
        return LANG_SPANISH;
    }
    const char* locale() {return "es";}
    #include "definitions_commons.inc"

    const char* menu_start() {return "Inicio";}
    const char* menu_saves() {return "Cargar";}
    const char* menu_extras() {return "Extras";}
    const char* menu_options() {return "Opciones";}
    const char* menu_accessibility() {return "Accesibilidad";}

    const char* menu_options_general() {return "General";}
    const char* menu_options_sound() {return "Sonido";}
    const char* menu_options_hdisabled() {return "Deshabilitar contenido adulto";}
    const char* menu_options_language() {return "Selección de idioma…";}
    const char* menu_options_accessibility() {return "Accesibilidad…";}
    const char* menu_options_music_volume() {return "Volumen de música";}
    const char* menu_options_sfx_volume() {return "Volumen SFX";}

    const char* menu_options_accessibility_display() {return "Pantalla";}
    const char* menu_options_accessibility_text_speed() {return "Velocidad del texto";}
    const char* menu_options_accessibility_brightness() {return "Brillo";}
    const char* menu_options_accessibility_high_contrast() {return "Alto contraste";}
    const char* menu_options_accessibility_mental() {return "Salud mental";}
    bn::array<const char*, 4> menu_options_accessibility_disable_disturbing_content() {
        return {"Omitir escenas adultas ofensivas"};
    }

    const char* menu_extras_jukebox() {return "Rocola";}
    const char* menu_extras_gallery() {return "Galería";}
    const char* menu_extras_library() {return "Biblioteca";}
    const char* menu_extras_cinema() {return "Cine";}

    unsigned int menu_extras_jukebox_xoffset() {return 4;}
    unsigned int menu_extras_gallery_xoffset() {return 0;}
    unsigned int menu_extras_library_xoffset() {return 0;}
    unsigned int menu_extras_cinema_xoffset() {return 0;}
    unsigned int menu_extras_return_xoffset() {return 0;}

    const char* menu_back() {return "Atrás";}
    const char* menu_page() {return "Página";}

    const char* screens_return() {return "Regresar";}
    const char* screens_history() {return "Historial (n/a)";}
    const char* screens_options() {return "Opciones";}
    const char* screens_saves_menu() {return "Cargar";}
    const char* screens_main_menu() {return "Menú principal";}

    const char* textbutton_save() {return "Guardar";}
    const char* saves_auto_suffix() {return "(auto)";}

    const char* screens_playtime() {return "Tiempo de juego";}
    const char* screens_current_scene() {return "Escena";}
    const char* screens_current_track() {return "Pista de música";}
    const char* screens_now_playing() {return "Reproduciendo";}

    const char* label(const label_t label) {
        if (const char* tl = get_label_translation(label); tl != nullptr) {
            return tl;
        }
        return definitions_no_scene();
    }

    opening_text opening_text_act1() {return {"Act 1:", "Life Expectancy"};}
    opening_text opening_text_act2_emi() {return {"Act 2:", "Form"};}
    opening_text opening_text_act2_hanako() {return {"Act 2:", "Hide and Seek"};}
    opening_text opening_text_act2_lilly() {return {"Act 2:", "Past"};}
    opening_text opening_text_act2_rin() {return {"Act 2:", "Disconnect"};}
    opening_text opening_text_act2_shizune() {return {"Act 2:", "Learning to Read"};}
    opening_text opening_text_act3_emi() {return {"Act 3:", "Perspective"};}
    opening_text opening_text_act3_hanako() {return {"Act 3:", "Castling"};}
    opening_text opening_text_act3_lilly() {return {"Act 3:", "Present"};}
    opening_text opening_text_act3_rin() {return {"Act 3:", "Distance"};}
    opening_text opening_text_act3_shizune() {return {"Act 3:", "Sleight of Hand"};}
    opening_text opening_text_act4_emi() {return {"Act 4:", "Motion"};}
    opening_text opening_text_act4_hanako() {return {"Act 4:", "Scars"};}
    opening_text opening_text_act4_lilly() {return {"Act 4:", "Future"};}
    opening_text opening_text_act4_rin() {return {"Act 4:", "Dream"};}
    opening_text opening_text_act4_shizune() {return {"Act 4:", "To My Other Self"};}
}
