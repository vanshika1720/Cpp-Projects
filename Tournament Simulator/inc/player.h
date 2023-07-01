#ifndef PLAYER_H
#define PLAYER_H
#include "iPlayer.h"
class Player:public IPlayer
{
    std::string playerName;
    int playerAge;
public:
    Player(std::string name, int age);
    std::string getPlayerName();
    int getPlayerAge();
};
#endif