#include "gtest/gtest.h"

extern "C" {
#include "testing.h"
}

TEST(testing, testing)
{
    EXPECT_EQ(getApple(), "apple");
}

