#ifndef IPLTOURNAMENT_H
#define IPLTOURNAMENT_H
#include "tournament.h"
class IPLTournamentSimulator : public TournamentSimulator
{
public:
    IPLTournamentSimulator() {}
    bool generateFixture(int numGroupTeams,const std::vector<std::string>&teamNames);
};
#endif
