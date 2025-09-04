#ifndef KS_ACT_OPENING_1_H
#define KS_ACT_OPENING_1_H

#include "act_opening.h"

#include "bn_regular_bg_items_act_1_slide.h"

namespace ks {
    class ActOpening1 final : public ActOpening<1> {
    public:
        explicit ActOpening1(): ActOpening(
            (const opening_slide[1]){
                opening_slide{
                    bn::regular_bg_items::act_1_slide,
                    88,
                    0
                }
            },
            {
                172,
                104,
            },
            "tc_act1.ulc"
        ) {}
    protected:
        opening_text get_text() override {
            return globals::i18n->opening_text_act1();
        }
    };
}
#endif //KS_ACT_OPENING_1_H
