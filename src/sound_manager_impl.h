#ifndef SOUND_MANAGER_IMPL_H
#define SOUND_MANAGER_IMPL_H

#include "gsmplayer/player_8ad.h"
#include "gsmplayer/player_gsm.h"

namespace ks::sound_manager {
    static channel_base* get_channel(sound_channel_t channel_name) {
        switch (channel_name) {
            case SOUND_CHANNEL_MUSIC:
                BN_ASSERT(&channel_music, "Music channel not initialized");
                return &channel_music;
            case SOUND_CHANNEL_SOUND:
                BN_ASSERT(&channel_sound, "Sound channel not initialized");
                return &channel_sound;
            case SOUND_CHANNEL_AMBIENT:
                BN_ASSERT(&channel_ambient, "Ambient channel not initialized");
                return &channel_ambient;
            default:
                return nullptr;
        }
    }

    template <sound_channel_t Channel>
    static bn::optional<volume_to_action<Channel>>& get_volume_to_action() {
        channel<Channel> *ch = static_cast<channel<Channel> *>(get_channel(Channel));
        return ch->volume_to;
    }

    template <sound_channel_t Channel>
    void play(const char *name) {
        const channel_base *ch = get_channel(Channel);

        if (Channel == SOUND_CHANNEL_MUSIC) {
            playerGSM_play(name);
            playerGSM_set_loop(ch->loop);
        } else if (Channel == SOUND_CHANNEL_SOUND) {
            player8AD_play(name);
            player8AD_set_loop(ch->loop);
        } else if (Channel == SOUND_CHANNEL_AMBIENT) {
            BN_LOG("[play] Ambient sound not implemented yet");
        }
    }

    template <sound_channel_t Channel>
    void stop() {
        if (Channel == SOUND_CHANNEL_MUSIC) {
            if (playerGSM_is_playing()) {
                playerGSM_stop();
            }
        } else if (Channel == SOUND_CHANNEL_SOUND) {
            if (player8AD_is_playing()) {
                player8AD_stop();
            }
        } else if (Channel == SOUND_CHANNEL_AMBIENT) {
            BN_LOG("[stop] Ambient sound not implemented yet");
        }
    }

    template <sound_channel_t Channel>
    void set_channel_loop(const bool is_looping) {
        channel_base *ch = get_channel(Channel);
        ch->loop = is_looping;
    }

    template <sound_channel_t Channel>
    bool get_channel_loop() {
        const channel_base *ch = get_channel(Channel);
        return ch->loop;
    }

    template <sound_channel_t Channel>
    void set_channel_volume(const bn::fixed volume) {
        channel_base *ch = get_channel(Channel);
        ch->channel_volume = volume;
    }

    template <sound_channel_t Channel>
    void set_sound_volume(const bn::fixed volume) {
        channel_base *ch = get_channel(Channel);
        ch->sound_volume = volume;
    }

    template <sound_channel_t Channel>
    bn::fixed get_channel_volume() {
        const channel_base *ch = get_channel(Channel);
        return ch->channel_volume;
    }

    template <sound_channel_t Channel>
    bn::fixed get_sound_volume() {
        const channel_base *ch = get_channel(Channel);
        return ch->sound_volume;
    }

    template <sound_channel_t Channel>
    bn::fixed get_mixed_volume() {
        const channel_base *ch = get_channel(Channel);
        return ch->channel_volume * ch->sound_volume;
    }

    template <sound_channel_t Channel>
    void set_fadein_action(int duration_updates) {
        auto& action = get_volume_to_action<Channel>();
        if (action.has_value()) {
            action->reset();
        }
        set_sound_volume<Channel>(0.0);
        action = volume_to_action<Channel>(duration_updates, 1.0);
    }

    template <sound_channel_t Channel>
    void set_fadeout_action(int duration_updates) {
        auto& action = get_volume_to_action<Channel>();
        if (action.has_value()) {
            action->reset();
        }
        action = volume_to_action<Channel>(duration_updates, 0.0);
    }
}

#endif //SOUND_MANAGER_IMPL_H
