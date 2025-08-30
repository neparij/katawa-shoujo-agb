#ifndef KS_SOUND_MANAGER_H
#define KS_SOUND_MANAGER_H

#include <bn_fixed.h>
#include <bn_log.h>
#include <bn_optional.h>
#include <bn_template_actions.h>

#include "definitions.h"


namespace ks::sound_manager {
    void init();

    void update();

    void restore_after_loading();

    BN_CODE_IWRAM void on_vblank();

    template<sound_channel_t Channel>
    void play(const char *name);

    inline void play(music_t music);

    template<sound_channel_t Channel>
    void stop();

    template<sound_channel_t Channel>
    void set_channel_loop(bool is_looping);

    template<sound_channel_t Channel>
    bool get_channel_loop();

    template<sound_channel_t Channel>
    BN_CODE_IWRAM void set_channel_volume(bn::fixed volume);

    template<sound_channel_t Channel>
    BN_CODE_IWRAM void set_sound_volume(bn::fixed volume);

    template<sound_channel_t Channel>
    BN_CODE_IWRAM bn::fixed get_channel_volume();

    template<sound_channel_t Channel>
    BN_CODE_IWRAM bn::fixed get_sound_volume();

    template<sound_channel_t Channel>
    BN_CODE_IWRAM bn::fixed get_mixed_volume();

    template<sound_channel_t Channel>
    void set_fadein_action(int duration_updates);

    template<sound_channel_t Channel>
    void set_fadeout_action(int duration_updates);

    template<sound_channel_t Channel>
    class action_volume_manager {
    public:
        [[nodiscard]] static bn::fixed get() {
            return ks::sound_manager::get_sound_volume<Channel>();
        }

        static void set(const bn::fixed volume) {
            // BN_LOG("Set sound volume of channel ", Channel, " to ", volume);
            ks::sound_manager::set_sound_volume<Channel>(volume);
        }
    };

    template<sound_channel_t Channel>
    class action_channel_volume_manager {
    public:
        [[nodiscard]] static bn::fixed get() {
            return ks::sound_manager::get_channel_volume<Channel>();
        }

        static void set(const bn::fixed volume) {
            // BN_LOG("Set channel volume of channel ", Channel, " to ", volume);
            ks::sound_manager::set_channel_volume<Channel>(volume);
        }
    };

    template<sound_channel_t Channel>
    class volume_to_action : public bn::to_template_action<bn::fixed, action_volume_manager<Channel> > {
    public:
        volume_to_action(int duration_updates, bn::fixed final_volume)
            : bn::to_template_action<bn::fixed, action_volume_manager<Channel> >(duration_updates, final_volume) {
            BN_ASSERT(final_volume >= 0 && final_volume <= 1, "Invalid final volume: ", final_volume);
        }

        [[nodiscard]] bn::fixed final_volume() const {
            return this->final_property();
        }
    };

    template<sound_channel_t Channel>
    class channel_volume_to_action : public bn::to_template_action<bn::fixed, action_channel_volume_manager<Channel> > {
    public:
        channel_volume_to_action(int duration_updates, bn::fixed final_volume)
            : bn::to_template_action<bn::fixed, action_channel_volume_manager<Channel> >(
                duration_updates, final_volume) {
            BN_ASSERT(final_volume >= 0 && final_volume <= 1, "Invalid final volume: ", final_volume);
        }

        [[nodiscard]] bn::fixed final_volume() const {
            return this->final_property();
        }
    };

    struct channel_base {
        bn::fixed channel_volume;
        bn::fixed sound_volume;
        bool loop;
    };

    template<sound_channel_t Channel>
    struct channel : public channel_base {
        channel(const bn::fixed initial_channel_volume, const bn::fixed initial_sound_volume, const bool initial_loop)
            : channel_base(initial_channel_volume, initial_sound_volume, initial_loop) {
        }

        bn::optional<channel_volume_to_action<Channel> > channel_volume_to = bn::nullopt;
        bn::optional<volume_to_action<Channel> > volume_to = bn::nullopt;
        sound_channel_t channel_name = Channel;
    };

    extern channel<SOUND_CHANNEL_MUSIC> channel_music;
    extern channel<SOUND_CHANNEL_SOUND> channel_sound;
    extern channel<SOUND_CHANNEL_AMBIENT> channel_ambient;
}

#include "sound_manager_impl.h"

#endif //KS_SOUND_MANAGER_H
