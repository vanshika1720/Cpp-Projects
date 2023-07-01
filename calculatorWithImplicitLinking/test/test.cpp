#include <iostream>
#include <sstream>
#include <gtest/gtest.h>
#include "userInput.h"
#include "libCalc.h"

TEST(AdditionTest, PositiveNumbers)
{
    double num1 = 2.0;
    double num2 = 3.0;
    double result = performingAddition(num1, num2);
    EXPECT_EQ(result, 5.0);
}

TEST(SubtractionTest, PositiveNumbers)
{
    double num1 = 5.0;
    double num2 = 3.0;
    double result = performingSubtraction(num1, num2);
    EXPECT_EQ(result, 2.0);
}

TEST(SubtractionTest, NegativeNumbers)
{
    double num1 = -5.0;
    double num2 = -3.0;
    double result = performingSubtraction(num1, num2);
    EXPECT_EQ(result, -2.0);
}

TEST(DivisionTest, PositiveNumbers)
{
    double num1 = 10.0;
    double num2 = 5.0;
    double result = performingDivision(num1, num2);
    EXPECT_EQ(result, 2.0);
}

TEST(DivisionTest, DivideByZero)
{
    double num1 = 10.0;
    double num2 = 0.0;
    EXPECT_THROW(performingDivision(3,0),std::invalid_argument);

}

TEST(MultiplicationTest, PositiveNumbers)
{
    double num1 = 2.0;
    double num2 = 3.0;
    double result = performingMultiplication(num1, num2);
    EXPECT_EQ(result, 6.0);
}

TEST(UserInputTest, PositiveNumbers)
{
    std::istringstream input("4.2\n");
    std::cin.rdbuf(input.rdbuf());
    double result;
    getSingleUserInput(result);
    EXPECT_EQ(result, 4.2);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}