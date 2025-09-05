#ifndef ASSERTS_H
#define ASSERTS_H

#include "bn_assert.h"
#include "bn_log.h"

#define KS_ASSERT(condition, ...) \
    do \
    { \
        ks::tests::set_message(__VA_ARGS__); \
        BN_ASSERT(condition, __VA_ARGS__); \
        ks::tests::pass(); \
    } while(false)



namespace ks::tests {
    static char message_buffer[BN_CFG_ASSERT_BUFFER_SIZE] = "";

    template<typename... Args>
    void set_message(const bn::string_view &message, const Args &... args) {
        message_buffer[0] = '\0';
        bn::istring_base istring(message_buffer);
        bn::ostringstream string_stream(istring);
        string_stream.append(message);
        string_stream.append_args(args...);
    }

    inline void pass() {
        if (message_buffer[0] != '\0') {
            BN_LOG("Test passed: ", message_buffer);
        }
    }

    inline void fail() {
        if (message_buffer[0] != '\0') {
            BN_LOG('\a', "Test failed: ", message_buffer);
        } else {
            BN_ERROR("Failing test without message");
        }
    }
}

#endif //ASSERTS_H
