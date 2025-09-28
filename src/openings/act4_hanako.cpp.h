#ifndef KS_ACT_OPENING_4_HANAKO_H
#define KS_ACT_OPENING_4_HANAKO_H

#include "act_opening.h"

#include "bn_regular_bg_items_act_4_hanako_slide.h"

namespace ks {
    class ActOpening4Hanako final : public ActOpening<1> {
    public:
        explicit ActOpening4Hanako(): ActOpening(
            slides,
            {
                50,
                24,
            },
            "tc_act1.ulc"
            ) {}
    protected:
        opening_text get_text() override {
            return globals::i18n->opening_text_act4_hanako();
        }
    private:
        static constexpr opening_slide slides[1] = {
            {
                bn::regular_bg_items::act_4_hanako_slide,
                88,
                0
            }
        };
    };
}
#endif //KS_ACT_OPENING_4_HANAKO_H
