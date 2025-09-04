#ifndef KS_ACT_OPENING_4_SHIZUNE_H
#define KS_ACT_OPENING_4_SHIZUNE_H

#include "act_opening.h"

#include "bn_regular_bg_items_act_4_shizune_slide.h"

namespace ks {
    class ActOpening4Shizune final : public ActOpening<1> {
    public:
        explicit ActOpening4Shizune(): ActOpening(
            (const opening_slide[1]){
                opening_slide{
                    bn::regular_bg_items::act_4_shizune_slide,
                    -88,
                    0
                }
            },
            {
                76,
                24,
            },
            "tc_act1.ulc"
            ) {}
    protected:
        opening_text get_text() override {
            return globals::i18n->opening_text_act4_shizune();
        }
    };
}
#endif //KS_ACT_OPENING_4_SHIZUNE_H
