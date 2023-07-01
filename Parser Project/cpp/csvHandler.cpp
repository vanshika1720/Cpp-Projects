#include "csvHandler.h"
CsvFileHandler::CsvFileHandler(std::string file){
    filename = file;
}
bool CsvFileHandler::openingFile()
{
    try
    {
        csvDocument = rapidcsv::Document(filename);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error opening file: " << e.what() << std::endl;
        return false;
    }
}

bool CsvFileHandler::parsingFile()
{
    numberOfRows = csvDocument.GetRowCount();
    numberOfColumns = csvDocument.GetColumnCount();
    if (numberOfRows < 2 || numberOfColumns < 1) {
        std::cerr << "Error: CSV file must have at least 2 rows and 1 column." << std::endl;
        return false;
    }
    std::vector<std::string> headerRow;
    headerRow = csvDocument.GetColumnNames();
    fileContents.push_back(headerRow);
    std::vector<std::string> dataRow;
    for (int i = 0; i < numberOfRows - 1; i++)
    {
        std::vector<std::string> dataRow;
        for (int j = 0; j < numberOfColumns; j++)
        {
            std::string cellValue = csvDocument.GetCell<std::string>(j, i);
            dataRow.push_back(cellValue);
        }
        fileContents.push_back(dataRow);
    }
    return true; 
}

bool CsvFileHandler::accessingFileContent()
{
    for (const auto &row : fileContents)
    {
        for (const auto &cell : row)
        {
            if (cell.empty())
            {
                std::cout<<"Error: Empty cell encountered"<<std::endl;
                return false;
            }
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
    return true;
}

void CsvFileHandler::closingFile()
{
    csvDocument.Clear();
}


