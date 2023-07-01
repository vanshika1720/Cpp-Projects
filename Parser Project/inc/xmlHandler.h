#ifndef XMLHANDLER_H
#define XMLHANDLER_H
#include "iFileHandler.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <rapidxml.hpp>
class XmlFileHandler : public IFileHandler
{
    std::ifstream file;
    std::string filename;
    rapidxml::xml_document<> doc;
    std::vector<char> buffer;
    rapidxml::xml_node<> *studentsNode;
public:
    XmlFileHandler(){}
    XmlFileHandler(std::string file);
    bool openingFile();
    bool parsingFile();
    bool accessingFileContent();
    void closingFile();
};
#endif