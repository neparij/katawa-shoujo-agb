#ifndef KS_ACT_OPENING_1_H
#define KS_ACT_OPENING_1_H

#include "act_opening.h"

#include "bn_regular_bg_items_act_1_slide.h"

namespace ks {
    class ActOpening1 final : public ActOpening<1> {
    public:
        explicit ActOpening1(): ActOpening(
            slides,
            {
                172,
                104,
            },
            "tc_act1.ulc"
        ) {}
    protected:
        opening_text get_text() override {
            return tl::opening_text_act1();
        }
    private:
        static constexpr opening_slide slides[1] = {
            {
                bn::regular_bg_items::act_1_slide,
                88,
                0
            }
        };
    };
}
#endif //KS_ACT_OPENING_1_H
