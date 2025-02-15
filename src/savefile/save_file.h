#ifndef SAVE_FILE_H
#define SAVE_FILE_H

#include <bn_array.h>
#include "definitions.h"

namespace ks {
    namespace saves {
        constexpr int TOTAL_SAVE_SLOTS = 500;

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
            // That's hardcoded string from scenario 'Hi! I'm new here. Hisao Nakai. We're in the same class.' in choices
            bool im_new_here;
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
            forceRoute_t force_route;

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

        struct __attribute__((__packed__)) SaveSettingsData {
            // User Settings
            language_t language;
            bool hdisabled;
            bool disable_disturbing_content;
            bool high_contrast;
            unsigned char text_speed;

            // States
            bool adult_warning_shown;
        };

        struct __attribute__((__packed__)) SaveFileData {
            // Integrity
            bn::array<char, 16> integrityTag;
            unsigned integrityVersion;

            SaveSettingsData settings;
            SaveSlotProgressData slot[TOTAL_SAVE_SLOTS];
        };

        // extern SaveFileData data;

        void log_progress(SaveSlotProgressData &progress);

        void log_settings(SaveSettingsData &settings);

        void load(SaveFileData* data_ptr);

        void save(SaveFileData* data_ptr);

        bool isValid(SaveFileData* data_ptr);

        bool initialize();

        SaveSettingsData getSettings();
        void saveSettings(SaveSettingsData settings);
    }
}

#endif // SAVE_FILE_H
