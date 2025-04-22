#ifndef SOUND_MANAGER_IMPL_H
#define SOUND_MANAGER_IMPL_H

#include "gsmplayer/player_8ad.h"
#include "gsmplayer/player_gsm.h"

namespace ks::sound_manager {
    extern music_t current_music;

    static const char* get_music_filename(const music_t music) {
        BN_ASSERT(music != MUSIC_NONE, "Invalid music type");
        switch (music) {
            case MUSIC_TRANQUIL: return "music_tranquil.gsm";
            case MUSIC_NURSE: return "music_nurse.gsm";
            case MUSIC_SOOTHING: return "music_soothing.gsm";
            case MUSIC_TWINKLE: return "music_twinkle.gsm";
            case MUSIC_MOONLIGHT: return "music_moonlight.gsm";
            case MUSIC_RAIN: return "music_rain.gsm";
            case MUSIC_TRAGIC: return "music_tragic.gsm";
            case MUSIC_COMFORT: return "music_comfort.gsm";
            case MUSIC_LILLY: return "music_lilly.gsm";
            case MUSIC_DAILY: return "music_daily.gsm";
            case MUSIC_EASE: return "music_ease.gsm";
            case MUSIC_ANOTHER: return "music_another.gsm";
            case MUSIC_FRIENDSHIP: return "music_friendship.gsm";
            case MUSIC_HAPPINESS: return "music_happiness.gsm";
            case MUSIC_COMEDY: return "music_comedy.gsm";
            case MUSIC_TENSION: return "music_tension.gsm";
            case MUSIC_RUNNING: return "music_running.gsm";
            case MUSIC_INNOCENCE: return "music_innocence.gsm";
            case MUSIC_HEART: return "music_heart.gsm";
            case MUSIC_SERENE: return "music_serene.gsm";
            case MUSIC_DRAMA: return "music_drama.gsm";
            case MUSIC_NIGHT: return "music_night.gsm";
            case MUSIC_KENJI: return "music_kenji.gsm";
            case MUSIC_HANAKO: return "music_hanako.gsm";
            case MUSIC_RIN: return "music_rin.gsm";
            case MUSIC_TIMESKIP: return "music_timeskip.gsm";
            case MUSIC_DREAMY: return "music_dreamy.gsm";
            case MUSIC_JAZZ: return "music_jazz.gsm";
            case MUSIC_ROMANCE: return "music_romance.gsm";
            case MUSIC_CREDITS: return "music_credits.gsm";
            case MUSIC_MUSICBOX: return "music_musicbox.gsm";
            case MUSIC_NORMAL: return "music_normal.gsm";
            case MUSIC_SADNESS: return "music_sadness.gsm";
            case MUSIC_EMI: return "music_emi.gsm";
            case MUSIC_PEARLY: return "music_pearly.gsm";
            case MUSIC_SHIZUNE: return "music_shizune.gsm";
            case MUSIC_ONE: return "music_one.gsm";
            case MUSIC_MENUS: return "music_menus.gsm";
            default: return "";
        }
    }

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
        BN_LOG("Channel volume: ", ch->channel_volume, "; Sound volume: ", ch->sound_volume);

        if (Channel == SOUND_CHANNEL_MUSIC) {
            playerGSM_set_volume(1.0);
            playerGSM_play(name);
            playerGSM_set_loop(ch->loop);
        } else if (Channel == SOUND_CHANNEL_SOUND) {
            // player8AD_set_volume(1.0, 0);
            player8AD_play(name, 0);
            player8AD_set_loop(ch->loop, 0);
        } else if (Channel == SOUND_CHANNEL_AMBIENT) {
            // player8AD_set_volume(1.0, 1);
            player8AD_play(name, 1);
            player8AD_set_loop(ch->loop, 1);
        }

        BN_LOG("A: Channel volume: ", ch->channel_volume, "; Sound volume: ", ch->sound_volume);
    }

    inline void play(const music_t music) {
        current_music = music;
        play<SOUND_CHANNEL_MUSIC>(get_music_filename(music));
    }

    template <sound_channel_t Channel>
    void stop() {
        if (Channel == SOUND_CHANNEL_MUSIC) {
            current_music = MUSIC_NONE;
            if (playerGSM_is_playing()) {
                playerGSM_stop();
            }
            if (auto& action = get_volume_to_action<SOUND_CHANNEL_MUSIC>(); action.has_value()) {
                action.reset();
            }
        } else if (Channel == SOUND_CHANNEL_SOUND) {
            if (player8AD_is_playing(0)) {
                player8AD_stop(0);
            }
            if (auto& action = get_volume_to_action<SOUND_CHANNEL_SOUND>(); action.has_value()) {
                action.reset();
            }
        } else if (Channel == SOUND_CHANNEL_AMBIENT) {
            if (player8AD_is_playing(1)) {
                player8AD_stop(1);
            }
            if (auto& action = get_volume_to_action<SOUND_CHANNEL_AMBIENT>(); action.has_value()) {
                action.reset();
            }
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
        BN_LOG("Set fadein action for channel ", Channel, " with duration ", duration_updates);
        auto& action = get_volume_to_action<Channel>();
        if (action.has_value()) {
            action->reset();
        }
        set_sound_volume<Channel>(0.0);
        action = volume_to_action<Channel>(duration_updates, 1.0);
    }

    template <sound_channel_t Channel>
    void set_fadeout_action(int duration_updates) {
        BN_LOG("Set fadeout action for channel ", Channel, " with duration ", duration_updates);
        auto& action = get_volume_to_action<Channel>();
        if (action.has_value()) {
            action->reset();
        }
        action = volume_to_action<Channel>(duration_updates, 0.0);
    }
}

#endif //SOUND_MANAGER_IMPL_H
