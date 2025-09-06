#ifndef TESTING_H
#define TESTING_H

#include "bn_assert.h"
#include "bn_log.h"
#include "bn_string_view.h"

#define KS_TEST_LOGGING 0

#ifdef KS_TEST_LOGGING
    #define KS_ASSERT(condition, ...) \
    do { \
        ks::tests::log(#condition __VA_OPT__(, ) __VA_ARGS__); \
        if(! (condition)) [[unlikely]] { \
            ks::tests::test_status = 1; \
            return; \
        } \
    } while(false)
#else
    #define KS_ASSERT(condition, ...) \
    do { \
        if(! (condition)) [[unlikely]] { \
            ks::tests::test_status = 1; \
            return; \
        } \
    } while(false)
#endif

namespace ks::tests {
    static char message_buffer[BN_CFG_ASSERT_BUFFER_SIZE] = "";
    static int test_status = 0; // 0: OK, 1: Failed
    static int passed_tests = 0;
    static int failed_tests = 0;

    static bn::string_view current_suite = "";
    static bn::string_view current_case = "";

    inline bn::string_view& set_suite(const bn::string_view& name) {
        current_suite = name;
        BN_LOG("Running suite '", current_suite, "'...");
        return current_suite;
    }

    inline bn::string_view& set_case(const bn::string_view& name) {
        test_status = 0;
        current_case = name;
        BN_LOG(" Running case '", current_case, "'...");
        return current_case;
    }

    inline void unset_suite() {
        current_suite = "";
    }

    inline void unset_case() {
        current_case = "";
    }

    template<typename... Args>
    void log(const char* condition_msg, const Args &... args) {
        message_buffer[0] = '\0';
        bn::istring_base istring(message_buffer);
        bn::ostringstream string_stream(istring);
        string_stream.append("  :: ");
        string_stream.append(condition_msg);
        if constexpr (KS_TEST_LOGGING > 0) {
            if (sizeof...(args) != 0) {
                string_stream.append(" :: ");
                string_stream.append_args(args...);
            }
        }
        BN_LOG(message_buffer);
    }

    inline void pass() {
        passed_tests++;
        BN_LOG("✅ Test passed: ", current_suite, " - ", current_case);
    }

    inline void fail() {
        failed_tests++;
        BN_LOG('\a', "❌ Test failed: ", current_suite, " - ", current_case);
    }

    inline void finalize_testcase() {
        if (test_status == 0) {
            pass();
        } else {
            fail();
        }
    }
}

#endif //TESTING_H
