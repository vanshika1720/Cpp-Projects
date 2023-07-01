#include <iostream>
#include "userInput.h"
#include "calculator.h"

void performArithmeticOperation(int operationChoice)
{

    Input<double> number1, number2;
    double num1 = number1.getUserInput();
    double num2 = number2.getUserInput();
    Calculator<double> arithmeticCalculator(num1, num2);
    if (operationChoice == 1)
    {
        std::cout << "Output : " << arithmeticCalculator.addition(num1,num2) << std::endl;
    }
    else if (operationChoice == 2)
    {
        std::cout << "Output : " << arithmeticCalculator.subtraction(num1, num2) << std::endl;
    }
    else if (operationChoice == 3)
    {
        std::cout << "Output : " << arithmeticCalculator.multiplication(num1, num2) << std::endl;
    }
    else
    {
        std::cout << "Output : " << arithmeticCalculator.division(num1, num2) << std::endl;
    }
}

void performPowerOperation(int operationChoice)
{
    Input<double> number1;
    double num1 = number1.getUserInput();
    Calculator<double> powerCalculator(num1);
    if (operationChoice == 5)
    {
        std::cout << "Output : " << powerCalculator.square(num1) << std::endl;
    }
    else if (operationChoice == 6)
    {
        std::cout << "Output : " << powerCalculator.squareRoot(num1) << std::endl;
    }
    else if (operationChoice == 7)
    {
        std::cout << "Output : " << powerCalculator.cube(num1) << std::endl;
    }
    else
    {
        std::cout << "Output : " << powerCalculator.cubeRoot(num1) << std::endl;
    }
}

void performBitwiseOperator(int operationChoice)
{
    if (operationChoice >= 9 && operationChoice <= 11)
    {
        Input<int> number1, number2;
        int num1 = number1.getUserInput();
        int num2 = number2.getUserInput();
        Calculator<int> bitwiseCalculator(num1, num2);
        if (operationChoice == 9)
        {
            std::cout << "Output : " << bitwiseCalculator.BitwiseOR(num1, num2) << std::endl;
        }
        else if (operationChoice == 10)
        {
            std::cout << "Output : " << bitwiseCalculator.BitwiseAND(num1, num2) << std::endl;
        }
        else
        {
            std::cout << "Output : " << bitwiseCalculator.BitwiseXOR(num1, num2) << std::endl;
        }
    }
    else
    {
        Input<int> number1;
        int num1 = number1.getUserInput();
        Calculator<int> bitwiseCalculator(num1);
        std::cout << "Output : " << bitwiseCalculator.BitwiseNOT(num1) << std::endl;
    }
}

void displayMenu()
{
    std::cout << "Given are the listed operation you can perform " << std::endl;
    std::cout << "1:addition \n2:subtraction \n3:multiplication \n4:division "
                 "\n5:square \n6:square root \n7:cube \n8:cube root \n9:bitwise "
                 "OR \n10:bitwise AND \n11:bitwise XOR \n12:bitwise NOT\nEnter operation you want to perform\n";
}