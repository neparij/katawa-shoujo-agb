#include "globals.h"
#include "bn_core.h"
#include "gsmplayer/player.h"
#include "gsmplayer/player_sfx.h"

namespace ks {
    namespace globals {
        bool show_memory_debug = false;
        bool use_alt_lang = false;
        bool exit_scenario = false;

        void main_update() {
            bn::core::update();
            player_update(0, [](unsigned current) {});
            player_sfx_update();
        };

        void BN_CODE_IWRAM ISR_VBlank() {
            player_onVBlank();
            player_sfx_onVBlank();
        }
    }
}
