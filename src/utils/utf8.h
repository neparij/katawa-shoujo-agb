#ifndef KS_UTF8_H
#define KS_UTF8_H

#include "bn_log.h"
#include "bn_string_view.h"

namespace ks {
    class utf8 {
    public:
        explicit utf8(const bn::string_view &from) : _view(from) {

        }

        static unsigned char get_char_size(const unsigned char c) {
            if ((c & 0x80) == 0) {
                return 1;
            }
            if ((c & 0xE0) == 0xC0) {
                return 2;
            }
            if ((c & 0xF0) == 0xE0) {
                return 3;
            }
            if ((c & 0xF8) == 0xF0) {
                return 4;
            }
            // BN_ERROR("Unknown char size");
            return 1;
        }

        [[nodiscard]] bn::string_view substr(const unsigned int pos, const unsigned int count) const {
            int i = 0;
            for (int cursor = 0; cursor < _view.size();) {
                if (i == pos) {
                    const int start = cursor;
                    for (unsigned int j = 0; j < count && cursor < _view.size();) {
                        const int char_length = get_char_size(static_cast<unsigned char>(_view.at(cursor)));
                        cursor += char_length;
                        j++;
                    }
                    return {_view.data() + start, cursor - start};
                }
                const int char_length = get_char_size(static_cast<unsigned char>(_view.at(cursor)));
                cursor += char_length;
                i++;
            }
            return {};
        }

        [[nodiscard]] int length() const {
            for (int cursor = 0, count = 0; cursor < _view.size();) {
                const int char_length = get_char_size(static_cast<unsigned char>(_view.at(cursor)));
                cursor += char_length;
                count++;
                if (cursor == _view.size()) {
                    return count;
                }
            }
            return 0;
        }

        [[nodiscard]] bn::string_view& view() {
            return _view;
        }

    private:
        bn::string_view _view;
    };
}

#endif //KS_UTF8_H
