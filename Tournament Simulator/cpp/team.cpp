#include<iostream>
#include <vector>
#include"../inc/team.h"

Team::Team(std::string name){
    teamName = name;
}
bool Team::addPlayerInTeam(IPlayer *player)
{
    players.push_back(player);
    return true;
}
bool Team::displayPlayersInTeam(std::string teamName)
{
    for(int i = 0 ; i < players.size();i++){
        std::cout << players[i]->getPlayerName() << std::endl;
        std::cout << players[i]->getPlayerAge() << std::endl;
    }
    return true;
}
std::string Team::getTeamName()
{
    return teamName;
}
