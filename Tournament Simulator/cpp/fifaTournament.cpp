#include "fifaTournament.h"

bool FifaTournamentSimulator::generateFixture(int numGroupTeams, const std::vector<std::string> &teamNames)
{
    int totalMatches = numGroupTeams / 2;
    std::cout << "Fixture:" << std::endl;
    for (int match = 0; match < totalMatches; match++)
    {
        std::cout << "Match " << match + 1 << ": " << teamNames[match] << " vs " << teamNames[numGroupTeams - match - 1] << std::endl;
        fixture.push_back(make_pair(teamNames[match], teamNames[numGroupTeams - match - 1]));
    }
    if (numGroupTeams % 2 != 0)
    {
        std::cout << "Match " << totalMatches + 1 << ": " << teamNames[totalMatches] << " has a bye" << std::endl;
        fixture.push_back(make_pair(teamNames[totalMatches], "Bye"));
    }
    return true;
}