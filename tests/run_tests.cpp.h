#ifndef RUN_TESTS_CPP_H
#define RUN_TESTS_CPP_H

#include "testing/testing.h"
#include "bn_core.h"

#include "suites/example_tests.h"
#include "suites/text_render_tests.h"

namespace ks::tests {
    inline void run() {
        bn::core::init();
        bn::assert::set_callback(fail);

        example_tests().run();
        text_render_tests().run();
    }
}


#endif
