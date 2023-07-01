#ifndef WORLDCUPTOURNAMENT_H
#define WORLDCUPTOURNAMENT_H
#include "tournament.h"
class WorldCupTournamentSimulator : public TournamentSimulator
{
public:
    WorldCupTournamentSimulator() {}
    bool generateFixture(int numGroupTeams, const std::vector<std::string> &teamNames);
};
#endif