#ifndef KS_ACT_OPENING_2_EMI_H
#define KS_ACT_OPENING_2_EMI_H

#include "act_opening.h"

#include "bn_regular_bg_items_act_2_emi_slide.h"

namespace ks {
    class ActOpening2Emi final : public ActOpening<1> {
    public:
        explicit ActOpening2Emi(): ActOpening(
            slides,
            {
                32,
                24,
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
            return tl::opening_text_act2_emi();
        }
        static constexpr opening_slide slides[1] = {
            {
                bn::regular_bg_items::act_2_emi_slide,
                -88,
                0
            }
        };
    };
}
#endif //KS_ACT_OPENING_2_EMI_H
