#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include <vector>
#include <iostream>
#include "team.h"
class TournamentSimulator
{
protected:
    int numOfGroupedTeams;
    std::vector<ITeam *> teams;
    std::vector<std::string> teamNames;
    std::vector<std::pair<std::string, std::string>> fixture;
    std::vector<std::string> winnerOfRound;
    std::vector<std::pair<std::string, double>> scoreBoard;
public:
    bool addTeam(ITeam *team);
    std::vector<ITeam *> getTeams();
    bool setTeamNames(std::string &names);
    std::vector<std::string> getTeamNames();
    virtual bool generateFixture(int numGroupTeams, const std::vector<std::string> &teamNames) = 0;
    bool addWinnerOfRound(const std::string &winner);
    bool displayfinalWinner(std::string winner);
    std::vector<std::pair<std::string, std::string>> getFixtures();
    std::vector<std::string> getWinnerOfRound();
    bool clearFixtures();
    bool clearTeamNames();
    bool clearWinnerOfRound();
    bool printScoreBoard();
    bool addValueToScoreBoard(const std::string &teamName, double newScore);
    void sortPairsDescending(std::vector<std::pair<std::string, double>>& pairs);
    bool updateScoreBorad();
    bool insertingTopTwoTeams();
};
#endif
