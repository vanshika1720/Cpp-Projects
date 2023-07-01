#include<iostream>
#include "player.h"
Player::Player(std::string name , int age){
    playerName = name;
    playerAge = age;
}

std::string Player::getPlayerName()
{
    return playerName;
}
int Player::getPlayerAge()
{
    return playerAge;
}