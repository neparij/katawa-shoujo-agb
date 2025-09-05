#ifndef RUN_TESTS_CPP_H
#define RUN_TESTS_CPP_H

#include "asserts.h"
#include "tests.h"
#include "bn_core.h"

#include "suites/example_tests.h"


namespace ks::tests {
    inline void run() {
        bn::core::init();
        bn::assert::set_callback(fail);
        BN_LOG("Running tests...");

        example_tests();
    }
}


#endif
