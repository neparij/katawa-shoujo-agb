#ifndef KS_ACT_OPENING_1_H
#define KS_ACT_OPENING_1_H

#include "act_opening.h"

#include "bn_regular_bg_items_act_1_slide.h"

namespace ks {
    class ActOpening1 final : public ActOpening<1> {
    public:
        explicit ActOpening1(): ActOpening(
            (const opening_slide[]){
                opening_slide{
                    bn::regular_bg_items::act_1_slide,
                    88,
                    0
                }
            },
            {
                OP_TEXT_ALIGN_RIGHT, 164, 104,
                OP_TEXT_ALIGN_CENTER, 164, 120
            },
            "video_tc_act1.ulc"
        ) {
            _text = globals::i18n->opening_text_act1();
            init();
        }
    };
}
#endif //KS_ACT_OPENING_1_H
