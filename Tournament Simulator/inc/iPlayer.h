#ifndef IPLAYER_H
#define IPLAYER_H
#include<iostream>
class IPlayer{
public:
    virtual std::string getPlayerName()=0;
    virtual int getPlayerAge()=0;
};
#endif