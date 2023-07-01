#ifndef IFILEHANDLER_H
#define IFILEHANDLER_H
#include <string>
class IFileHandler
{
public:
    virtual bool openingFile() = 0;
    virtual bool parsingFile() = 0;
    virtual bool accessingFileContent() = 0;
    virtual void closingFile() = 0;
};
#endif