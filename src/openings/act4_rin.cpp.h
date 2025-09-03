#ifndef KS_ACT_OPENING_4_RIN_H
#define KS_ACT_OPENING_4_RIN_H

#include "act_opening.h"

#include "bn_regular_bg_items_act_4_rin_slide.h"

namespace ks {
    class ActOpening4Rin final : public ActOpening<1> {
    public:
        explicit ActOpening4Rin(): ActOpening(
            (const opening_slide[1]){
                opening_slide{
                    bn::regular_bg_items::act_4_rin_slide,
                    88,
                    0
                }
            },
            {
                198,
                104,
            },
            "tc_act1.ulc"
            ) {}
    protected:
        opening_text get_text() override {
            return globals::i18n->opening_text_act4_rin();
        }
    };
}
#endif //KS_ACT_OPENING_4_RIN_H
