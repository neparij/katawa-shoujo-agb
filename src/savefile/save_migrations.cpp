#include "save_migrations.h"

#include "bn_log.h"
#include "definitions.h"

void ks::saves::migrate_from_v1(const SaveFileDataV1 *v1, SaveFileData *latest) {
    BN_ASSERT(v1 != nullptr, "Unable to migrate. V1 Data pointer is null.");
    BN_ASSERT(latest != nullptr, "Unable to migrate. LATEST Data pointer is null.");
    BN_LOG("Migrating save data from v1...");

    latest->settings.language = v1->settings.language;
    latest->settings.hdisabled = v1->settings.hdisabled;
    latest->settings.music_volume = 0xCC;
    latest->settings.sfx_volume = 0xCC;
    latest->settings.text_speed = 0xCC;
    latest->settings.brightness = 0x00;
    latest->settings.high_contrast = v1->settings.high_contrast;
    latest->settings.disable_disturbing_content = v1->settings.disable_disturbing_content;
    BN_LOG("Migrated settings from v1");

    latest->states.adult_warning_shown = v1->settings.adult_warning_shown;
    for (int i = 0; i < 64; i++) {
        latest->states.seen_displayables[i] = 0;
    }
    BN_LOG("Migrated states from v1");

    latest->autosave = v1->autosave;
    BN_LOG("Migrated autosave from v1");

    for (int i = 0; i < 400; i++) {
        latest->slot[i] = v1->slot[i];
    }
    BN_LOG("Migrated save slots from v1");

    latest->integrity_begin.version = INTEGRITY_VERSION_V2;
    latest->integrity_end.version = INTEGRITY_VERSION_V2;
    BN_LOG("Migration complete.");
}
