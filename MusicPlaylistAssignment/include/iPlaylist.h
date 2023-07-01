#ifndef IPLAYLIST_H
#define IPLAYLIST_H
#include <string>
#include <map>
class IPlaylist
{
public:
    virtual ~IPlaylist(){}
    virtual std::string getName() = 0;
};

#endif

