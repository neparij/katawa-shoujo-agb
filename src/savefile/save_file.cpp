#include "save_file.h"

#include <bn_core.h>
#include <BN_LOG.h>
#include <bn_sram.h>

#include <bn_memory.h>
#include <gba_types.h>

#include "../globals.h"

#define INTEGRITY_VERSION 2121210001
#define INTEGRITY_TAG "KATAWASHOUJOAGB"

extern FlashInfo gFlashInfo;
extern bool faked = false; // For testing purposes, to fake flash memory

// BN_DATA_EWRAM static u8 flash_buffer[FLASH_SECTOR_SIZE_4KB];  // Temporary buffer in RAM

inline bn::array<char, 16> getIntegrityTag() {
    bn::array<char, 16> expected_format_tag{};
    bn::istring_base expected_format_tag_istring(expected_format_tag._data);
    bn::ostringstream expected_format_tag_stream(expected_format_tag_istring);
    expected_format_tag_stream.append(INTEGRITY_TAG);

    return expected_format_tag;
}

void ks::saves::load(SaveFileData *data_ptr) {
    BN_LOG("Load save data to ptr ", data_ptr);
    BN_ASSERT(data_ptr != nullptr, "Unable to load. Data pointer is null.");

    if (is_flash()) {
        BN_LOG("Full Load from flash");
        flash_read(0, (u8 *) data_ptr, sizeof(*data_ptr));
    } else {
        BN_LOG("Full Load from SRAM");
        bn::sram::read(*data_ptr);
    }
}

void ks::saves::save(SaveFileData *data_ptr) {
    BN_LOG("Save save data to ptr ", data_ptr);
    BN_ASSERT(data_ptr != nullptr, "Unable to save. Data pointer is null.");
    BN_ASSERT(isValid(data_ptr), "Unable to save. Data is corrupted.");

    if (is_flash()) {
        BN_LOG("Full Save to flash");
        flash_write(0, (u8 *) data_ptr, sizeof(*data_ptr));
    } else {
        BN_LOG("Full Save to SRAM");
        bn::sram::write(*data_ptr);
    }
}

bool ks::saves::initialize() {
    bool valid = false;
    BN_LOG("Initializing saves...");

    auto *save_data = static_cast<SaveFileData *>(bn::memory::ewram_alloc(sizeof(SaveFileData)));

    if (!faked) {
        const int flash_init_success = flash_init((u8) FLASH_SIZE_AUTO);
        BN_LOG("Flash DeviceID: ", gFlashInfo.device);
        BN_LOG("Flash ManufacturerID: ", gFlashInfo.manufacturer);
        BN_LOG("Flash SizeType: ", gFlashInfo.size);
        BN_LOG("Flash init success: ", flash_init_success == 0);
        if (flash_init_success != 0) {
            gFlashInfo.device = 0;
            gFlashInfo.manufacturer = 0;
            gFlashInfo.size = 0;
        }
    }

    load(save_data);
    log_settings(save_data->settings);
    valid = isValid(save_data);
    bn::memory::ewram_free(save_data);

    if (!valid) {
        save_data = new SaveFileData();
        save_data->integrity_begin.tag = getIntegrityTag();
        save_data->integrity_end.tag = getIntegrityTag();
        save_data->integrity_begin.version = INTEGRITY_VERSION;
        save_data->integrity_end.version = INTEGRITY_VERSION;

        // TODO: savegame restoration if any
        // Should go through all save slots and check if they are have any data and valid
        // Then restore it one-by-one.
        // Log the restoration process.

        if (is_flash()) {
            flash_reset();
        }
        save(save_data);
        bn::memory::ewram_free(save_data);
        return true;
    }

    return false;
}


bool ks::saves::isValid(const SaveFileData *data_ptr) {
    if (data_ptr->integrity_begin.tag != getIntegrityTag()) {
        BN_LOG("SaveFileData begin integrity tag does not match.");
        return false;
    }
    if (data_ptr->integrity_begin.version != INTEGRITY_VERSION) {
        BN_LOG("SaveFileData begin integrity version does not match.");
        return false;
    }
    if (data_ptr->integrity_end.tag != getIntegrityTag()) {
        BN_LOG("SaveFileData end integrity tag does not match.");
        return false;
    }
    if (data_ptr->integrity_end.version != INTEGRITY_VERSION) {
        BN_LOG("SaveFileData end integrity version does not match.");
        return false;
    }

    BN_LOG("SaveFileData integrity is valid.");
    return true;
}

