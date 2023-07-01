#include "jsonHandler.h"
JsonFileHandler::JsonFileHandler(std::string file){
    filename = file;
}
bool JsonFileHandler::openingFile()
{
    file.open(filename);
    if (!file.is_open())
    {
        return false;
    }
    return true;
}
bool JsonFileHandler::parsingFile()
{
    jsonData.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    jsonDocument.Parse(jsonData.c_str());
    if (jsonDocument.HasParseError())
    {
        std::cout << "Error parsing JSON: " << jsonDocument.GetParseError() << std::endl;
        return false;
    }
    return true; 
}
bool JsonFileHandler::accessingFileContent()
{
    if (!jsonDocument.IsArray())
    {
        std::cout << "Invalid JSON format: Array expected." << std::endl;
        return false;
    }
    rapidjson::Value::ConstValueIterator itr;
    for (itr = jsonDocument.Begin(); itr < jsonDocument.End(); itr++)
    {
        if (!itr->IsObject())
        {
            std::cout << "Invalid JSON format: Object expected." << std::endl;
            return false;
        }
        std::cout << "student_id: "<< itr->GetObject()["student_id"].GetInt()<< std::endl;
        std::cout << "name: "<< itr->GetObject()["name"].GetString()<< std::endl;
        std::cout << "age: "<< itr->GetObject()["age"].GetInt()<< std::endl;
    }
    return true;
}

void JsonFileHandler::closingFile()
{
    file.close();
}