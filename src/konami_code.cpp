#include "konami_code.h"

#include "bn_log.h"
#include "build_info.h"
#include "globals.h"

int konami_progress = 0;

void update_konami_code() {
    if (bn::keypad::pressed(konami_code[konami_progress])) {
        ++konami_progress;
        if (konami_progress == konami_code.size()) {

            BN_LOG("Unlocking all gallery");
            for (int i = 0; i < 64; ++i) {
                ks::globals::states.seen_displayables[i] = 0xFF; // Set all bits to 1
            }
            ks::saves::writeStates(ks::globals::states);

            BN_ERROR("Katawa Shoujo GBA by neparij", "\n",
                     "Version: ", KS_BUILD_STRING, "\n",
                     "Build date: ", KS_BUILD_DATE, "\n",
                     "Built on: ", KS_BUILD_HOST_OS, "/", KS_BUILD_HOST_ENV, "\n",
                     "Compiler: ", KS_BUILD_COMPILER);
            konami_progress = 0;
        }
    } else {
        for (const auto key: all_keys) {
            if (bn::keypad::pressed(key) && key != konami_code[konami_progress]) {
                konami_progress = 0;
                break;
            }
        }
    }
}
