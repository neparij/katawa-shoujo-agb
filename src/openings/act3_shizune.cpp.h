#ifndef KS_ACT_OPENING_3_SHIZUNE_H
#define KS_ACT_OPENING_3_SHIZUNE_H

#include "act_opening.h"

#include "bn_regular_bg_items_act_3_shizune_slide.h"

namespace ks {
    class ActOpening3Shizune final : public ActOpening<1> {
    public:
        explicit ActOpening3Shizune(): ActOpening(
            slides,
            {
                178,
                104,
            },
            "tc_act1.ulc"
            ) {}
    protected:
        opening_text get_text() override {
            return globals::i18n->opening_text_act3_shizune();
        }
    private:
        static constexpr opening_slide slides[1] = {
            {
                bn::regular_bg_items::act_3_shizune_slide,
                88,
                0
            }
        };
    };
}
#endif //KS_ACT_OPENING_3_SHIZUNE_H
