#include "sound_manager.h"

#include <bn_assert.h>

#include "gsmplayer/player_8ad.h"
#include "gsmplayer/player_gsm.h"

namespace ks::sound_manager {
    music_t current_music = MUSIC_NONE;
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

        if (channel_sound.volume_to.has_value()) {
            if (auto& action = channel_sound.volume_to.value(); !action.done()) {
                action.update();
            } else {
                if (action.final_volume() == 0) {
                    stop<SOUND_CHANNEL_SOUND>();
                    channel_sound.sound_volume = 1.0;
                }
                channel_sound.volume_to.reset();
            }
        }

        if (channel_ambient.volume_to.has_value()) {
            if (auto& action = channel_ambient.volume_to.value(); !action.done()) {
                action.update();
            } else {
                if (action.final_volume() == 0) {
                    stop<SOUND_CHANNEL_AMBIENT>();
                    channel_ambient.sound_volume = 1.0;
                }
                channel_ambient.volume_to.reset();
            }
        }

        playerGSM_set_volume(get_mixed_volume<SOUND_CHANNEL_MUSIC>().to_float());
        // player8AD_set_volume(get_mixed_volume(SOUND_CHANNEL_SOUND).to_float());

        playerGSM_update(0, [](unsigned current) {});
        player8AD_update();
    }

    void restore_after_loading() {
        if (!channel_music.loop && playerGSM_is_playing()) {
            playerGSM_stop();
        }
        if (!channel_sound.loop && player8AD_is_playing(0)) {
            player8AD_stop(0);
        }
        if (!channel_ambient.loop && player8AD_is_playing(1)) {
            player8AD_stop(1);
        }
    }


    BN_CODE_IWRAM void on_vblank() {
        playerGSM_on_vblank();
        player8AD_on_vblank();
    }
}
