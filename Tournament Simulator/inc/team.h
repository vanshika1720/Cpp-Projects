#ifndef TEAM_H
#define TEAM_H
#include <string>
#include<vector>
#include"player.h"
#include "iTeam.h"
class Team: public ITeam{
    std::vector<IPlayer*> players;
    std::string teamName;
public:
    Team(std::string name);
    bool addPlayerInTeam(IPlayer *player);
    bool displayPlayersInTeam(std::string teamName);
    std::string getTeamName();
};
#endif
