#include "ks_huge_bgs_manager.h"

#include "bn_log.h"
#include "ks_huge_bg.h"

#include "bn_vector.h"

namespace ks::huge_bgs_manager {
    class static_data {
    public:
        bn::vector<huge_bg *, 2> items_vector;
    };

    BN_DATA_EWRAM_BSS static_data data;


    void push(huge_bg *bg) {
        BN_ASSERT(bg != nullptr, "huge_bg pointer is null");
        for (const auto &item: data.items_vector) {
            BN_ASSERT(item != bg, "huge_bg already exists in the manager");
        }
        BN_ASSERT(data.items_vector.size() < data.items_vector.max_size(),
                  "huge_bgs_manager: maximum number of huge_bgs [", data.items_vector.max_size(), "] reached");

        data.items_vector.push_back(bg);
    }

    void pop(huge_bg *bg) {
        BN_ASSERT(bg != nullptr, "huge_bg pointer is null");
        for (auto it = data.items_vector.begin(); it != data.items_vector.end(); ++it) {
            if (*it == bg) {
                data.items_vector.erase(it);
                return;
            }
        }
        BN_ERROR("huge_bg not found in the manager");
    }

    void update() {
        for (const auto &bg: data.items_vector) {
            if (bg != nullptr) {
                bg->update();
            }
        }
    }
}
