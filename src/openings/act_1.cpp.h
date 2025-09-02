#ifndef KS_ACT_OPENING_1_H
#define KS_ACT_OPENING_1_H

#include "act_opening.h"

#include "bn_regular_bg_items_act_1_slide.h"

namespace ks {
    class ActOpening1 final : public ActOpening<1> {
    public:
        // explicit ActOpening1(): ActOpening(
        //     15 * 60,
        //     5 * 60,
        //     (const opening_slide[]){
        //         opening_slide {
        //             bn::regular_bg_items::act_1_slide,
        //             80,
        //             0
        //         }
        //     }
        // ) {
        // }
        explicit ActOpening1(): ActOpening(
            (const opening_slide[]){
                opening_slide{
                    bn::regular_bg_items::act_1_slide,
                    88,
                    0
                }
            }
        ) {
        }
    };
}


// const action_duration move_in_duration = {0, 360};
// const action_duration fade_in_duration = {120, 300};
// const action_duration colorize_in_duration = {240, 420};

#endif //KS_ACT_OPENING_1_H
