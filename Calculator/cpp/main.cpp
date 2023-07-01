#include <iostream>
#include <cmath>
#include "utilityFunctions.h"
#include "validateUserInput.h"
int main()
{
    int operationChoice;
    while (true)
    {
        try
        {
            displayMenu();
            int operationChoice;
            std::cin >> operationChoice;
            if (validateUserInput(operationChoice) == true)
            {
                if (operationChoice >= 1 && operationChoice <= 4)
                {
                    performArithmeticOperation(operationChoice);
                }
                else if (operationChoice >= 5 && operationChoice <= 8)
                {
                    performPowerOperation(operationChoice);
                }
                else if (operationChoice >= 9 && operationChoice <= 12)
                {
                    performBitwiseOperator(operationChoice);
                }
                else
                {
                    std::cout << "Invalid Operation " << std::endl;
                }
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        char response;
        std::cout << "\nDo you want to continue? (y/n) ";
        std::cin >> response;
        try{
            if (validateUserInput(response))
        {
            if (response == 'y' || response == 'Y')
            {
                continue;
            }
            else
            {
                if (response == 'n' || response == 'N')
                {
                    break;
                }
                else
                {
                    std::cout << "Invalid response" << std::endl;
                }
            }
        }

        }
        catch (const std::invalid_argument &e)
        {
            //std::cerr << "Error: " << e.what() << std::endl;
            std::cout << "Error: " << e.what() << std::endl;
        }
        
    }

    return 0;
}