#ifndef KS_ACT_OPENING_3_RIN_H
#define KS_ACT_OPENING_3_RIN_H

#include "act_opening.h"

#include "bn_regular_bg_items_act_3_rin_left_slide.h"
#include "bn_regular_bg_items_act_3_rin_right_slide.h"

namespace ks {
    class ActOpening3Rin final : public ActOpening<2> {
    public:
        explicit ActOpening3Rin(): ActOpening(
            (const opening_slide[2]){
                opening_slide{
                    bn::regular_bg_items::act_3_rin_left_slide,
                    88,
                    0
                },
                opening_slide{
                    bn::regular_bg_items::act_3_rin_right_slide,
                    -88,
                    0
                }
            },
            {
                124,
                24,
            },
            "tc_act1.ulc"
            ) {}
    protected:
        opening_text get_text() override {
            return globals::i18n->opening_text_act3_rin();
        }
    };
}
#endif //KS_ACT_OPENING_3_RIN_H
