#ifndef KS_ACT_OPENING_2_SHIZUNE_H
#define KS_ACT_OPENING_2_SHIZUNE_H

#include "act_opening.h"

#include "bn_regular_bg_items_act_2_shizune_slide.h"

namespace ks {
    class ActOpening2Shizune final : public ActOpening<1> {
    public:
        explicit ActOpening2Shizune(): ActOpening(
            (const opening_slide[1]){
                opening_slide{
                    bn::regular_bg_items::act_2_shizune_slide,
                    -88,
                    0
                }
            },
            {
                32,
                104,
                OP_TEXT_ALIGN_LEFT
            },
            nullptr,
            {0, 120},
            {420, 600},
            {120, 180},
            {0, 180},
            {60, 180},
            {120, 180}
            ) {}
    protected:
        opening_text get_text() override {
            return globals::i18n->opening_text_act2_shizune();
        }
    };
}
#endif //KS_ACT_OPENING_2_SHIZUNE_H
