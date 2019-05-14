//
// Created by hun46 on 2019. 05. 02..
//

#include <gtest/gtest.h>
#include "Decrypter.h"


class DecrypterTest : public ::testing::Test {
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {}

    Decrypter _dec;
};


TEST_F(DecrypterTest, empty_file)
{
    EXPECT_ANY_THROW(_dec.fileToStream("empty.txt").str());
}

TEST_F(DecrypterTest, empty_string)
{
    EXPECT_ANY_THROW(_dec.fileToStream("").str());
}

TEST_F(DecrypterTest, non_existing_file)
{
    EXPECT_ANY_THROW(_dec.fileToStream("valami.txt").str());
}