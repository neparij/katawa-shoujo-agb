#include "sound_manager.h"

#include <bn_assert.h>

#include "gsmplayer/player_8ad.h"
#include "gsmplayer/player_gsm.h"

namespace ks::sound_manager {
    channel<SOUND_CHANNEL_MUSIC> channel_music = channel<SOUND_CHANNEL_MUSIC>(1.0, 1.0, true);
    channel<SOUND_CHANNEL_SOUND> channel_sound = channel<SOUND_CHANNEL_SOUND>(1.0, 1.0, false);
    channel<SOUND_CHANNEL_AMBIENT> channel_ambient = channel<SOUND_CHANNEL_AMBIENT>(1.0, 1.0, true);

    void init() {
        playerGSM_init();
        player8AD_init();
    }

    void update() {
        if (channel_music.volume_to.has_value()) {
            if (auto& action = channel_music.volume_to.value(); !action.done()) {
                action.update();
            } else {
                if (action.final_volume() == 0) {
                    stop<SOUND_CHANNEL_MUSIC>();
                    channel_music.sound_volume = 1.0;
                }
                channel_music.volume_to.reset();
            }
        }

        playerGSM_set_volume(get_mixed_volume<SOUND_CHANNEL_MUSIC>().to_float());
        // player8AD_set_volume(get_mixed_volume(SOUND_CHANNEL_SOUND).to_float());

        playerGSM_update(0, [](unsigned current) {});
        player8AD_update();
    }

    BN_CODE_IWRAM void on_vblank() {
        playerGSM_on_vblank();
        player8AD_on_vblank();
    }
}
