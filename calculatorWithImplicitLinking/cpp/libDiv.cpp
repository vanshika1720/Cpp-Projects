#include <iostream>
#include "userInput.h"
double performingDivision(double number1, double number2)
{
    if (number2 == 0)
    {
        throw std::invalid_argument(" Denominator sholud not be zero , Enter a Valid Input\n");
    }
    std::cout << "Output : ";
    return number1 / number2;
}