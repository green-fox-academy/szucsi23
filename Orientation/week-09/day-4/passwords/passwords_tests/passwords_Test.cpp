#include <gtest/gtest.h>
#include "gtest/gtest.h"

extern "C" {
#include "passwords.h"
}

TEST(Password_tests, Test_for_error)
{
    EXPECT_EQ(get_pwd_strength("a"), ERROR);
}

TEST(Password_tests, Test_for_weak)
{
    EXPECT_EQ(get_pwd_strength("almafa"), WEAK);
}

TEST(Password_tests, Test_for_moderate)
{
    EXPECT_EQ(get_pwd_strength("almafa23"), MODERATE);
}

TEST(Password_tests, Test_for_strong)
{
    EXPECT_EQ(get_pwd_strength("almafa23....23almafa"), STRONG);
}

TEST(Password_tests, Test_for_error2)
{
    EXPECT_EQ(get_pwd_strength("almafaalmafaalmafaalmafaalmafaalmafaalmafaalmafaalmafaalmafaalmafaalmafaalmafa"), ERROR);
}


