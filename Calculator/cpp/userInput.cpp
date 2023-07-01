#include <iostream>
#include <cmath>
#include "userInput.h"
#include "validateUserInput.h"

template class Input<double>;
template class Input<int>;

template <class Type>
Type Input<Type>::getUserInput()
{
    std::cout << "Enter number : ";
    std::cin >> number1;
    if (validateUserInput(number1) == false)
    {
        throw std::invalid_argument("Invalid input");
    }
    return number1;
}
