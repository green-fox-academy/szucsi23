//
// Created by hun46 on 2019. 04. 25..
//

#include "gtest/gtest.h"
#include "apple.h"

TEST(apple_check, test_apple)
{
    EXPECT_EQ(getApple(),"alma");
}
//----------------------------------------------------------------------------------------------------------------------
TEST(sum_check, test_sum_base)
{
    std::vector<int> testingInts = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ASSERT_EQ(sum(testingInts), 55);
}

TEST(sum_check, test_sum_empty)
{
    std::vector<int> testingInts = {};
    ASSERT_EQ(sum(testingInts), 0);
}

TEST(sum_check, test_sum_negative)
{
    std::vector<int> testingInts = {0, -1, -2, -3, -4, -5};
    ASSERT_EQ(sum(testingInts), -15);
}
//----------------------------------------------------------------------------------------------------------------------
TEST(palindrom_check, test_string_empty)
{
    std::string teststring = "";
    ASSERT_EQ(isPalindrom(teststring), true);
}

TEST(palindrom_check, test_string_numbers)
{
    std::string teststring = "12345";
    ASSERT_EQ(isPalindrom(teststring), false);

    teststring = "123454321";
    ASSERT_EQ(isPalindrom(teststring), true);
}

TEST(palindrom_check, test_string_has_space)
{
    std::string teststring = "pa li il ap";
    ASSERT_EQ(isPalindrom(teststring), true);
}