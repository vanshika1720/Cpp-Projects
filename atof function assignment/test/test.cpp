#include <iostream>
#include <sstream>
#include <gtest/gtest.h>
#include "parseString.h"
#include <string>
#include <stdexcept>
#include "atofFunc.h"

TEST(atofFuncTest, ValidInput)
{
    std::string str = "123.45";
    testing::internal::CaptureStdout();
    atofFunc(str);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "123.45\n");
}

TEST(atofFuncTest, NegativeInput)
{
    std::string str = "-123.45";
    testing::internal::CaptureStdout();
    atofFunc(str);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "-123.45\n");
}

TEST(atofFuncTest, ScientificNotationInput)
{
    std::string str = "1.23e-4";
    testing::internal::CaptureStdout();
    atofFunc(str);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
}

TEST(atofFuncTest, InvalidInput)
{
    std::string str = "abc\n";
    EXPECT_THROW(atofFunc(str), std::invalid_argument);
}

TEST(ParsingStringTest, PositiveNumber)
{
    std::string input = "123";
    int index = 0;
    int sign = 1;
    double expected = 123.0;
    EXPECT_DOUBLE_EQ(expected, parsingString(input, index, sign));
}

TEST(ParsingStringTest, NegativeNumber)
{
    std::string input = "-123";
    int index = 0;
    int sign = -1;
    double expected = -123.0;
    EXPECT_DOUBLE_EQ(expected, parsingString(input, index, sign));
}

TEST(ParsingStringTest, DecimalNumber)
{
    std::string input = "123.456";
    int index = 0;
    int sign = 1;
    double expected = 123.456;
    EXPECT_DOUBLE_EQ(expected, parsingString(input, index, sign));
}

TEST(ParsingStringTest, MultipleDecimals)
{
    std::string input = "12.3.4";
    int index = 0;
    int sign = 1;
    EXPECT_THROW(parsingString(input, index, sign), std::invalid_argument);
}

TEST(ParsingStringTest, NonNumericInput)
{
    std::string input = "123a";
    int index = 0;
    int sign = 1;
    EXPECT_THROW(parsingString(input, index, sign), std::invalid_argument);
}

TEST(ParsingStringTest, EmptyString)
{
    std::string input = "";
    int index = 0;
    int sign = 1;
    double expected = 0.0;
    EXPECT_DOUBLE_EQ(expected, parsingString(input, index, sign));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