bool ks::saves::isValid(const SaveSlotProgressData *data_ptr, const short slot) {
    BN_ASSERT(slot == -1 || (slot >= 0 && slot < TOTAL_SAVE_SLOTS), "Invalid slot number: ", slot);

    if (slot == -1) {
        if (data_ptr->integrity != 0xFFFF - 1024) {
            BN_LOG("AutosaveSlotProgressData integrity does not match.");
            return false;
        }
    } else if (data_ptr->integrity != 0xFFFF - slot) {
        BN_LOG("SaveSlotProgressData integrity does not match.");
        return false;
    }

    BN_LOG("SaveSlotProgressData integrity is valid.");
    return true;
}

unsigned short ks::saves::getTotalSaveSlots() {
    return TOTAL_SAVE_SLOTS;
}

unsigned short ks::saves::getUsedSaveSlots() {
    unsigned short used_slots = 0;
    for (unsigned int i = 0; i < TOTAL_SAVE_SLOTS; i++) {
        bool has_data;
        read_offset(has_data, getSaveSlotDataOffset(i));

        BN_LOG("Slot ", i, " has data: ", has_data);
        if (has_data) {
            used_slots++;
        } else {
            return used_slots;
        }
    }

    return used_slots;
}

int ks::saves::getSettingsDataOffset() {
    return sizeof(SaveIntegrityData);
}

int ks::saves::getAutosaveDataOffset() {
    return sizeof(SaveIntegrityData) +
           sizeof(SaveSettingsData);
}

int ks::saves::getSaveSlotDataOffset(const unsigned int slot) {
    return sizeof(SaveIntegrityData) +
           sizeof(SaveSettingsData) +
           sizeof(SaveSlotProgressData) +
           sizeof(SaveSlotProgressData) * slot;
}

ks::saves::SaveSettingsData ks::saves::readSettings() {
    BN_LOG("Read Settings");
    SaveSettingsData settings;
    read_offset(settings, getSettingsDataOffset());

    log_settings(settings);
    return settings;
}

void ks::saves::writeSettings(const SaveSettingsData settings) {
    BN_LOG("Write Settings");
    write_offset(settings, getSettingsDataOffset());

    const SaveSettingsData saved_settings = readSettings();
    BN_ASSERT(settings == saved_settings, "Writing settings failed. SRAM data does not match.");
}

ks::saves::SaveSlotMetadata ks::saves::readAutosaveMetadata() {
    BN_LOG("Read Autosave Metadata");
    SaveSlotMetadata metadata;
    read_offset(metadata, getAutosaveDataOffset());
    log_progress_metadata(metadata);

    return metadata;
}

ks::saves::SaveSlotProgressData ks::saves::readAutosave() {
    BN_LOG("Read Autosave");
    SaveSlotProgressData progress;
    read_offset(progress, getAutosaveDataOffset());

    log_progress(progress);
    return progress;
}

void ks::saves::writeAutosave(SaveSlotProgressData progress) {
    BN_LOG("Write Autosave");
    progress.metadata.has_data = true;
    progress.integrity = 0xFFFF - 1024;

    write_offset(progress, getAutosaveDataOffset());
    bn::core::update();

    const SaveSlotProgressData saved_progress = readAutosave();
    // BN_ASSERT(progress == saved_progress, "Writing autosave failed. SRAM data does not match.");
}

ks::saves::SaveSlotMetadata ks::saves::readSlotMetadata(const unsigned int slot) {
    BN_LOG("Read Save Slot Metadata ", slot);
    SaveSlotMetadata metadata;
    read_offset(metadata, getSaveSlotDataOffset(slot));
    log_progress_metadata(metadata);

    return metadata;
}

ks::saves::SaveSlotProgressData ks::saves::readSaveSlot(const unsigned int slot) {
    BN_LOG("Read Save Slot ", slot);
    SaveSlotProgressData progress;
    read_offset(progress, getSaveSlotDataOffset(slot));

    log_progress(progress);
    return progress;
}

void ks::saves::writeSaveSlot(const unsigned int slot, SaveSlotProgressData progress) {
    BN_LOG("Write Save Slot ", slot);
    progress.metadata.has_data = true;
    progress.integrity = 0xFFFF - slot;

    write_offset(progress, getSaveSlotDataOffset(slot));

    const SaveSlotProgressData saved_progress = readSaveSlot(slot);
    BN_ASSERT(progress == saved_progress, "Writing save slot failed. SRAM data does not match.");
}

