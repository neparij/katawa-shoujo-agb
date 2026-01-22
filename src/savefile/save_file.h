#ifndef SAVE_FILE_H
#define SAVE_FILE_H

#include <bn_array.h>
#include <bn_log.h>
#include <bn_sprite_item.h>
#include <gba_types.h>

#include "definitions.h"
#include "seen_bitmask.h"

#ifdef SAVE_TYPE
#define SAVE_TYPE_SRAM 0
#define SAVE_TYPE_FLASH 1
#if SAVE_TYPE == SAVE_TYPE_SRAM
#define SAVE_TYPE_STRING "SRAM"
#include <bn_sram.h>
#elif SAVE_TYPE == SAVE_TYPE_FLASH
#define SAVE_TYPE_STRING "FLASH"
#else
#define SAVE_TYPE_STRING "UNKNOWN"
#endif
#else
#error "SAVE_TYPE is not defined. Please define SAVE_TYPE as SRAM or FLASH."
#endif

#if SAVE_TYPE == SAVE_TYPE_FLASH
extern "C" {
#include "gba_flash.h"
    int flash_write_byte(u32 addr, u8 data);
    void flash_switch_bank(int bank);
}
#define FLASH_SECTOR_SIZE_4KB  4096
struct FlashInfo {
    u8 device;
    u8 manufacturer;
    u8 size;
};
#endif

namespace ks {
    namespace saves {
        constexpr unsigned short TOTAL_SAVE_SLOTS = 400;
        constexpr unsigned char BLOCK_END = 0xFF;

        struct alignas(4) SaveIntegrityData {
            bn::array<char, 16> tag;
            unsigned version;
        };

        struct alignas(4) SaveSettingsData {
            // User Settings
            language_t language;
            bool hdisabled;

            // Sound settings
            unsigned char music_volume = 0xCC; // Music volume (ULC), default is 80%
            unsigned char sfx_volume = 0xCC;   // SFX volume (8ad), default is 80%

            // Accessibility
            unsigned char text_speed = 0xCC; // Text rendering speed, default is 80%
            unsigned char brightness = 0x00; // Additional brightness, default is 0%
            bool high_contrast;
            bool disable_disturbing_content;

            bool operator==(const SaveSettingsData &other) const {
                return language == other.language &&
                       hdisabled == other.hdisabled &&
                       music_volume == other.music_volume &&
                       sfx_volume == other.sfx_volume &&
                       text_speed == other.text_speed &&
                       high_contrast == other.high_contrast &&
                       disable_disturbing_content == other.disable_disturbing_content;
            }
        };

        struct alignas(4) SaveStatesData {
            // States
            bool adult_warning_shown;
            uint8_t seen_displayables[64]; // Bitmask for seen CGs and backgrounds (64 bytes, 512 entries)

            void set_seen_displayable(const displayable_bitmask_t index, const bool value) {
                if (index >= 512) {
                    BN_ERROR("Displayable index out of range: ", index);
                }
                const unsigned int array_index = index / 8;
                const unsigned int bit_index = index % 8;
                if (value) {
                    seen_displayables[array_index] |= (1u << bit_index);
                } else {
                    seen_displayables[array_index] &= ~(1u << bit_index);
                }
            }

            [[nodiscard]] bool is_seen_displayable(const displayable_bitmask_t index) const {
                if (index >= 512) {
                    BN_ERROR("Displayable index out of range: ", index);
                }
                const unsigned int array_index = index / 8;
                const unsigned int bit_index = index % 8;
                return (seen_displayables[array_index] & (1u << bit_index)) != 0;
            }

            bool operator==(const SaveStatesData &other) const {
                if(adult_warning_shown != other.adult_warning_shown) {
                    return false;
                }
                for(int i = 0; i < 64; i++) {
                    if(seen_displayables[i] != other.seen_displayables[i]) {
                        return false;
                    }
                }
                return true;
            }
        };

        struct SaveSlotMetadataCharacters {
            // This stores character thumbnail hash in 0x0000 - 0xFFFF range
            unsigned short thumbnail_hash;
            short offset_x;
        };

        struct alignas(4) SaveSlotMetadata {
            bool has_data;
            script_t script;
            label_t label;

