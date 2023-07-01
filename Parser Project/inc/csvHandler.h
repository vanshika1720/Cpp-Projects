#ifndef CSVHANDLER_H
#define CSVHANDLER_H
#include "iFileHandler.h"
#include <vector>
#include <string>
#include "rapidcsv.h"

class CsvFileHandler : public IFileHandler
{
    rapidcsv::Document csvDocument;
    std::string filename;
    int numberOfRows, numberOfColumns;
    std::vector<std::vector<std::string>> fileContents; 
public:
    CsvFileHandler(){}
    CsvFileHandler(std::string file);
    bool openingFile();
    bool parsingFile();
    bool accessingFileContent();
    void closingFile();
};
#endif