// Deletes save slot and re-organize save slots in save data (remove current slot, shift the remaining)
void ks::saves::deleteSaveSlot(const unsigned int slot) {
    // TODO: implement
    // // Remove the save slot data
    // // bn::sram::write_offset(SaveSlotProgressData{}, getSaveSlotDataOffset(slot));
    // SaveSlotProgressData empty;
    // flash_write(getSaveSlotDataOffset(slot), (u8 *) &empty, sizeof(empty));
    //
    // // Shift the remaining save slots
    // for (unsigned int i = slot + 1; i < TOTAL_SAVE_SLOTS; i++) {
    //     SaveSlotProgressData progress = readSaveSlot(i);
    //     progress.integrity = 0xFFFF - (i - 1);
    //     writeSaveSlot(i - 1, progress);
    // }
    //
    // // Delete the last save slot
    // // bn::sram::write_offset(SaveSlotProgressData{}, getSaveSlotDataOffset(TOTAL_SAVE_SLOTS - 1));
    // flash_write(getSaveSlotDataOffset(TOTAL_SAVE_SLOTS - 1), (u8 *) &empty, sizeof(empty));
}

void ks::saves::log_progress_metadata(SaveSlotMetadata &metadata) {
    BN_LOG("  METADATA:");
    BN_LOG("    has_data: ", metadata.has_data);
    BN_LOG("    script: ", metadata.script);
    BN_LOG("    label: ", metadata.label);
    BN_LOG("    thumbnail_hash: ", metadata.thumbnail_hash);
    BN_LOG("    hours_played: ", metadata.hours_played);
    BN_LOG("    minutes_played: ", metadata.minutes_played);
    BN_LOG("    seconds_played: ", metadata.seconds_played);
}

void ks::saves::log_progress(SaveSlotProgressData &progress) {
    BN_LOG("Progress:");

    log_progress_metadata(progress.metadata);

    BN_LOG(" REPRODUCTION DATA:");
    BN_LOG("    line_hash: ", progress.reproduction.line_hash);
    BN_LOG("    answer_indices:");
    for (unsigned char answer_index : progress.reproduction.answer_indices) {
        BN_LOG("      ", answer_index);
    }

    BN_LOG("  ACT 1 DATA:");
    BN_LOG("    attraction_hanako: ", progress.attraction_hanako);
    BN_LOG("    attraction_sc: ", progress.attraction_sc);
    BN_LOG("    im_new_here: ", progress.im_new_here);
    BN_LOG("    talk_with_hanako: ", progress.talk_with_hanako);
    BN_LOG("    wait_for_shizu: ", progress.wait_for_shizu);
    BN_LOG("    promised: ", progress.promised);
    BN_LOG("    wanted_introduce: ", progress.wanted_introduce);
    BN_LOG("    side_lilly: ", progress.side_lilly);
    BN_LOG("    go_for_it: ", progress.go_for_it);
    BN_LOG("    kick_shizu: ", progress.kick_shizu);
    BN_LOG("    fun_fun_at_office: ", progress.fun_fun_at_office);
    BN_LOG("    not_much_talking: ", progress.not_much_talking);
    BN_LOG("    are_student_council: ", progress.are_student_council);
    BN_LOG("    force_route: ", progress.force_route);

    BN_LOG("  EMI ROUTE DATA:");
    BN_LOG("    run_with_emi: ", progress.run_with_emi);
    BN_LOG("    have_a_minute: ", progress.have_a_minute);
    BN_LOG("    got_advice: ", progress.got_advice);
    BN_LOG("    talk_to_her_mom: ", progress.talk_to_her_mom);
    BN_LOG("    let_misha_know: ", progress.let_misha_know);
    BN_LOG("    pressed_emi: ", progress.pressed_emi);

    BN_LOG("  RIN ROUTE DATA:");
    BN_LOG("    rin_amazing: ", progress.rin_amazing);
    BN_LOG("    its_refreshing: ", progress.its_refreshing);
    BN_LOG("    be_like_rin: ", progress.be_like_rin);
    BN_LOG("    believes_in_rin: ", progress.believes_in_rin);
    BN_LOG("    believes_in_half: ", progress.believes_in_half);
    BN_LOG("    what_about_emi: ", progress.what_about_emi);
    BN_LOG("    cant_leave_alone: ", progress.cant_leave_alone);
    BN_LOG("    want_to_support: ", progress.want_to_support);
    BN_LOG("    explain: ", progress.explain);
    BN_LOG("    is_true: ", progress.is_true);

    BN_LOG("  SHIZUNE ROUTE DATA:");
    BN_LOG("    refuse_misha: ", progress.refuse_misha);

    BN_LOG("  HANAKO ROUTE DATA:");
    BN_LOG("    ask_hanako: ", progress.ask_hanako);
    BN_LOG("    like_hanako: ", progress.like_hanako);
    BN_LOG("    go_to_the_city: ", progress.go_to_the_city);
    BN_LOG("    agree_with_lilly: ", progress.agree_with_lilly);

    BN_LOG("  LILLY ROUTE DATA:");
    BN_LOG("    want_true: ", progress.want_true);
    BN_LOG("    address_it: ", progress.address_it);
    BN_LOG("    mention_the_letter: ", progress.mention_the_letter);
}