            // This stores current background hash in 0x00000000 - 0xFFFFFFFF range
            unsigned int thumbnail_hash;
            SaveSlotMetadataCharacters thumbnail_characters[4];

            unsigned short hours_played;
            unsigned char minutes_played;
            unsigned char seconds_played;

            bool operator==(const ks::saves::SaveSlotMetadata &other) const {
                return has_data == other.has_data &&
                       script == other.script &&
                       label == other.label &&
                       thumbnail_hash == other.thumbnail_hash &&
                       hours_played == other.hours_played &&
                       minutes_played == other.minutes_played &&
                       seconds_played == other.seconds_played;
            }
        };

        struct __attribute__((__packed__)) alignas(4) SaveSlotReproductionData {
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
        struct alignas(4) SaveSlotProgressData {
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

            [[nodiscard]] bool go_through_lilly() const {
                // #     def go_through_lilly():
                // #         return talk_with_hanako and side_lilly
                return talk_with_hanako && side_lilly;
            }

            [[nodiscard]] bool go_through_shizu() const {
                // #     def go_through_shizu():
                // #         return wait_for_shizu and not side_lilly
                return wait_for_shizu && !side_lilly;
            }

            [[nodiscard]] bool get_tired() const {
                // #     def get_tired():
                // #         return promised and go_for_it
                return promised && go_for_it;
            }

            [[nodiscard]] bool got_kenji() const {
                // #     def got_kenji():
                // #         return kick_shizu or fun_fun_at_office or not_much_talking
                return kick_shizu || fun_fun_at_office || not_much_talking;
            }

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

        struct alignas(4) SaveFileData {
            SaveIntegrityData integrity_begin;
            SaveSettingsData settings;
            SaveStatesData states;
            SaveSlotProgressData autosave;
            SaveSlotProgressData slot[TOTAL_SAVE_SLOTS];
            SaveIntegrityData integrity_end;
        };


        void log_progress_metadata(SaveSlotMetadata &metadata);

        void log_progress(SaveSlotProgressData &progress);

        void log_settings(SaveSettingsData &settings);

        template<typename Type>
        void load(Type *data_ptr);

        void save(SaveFileData *data_ptr);

        bool isValid(const SaveFileData *data_ptr);

        bool isValid(const SaveSlotProgressData *data_ptr, short slot);

        unsigned short getTotalSaveSlots();

        unsigned short getUsedSaveSlots();

        int getSettingsDataOffset();

        int getStatesDataOffset();

        int getAutosaveDataOffset();

        int getSaveSlotDataOffset(unsigned int slot);

        bool initialize();

        SaveSettingsData readSettings();

        void writeSettings(SaveSettingsData settings);

        SaveStatesData readStates();

        void writeStates(const SaveStatesData &states);

        SaveSlotMetadata readAutosaveMetadata();

        SaveSlotProgressData readAutosave();

        void writeAutosave(SaveSlotProgressData progress);

        SaveSlotMetadata readSlotMetadata(unsigned int slot);

        SaveSlotProgressData readSaveSlot(unsigned int slot);

        void writeSaveSlot(unsigned int slot, SaveSlotProgressData &progress);

        void deleteSaveSlot(unsigned int slot);

#if SAVE_TYPE == SAVE_TYPE_SRAM
        template<typename Type>
        void write_offset(const Type& source, int offset) {
            bn::sram::write_offset(source, offset);
        }

        template<typename Type>
        void read_offset(Type& destination, int offset) {
            bn::sram::read_offset(destination, offset);
        }
#endif
#if SAVE_TYPE == SAVE_TYPE_FLASH
        template<typename Type>
        void flash_write_offset(const Type& source, int offset);

        template<typename Type>
        BN_CODE_EWRAM void write_offset(const Type& source, int offset) {
            flash_write_offset(source, offset);
        }

        template<typename Type>
        BN_CODE_EWRAM void read_offset(Type& destination, int offset) {
            const int result = flash_read(offset, (u8 *) &destination, int(sizeof(Type)));
            BN_ASSERT(result == 0, "Unable to read from flash. Reboot your console");
        }

        FlashInfo get_flash_info();
#endif
    }
}

#endif // SAVE_FILE_H
