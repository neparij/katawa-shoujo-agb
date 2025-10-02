#ifndef SAVE_MIGRATIONS_H
#define SAVE_MIGRATIONS_H

#define INTEGRITY_VERSION_V1 2121210001
#define INTEGRITY_VERSION_V2 2121210002

#include "bn_memory.h"
#include "definitions.h"
#include "save_file.h"

namespace ks {
    namespace saves {
        struct alignas(4) SaveSettingsDataV1 {
            language_t language;
            bool hdisabled;
            bool disable_disturbing_content;
            bool high_contrast;
            unsigned char text_speed;
            bool adult_warning_shown;
        };

        struct alignas(4) SaveFileDataV1 {
            SaveIntegrityData integrity_begin;
            SaveSettingsDataV1 settings;
            SaveSlotProgressData autosave;
            SaveSlotProgressData slot[TOTAL_SAVE_SLOTS];
            SaveIntegrityData integrity_end;
        };

        void migrate_from_v1(const SaveFileDataV1 *v1, SaveFileData *latest);

        inline void migrate(SaveFileData *save_data) {
            if (save_data->integrity_begin.version == INTEGRITY_VERSION_V1) {
                auto *v1 = static_cast<SaveFileDataV1 *>(bn::memory::ewram_alloc(sizeof(SaveFileDataV1)));
                load<SaveFileDataV1>(v1);
                migrate_from_v1(v1, save_data);
                bn::memory::ewram_free(v1);
            }

            save_data->integrity_end.tag = save_data->integrity_begin.tag;
            save_data->integrity_end.version = save_data->integrity_begin.version;
        }
    }
}

#endif //SAVE_MIGRATIONS_H
