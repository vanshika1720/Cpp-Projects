#include <iostream>
#include "inputValidator.h"
#include "xmlHandler.h"
#include "jsonHandler.h"
#include "csvHandler.h"
void Menu()
{
    std::cout << "Select the File you want to Read:" << std::endl;
    std::cout << "1. csv File" << std::endl;
    std::cout << "2. json File" << std::endl;
    std::cout << "3. xml File" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

int main()
{
    std::cout << "Welcome to the File Parser" << std::endl;
    while (true)
    {
        Menu();
        InputValidator validator;
        int userChoice = validator.getIntInput("Enter your choice: ");
        IFileHandler *ifilehandler;
        if (userChoice == 1)
        {
            CsvFileHandler csvFile("dataCsv.csv");
            ifilehandler = &csvFile;
            if(ifilehandler->openingFile()&&ifilehandler->parsingFile()){
                ifilehandler->accessingFileContent();
            }else{
                std::cout<<"Error opening or Parsing file.Please Enter a Valid file"<<std::endl;
            }
        }
        else if (userChoice == 2)
        {
            JsonFileHandler jsonFile("data.json");
            ifilehandler = &jsonFile;
            if(ifilehandler->openingFile()&&ifilehandler->parsingFile()){
                ifilehandler->accessingFileContent();
            }else{
                std::cout<<"Error opening or Parsing file.Please Enter a Valid file"<<std::endl;
            }
        }
        else if (userChoice == 3)
        {
            XmlFileHandler xmlFile("dataXml.xml");
            ifilehandler = &xmlFile;
            if(ifilehandler->openingFile() && ifilehandler->parsingFile()){
                ifilehandler->accessingFileContent();
            }else{
                std::cout<<"Error opening or Parsing file.Please Enter a Valid file"<<std::endl;
            }
        }
        else if (userChoice == 4)
        {
            break;
        }
        else
        {
            std::cout << "Invalid Choice" << std::endl;
            return 0;
        }
    }
    return 0;
}