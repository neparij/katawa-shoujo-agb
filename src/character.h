#ifndef CHARACTER_H
#define CHARACTER_H

#include <bn_sprite_items_common_variable_8x8_font.h>
#include <bn_sprite_items_variable_16x16_font.h>
#include <bn_sprite_items_variable_16x16_font_beige_pal.h>
#include <bn_sprite_items_variable_16x16_font_hi_pal.h>
#include <bn_sprite_items_variable_16x16_font_ha_pal.h>
#include <bn_sprite_items_variable_16x16_font_emi_pal.h>
#include <bn_sprite_items_variable_16x16_font_rin_pal.h>
#include <bn_sprite_items_variable_16x16_font_li_pal.h>
#include <bn_sprite_items_variable_16x16_font_shi_pal.h>
#include <bn_sprite_items_variable_16x16_font_mi_pal.h>
#include <bn_sprite_items_variable_16x16_font_ke_pal.h>
#include <bn_sprite_items_variable_16x16_font_mu_pal.h>
#include <bn_sprite_items_variable_16x16_font_nk_pal.h>
#include <bn_sprite_items_variable_16x16_font_no_pal.h>
#include <bn_sprite_items_variable_16x16_font_yu_pal.h>
#include <bn_sprite_items_variable_16x16_font_sa_pal.h>
#include <bn_sprite_items_variable_16x16_font_aki_pal.h>
#include <bn_sprite_items_variable_16x16_font_hh_pal.h>
#include <bn_sprite_items_variable_16x16_font_hx_pal.h>
#include <bn_sprite_items_variable_16x16_font_emm_pal.h>
#include <bn_sprite_items_variable_16x16_font_sk_pal.h>
#include <bn_sprite_items_variable_16x16_font_mk_pal.h>

#include "globals.h"
#include "translation.h"
#include <bn_sprite_palette_item.h>

namespace ks {

static const char* static_name(const char* name) {
    return name;
}

struct character_definition
{
    const char* (*name)() = 0;
    const char* what_prefix = "\"";
    const char* what_suffix = "\"";
    bn::sprite_palette_item who_color = bn::sprite_items::variable_16x16_font.palette_item();

    character_definition with(const char* (*new_name)() = nullptr,
                              const char* new_prefix = nullptr,
                              const char* new_suffix = nullptr,
                              bn::sprite_palette_item new_who_color = bn::sprite_items::variable_16x16_font.palette_item()) const
    {
        return character_definition{
                                    new_name ? new_name : name,
                                    new_prefix ? new_prefix : what_prefix,
                                    new_suffix ? new_suffix : what_suffix,
                                    new_who_color};
    }

