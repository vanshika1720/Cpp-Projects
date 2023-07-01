#include <iostream>
#include <sstream>
#include <gtest/gtest.h>
#include "userInput.h"
#include "Calc.h"
#include <dlfcn.h>

TEST(CalculatorTest, LoadLibrary)
{
    void *libHandle = dlopen("./libcal.so", RTLD_LAZY);
    ASSERT_NE(libHandle, nullptr);
    dlclose(libHandle);
}

TEST(CalculatorTest, Addition)
{
    EXPECT_EQ(performingAddition(1, 2), 3);
    EXPECT_EQ(performingAddition(-1, 2), 1);
}

TEST(CalculatorTest, Subtraction)
{
    EXPECT_EQ(performingSubtraction(2, 1), 1);
    EXPECT_EQ(performingSubtraction(-1, 2), -3);
    EXPECT_EQ(performingSubtraction(2.5, 1.5), 1);
}

TEST(CalculatorTest, Multiplication)
{
    EXPECT_EQ(performingMultiplication(2, 3), 6);
    EXPECT_EQ(performingMultiplication(-1, 2), -2);
    EXPECT_EQ(performingMultiplication(2.5, 2), 5);
}

TEST(CalculatorTest, Division)
{
    EXPECT_EQ(performingDivision(4, 2), 2);
    EXPECT_THROW(performingDivision(3, 0), std::invalid_argument);
    EXPECT_EQ(performingDivision(-2, 2), -1);
    EXPECT_NEAR(performingDivision(1.5, 2), 0.75, 0.00001);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}