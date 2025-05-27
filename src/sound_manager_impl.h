#ifndef SOUND_MANAGER_IMPL_H
#define SOUND_MANAGER_IMPL_H

#include "globals.h"
#include "sound/player_8ad.h"
#include "sound/player_ulc.h"

namespace ks::sound_manager {
    extern music_t current_music;

    static const char* get_music_filename(const music_t music) {
        BN_ASSERT(music != MUSIC_NONE, "Invalid music type");
        switch (music) {
            case MUSIC_TRANQUIL: return "music_tranquil.ulc";
            case MUSIC_NURSE: return "music_nurse.ulc";
            case MUSIC_SOOTHING: return "music_soothing.ulc";
            case MUSIC_TWINKLE: return "music_twinkle.ulc";
            case MUSIC_MOONLIGHT: return "music_moonlight.ulc";
            case MUSIC_RAIN: return "music_rain.ulc";
            case MUSIC_TRAGIC: return "music_tragic.ulc";
            case MUSIC_COMFORT: return "music_comfort.ulc";
            case MUSIC_LILLY: return "music_lilly.ulc";
            case MUSIC_DAILY: return "music_daily.ulc";
            case MUSIC_EASE: return "music_ease.ulc";
            case MUSIC_ANOTHER: return "music_another.ulc";
            case MUSIC_FRIENDSHIP: return "music_friendship.ulc";
            case MUSIC_HAPPINESS: return "music_happiness.ulc";
            case MUSIC_COMEDY: return "music_comedy.ulc";
            case MUSIC_TENSION: return "music_tension.ulc";
            case MUSIC_RUNNING: return "music_running.ulc";
            case MUSIC_INNOCENCE: return "music_innocence.ulc";
            case MUSIC_HEART: return "music_heart.ulc";
            case MUSIC_SERENE: return "music_serene.ulc";
            case MUSIC_DRAMA: return "music_drama.ulc";
            case MUSIC_NIGHT: return "music_night.ulc";
            case MUSIC_KENJI: return "music_kenji.ulc";
            case MUSIC_HANAKO: return "music_hanako.ulc";
            case MUSIC_RIN: return "music_rin.ulc";
            case MUSIC_TIMESKIP: return "music_timeskip.ulc";
            case MUSIC_DREAMY: return "music_dreamy.ulc";
            case MUSIC_JAZZ: return "music_jazz.ulc";
            case MUSIC_ROMANCE: return "music_romance.ulc";
            case MUSIC_CREDITS: return "music_credits.ulc";
            case MUSIC_MUSICBOX: return "music_musicbox.ulc";
            case MUSIC_NORMAL: return "music_normal.ulc";
            case MUSIC_SADNESS: return "music_sadness.ulc";
            case MUSIC_EMI: return "music_emi.ulc";
            case MUSIC_PEARLY: return "music_pearly.ulc";
            case MUSIC_SHIZUNE: return "music_shizune.ulc";
            case MUSIC_ONE: return "music_one.ulc";
            case MUSIC_MENUS: return "music_menus.ulc";
            default: return "";
        }
    }

    static channel_base* get_channel(sound_channel_t channel_name) {
        switch (channel_name) {
            case SOUND_CHANNEL_MUSIC:
            case SOUND_CHANNEL_VIDEO:
                BN_ASSERT(&channel_music, "Music channel not initialized");
                return &channel_music;
            case SOUND_CHANNEL_SOUND:
                BN_ASSERT(&channel_sound, "Sound channel not initialized");
                return &channel_sound;
            case SOUND_CHANNEL_AMBIENT:
                BN_ASSERT(&channel_ambient, "Ambient channel not initialized");
                return &channel_ambient;
            default:
                BN_ERROR("Invalid channel name");
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
            // playerULC_set_volume(1.0);
            channel_music.channel_volume = 1.0;
            playerULC_play(name);
            playerULC_set_loop(ch->loop);
        } else if (Channel == SOUND_CHANNEL_VIDEO) {
            BN_LOG("PLAYING VIDEO, NO LOOP!");
            // playerULC_set_volume(1.0);
            channel_music.channel_volume = 1.0;
            playerULC_play(name);
            playerULC_set_loop(false);
        } else if (Channel == SOUND_CHANNEL_SOUND) {
            // player8AD_set_volume(1.0, 0);
            channel_sound.channel_volume = 1.0;
            player8AD_play(name, 0);
            player8AD_set_loop(ch->loop, 0);
        } else if (Channel == SOUND_CHANNEL_AMBIENT) {
            // player8AD_set_volume(1.0, 1);
            channel_ambient.channel_volume = 1.0;
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
            if (playerULC_is_playing()) {
                playerULC_stop();
            }
            if (auto& action = get_volume_to_action<SOUND_CHANNEL_MUSIC>(); action.has_value()) {
                action.reset();
            }
        } else if (Channel == SOUND_CHANNEL_VIDEO) {
            if (playerULC_is_playing()) {
                playerULC_stop();
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
