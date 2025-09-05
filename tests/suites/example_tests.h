#ifndef EXAMPLE_TESTS_H
#define EXAMPLE_TESTS_H

#include "asserts.h"
#include "tests.h"

class example_tests : public tests
{

public:
    example_tests() : tests("example")
    {
        KS_ASSERT(true == true, "true == true");
        KS_ASSERT(false == false, "false == false");
    }
};
#endif //EXAMPLE_TESTS_H
