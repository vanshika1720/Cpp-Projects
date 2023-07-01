#ifndef FIFATOURNAMENT_H
#define FIFATOURNAMENT_H
#include "tournament.h"
class FifaTournamentSimulator : public TournamentSimulator
{
public:
    FifaTournamentSimulator() {}
    virtual bool generateFixture(int numGroupTeams, const std::vector<std::string>&teamNames) override;
};
#endif
