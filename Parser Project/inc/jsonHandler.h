#ifndef JSONHANDLER_H
#define JSONHANDLER_H
#include "iFileHandler.h"
#include "document.h"
#include <fstream>
#include <iostream>
class JsonFileHandler : public IFileHandler
{
    std::ifstream file;
    std::string filename;
    rapidjson::Document jsonDocument;
    std::string jsonData;
    public:
    JsonFileHandler(){}
    JsonFileHandler(std::string file);
    bool openingFile();
    bool parsingFile();
    bool accessingFileContent();
    void closingFile();
};
#endif