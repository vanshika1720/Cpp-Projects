#include "utilityF.h"
void displayGivenTournaments()
{
    std::cout << "Select the tournament you want to simulate:" << std::endl;
    std::cout << "1. FIFA  " << std::endl;
    std::cout << "2. World Cup" << std::endl;
    std::cout << "3. IPL" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

template void validateUserInput<int>(int);
template void validateUserInput<std::string>(std::string);
template void validateUserInput<char>(char);
template <class T>
void validateUserInput(T input)
{
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Invalid input");
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void createTeamForTournament(TournamentSimulator *tournamentSimulator)
{
    int teamCount;
    std::string teamName;
    int playerCount;
    std::cout << "Enter the number of Teams: ";
    std::cin >> teamCount;
    validateUserInput(teamCount);
    for (int i = 0; i < teamCount; i++)
    {
        std::cout << "Enter " << i + 1 << " team name: ";
        std::getline(std::cin, teamName);
        validateUserInput(teamName);
        if (teamCount == 1)
        {
            std::cout << "Can't compete. Minimum two teams are required." << std::endl;
            continue;
        }
        Team *team = new Team(teamName);
        tournamentSimulator->setTeamNames(teamName);
        std::cout << "Enter the number of Players for team " << i + 1 << ": ";
        std::cin >> playerCount;
        validateUserInput(playerCount);
        for (int j = 0; j < playerCount; j++)
        {
            std::string playerName;
            int playerAge;
            std::cout << "Enter the name of Player " << j + 1 << ": ";
            std::cin.ignore();
            std::getline(std::cin, playerName);
            validateUserInput(playerName);
            std::cout << "Enter the age of Player " << j + 1 << ": ";
            std::cin >> playerAge;
            validateUserInput(playerAge);
            Player *player = new Player(playerName, playerAge);
            team->addPlayerInTeam(player);
        }
        tournamentSimulator->addTeam(team);
        std::cout << std::endl;
    }
}

void finalMatch(TournamentSimulator *tournamentSimulator)
{
     if (tournamentSimulator->getTeams().size() < 2)
    {
        std::cout << "Insufficient teams to proceed, Minimum two teams are required." << std::endl;
        return;  
    }
    std::cout << std::endl<< "----- Final Round -----" << std::endl;
    tournamentSimulator->generateFixture(2, tournamentSimulator->getTeamNames());
    std::string winner;
    std::cout << "Enter the final winner team: " << std::endl;
    std::cin >> winner;
    tournamentSimulator->displayfinalWinner(winner);
}

void roundsOfFifa(TournamentSimulator *tournamentSimulator)
{
    int numRounds = 0;
    int numGroupTeams = tournamentSimulator->getTeamNames().size();
    while (numGroupTeams > 2)
    {
        std::cout << std::endl<< "----- Round " << ++numRounds << " -----" << std::endl;
        tournamentSimulator->generateFixture(numGroupTeams, tournamentSimulator->getTeamNames());
        tournamentSimulator->clearTeamNames();
        for (const auto &fixture : tournamentSimulator->getFixtures())
        {
            std::string winner;
            std::cout << "Enter the winner team for the match " << fixture.first << " Vs " << fixture.second << ": ";
            std::cin >> winner;
            if (winner == fixture.first || winner == fixture.second)
            {
                tournamentSimulator->addWinnerOfRound(winner);
                tournamentSimulator->setTeamNames(winner);
            }
            else
            {
                std::cout << "Invalid winner team entered" << std::endl;
                break;
            }
        }

        numGroupTeams = tournamentSimulator->getWinnerOfRound().size();
        tournamentSimulator->clearFixtures();
        tournamentSimulator->clearWinnerOfRound();
    }
    finalMatch(tournamentSimulator);
}

void roundsOfWC(TournamentSimulator *tournamentSimulator)
{
    int numRounds = 0;
    int numGroupTeams = tournamentSimulator->getTeamNames().size();
    while (numGroupTeams > 2)
    {
        std::cout << std::endl<< "----- Round " << ++numRounds << " -----" << std::endl;
        tournamentSimulator->generateFixture(numGroupTeams, tournamentSimulator->getTeamNames());
        tournamentSimulator->clearTeamNames();
        for (const auto &fixture : tournamentSimulator->getFixtures())
        {
            std::string winner;
            std::cout << "Enter the winner team for the match " << fixture.first << " Vs " << fixture.second << ": ";
            std::cin >> winner;
            if (winner == fixture.first || winner == fixture.second)
            {
                tournamentSimulator->addWinnerOfRound(winner);
                tournamentSimulator->setTeamNames(winner);
            }
            else
            {
                std::cout << "Invalid winner team entered" << std::endl;
                break;
            }
        }
        numGroupTeams = tournamentSimulator->getWinnerOfRound().size();
        tournamentSimulator->clearFixtures();
        tournamentSimulator->clearWinnerOfRound();
    }
    finalMatch(tournamentSimulator);
}

void roundsOfIPL(TournamentSimulator *tournamentSimulator)
{
    int numRounds = 0;
    int numGroupTeams = tournamentSimulator->getTeamNames().size();
    while (numGroupTeams > 2)
    {
        std::cout << std::endl<< "----- Round " << ++numRounds << " -----" << std::endl;
        tournamentSimulator->generateFixture(numGroupTeams, tournamentSimulator->getTeamNames());
        for (const auto &fixture : tournamentSimulator->getFixtures())
        {
            std::string winner;
            double score;
            std::cout << "Enter the winner team for the match " << fixture.first << " Vs " << fixture.second << ": ";
            std::cin >> winner;
            if (winner == fixture.first || winner == fixture.second)
            {
                std::cout << "Enter the score of winning team for the match " << fixture.first << " Vs " << fixture.second << ": ";
                std::cin >> score;
                tournamentSimulator->addValueToScoreBoard(winner, score);
            }
            else
            {
                std::cout << "Invalid winner team entered" << std::endl;
                break;
            }
        }
        tournamentSimulator->updateScoreBorad();
        tournamentSimulator->printScoreBoard();
        numGroupTeams = 2;
        tournamentSimulator->clearFixtures();
        tournamentSimulator->insertingTopTwoTeams();
    }
    finalMatch(tournamentSimulator);
}

