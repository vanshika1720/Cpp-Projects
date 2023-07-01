#include <iostream>
#include <vector>
#include "tournament.h"
#include "fifaTournament.h"
#include "worldCupTournament.h"
#include "iplTournament.h"
#include "utilityF.h"

int main()
{
    TournamentSimulator *tournamentSimulator;
    std::cout << "Welcome to Tournament Simulator" << std::endl;
    displayGivenTournaments();
    int userChoice;
    std::cout << "Enter your Choice : ";
    std::cin >> userChoice;
    while (true)
    {
        try
        {
            validateUserInput(userChoice);
            if (userChoice == 1)
            {
                tournamentSimulator = new FifaTournamentSimulator();
                createTeamForTournament(tournamentSimulator);
                roundsOfFifa(tournamentSimulator);
            }
            else if (userChoice == 2)
            {
                tournamentSimulator = new WorldCupTournamentSimulator();
                createTeamForTournament(tournamentSimulator);
                roundsOfWC(tournamentSimulator);
            }
            else if (userChoice == 3)
            {
                tournamentSimulator = new IPLTournamentSimulator();
                createTeamForTournament(tournamentSimulator);
                roundsOfIPL(tournamentSimulator);
            }
            else if (userChoice == 4)
            {
                break;
            }
            else
            {
                std::cout << "Invalid Tournament Choice" << std::endl;
                return 0;
            }
            delete tournamentSimulator;
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
        char response;
        std::cout << "Do you want to continue? (y/n) ";
        std::cin >> response;
        if (response == 'y' || response == 'Y')
        {
            continue;
        }
        else
        {
            break;
        }
    }
    return 0;
}
