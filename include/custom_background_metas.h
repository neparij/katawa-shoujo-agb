#ifndef CUSTOM_BACKGROUND_METAS_H
#define CUSTOM_BACKGROUND_METAS_H

#include "event_missing.h"

namespace ks::background_metas {
    inline const background_meta* get_custom_by_hash(const unsigned int hash) {
        switch (hash) {
            case 0xFFFF0000: return &hisao_class;
            case 0xFFFF0001: return &emi_knockeddown;
            case 0xFFFF0002: return &emi_knockeddown_facepullout;
            case 0xFFFF0003: return &emi_knockeddown_largepullout;
            case 0xFFFF0004: return &emi_knockeddown_legs;
            case 0xFFFF0005: return &lilly_shizu_showdown_slices_lilly;
            case 0xFFFF0006: return &lilly_shizu_showdown_slices_shizu;
            case 0xFFFF0007: return &lilly_shizu_showdown_both;
            default: return &event_missing;
        }
    }
}

#endif //CUSTOM_BACKGROUND_METAS_H