    character_definition with_name(const char* new_name) const
    {
        static const char* dynamic_name = nullptr;
        dynamic_name = new_name;

        return character_definition{
                                    []() { return static_name(dynamic_name); },
                                    what_prefix,
                                    what_suffix,
                                    who_color};
    }
};

namespace definitions {

// const bn::sprite_palette_item hi_palette = bn::sprite_items::variable_16x16_font_hi_pal.palette_item();
// const bn::sprite_palette_item base_palette = globals::text_palettes::hi;
// const bn::sprite_palette_item base_palette = bn::sprite_items::variable_16x16_font_hi_pal.palette_item();

// const character_definition base([]() {return "";}, "\"", "\"", &globals::text_palettes::hi);
constexpr character_definition base([]() {return "";}, "\"", "\"");

constexpr character_definition no_char = base;

//TODO: n and nvl
constexpr character_definition n = base;

//TODO: centered???
constexpr character_definition centered = base;

//TODO: extend
constexpr character_definition extend = base;


const character_definition hi = base.with([]() { return ks::globals::i18n->definitions_hi(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_hi_pal.palette_item());
const character_definition ha = base.with([]() { return ks::globals::i18n->definitions_ha(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_ha_pal.palette_item());
const character_definition emi = base.with([]() { return ks::globals::i18n->definitions_emi(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_emi_pal.palette_item());
const character_definition rin = base.with([]() { return ks::globals::i18n->definitions_rin(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_rin_pal.palette_item());
const character_definition li = base.with([]() { return ks::globals::i18n->definitions_li(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_li_pal.palette_item());
const character_definition shi = base.with([]() { return ks::globals::i18n->definitions_shi(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_shi_pal.palette_item());
const character_definition mi = base.with([]() { return ks::globals::i18n->definitions_mi(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_mi_pal.palette_item());
const character_definition ke = base.with([]() { return ks::globals::i18n->definitions_ke(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_ke_pal.palette_item());
const character_definition mu = base.with([]() { return ks::globals::i18n->definitions_mu(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_mu_pal.palette_item());
const character_definition nk = base.with([]() { return ks::globals::i18n->definitions_nk(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_nk_pal.palette_item());
const character_definition no = base.with([]() { return ks::globals::i18n->definitions_no(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_no_pal.palette_item());
const character_definition yu = base.with([]() { return ks::globals::i18n->definitions_yu(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_yu_pal.palette_item());
const character_definition sa = base.with([]() { return ks::globals::i18n->definitions_sa(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_sa_pal.palette_item());
const character_definition aki = base.with([]() { return ks::globals::i18n->definitions_aki(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_aki_pal.palette_item());
const character_definition hh = base.with([]() { return ks::globals::i18n->definitions_hh(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_hh_pal.palette_item());
const character_definition hx = base.with([]() { return ks::globals::i18n->definitions_hx(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_hx_pal.palette_item());
const character_definition emm = base.with([]() { return ks::globals::i18n->definitions_emm(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_emm_pal.palette_item());
const character_definition sk = base.with([]() { return ks::globals::i18n->definitions_sk(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_sk_pal.palette_item());
const character_definition mk = base.with([]() { return ks::globals::i18n->definitions_mk(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_mk_pal.palette_item());

const character_definition mi_shi = base.with([]() { return ks::globals::i18n->definitions_mi_shi(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_mi_pal.palette_item());
const character_definition mi_not_shi = base.with([]() { return ks::globals::i18n->definitions_mi_not_shi(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_mi_pal.palette_item());

const character_definition mystery = base.with([]() { return ks::globals::i18n->definitions_mystery(); });

const character_definition ssh = shi.with(nullptr, "[", "]", bn::sprite_items::variable_16x16_font_shi_pal.palette_item());
const character_definition his = hi.with(nullptr, "[", "]", bn::sprite_items::variable_16x16_font_hi_pal.palette_item());

const character_definition ha_ = ha.with([]() { return ks::globals::i18n->definitions_ha_(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_ha_pal.palette_item());
const character_definition emi_ = emi.with([]() { return ks::globals::i18n->definitions_emi_(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_emi_pal.palette_item());
const character_definition rin_ = rin.with([]() { return ks::globals::i18n->definitions_rin_(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_rin_pal.palette_item());
const character_definition li_ = li.with([]() { return ks::globals::i18n->definitions_li_(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_li_pal.palette_item());
const character_definition mi_ = mi.with([]() { return ks::globals::i18n->definitions_mi_(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_mi_pal.palette_item());
const character_definition ke_ = ke.with([]() { return ks::globals::i18n->definitions_ke_(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_ke_pal.palette_item());
const character_definition mu_ = mu.with([]() { return ks::globals::i18n->definitions_mu_(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_mu_pal.palette_item());
const character_definition yu_ = yu.with([]() { return ks::globals::i18n->definitions_yu_(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_yu_pal.palette_item());
const character_definition no_ = no.with([]() { return ks::globals::i18n->definitions_no_(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_no_pal.palette_item());
const character_definition sa_ = sa.with([]() { return ks::globals::i18n->definitions_sa_(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_sa_pal.palette_item());
const character_definition aki_ = aki.with([]() { return ks::globals::i18n->definitions_aki_(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_aki_pal.palette_item());
const character_definition nk_ = nk.with([]() { return ks::globals::i18n->definitions_nk_(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_nk_pal.palette_item());
const character_definition hx_ = hx.with([]() { return ks::globals::i18n->definitions_hx_(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_hx_pal.palette_item());
const character_definition hh_ = hh.with([]() { return ks::globals::i18n->definitions_hh_(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_hh_pal.palette_item());
const character_definition emm_ = emm.with([]() { return ks::globals::i18n->definitions_emm_(); }, nullptr, nullptr, bn::sprite_items::variable_16x16_font_emm_pal.palette_item());

}
}

#endif // CHARACTER_H
