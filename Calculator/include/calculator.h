#ifndef CALCULATOR_H
#define CALCULATOR_H

template <class Type1>
class Calculator
{
    Type1 number1, number2;
public:
    Calculator(Type1 a) : number1(a) {}
    Calculator(Type1 a, Type1 b) : number1(a), number2(b) {}
    Type1 addition(Type1 number1,Type1 number2);
    Type1 subtraction(Type1 number1,Type1 number2);
    Type1 multiplication(Type1 number1,Type1 number2);
    Type1 division(Type1 number1,Type1 number2);
    Type1 square(Type1 number1);
    Type1 squareRoot(Type1 number1);
    Type1 cube(Type1 number1);
    Type1 cubeRoot(Type1 number1);
    Type1 BitwiseOR(Type1 number1,Type1 number2);
    Type1 BitwiseAND(Type1 number1,Type1 number2);
    Type1 BitwiseNOT(Type1 number1);
    Type1 BitwiseXOR(Type1 number1,Type1 number2);
};
#endif
