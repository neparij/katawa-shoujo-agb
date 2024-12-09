#ifndef SAVE_FILE_H
#define SAVE_FILE_H

#include "bn_sram.h"

namespace ks {
    namespace saves {

        const int TOTAL_SAVE_SLOTS = 64;

        /*
         * This struct represents the current game session data.
         * Used to save all your decisions in one save slot.
         *
         * PS: Grouped by routes and ordered the same way I have played Katawa Shoujo.
         */
        struct __attribute__((__packed__)) SaveSlotProgressData {

            // Act 1 data
            unsigned char attraction_hanako;
            unsigned char attraction_sc;
            bool im_new_here; // That's hardcoded string from scenario 'Hi! I'm new here. Hisao Nakai. We're in the same class.' in choices
            bool talk_with_hanako;
            bool wait_for_shizu;
            bool promised;
            bool wanted_introduce;
            bool side_lilly;
            bool go_for_it;
            bool kick_shizu;
            bool fun_fun_at_office;
            bool not_much_talking;
            bool are_student_council;
            unsigned char force_route; // FR_RIN, etc... It should work somehow with Enum

            // Emi route data
            bool run_with_emi;
            bool have_a_minute;
            bool got_advice;
            bool talk_to_her_mom;
            bool let_misha_know;
            bool pressed_emi;

            // Rin route data
            bool rin_amazing;
            bool its_refreshing;
            bool be_like_rin;
            bool believes_in_rin;
            bool believes_in_half;
            bool what_about_emi;
            bool cant_leave_alone;
            bool want_to_support;
            bool explain;
            bool is_true;

            // Shizune route data
            bool refuse_misha;

            // Hanako route data
            bool ask_hanako;
            bool like_hanako;
            bool go_to_the_city;
            bool agree_with_lilly;

            // Lilly route data
            bool want_true;
            bool address_it;
            bool mention_the_letter;
        };

        struct __attribute__((__packed__)) SaveFileData {
            // Integrity
            unsigned integrityHash;

            // User Settings
            unsigned char language;
            bool hdisabled;
            bool disable_disturbing_content;
            bool high_contrasrt;
            unsigned char text_speed;

            // States
            bool adult_warning_shown;
            unsigned char video_playback_state; // Will be used as enum value (OP_1, TC_ACT2_EMI, etc) to restore game state after soft-resetting

            // Save Slots
            SaveSlotProgressData slot[TOTAL_SAVE_SLOTS];
        };

        extern SaveFileData data;

        void load();
        void save();
    }
}

#endif // SAVE_FILE_H
