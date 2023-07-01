#ifndef ISONG_H
#define ISONG_H
#include <string>
class ISong 
{
public:
    virtual ~ISong() {}
    virtual std::string getTitle() = 0;
    virtual bool play() = 0;
    virtual bool pause() = 0;
};
#endif    