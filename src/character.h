#ifndef CHARACTER_H
#define CHARACTER_H

#include <bn_sprite_items_fontpalette_main.h>
#include <bn_sprite_items_fontpalette_hi.h>
#include <bn_sprite_items_fontpalette_ha.h>
#include <bn_sprite_items_fontpalette_emi.h>
#include <bn_sprite_items_fontpalette_rin.h>
#include <bn_sprite_items_fontpalette_li.h>
#include <bn_sprite_items_fontpalette_shi.h>
#include <bn_sprite_items_fontpalette_mi.h>
#include <bn_sprite_items_fontpalette_ke.h>
#include <bn_sprite_items_fontpalette_mu.h>
#include <bn_sprite_items_fontpalette_nk.h>
#include <bn_sprite_items_fontpalette_no.h>
#include <bn_sprite_items_fontpalette_yu.h>
#include <bn_sprite_items_fontpalette_sa.h>
#include <bn_sprite_items_fontpalette_aki.h>
#include <bn_sprite_items_fontpalette_hh.h>
#include <bn_sprite_items_fontpalette_hx.h>
#include <bn_sprite_items_fontpalette_emm.h>
#include <bn_sprite_items_fontpalette_sk.h>
#include <bn_sprite_items_fontpalette_mk.h>

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
    bn::sprite_palette_item who_color = bn::sprite_items::fontpalette_main.palette_item();
    const char* log_color = "15";

    character_definition with(const char* (*new_name)() = nullptr,
                              const char* new_prefix = nullptr,
                              const char* new_suffix = nullptr,
                              bn::sprite_palette_item new_who_color = bn::sprite_items::fontpalette_main.palette_item(),
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
};

