#include "save_migrations.h"

#include "bn_log.h"
#include "definitions.h"

void ks::saves::migrate_v1_to_v2(SaveFileDataV1 *v1, SaveFileData *v2) {
    BN_ASSERT(v1 != nullptr, "Unable to migrate. V1 Data pointer is null.");
    BN_ASSERT(v2 != nullptr, "Unable to migrate. V2 Data pointer is null.");
    BN_LOG("Migrating save data from v1 to v2...");

    v2->settings.language = v1->settings.language;
    v2->settings.hdisabled = v1->settings.hdisabled;
    v2->settings.music_volume = 0xCC;
    v2->settings.sfx_volume = 0xCC;
    v2->settings.text_speed = 0xCC;
    v2->settings.brightness = 0x00;
    v2->settings.high_contrast = v1->settings.high_contrast;
    v2->settings.disable_disturbing_content = v1->settings.disable_disturbing_content;
    v2->settings.adult_warning_shown = v1->settings.adult_warning_shown;

    BN_LOG("Migrated settings from v1 to v2");

    v2->autosave = v1->autosave;
    BN_LOG("Migrated autosave from v1 to v2");

    for (int i = 0; i < 400; i++) {
        v2->slot[i] = v1->slot[i];
    }
    BN_LOG("Migrated save slots from v1 to v2");

    v2->integrity_begin.version = INTEGRITY_VERSION_V2;
    v2->integrity_end.version = INTEGRITY_VERSION_V2;
    BN_LOG("Migration to v2 complete.");
}
