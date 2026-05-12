#ifndef KS_ACT_OPENING_4_EMI_H
#define KS_ACT_OPENING_4_EMI_H

#include "act_opening.h"

#include "bn_regular_bg_items_act_4_emi_slide.h"

namespace ks {
    class ActOpening4Emi final : public ActOpening<1> {
    public:
        explicit ActOpening4Emi(): ActOpening(
            slides,
            {
                124,
                16,
            },
            "tc_act1.ulc"
            ) {}
    protected:
        opening_text get_text() override {
            return tl::opening_text_act4_emi();
        }
    private:
        static constexpr opening_slide slides[1] = {
            {
                bn::regular_bg_items::act_4_emi_slide,
                0,
                -72
            }
        };
    };
}
#endif //KS_ACT_OPENING_4_EMI_H
