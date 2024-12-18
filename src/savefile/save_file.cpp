#include "save_file.h"

BN_DATA_EWRAM ks::saves::SaveFileData ks::saves::data;

void ks::saves::load() {
    bn::sram::read(data);
}

void ks::saves::save() {
    bn::sram::write(data);
}
