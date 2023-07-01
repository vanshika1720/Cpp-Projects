#include <iostream>
#include <cmath>
#include "calculator.h"

template class Calculator<double>;
template class Calculator<int>;

template <class Type1>
Type1 Calculator<Type1>::addition(Type1 number1,Type1 number2) { return number1 + number2; }

template <class Type1>
Type1 Calculator<Type1>::subtraction(Type1 number1,Type1 number2) { return number1 - number2; }

template <class Type1>
Type1 Calculator<Type1>::multiplication(Type1 number1,Type1 number2) { return number1 * number2; }

template <class Type1>
Type1 Calculator<Type1>::division(Type1 number1,Type1 number2)
{
    if (number2 == 0)
    {
        throw std::invalid_argument(" Denominator sholud not be zero , Enter a Valid Input\n");
    }
    return number1 / number2;
}

template <class Type1>
Type1 Calculator<Type1>::square(Type1 number1) { return number1 * number1; }

template <class Type1>
Type1 Calculator<Type1>::squareRoot(Type1 number1) { return sqrt(number1); }

template <class Type1>
Type1 Calculator<Type1>::cube(Type1 number1) { return pow(number1, 3); }

template <class Type1>
Type1 Calculator<Type1>::cubeRoot(Type1 number1) { return cbrt(number1); }

template <class Type1>
Type1 Calculator<Type1>::BitwiseOR(Type1 number1,Type1 number2) { return int(number1) | int(number2); }

template <class Type1>
Type1 Calculator<Type1>::BitwiseAND(Type1 number1,Type1 number2) {return int(number1) & int(number2); }

template <class Type1>
Type1 Calculator<Type1>::BitwiseNOT(Type1 number1) { return ~int(number2); }

template <class Type1>
Type1 Calculator<Type1>::BitwiseXOR(Type1 number1,Type1 number2) { return int(number1) ^ int(number2); }
