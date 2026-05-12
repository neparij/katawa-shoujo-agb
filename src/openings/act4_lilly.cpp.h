#ifndef KS_ACT_OPENING_4_LILLY_H
#define KS_ACT_OPENING_4_LILLY_H

#include "act_opening.h"

#include "bn_regular_bg_items_act_4_lilly_slide.h"

namespace ks {
    class ActOpening4Lilly final : public ActOpening<1> {
    public:
        explicit ActOpening4Lilly(): ActOpening(
            slides,
            {
                176,
                104,
            },
            "tc_act1.ulc"
            ) {}
    protected:
        opening_text get_text() override {
            return tl::opening_text_act4_lilly();
        }
    private:
        static constexpr opening_slide slides[1] = {
            {
                bn::regular_bg_items::act_4_lilly_slide,
                88,
                0
            }
        };
    };
}
#endif //KS_ACT_OPENING_4_LILLY_H
