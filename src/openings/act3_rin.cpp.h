#ifndef KS_ACT_OPENING_3_RIN_H
#define KS_ACT_OPENING_3_RIN_H

#include "act_opening.h"

#include "bn_regular_bg_items_act_3_rin_left_slide.h"
#include "bn_regular_bg_items_act_3_rin_right_slide.h"

namespace ks {
    class ActOpening3Rin final : public ActOpening<2> {
    public:
        explicit ActOpening3Rin(): ActOpening(
            slides,
            {
                124,
                24,
            },
            "tc_act1.ulc"
            ) {}
    protected:
        opening_text get_text() override {
            return tl::opening_text_act3_rin();
        }
    private:
        static constexpr opening_slide slides[2] = {
            {
                bn::regular_bg_items::act_3_rin_left_slide,
                88,
                0
            },
            {
                bn::regular_bg_items::act_3_rin_right_slide,
                -88,
                0
            }
        };
    };
}
#endif //KS_ACT_OPENING_3_RIN_H
