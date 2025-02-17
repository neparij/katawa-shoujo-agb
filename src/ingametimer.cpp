#include "ingametimer.h"

#include <BN_LOG.h>
#include <bn_timer.h>
#include <bn_timers.h>

#include "scenemanager.h"
namespace ks {
    namespace timer {
        bn::optional<bn::timer> _internal_timer;

        timer_state_t state_ingame = TIMER_STATE_NONE;

        void init() {
            BN_LOG("Init timer");
            _internal_timer.reset();
            _internal_timer = bn::timer();
        }

        void update() {
            if (_internal_timer.has_value()) {
                if (_internal_timer->elapsed_ticks() >= bn::timers::ticks_per_second()) {
                    ingame_timer_update();
                    _internal_timer->restart();
                }
            }
        }

        void reset() {
            reset_ingame_timer();
            _internal_timer.reset();
        }


        void reset_ingame_timer() {
            BN_LOG("Reset ingame timer");
            ks::progress.metadata.hours_played = 0;
            ks::progress.metadata.minutes_played = 0;
            ks::progress.metadata.seconds_played = 0;
            state_ingame = TIMER_STATE_NONE;
        }

        void start_ingame_timer() {
            reset_ingame_timer();
            BN_ASSERT(_internal_timer.has_value(), "Timer not initialized");
            _internal_timer->restart();
            state_ingame = TIMER_STATE_COUNTING;
        }


        void resume_ingame_timer() {
            if (state_ingame == TIMER_STATE_PAUSED) {
                BN_LOG("Resume ingame timer");
                BN_ASSERT(_internal_timer.has_value(), "Timer not initialized");
                _internal_timer->restart();
                state_ingame = TIMER_STATE_COUNTING;
            }
        }

        void pause_ingame_timer() {
            if (state_ingame == TIMER_STATE_COUNTING) {
                BN_LOG("Pause ingame timer");
                state_ingame = TIMER_STATE_PAUSED;
            }
        }

        void ingame_timer_update() {
            if (state_ingame != TIMER_STATE_COUNTING) {
                return;
            }
            ks::progress.metadata.seconds_played++;
            if (ks::progress.metadata.seconds_played >= 60) {
                ks::progress.metadata.seconds_played = 0;
                ks::progress.metadata.minutes_played++;
                if (ks::progress.metadata.minutes_played >= 60) {
                    ks::progress.metadata.minutes_played = 0;
                    ks::progress.metadata.hours_played++;
                }
            }
        }
    } // namespace timer
} // namespace ks