void ks::saves::log_settings(SaveSettingsData &settings) {
    BN_LOG("Settings:");
    BN_LOG("  language: ", settings.language);
    BN_LOG("  hdisabled: ", settings.hdisabled);
    BN_LOG("  disable_disturbing_content: ", settings.disable_disturbing_content);
    BN_LOG("  high_contrasrt: ", settings.high_contrast);
    BN_LOG("  text_speed: ", settings.text_speed);
    BN_LOG("  adult_warning_shown: ", settings.adult_warning_shown);
}

__attribute__ ((noinline, section(".ewram.flash"))) void ks::saves::flash_write_offset(u8* data, int offset, int size) {
    BN_LOG("Flash write offset ", offset, " size ", size);

    const int sector_start = offset & ~(FLASH_SECTOR_SIZE_4KB - 1);  // Align to sector
    const int sector_offset = offset - sector_start;  // Offset within sector
    const int end_offset = offset + size;  // End of data
    const int end_sector_start = end_offset & ~(FLASH_SECTOR_SIZE_4KB - 1);  // Last sector start

    BN_LOG("Sector start ", sector_start, " offset ", sector_offset, " end sector start ", end_sector_start);

    // Process the first sector
    auto *flash_buffer = static_cast<u8 *>(bn::memory::ewram_alloc(FLASH_SECTOR_SIZE_4KB));
    flash_read(sector_start, flash_buffer, FLASH_SECTOR_SIZE_4KB);  // Read first sector
    int first_sector_write_size = FLASH_SECTOR_SIZE_4KB - sector_offset;  // Bytes we can write in first sector
    if (first_sector_write_size > size) first_sector_write_size = size;  // Clamp to total data size

    // Modify first sector buffer
    for (int i = 0; i < first_sector_write_size; i++) {
        flash_buffer[sector_offset + i] = data[i];
    }

    // Erase and write first sector
    flash_write(sector_start, flash_buffer, FLASH_SECTOR_SIZE_4KB);
    bn::memory::ewram_free(flash_buffer);

    // If data spans two sectors, process the second one
    if (end_sector_start != sector_start) {
        BN_LOG("Should also write second sector!");
        int second_sector_size = size - first_sector_write_size;  // Remaining data for second sector
        flash_buffer = static_cast<u8 *>(bn::memory::ewram_alloc(FLASH_SECTOR_SIZE_4KB));
        flash_read(end_sector_start, flash_buffer, FLASH_SECTOR_SIZE_4KB);  // Read second sector

        // Modify second sector buffer
        for (int i = 0; i < second_sector_size; i++) {
            flash_buffer[i] = data[first_sector_write_size + i];
        }

        // Erase and write second sector
        flash_write(end_sector_start, flash_buffer, FLASH_SECTOR_SIZE_4KB);
        bn::memory::ewram_free(flash_buffer);
    }
}

bool ks::saves::is_flash() {
    return gFlashInfo.device != 255 && gFlashInfo.manufacturer != 255 && gFlashInfo.size != 0;
}

FlashInfo ks::saves::get_flash_info() {
    return gFlashInfo;
}

void ks::saves::set_flash_info_fake_sram() {
    gFlashInfo.device = 255;
    gFlashInfo.manufacturer = 255;
    gFlashInfo.size = 0;

    faked = true;  // Set faked flag to true for testing purposes
}
