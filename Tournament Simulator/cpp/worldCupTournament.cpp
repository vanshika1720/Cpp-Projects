#include "worldCupTournament.h"
bool WorldCupTournamentSimulator::generateFixture(int numGroupTeams, const std::vector<std::string> &teamNames)
{
    int totalMatches = numGroupTeams / 2;
    std::cout << "Fixture:" << std::endl;
    for (int match = 0; match < totalMatches; match++)
    {
        std::cout << "Match " << match + 1 << ": " << teamNames[match * 2] << " vs " << teamNames[match * 2 + 1] << std::endl;
        fixture.push_back(std::make_pair(teamNames[match * 2], teamNames[match * 2 + 1]));
    }
    if (numGroupTeams % 2 != 0)
    {
        std::cout << "Match " << totalMatches + 1 << ": " << teamNames[numGroupTeams - 1] << " has a bye" << std::endl;
        fixture.push_back(std::make_pair(teamNames[numGroupTeams - 1], "Bye"));
    }
    return true;
}