//
// Created by hun46 on 2019. 04. 25..
//

#include "gtest/gtest.h"
#include "apple.h"


TEST(apple_check, test_apple)
{
    EXPECT_EQ(getApple(), "alma");
}
