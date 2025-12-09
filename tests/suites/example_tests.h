#ifndef EXAMPLE_TESTS_H
#define EXAMPLE_TESTS_H

#include "suite.h"

class example_tests : public testing::test_suite {
public:
    example_tests() : test_suite("example suite") {
    }

    void run() {
        test_case("check booleans", [this] {
            TEST_ASSERT(true == true);
            TEST_ASSERT(false == false);
        });

        test_case("check integer", [this] {
            TEST_ASSERT(this->foo == 42, "foo should be 42");
        });
    }

private:
    int foo = 42;
};


#endif //EXAMPLE_TESTS_H
