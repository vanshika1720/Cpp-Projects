#include <iostream>
#include "userInput.h"
#include "libCalc.h"

int main()
{
    int op;
    while (true)
    {
        try
        {
            std::cout << "Given are the listed operation you can perform " << std::endl;
            std::cout << "1:addition \n2:subtraction \n3:multiplication \n4:division ";
            "\nEnter op you want to perform\n";
            op = getUserInput();
            double number1, number2;
            switch (op)
            {
            case 1:
                getTwoUserInput(number1, number2);
                std::cout << performingAddition(number1, number2) << std::endl;
                break;
            case 2:
                getTwoUserInput(number1, number2);
                std::cout << performingSubtraction(number1, number2) << std::endl;
                break;
            case 3:
                getTwoUserInput(number1, number2);
                std::cout << performingMultiplication(number1, number2) << std::endl;
                break;
            case 4:
                getTwoUserInput(number1, number2);
                std::cout << performingDivision(number1, number2) << std::endl;

                break;
            default:
                std::cout << "Invalid Input, Enter a Valid Input" << std::endl;
                break;
            }
        }
        catch (const char *s)
        {
            std::cerr << "Error :" << s;
        }
        char response;
        std::cout << "\nDo you want to continue? (y/n) ";
        std::cin >> response;
        if (response == 'y' || response == 'Y')
        {
            continue;
        }
        else
        {
            break;
        }
    }
    return 0;
}