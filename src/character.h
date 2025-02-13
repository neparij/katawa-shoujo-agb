#ifndef CHARACTER_H
#define CHARACTER_H

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
    const bn::sprite_palette_item* who_color = nullptr;

    character_definition with(const char* (*new_name)() = nullptr,
                              const char* new_prefix = nullptr,
                              const char* new_suffix = nullptr,
                              const bn::sprite_palette_item* new_who_color = nullptr) const
    {
        return character_definition{
                                    new_name ? new_name : name,
                                    new_prefix ? new_prefix : what_prefix,
                                    new_suffix ? new_suffix : what_suffix,
                                    new_who_color ? new_who_color : who_color};
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

const character_definition base([]() {return "";}, "\"", "\"", nullptr);

const character_definition no_char = base;

//TODO: n and nvl
const character_definition n = base;

//TODO: centered???
const character_definition centered = base;

//TODO: extend
const character_definition extend = base;

const character_definition hi = base.with([]() { return ks::globals::i18n->definitions_hi(); });
const character_definition ha = base.with([]() { return ks::globals::i18n->definitions_ha(); });
const character_definition emi = base.with([]() { return ks::globals::i18n->definitions_emi(); });
const character_definition rin = base.with([]() { return ks::globals::i18n->definitions_rin(); });
const character_definition li = base.with([]() { return ks::globals::i18n->definitions_li(); });
const character_definition shi = base.with([]() { return ks::globals::i18n->definitions_shi(); });
const character_definition mi = base.with([]() { return ks::globals::i18n->definitions_mi(); });
const character_definition ke = base.with([]() { return ks::globals::i18n->definitions_ke(); });
const character_definition mu = base.with([]() { return ks::globals::i18n->definitions_mu(); });
const character_definition nk = base.with([]() { return ks::globals::i18n->definitions_nk(); });
const character_definition no = base.with([]() { return ks::globals::i18n->definitions_no(); });
const character_definition yu = base.with([]() { return ks::globals::i18n->definitions_yu(); });
const character_definition sa = base.with([]() { return ks::globals::i18n->definitions_sa(); });
const character_definition aki = base.with([]() { return ks::globals::i18n->definitions_aki(); });
const character_definition hh = base.with([]() { return ks::globals::i18n->definitions_hh(); });
const character_definition hx = base.with([]() { return ks::globals::i18n->definitions_hx(); });
const character_definition emm = base.with([]() { return ks::globals::i18n->definitions_emm(); });
const character_definition sk = base.with([]() { return ks::globals::i18n->definitions_sk(); });
const character_definition mk = base.with([]() { return ks::globals::i18n->definitions_mk(); });

const character_definition mi_shi = base.with([]() { return ks::globals::i18n->definitions_mi_shi(); });
const character_definition mi_not_shi = base.with([]() { return ks::globals::i18n->definitions_mi_not_shi(); });

const character_definition mystery = base.with([]() { return ks::globals::i18n->definitions_mystery(); });

const character_definition ssh = shi.with(nullptr, "[", "]");
const character_definition his = hi.with(nullptr, "[", "]");

const character_definition ha_ = ha.with([]() { return ks::globals::i18n->definitions_ha_(); });
const character_definition emi_ = emi.with([]() { return ks::globals::i18n->definitions_emi_(); });
const character_definition rin_ = rin.with([]() { return ks::globals::i18n->definitions_rin_(); });
const character_definition li_ = li.with([]() { return ks::globals::i18n->definitions_li_(); });
const character_definition mi_ = mi.with([]() { return ks::globals::i18n->definitions_mi_(); });
const character_definition ke_ = ke.with([]() { return ks::globals::i18n->definitions_ke_(); });
const character_definition mu_ = mu.with([]() { return ks::globals::i18n->definitions_mu_(); });
const character_definition yu_ = yu.with([]() { return ks::globals::i18n->definitions_yu_(); });
const character_definition no_ = no.with([]() { return ks::globals::i18n->definitions_no_(); });
const character_definition sa_ = sa.with([]() { return ks::globals::i18n->definitions_sa_(); });
const character_definition aki_ = aki.with([]() { return ks::globals::i18n->definitions_aki_(); });
const character_definition nk_ = nk.with([]() { return ks::globals::i18n->definitions_nk_(); });
const character_definition hx_ = hx.with([]() { return ks::globals::i18n->definitions_hx_(); });
const character_definition hh_ = hh.with([]() { return ks::globals::i18n->definitions_hh_(); });
const character_definition emm_ = emm.with([]() { return ks::globals::i18n->definitions_emm_(); });

}
}

#endif // CHARACTER_H
