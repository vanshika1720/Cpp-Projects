#include "tournament.h"
bool TournamentSimulator::addTeam(ITeam *team)
{
    teams.push_back(team);
    std::cout << "Added Team :" << team->getTeamName();
    return true;
}

std::vector<ITeam *> TournamentSimulator::getTeams()
{
    return teams;
}

std::vector<std::string> TournamentSimulator::getTeamNames()
{
    return teamNames;
}
bool TournamentSimulator::setTeamNames(std::string &names)
{
    teamNames.push_back(names);
    return true;
}

bool TournamentSimulator::addWinnerOfRound(const std::string &winner)
{
    winnerOfRound.push_back(winner);
    return true;
}

std::vector<std::string> TournamentSimulator::getWinnerOfRound()
{
    return winnerOfRound;
}

bool TournamentSimulator::displayfinalWinner(std::string winner)
{
    std::cout << "Final Winner: " << winner << std::endl;
    return true;
}

std::vector<std::pair<std::string, std::string>> TournamentSimulator::getFixtures()
{
    return fixture;
}
bool TournamentSimulator::clearFixtures()
{
    fixture.clear();
    return true;
}
bool TournamentSimulator::clearTeamNames()
{
    teamNames.clear();
    return true;
}
bool TournamentSimulator::clearWinnerOfRound()
{
    winnerOfRound.clear();
    return true;
}

bool TournamentSimulator::printScoreBoard()
{
    for (const auto &team : scoreBoard)
    {
        std::cout << team.first << ": " << team.second << std::endl;
    }
    return true;
}

bool TournamentSimulator::addValueToScoreBoard(const std::string &teamName, double newScore)
{
    auto iter = scoreBoard.end();
    for (auto it = scoreBoard.begin(); it != scoreBoard.end(); ++it)
    {
        if (it->first == teamName)
        {
            iter = it;
            break;
        }
    }
    if (iter != scoreBoard.end())
    {
        iter->second += newScore;
        return true;
    }
    else
    {
        scoreBoard.emplace_back(teamName, newScore);
        return false;
    }
}

void TournamentSimulator::sortPairsDescending(std::vector<std::pair<std::string, double>> &pairs)
{
    for (size_t i = 0; i < pairs.size() - 1; ++i)
    {
        for (size_t j = 0; j < pairs.size() - i - 1; ++j)
        {
            if (pairs[j].second < pairs[j + 1].second)
            {
                std::swap(pairs[j], pairs[j + 1]);
            }
        }
    }
}
bool TournamentSimulator::updateScoreBorad()
{
    sortPairsDescending(scoreBoard);
    return true;
}

bool TournamentSimulator::insertingTopTwoTeams()
{
    if (scoreBoard.size() >= 2)
    {
        std::string team1 = scoreBoard[0].first;
        std::string team2 = scoreBoard[1].first;
        teamNames.clear();
        teamNames.push_back(team1);
        teamNames.push_back(team2);
        return true;
    }
    else
    {
        throw std::invalid_argument("There are not enough teams in the scoreBoard.");
        return false;
    }
}
