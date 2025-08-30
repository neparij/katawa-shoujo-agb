#include "ingametimer.h"

#include <bn_log.h>
#include <bn_timer.h>
#include <bn_timers.h>

#include "scenemanager.h"
namespace ks {
    namespace timer {
        bn::optional<bn::timer> _internal_timer;
        BN_DATA_EWRAM timer_state_t state;

        void init() {
            BN_LOG("Init timer");
            _internal_timer.reset();
            _internal_timer = bn::timer();
            state = TIMER_STATE_READY;
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


        void reset_ingame_timer(const bool reset_values) {
            BN_LOG("Reset ingame timer");
            state = TIMER_STATE_NONE;
            if (_internal_timer.has_value()) {
                _internal_timer.reset();
            }
            _internal_timer = bn::timer();

            if (reset_values) {
                ks::progress.metadata.hours_played = 0;
                ks::progress.metadata.minutes_played = 0;
                ks::progress.metadata.seconds_played = 0;
            }
            state = TIMER_STATE_READY;
        }

        void start_ingame_timer(const bool reset_values) {
            reset_ingame_timer(reset_values);
            BN_ASSERT(_internal_timer.has_value(), "Timer not initialized");
            _internal_timer->restart();
            state = TIMER_STATE_COUNTING;
        }


        void resume_ingame_timer() {
            BN_ASSERT(state != TIMER_STATE_NONE, "Timer state not initialized");
            BN_LOG("Try to resume timer. State = ", state);
            if (state == TIMER_STATE_PAUSED) {
                BN_LOG("Resume ingame timer");
                BN_ASSERT(_internal_timer.has_value(), "Timer not initialized");
                _internal_timer->restart();
                state = TIMER_STATE_COUNTING;
            }
        }

        void pause_ingame_timer() {
            BN_ASSERT(state != TIMER_STATE_NONE, "Timer state not initialized");
            if (state == TIMER_STATE_COUNTING) {
                BN_LOG("Pause ingame timer");
                state = TIMER_STATE_PAUSED;
            }
        }

        void ingame_timer_update() {
            BN_ASSERT(state != TIMER_STATE_NONE, "Timer state not initialized");
            if (state != TIMER_STATE_COUNTING) {
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
