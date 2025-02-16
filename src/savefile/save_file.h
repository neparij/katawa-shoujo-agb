#ifndef SAVE_FILE_H
#define SAVE_FILE_H

#include <bn_array.h>
#include "definitions.h"

namespace ks {
    namespace saves {
        constexpr unsigned short TOTAL_SAVE_SLOTS = 500;

        struct __attribute__((__packed__)) SaveIntegrityData {
            bn::array<char, 16> tag;
            unsigned version;
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

            bool operator==(const SaveSettingsData &other) const {
                return language == other.language &&
                       hdisabled == other.hdisabled &&
                       disable_disturbing_content == other.disable_disturbing_content &&
                       high_contrast == other.high_contrast &&
                       text_speed == other.text_speed &&
                       adult_warning_shown == other.adult_warning_shown;
            }
        };

        struct __attribute__((__packed__)) SaveSlotMetadata {
            bool has_data;
            script_t script;
            label_t label;

            unsigned short hours_played;
            unsigned char minutes_played;
            unsigned char seconds_played;

            bool operator==(const ks::saves::SaveSlotMetadata &other) const {
                return has_data == other.has_data &&
                       script == other.script &&
                       label == other.label &&
                       hours_played == other.hours_played &&
                       minutes_played == other.minutes_played &&
                       seconds_played == other.seconds_played;
            }
        };

        struct __attribute__((__packed__)) SaveSlotReproductionData {
            // This stores current scenario line hash in 0x00000000 - 0xFFFFFFFF range
            unsigned int line_hash;

            // This stores up to 8 answer indices
            bn::array<unsigned char, 8> answer_indices;
        };

        /*
         * This struct represents the current game session data.
         * Used to save all your decisions in one save slot.
         *
         * Important! It contains all the flags that are set on scenario was started and choices were made.
         *
         * PS: Grouped by routes and ordered the same way I have played Katawa Shoujo.
         */
        struct __attribute__((__packed__)) SaveSlotProgressData {
            SaveSlotMetadata metadata;
            SaveSlotReproductionData reproduction;

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

            // Integrity check (0xFFFF-i)
            unsigned short integrity;

            bool operator==(const SaveSlotProgressData &other) const {
                return metadata == other.metadata &&
                       attraction_hanako == other.attraction_hanako &&
                       attraction_sc == other.attraction_sc &&
                       im_new_here == other.im_new_here &&
                       talk_with_hanako == other.talk_with_hanako &&
                       wait_for_shizu == other.wait_for_shizu &&
                       promised == other.promised &&
                       wanted_introduce == other.wanted_introduce &&
                       side_lilly == other.side_lilly &&
                       go_for_it == other.go_for_it &&
                       kick_shizu == other.kick_shizu &&
                       fun_fun_at_office == other.fun_fun_at_office &&
                       not_much_talking == other.not_much_talking &&
                       are_student_council == other.are_student_council &&
                       force_route == other.force_route &&
                       run_with_emi == other.run_with_emi &&
                       have_a_minute == other.have_a_minute &&
                       got_advice == other.got_advice &&
                       talk_to_her_mom == other.talk_to_her_mom &&
                       let_misha_know == other.let_misha_know &&
                       pressed_emi == other.pressed_emi &&
                       rin_amazing == other.rin_amazing &&
                       its_refreshing == other.its_refreshing &&
                       be_like_rin == other.be_like_rin &&
                       believes_in_rin == other.believes_in_rin &&
                       believes_in_half == other.believes_in_half &&
                       what_about_emi == other.what_about_emi &&
                       cant_leave_alone == other.cant_leave_alone &&
                       want_to_support == other.want_to_support &&
                       explain == other.explain &&
                       is_true == other.is_true &&
                       refuse_misha == other.refuse_misha &&
                       ask_hanako == other.ask_hanako &&
                       like_hanako == other.like_hanako &&
                       go_to_the_city == other.go_to_the_city &&
                       agree_with_lilly == other.agree_with_lilly &&
                       want_true == other.want_true &&
                       address_it == other.address_it &&
                       mention_the_letter == other.mention_the_letter &&
                       integrity == other.integrity;
            }
        };

        struct __attribute__((__packed__)) SaveFileData {
            SaveIntegrityData integrity_begin;
            SaveSettingsData settings;
            SaveSlotProgressData autosave;
            SaveSlotProgressData slot[TOTAL_SAVE_SLOTS];
            SaveIntegrityData integrity_end;
        };

        // extern SaveFileData data;

        void log_progress(SaveSlotProgressData &progress);

        void log_settings(SaveSettingsData &settings);

        void load(SaveFileData *data_ptr);

        void save(SaveFileData *data_ptr);

        bool isValid(const SaveFileData *data_ptr);

        bool isValid(const SaveSlotProgressData *data_ptr, unsigned int slot);

        unsigned short getTotalSaveSlots();

        unsigned short getUsedSaveSlots();

        int getSettingsDataOffset();

        int getAutosaveDataOffset();

        int getSaveSlotDataOffset(unsigned int slot);

        bool initialize();

        SaveSettingsData readSettings();

        void writeSettings(SaveSettingsData settings);

        SaveSlotMetadata readAutosaveMetadata();

        SaveSlotProgressData readAutosave();

        void writeAutosave(SaveSlotProgressData progress);

        SaveSlotMetadata readSlotMetadata(unsigned int slot);

        SaveSlotProgressData readSaveSlot(unsigned int slot);

        void writeSaveSlot(unsigned int slot, SaveSlotProgressData progress);

        void deleteSaveSlot(unsigned int slot);
    }
}

#endif // SAVE_FILE_H
