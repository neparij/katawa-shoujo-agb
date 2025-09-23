#ifndef KS_ACT_OPENING_3_LILLY_H
#define KS_ACT_OPENING_3_LILLY_H

#include "act_opening.h"

#include "bn_regular_bg_items_act_3_lilly_slide.h"

namespace ks {
    class ActOpening3Lilly final : public ActOpening<1> {
    public:
        explicit ActOpening3Lilly(): ActOpening(
            slides,
            {
                58,
                24,
            },
            "tc_act1.ulc"
            ) {}
    protected:
        opening_text get_text() override {
            return globals::i18n->opening_text_act3_lilly();
        }
    private:
        static constexpr opening_slide slides[1] = {
            {
                bn::regular_bg_items::act_3_lilly_slide,
                88,
                0
            }
        };
    };
}
#endif //KS_ACT_OPENING_3_LILLY_H
