#include "iplTournament.h"
bool IPLTournamentSimulator::generateFixture(int numGroupTeams, const std::vector<std::string> &teamNames)
{
    int numTeams = teamNames.size();
    int totalMatches = numTeams * (numTeams - 1) / 2;

    std::cout << "Fixture:" << std::endl;

    int match = 0;
    for (int i = 0; i < numTeams - 1; i++)
    {
        for (int j = i + 1; j < numTeams; j++)
        {
            std::cout << "Match " << match + 1 << ": " << teamNames[i] << " vs " << teamNames[j] << std::endl;
            fixture.push_back(std::make_pair(teamNames[i], teamNames[j]));
            match++;
        }
    }
    return true;
}
