#ifndef RUN_TESTS_CPP_H
#define RUN_TESTS_CPP_H

#include "allure.h"
#include "bn_core.h"

#include "suites/example_tests.h"
#include "suites/text_parser_tests.h"
#include "suites/utf8_tests.h"

namespace ks::tests {
    inline void run() {
        bn::core::init();
        testing::allure::init();
        example_tests().run();
        utf8_tests().run();
        text_parser_tests().run();
        testing::allure::close();
    }
}


#endif
