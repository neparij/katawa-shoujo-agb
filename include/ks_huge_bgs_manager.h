#ifndef KS_HUGE_BGS_MANAGER_H
#define KS_HUGE_BGS_MANAGER_H

namespace ks {
    class huge_bg; // Forward declaration
}

namespace ks::huge_bgs_manager {
    using ks::huge_bg;

    void push(huge_bg* bg);
    void pop(huge_bg* bg);
    void update();
}

#endif //KS_HUGE_BGS_MANAGER_H
