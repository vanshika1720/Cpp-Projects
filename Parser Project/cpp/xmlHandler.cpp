#include "xmlHandler.h"
XmlFileHandler::XmlFileHandler(std::string file){
    filename = file;
}
bool XmlFileHandler::openingFile()
{
    file.open(filename);
    if (!file.is_open())
    {
        return false;
    }
    return true;
}

bool XmlFileHandler::parsingFile()
{
    buffer.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    try
    {
        doc.parse<0>(&buffer[0]);
        return true;
    }
    catch (const rapidxml::parse_error &e)
    {
        std::cout << "Error parsing XML: " << e.what() << std::endl;
        return false;
    }
}

bool XmlFileHandler::accessingFileContent()
{
    studentsNode = doc.first_node("students");
    if (!studentsNode)
    {
        std::cout << "Error: 'students' node not found. Cannot access file content." << std::endl;
        return false;
    }
    for (rapidxml::xml_node<> *studentNode = studentsNode->first_node("student"); studentNode; studentNode = studentNode->next_sibling("student"))
    {
        rapidxml::xml_node<> *studentIdNode = studentNode->first_node("student_id");
        rapidxml::xml_node<> *nameNode = studentNode->first_node("name");
        rapidxml::xml_node<> *ageNode = studentNode->first_node("age");
        if (!studentIdNode && !nameNode && !ageNode)
        {
            std::cout << "Error: Invalid File Syntax." << std::endl;
            return false;
        }
        std::cout << "student id: " << studentIdNode->value() << std::endl;
        std::cout << "name: " << nameNode->value() << std::endl;
        std::cout << "age: " << ageNode->value() << std::endl;
        std::cout << std::endl;
    }
    return true;
}

void XmlFileHandler::closingFile()
{
    file.close();
}
