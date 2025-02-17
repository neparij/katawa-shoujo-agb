#ifndef INGAMETIMER_H
#define INGAMETIMER_H
#include <bn_optional.h>
#include <bn_timer.h>


typedef unsigned char timer_state_t;
#define TIMER_STATE_NONE ((timer_state_t)0)
#define TIMER_STATE_COUNTING ((timer_state_t)1)
#define TIMER_STATE_PAUSED ((timer_state_t)2)


namespace ks {
    namespace timer {
        extern bn::optional<bn::timer> _internal_timer;

        extern timer_state_t state_ingame;

        extern void init();

        extern void update();

        extern void reset();

        // Resets ingame timer and sets it to 0
        extern void reset_ingame_timer();

        // Resets and starts ingame timer
        extern void start_ingame_timer();

        // Resumes ingame timer
        extern void resume_ingame_timer();

        // Pauses ingame timer
        extern void pause_ingame_timer();

        extern void ingame_timer_update();
    } // namespace timer
} // namespace ks

#endif // INGAMETIMER_H
