#include <iostream>
#include "validateUserInput.h"
#include "utilityFunction.h"
#include "playlistManager.h"

int main()
{
    std::cout << "Welcome to the Music Playlist program!" << std::endl;
    std::vector<Song> songLibrary = songList();
    PlaylistManager playlistManager;
    while (true)
    {
        try

        {
            displayMainMenu();
            int choice;
            std::cin >> choice;
            if (validateUserInput(choice))
            {
                if (choice == 1)
                {
                    createPlaylist(playlistManager, songLibrary);
                }
                else if (choice == 2)
                {
                    loadPlaylist(playlistManager, songLibrary);
                }
                else if (choice == 3)
                {
                    break;
                }
                else
                {
                    std::cout << "Invalid selection" << std::endl;
                }
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
