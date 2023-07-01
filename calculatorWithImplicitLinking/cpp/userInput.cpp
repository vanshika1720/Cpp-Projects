#include <iostream>
#include <limits>
#include "userInput.h"

double getUserInput()
{
    int numAttempts = 0;
    const int maxAttempts = 3;
    while (numAttempts < maxAttempts)
    {
        try
        {
            double userInput;
            std::cin >> userInput;
            if (std::cin.fail() || std::cin.peek() != '\n')
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::invalid_argument("Invalid input, Enter a Valid Input");
            }
            return userInput;
        }

        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            ++numAttempts;
            if (numAttempts == maxAttempts)
            {
                std::cerr << "Maximum number of attempts reached." << std::endl;
            }
        }
    }
    return 0.0;
}

void getSingleUserInput(double &number1)
{
    std::cout << "Enter the number: ";
    number1 = getUserInput();
}

void getTwoUserInput(double &number1, double &number2)
{
    std::cout << "Enter the first number: ";
    number1 = getUserInput();
    std::cout << "Enter the second number: ";
    number2 = getUserInput();
}