#include "character.h"

#include <bn_sprite_items_fontpalette_main_bold.h>
#include <bn_sprite_items_fontpalette_hi_bold.h>
#include <bn_sprite_items_fontpalette_ha_bold.h>
#include <bn_sprite_items_fontpalette_emi_bold.h>
#include <bn_sprite_items_fontpalette_rin_bold.h>
#include <bn_sprite_items_fontpalette_li_bold.h>
#include <bn_sprite_items_fontpalette_shi_bold.h>
#include <bn_sprite_items_fontpalette_mi_bold.h>
#include <bn_sprite_items_fontpalette_ke_bold.h>
#include <bn_sprite_items_fontpalette_mu_bold.h>
#include <bn_sprite_items_fontpalette_nk_bold.h>
#include <bn_sprite_items_fontpalette_no_bold.h>
#include <bn_sprite_items_fontpalette_yu_bold.h>
#include <bn_sprite_items_fontpalette_sa_bold.h>
#include <bn_sprite_items_fontpalette_aki_bold.h>
#include <bn_sprite_items_fontpalette_hh_bold.h>
#include <bn_sprite_items_fontpalette_hx_bold.h>
#include <bn_sprite_items_fontpalette_emm_bold.h>
#include <bn_sprite_items_fontpalette_sk_bold.h>
#include <bn_sprite_items_fontpalette_mk_bold.h>

#include "globals.h"
#include "translation.h"

namespace ks {
namespace definitions {

const character_definition hi = base.with([]() { return tl::definitions_hi(); }, nullptr, nullptr, bn::sprite_items::fontpalette_hi_bold.palette_item(), "108");
const character_definition ha = base.with([]() { return tl::definitions_ha(); }, nullptr, nullptr, bn::sprite_items::fontpalette_ha_bold.palette_item(), "93");
const character_definition emi = base.with([]() { return tl::definitions_emi(); }, nullptr, nullptr, bn::sprite_items::fontpalette_emi_bold.palette_item(), "202");
const character_definition rin = base.with([]() { return tl::definitions_rin(); }, nullptr, nullptr, bn::sprite_items::fontpalette_rin_bold.palette_item(), "88");
const character_definition li = base.with([]() { return tl::definitions_li(); }, nullptr, nullptr, bn::sprite_items::fontpalette_li_bold.palette_item(), "228");
const character_definition shi = base.with([]() { return tl::definitions_shi(); }, nullptr, nullptr, bn::sprite_items::fontpalette_shi_bold.palette_item(), "81");
const character_definition mi = base.with([]() { return tl::definitions_mi(); }, nullptr, nullptr, bn::sprite_items::fontpalette_mi_bold.palette_item(), "213");
const character_definition ke = base.with([]() { return tl::definitions_ke(); }, nullptr, nullptr, bn::sprite_items::fontpalette_ke_bold.palette_item(), "172");
const character_definition mu = base.with([]() { return tl::definitions_mu(); }, nullptr, nullptr, bn::sprite_items::fontpalette_mu_bold.palette_item());
const character_definition nk = base.with([]() { return tl::definitions_nk(); }, nullptr, nullptr, bn::sprite_items::fontpalette_nk_bold.palette_item());
const character_definition no = base.with([]() { return tl::definitions_no(); }, nullptr, nullptr, bn::sprite_items::fontpalette_no_bold.palette_item(), "250");
const character_definition yu = base.with([]() { return tl::definitions_yu(); }, nullptr, nullptr, bn::sprite_items::fontpalette_yu_bold.palette_item(), "28");
const character_definition sa = base.with([]() { return tl::definitions_sa(); }, nullptr, nullptr, bn::sprite_items::fontpalette_sa_bold.palette_item(), "117");
const character_definition aki = base.with([]() { return tl::definitions_aki(); }, nullptr, nullptr, bn::sprite_items::fontpalette_aki_bold.palette_item(), "196");
const character_definition hh = base.with([]() { return tl::definitions_hh(); }, nullptr, nullptr, bn::sprite_items::fontpalette_hh_bold.palette_item(), "75");
const character_definition hx = base.with([]() { return tl::definitions_hx(); }, nullptr, nullptr, bn::sprite_items::fontpalette_hx_bold.palette_item(), "67");
const character_definition emm = base.with([]() { return tl::definitions_emm(); }, nullptr, nullptr, bn::sprite_items::fontpalette_emm_bold.palette_item(), "131");
const character_definition sk = base.with([]() { return tl::definitions_sk(); }, nullptr, nullptr, bn::sprite_items::fontpalette_sk_bold.palette_item(), "25");
const character_definition mk = base.with([]() { return tl::definitions_mk(); }, nullptr, nullptr, bn::sprite_items::fontpalette_mk_bold.palette_item(), "130");

const character_definition mi_shi = base.with([]() { return tl::definitions_mi_shi(); }, nullptr, nullptr, bn::sprite_items::fontpalette_mi_bold.palette_item(), "213");
const character_definition mi_not_shi = base.with([]() { return tl::definitions_mi_not_shi(); }, nullptr, nullptr, bn::sprite_items::fontpalette_mi_bold.palette_item(), "213");

const character_definition mystery = base.with([]() { return tl::definitions_mystery(); });

const character_definition ssh = shi.with(nullptr, "[", "]", bn::sprite_items::fontpalette_shi_bold.palette_item());
const character_definition his = hi.with(nullptr, "[", "]", bn::sprite_items::fontpalette_hi_bold.palette_item());

const character_definition ha_ = ha.with([]() { return tl::definitions_ha_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_ha_bold.palette_item());
const character_definition emi_ = emi.with([]() { return tl::definitions_emi_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_emi_bold.palette_item());
const character_definition rin_ = rin.with([]() { return tl::definitions_rin_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_rin_bold.palette_item());
const character_definition li_ = li.with([]() { return tl::definitions_li_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_li_bold.palette_item());
const character_definition mi_ = mi.with([]() { return tl::definitions_mi_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_mi_bold.palette_item());
const character_definition ke_ = ke.with([]() { return tl::definitions_ke_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_ke_bold.palette_item());
const character_definition mu_ = mu.with([]() { return tl::definitions_mu_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_mu_bold.palette_item());
const character_definition yu_ = yu.with([]() { return tl::definitions_yu_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_yu_bold.palette_item());
const character_definition no_ = no.with([]() { return tl::definitions_no_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_no_bold.palette_item());
const character_definition sa_ = sa.with([]() { return tl::definitions_sa_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_sa_bold.palette_item());
const character_definition aki_ = aki.with([]() { return tl::definitions_aki_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_aki_bold.palette_item());
const character_definition nk_ = nk.with([]() { return tl::definitions_nk_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_nk_bold.palette_item());
const character_definition hx_ = hx.with([]() { return tl::definitions_hx_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_hx_bold.palette_item());
const character_definition hh_ = hh.with([]() { return tl::definitions_hh_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_hh_bold.palette_item());
const character_definition emm_ = emm.with([]() { return tl::definitions_emm_(); }, nullptr, nullptr, bn::sprite_items::fontpalette_emm_bold.palette_item());

}  // namespace definitions
}  // namespace ks
