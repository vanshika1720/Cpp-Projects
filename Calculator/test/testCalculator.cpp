#include <gtest/gtest.h>
#include "userInput.h"
#include "calculator.h"
TEST(CalculatorTest, AdditionTest) {
    Calculator<double> calculator(1, 2);
    EXPECT_EQ(calculator.addition(), 3);

    Calculator<double> calculator2(-1, 2.5);
    EXPECT_EQ(calculator2.addition(), 1.5);
}

TEST(CalculatorTest, SubtractionTest) {
    Calculator<double> calculator(2, 1);
    EXPECT_EQ(calculator.subtraction(), 1);

    Calculator<double> calculator2(-1, 2.5);
    EXPECT_EQ(calculator2.subtraction(), -3.5);
}

TEST(CalculatorTest, MultiplicationTest) {
    Calculator<double> calculator(2, 3);
    EXPECT_EQ(calculator.multiplication(), 6);

    Calculator<double> calculator2(2.5, 2);
    EXPECT_EQ(calculator2.multiplication(), 5);
}

TEST(CalculatorTest, DivisionTest) {
    Calculator<double> calculator(4, 2);
    EXPECT_EQ(calculator.division(), 2);

    Calculator<double> calculator2(1.5, 2);
    EXPECT_NEAR(calculator2.division(), 0.75, 0.00001);

    Calculator<double> calculator3(3, 0);
    EXPECT_THROW(calculator3.division(), std::invalid_argument);
}

TEST(CalculatorTest, SquareTest) {
    Calculator<double> calculator(2);
    EXPECT_EQ(calculator.square(), 4);

    Calculator<double> calculator2(2.5);
    EXPECT_EQ(calculator2.square(), 6.25);
}

TEST(CalculatorTest, SquareRootTest) {
    Calculator<double> calculator(4);
    EXPECT_EQ(calculator.squareRoot(), 2);

    Calculator<double> calculator2(6.25);
    EXPECT_NEAR(calculator2.squareRoot(), 2.5, 0.00001);

    Calculator<double> calculator3(-4);
    EXPECT_THROW(calculator3.squareRoot(), std::invalid_argument);
}

TEST(CalculatorTest, CubeTest) {
    Calculator<double> calculator(2);
    EXPECT_EQ(calculator.cube(), 8);

    Calculator<double> calculator2(2.5);
    EXPECT_EQ(calculator2.cube(), 15.625);

    Calculator<double> calculator3(-2);
    EXPECT_EQ(calculator3.cube(), -8);
}

TEST(CalculatorTest, CubeRootTest) {
    Calculator<double> calculator(8);
    EXPECT_EQ(calculator.cubeRoot(), 2);

    Calculator<double> calculator2(15.625);
    EXPECT_NEAR(calculator2.cubeRoot(), 2.5, 0.00001);

    Calculator<double> calculator3(-8);
    EXPECT_EQ(calculator3.cubeRoot(), -2);
}

