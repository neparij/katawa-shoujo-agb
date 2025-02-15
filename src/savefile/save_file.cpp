#include "save_file.h"

#include <bn_core.h>
#include <BN_LOG.h>
#include <bn_sram.h>

#include <bn_memory.h>
#include <gba_types.h>

// BN_DATA_EWRAM_BSS ks::saves::SaveFileData ks::saves::data;

#define INTEGRITY_VERSION 2121210001
#define INTEGRITY_TAG "KATAWASHOUJOAGB"

inline bn::array<char, 16> getIntegrityTag() {
    bn::array<char, 16> expected_format_tag{};
    bn::istring_base expected_format_tag_istring(expected_format_tag._data);
    bn::ostringstream expected_format_tag_stream(expected_format_tag_istring);
    expected_format_tag_stream.append(INTEGRITY_TAG);

    return expected_format_tag;
}

void ks::saves::load(SaveFileData* data_ptr) {
    BN_LOG("Load save data to ptr ", data_ptr);
    BN_ASSERT(data_ptr != nullptr, "Unable to load. Data pointer is null.");
    bn::sram::read(*data_ptr);

    // TODO: save and load using offsets with spans (reduce time for saving and loading)
}

void ks::saves::save(SaveFileData* data_ptr) {
    BN_LOG("Save save data to ptr ", data_ptr);
    BN_ASSERT(data_ptr != nullptr, "Unable to save. Data pointer is null.");
    BN_ASSERT(isValid(data_ptr), "Unable to save. Data is corrupted.");
    bn::sram::write(*data_ptr);
}

bool ks::saves::initialize() {
    bool valid = false;
    BN_LOG("Initializing saves...");

    BN_LOG("Free EWRAM init1: ", bn::memory::available_alloc_ewram());
    auto* save_data = static_cast<SaveFileData *>(bn::memory::ewram_alloc(sizeof(SaveFileData)));
    BN_LOG("Free EWRAM init2: ", bn::memory::available_alloc_ewram());

    load(save_data);

    BN_LOG("Validating save data...");
    valid = isValid(save_data);

    BN_LOG("Free EWRAM init3: ", bn::memory::available_alloc_ewram());
    bn::memory::ewram_free(save_data);
    BN_LOG("Free EWRAM init4: ", bn::memory::available_alloc_ewram());

    if (!valid) {
        save_data = new SaveFileData();
        save_data->integrityTag = getIntegrityTag();
        save_data->integrityVersion = INTEGRITY_VERSION;

        BN_LOG("Free EWRAM init5: ", bn::memory::available_alloc_ewram());
        save(save_data);
        BN_LOG("Free EWRAM init6: ", bn::memory::available_alloc_ewram());
        bn::memory::ewram_free(save_data);
        BN_LOG("Free EWRAM init7: ", bn::memory::available_alloc_ewram());
        return true;
    }

    return false;
}


bool ks::saves::isValid(SaveFileData* data_ptr) {
    BN_LOG("isValid?");

    // BN_LOG("integrityTag", data_ptr->integrityTag);
    BN_LOG("integrityVersion", data_ptr->integrityVersion);

    if (data_ptr->integrityTag != getIntegrityTag()) {
        return false;
    }
    if (data_ptr->integrityVersion != INTEGRITY_VERSION) {
        return false;
    }

    return true;
}

ks::saves::SaveSettingsData ks::saves::getSettings() {
    BN_LOG("Get Settings");
    auto* save_data = static_cast<SaveFileData *>(bn::memory::ewram_alloc(sizeof(SaveFileData)));
    load(save_data);
    SaveSettingsData settings = save_data->settings;
    bn::memory::ewram_free(save_data);

    log_settings(settings);
    return settings;
}

void ks::saves::saveSettings(const SaveSettingsData settings) {
    // bn::core::update();
    BN_LOG("Save Settings");
    BN_LOG("Free EWRAM on save: ", bn::memory::available_alloc_ewram());
    BN_LOG("Size of SFD: ", sizeof(SaveFileData));
    auto* save_data = static_cast<SaveFileData *>(bn::memory::ewram_alloc(sizeof(SaveFileData)));
    BN_LOG("Free EWRAM on save after alloc: ", bn::memory::available_alloc_ewram());
    load(save_data);
    save_data->settings = settings;
    save(save_data);
    bn::memory::ewram_free(save_data);
}

void ks::saves::log_progress(SaveSlotProgressData& progress) {
    BN_LOG("Progress:");
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
