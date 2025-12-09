#ifndef UTF8_TESTS_H
#define UTF8_TESTS_H

#include "suite.h"

#include "../src/utils/utf8.h"

class utf8_tests : public testing::test_suite {
public:
    utf8_tests() : test_suite("utf8") {
    }

    void run() {
        test_case("get_char_size", [this] {
            // Check UTF-8 character size detection
            const auto s1 = reinterpret_cast<const unsigned char *>("A");
            TEST_ASSERT(ks::utf8::get_char_size(s1[0]) == 1, "A");

            const auto s2 = reinterpret_cast<const unsigned char *>("ñ"); // UTF-8: 0xC3 0xB1
            TEST_ASSERT(ks::utf8::get_char_size(s2[0]) == 2, "ñ");

            const auto s3 = reinterpret_cast<const unsigned char *>("あ"); // UTF-8: 0xE3 0x81 0x82
            TEST_ASSERT(ks::utf8::get_char_size(s3[0]) == 3, "あ");

            const auto s4 = reinterpret_cast<const unsigned char *>("𐍈"); // UTF-8: 0xF0 0x90 0x8D 0x88
            TEST_ASSERT(ks::utf8::get_char_size(s4[0]) == 4, "𐍈");
        });
    }
};

#endif //UTF8_TESTS_H