namespace definitions {

constexpr character_definition base([]() {return "";}, "\"", "\"");

constexpr character_definition no_char = base;

//TODO: n and nvl
constexpr character_definition n = base;

//TODO: centered???
constexpr character_definition centered = base;

//TODO: extend
constexpr character_definition extend = base;


const character_definition hi = base.with([]() { return ks::globals::i18n->definitions_hi(); }, nullptr, nullptr, bn::sprite_items::fontpalette_hi.palette_item(), "108");
const character_definition ha = base.with([]() { return ks::globals::i18n->definitions_ha(); }, nullptr, nullptr, bn::sprite_items::fontpalette_ha.palette_item(), "93");
const character_definition emi = base.with([]() { return ks::globals::i18n->definitions_emi(); }, nullptr, nullptr, bn::sprite_items::fontpalette_emi.palette_item(), "202");
const character_definition rin = base.with([]() { return ks::globals::i18n->definitions_rin(); }, nullptr, nullptr, bn::sprite_items::fontpalette_rin.palette_item(), "88");
const character_definition li = base.with([]() { return ks::globals::i18n->definitions_li(); }, nullptr, nullptr, bn::sprite_items::fontpalette_li.palette_item(), "228");
const character_definition shi = base.with([]() { return ks::globals::i18n->definitions_shi(); }, nullptr, nullptr, bn::sprite_items::fontpalette_shi.palette_item(), "81");
const character_definition mi = base.with([]() { return ks::globals::i18n->definitions_mi(); }, nullptr, nullptr, bn::sprite_items::fontpalette_mi.palette_item(), "213");
const character_definition ke = base.with([]() { return ks::globals::i18n->definitions_ke(); }, nullptr, nullptr, bn::sprite_items::fontpalette_ke.palette_item(), "172");
const character_definition mu = base.with([]() { return ks::globals::i18n->definitions_mu(); }, nullptr, nullptr, bn::sprite_items::fontpalette_mu.palette_item());
const character_definition nk = base.with([]() { return ks::globals::i18n->definitions_nk(); }, nullptr, nullptr, bn::sprite_items::fontpalette_nk.palette_item());
const character_definition no = base.with([]() { return ks::globals::i18n->definitions_no(); }, nullptr, nullptr, bn::sprite_items::fontpalette_no.palette_item(), "250");
const character_definition yu = base.with([]() { return ks::globals::i18n->definitions_yu(); }, nullptr, nullptr, bn::sprite_items::fontpalette_yu.palette_item(), "28");
const character_definition sa = base.with([]() { return ks::globals::i18n->definitions_sa(); }, nullptr, nullptr, bn::sprite_items::fontpalette_sa.palette_item(), "117");
const character_definition aki = base.with([]() { return ks::globals::i18n->definitions_aki(); }, nullptr, nullptr, bn::sprite_items::fontpalette_aki.palette_item(), "196");
const character_definition hh = base.with([]() { return ks::globals::i18n->definitions_hh(); }, nullptr, nullptr, bn::sprite_items::fontpalette_hh.palette_item(), "75");
const character_definition hx = base.with([]() { return ks::globals::i18n->definitions_hx(); }, nullptr, nullptr, bn::sprite_items::fontpalette_hx.palette_item(), "67");
const character_definition emm = base.with([]() { return ks::globals::i18n->definitions_emm(); }, nullptr, nullptr, bn::sprite_items::fontpalette_emm.palette_item(), "131");
const character_definition sk = base.with([]() { return ks::globals::i18n->definitions_sk(); }, nullptr, nullptr, bn::sprite_items::fontpalette_sk.palette_item(), "25");
const character_definition mk = base.with([]() { return ks::globals::i18n->definitions_mk(); }, nullptr, nullptr, bn::sprite_items::fontpalette_mk.palette_item(), "130");

const character_definition mi_shi = base.with([]() { return ks::globals::i18n->definitions_mi_shi(); }, nullptr, nullptr, bn::sprite_items::fontpalette_mi.palette_item(), "213");
const character_definition mi_not_shi = base.with([]() { return ks::globals::i18n->definitions_mi_not_shi(); }, nullptr, nullptr, bn::sprite_items::fontpalette_mi.palette_item(), "213");

const character_definition mystery = base.with([]() { return ks::globals::i18n->definitions_mystery(); });

const character_definition ssh = shi.with(nullptr, "[", "]", bn::sprite_items::fontpalette_shi.palette_item());
const character_definition his = hi.with(nullptr, "[", "]", bn::sprite_items::fontpalette_hi.palette_item());

const character_definition ha_ = ha.with([]() { return ks::globals::i18n->definitions_ha_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_ha.palette_item());
const character_definition emi_ = emi.with([]() { return ks::globals::i18n->definitions_emi_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_emi.palette_item());
const character_definition rin_ = rin.with([]() { return ks::globals::i18n->definitions_rin_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_rin.palette_item());
const character_definition li_ = li.with([]() { return ks::globals::i18n->definitions_li_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_li.palette_item());
const character_definition mi_ = mi.with([]() { return ks::globals::i18n->definitions_mi_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_mi.palette_item());
const character_definition ke_ = ke.with([]() { return ks::globals::i18n->definitions_ke_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_ke.palette_item());
const character_definition mu_ = mu.with([]() { return ks::globals::i18n->definitions_mu_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_mu.palette_item());
const character_definition yu_ = yu.with([]() { return ks::globals::i18n->definitions_yu_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_yu.palette_item());
const character_definition no_ = no.with([]() { return ks::globals::i18n->definitions_no_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_no.palette_item());
const character_definition sa_ = sa.with([]() { return ks::globals::i18n->definitions_sa_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_sa.palette_item());
const character_definition aki_ = aki.with([]() { return ks::globals::i18n->definitions_aki_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_aki.palette_item());
const character_definition nk_ = nk.with([]() { return ks::globals::i18n->definitions_nk_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_nk.palette_item());
const character_definition hx_ = hx.with([]() { return ks::globals::i18n->definitions_hx_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_hx.palette_item());
const character_definition hh_ = hh.with([]() { return ks::globals::i18n->definitions_hh_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_hh.palette_item());
const character_definition emm_ = emm.with([]() { return ks::globals::i18n->definitions_emm_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_emm.palette_item());

}
}

#endif // CHARACTER_H
