#ifndef KS_ACT_OPENING_2_EMI_H
#define KS_ACT_OPENING_2_EMI_H

#include "act_opening.h"

#include "bn_regular_bg_items_act_2_emi_slide.h"

namespace ks {
    class ActOpening2Emi final : public ActOpening<1> {
    public:
        explicit ActOpening2Emi(): ActOpening(
            (const opening_slide[1]){
                opening_slide{
                    bn::regular_bg_items::act_2_emi_slide,
                    -88,
                    0
                }
            },
            {
                32,
                24,
                OP_TEXT_ALIGN_LEFT
            },
            "tc_act1.ulc"
            ) {}
    protected:
        opening_text get_text() override {
            return globals::i18n->opening_text_act2_emi();
        }
    };
}
#endif //KS_ACT_OPENING_2_EMI_H
