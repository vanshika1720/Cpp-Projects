#include <iostream>
#include <dlfcn.h>
#include "userInput.h"
#include "Calc.h"

int main()
{
    typedef double (*calculatorFunc)(double, double);
    void *libHandle = dlopen("./libCal.so", RTLD_LAZY);
    if (!libHandle)
    {
        std::cerr << "Error loading library: " << dlerror() << std::endl;
        return 1;
    }
    calculatorFunc addFunc = (calculatorFunc)dlsym(libHandle, "performingAddition");
    if (!addFunc)
    {
        std::cerr << "Error getting add function: " << dlerror() << std::endl;
        dlclose(libHandle);
        return 1;
    }
    calculatorFunc subFunc = (calculatorFunc)dlsym(libHandle, "performingSubtraction");
    if (!subFunc)
    {
        std::cerr << "Error getting add function: " << dlerror() << std::endl;
        dlclose(libHandle);
        return 1;
    }
    calculatorFunc mulFunc = (calculatorFunc)dlsym(libHandle, "performingMultiplication");
    if (!mulFunc)
    {
        std::cerr << "Error getting add function: " << dlerror() << std::endl;
        dlclose(libHandle);
        return 1;
    }
    calculatorFunc divFunc = (calculatorFunc)dlsym(libHandle, "performingDivision");
    if (!divFunc)
    {
        std::cerr << "Error getting add function: " << dlerror() << std::endl;
        dlclose(libHandle);
        return 1;
    }

    int op;
    while (true)
    {
        try
        {
            std::cout << "Given are the listed operation you can perform " << std::endl;
            std::cout << "1:addition \n2:subtraction \n3:multiplication \n4:division\n "
                         "Enter op you want to perform\n";
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
                try
                {
                    getTwoUserInput(number1, number2);
                    std::cout << performingDivision(number1, number2) << std::endl;
                }
                catch (const char *s)
                {
                    std::cerr << "Error :" << s;
                }
                break;
            default:
                std::cout << "Invalid Input, Enter a Valid Input" << std::endl;
                break;
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
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