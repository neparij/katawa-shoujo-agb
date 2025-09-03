#ifndef KS_ACT_OPENING_4_EMI_H
#define KS_ACT_OPENING_4_EMI_H

#include "act_opening.h"

#include "bn_regular_bg_items_act_4_emi_slide.h"

namespace ks {
    class ActOpening4Emi final : public ActOpening<1> {
    public:
        explicit ActOpening4Emi(): ActOpening(
            (const opening_slide[1]){
                opening_slide{
                    bn::regular_bg_items::act_4_emi_slide,
                    0,
                    -72
                }
            },
            {
                124,
                16,
            },
            "tc_act1.ulc"
            ) {}
    protected:
        opening_text get_text() override {
            return globals::i18n->opening_text_act4_emi();
        }
    };
}
#endif //KS_ACT_OPENING_4_EMI_H
