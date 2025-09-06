#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include "bn_string_view.h"
#include "testing.h"

class test_suite {
public:
    explicit test_suite(const bn::string_view& name) : _name(ks::tests::set_suite(name)) {
    }

    ~test_suite() {
        ks::tests::unset_suite();
    }

    void run();

    template<typename Func>
    static void test_case(const bn::string_view& name, Func&& func) {
        ks::tests::set_case(name);
        func();
        ks::tests::finalize_testcase();
        ks::tests::unset_case();
    }

private:
    bn::string_view _name;
};


#endif //TEST_SUITE_H
