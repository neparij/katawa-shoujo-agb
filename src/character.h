#ifndef CHARACTER_H
#define CHARACTER_H

#include <bn_sprite_items_fontpalette_main_bold.h>
#include <bn_sprite_palette_item.h>

#include "globals.h"

namespace ks {

static const char* static_name(const char* name) {
    return name;
}

struct character_definition
{
    const char* (*name)() = 0;
    const char* what_prefix = "\"";
    const char* what_suffix = "\"";
    bn::sprite_palette_item who_color = bn::sprite_items::fontpalette_main_bold.palette_item();
    const char* log_color = "15";

    character_definition with(const char* (*new_name)() = nullptr,
                              const char* new_prefix = nullptr,
                              const char* new_suffix = nullptr,
                              const bn::sprite_palette_item &new_who_color = bn::sprite_items::fontpalette_main_bold.palette_item(),
                              const char* new_log_color = nullptr) const
    {
        return character_definition{
                                    new_name ? new_name : name,
                                    new_prefix ? new_prefix : what_prefix,
                                    new_suffix ? new_suffix : what_suffix,
                                    new_who_color,
                                    new_log_color ? new_log_color : log_color};
    }

    character_definition with_name(const char* new_name) const
    {
        static const char* dynamic_name = nullptr;
        dynamic_name = new_name;

        return character_definition{
                                    []() { return static_name(dynamic_name); },
                                    what_prefix,
                                    what_suffix,
                                    who_color,
                                    log_color};
    }

    bool operator==(const character_definition& other) const {
        return name == other.name &&
               what_prefix == other.what_prefix &&
               what_suffix == other.what_suffix &&
               who_color == other.who_color;
    }
};

namespace definitions {

inline const char* empty_name() { return ""; }

constexpr character_definition base(empty_name, "\"", "\"");

constexpr character_definition no_char = base;

//TODO: n and nvl
constexpr character_definition n = base;

//TODO: centered???
constexpr character_definition centered = base;

//TODO: centered BOLD/BLACK???
constexpr character_definition centered_b = base;

//TODO: extend
constexpr character_definition extend = base;

// One translation unit (character.cpp) holds the data; avoids N× duplication
// in every script object file.
extern const character_definition hi;
extern const character_definition ha;
extern const character_definition emi;
extern const character_definition rin;
extern const character_definition li;
extern const character_definition shi;
extern const character_definition mi;
extern const character_definition ke;
extern const character_definition mu;
extern const character_definition nk;
extern const character_definition no;
extern const character_definition yu;
extern const character_definition sa;
extern const character_definition aki;
extern const character_definition hh;
extern const character_definition hx;
extern const character_definition emm;
extern const character_definition sk;
extern const character_definition mk;

extern const character_definition mi_shi;
extern const character_definition mi_not_shi;

extern const character_definition mystery;

extern const character_definition ssh;
extern const character_definition his;

extern const character_definition ha_;
extern const character_definition emi_;
extern const character_definition rin_;
extern const character_definition li_;
extern const character_definition mi_;
extern const character_definition ke_;
extern const character_definition mu_;
extern const character_definition yu_;
extern const character_definition no_;
extern const character_definition sa_;
extern const character_definition aki_;
extern const character_definition nk_;
extern const character_definition hx_;
extern const character_definition hh_;
extern const character_definition emm_;

}
}

#endif // CHARACTER_H
