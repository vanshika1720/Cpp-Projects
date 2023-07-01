#include "inputValidator.h"
int InputValidator::getIntInput(const std::string &prompt)
{
    int value;
    std::cout << prompt;
    while (!(std::cin >> value) || std::cin.peek() != '\n')
    {
        std::cin.clear();                                                   
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "Invalid input. Please enter an integer: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    return value;
}
