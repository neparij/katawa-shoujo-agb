#ifndef EXAMPLE_TESTS_H
#define EXAMPLE_TESTS_H

#include "testing/suite.h"

class example_tests : public test_suite {
public:
    example_tests() : test_suite("example suite") {
    }

    void run() {
        test_case("check booleans", [this] {
            KS_ASSERT(true == true);
            KS_ASSERT(false == false);
        });

        test_case("check integer", [this] {
            KS_ASSERT(this->foo == 42, "foo should be 42");
        });
    }

private:
    int foo = 42;
};


#endif //EXAMPLE_TESTS_H
