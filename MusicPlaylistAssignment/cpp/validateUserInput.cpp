#include "validateUserInput.h"
template bool validateUserInput<int>(int);
template bool validateUserInput<std::string>(std::string);
template <class T>
bool validateUserInput(T input)
{
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Invalid input");
    }
    return true;
}