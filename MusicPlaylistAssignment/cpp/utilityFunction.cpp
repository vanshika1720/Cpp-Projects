#include <iostream>
#include "utilityFunction.h"
#include "playlistMenu.h"
#include "validateUserInput.h"
#include "playlistManager.h"

void displaySongs(std::vector<Song> &songs)
{
    std::cout << "Available Songs: " << std::endl;
    for (int i = 0; i < songs.size(); i++)
    {
        std::cout << i + 1 << ". " << songs[i].getTitle() << std::endl;
    }
}

std::vector<Song> songList()
{
    std::vector<Song> songs;
    songs.push_back(Song("Song 1"));
    songs.push_back(Song("Song 2"));
    songs.push_back(Song("Song 3"));
    songs.push_back(Song("Song 4"));
    songs.push_back(Song("Song 5"));
    return songs;
}

void displayMainMenu()
{
    std::cout << "What do you want to do?" << std::endl;
    std::cout << "1. Create a playlist" << std::endl;
    std::cout << "2. Show existing playlists" << std::endl;
    std::cout << "3. Exit" << std::endl;
}

void createPlaylist(PlaylistManager &playlistManager, std::vector<Song> &songLibrary)
{
    std::cout << "Enter the name of your playlist: ";
    std::string name;
    std::cin.ignore();
    std::getline(std::cin, name);
    Playlist* playlist = new Playlist(name);
    displayPlaylistMenu(playlist, songLibrary);
    playlistManager.addPlaylist(playlist);
    return;
}

void playlistMenu()
{
    std::cout << "What do you want to do with this Playlist ? " << std::endl;
    std::cout << "1. Add song" << std::endl;
    std::cout << "2. Move song up" << std::endl;
    std::cout << "3. Move song down" << std::endl;
    std::cout << "4. Print playlist" << std::endl;
    std::cout << "5. Play current song" << std::endl;
    std::cout << "6. Pause current song" << std::endl;
    std::cout << "7. Go to next song" << std::endl;
    std::cout << "8. Go to previous song" << std::endl;
    std::cout << "9. Exit playlist" << std::endl;
}

void loadPlaylist(PlaylistManager& playlistManager, std::vector<Song> &songs) {
    if(playlistManager.isEmpty()){
        std::cout<<"Playlist is Empty"<<std::endl;
        return;
    }
    playlistManager.printPlaylists();
    std::string playlistName;
    std::cout << "Enter the name of the playlist you want to select: ";
    std::cin.ignore();
    std::getline(std::cin, playlistName);
    Playlist* currentPlaylist = playlistManager.getPlaylist(playlistName);
    if (currentPlaylist == nullptr) {
        std::cout << "Playlist not found." << std::endl;
        return;
    }
    std::cout << "Playlist Loaded : " << currentPlaylist->getName() << std::endl;
    displayPlaylistMenu(currentPlaylist,songs);
}

void displayPlaylistMenu(Playlist *playlist, std::vector<Song> &songLibrary)
{
    while (true)
    {
        playlistMenu();
        int playlistChoice;
        std::cin >> playlistChoice;
        if (validateUserInput(playlistChoice))
        {
            if (playlistChoice == 1)
            {
                addSongToPlaylist(playlist, songLibrary);
            }
            else if (playlistChoice == 2)
            {
                moveSongUpWithinPlaylist(playlist);
            }
            else if (playlistChoice == 3)
            {
                moveSongDownWithinPlaylist(playlist);
            }
            else if (playlistChoice == 4)
            {
                printPlaylists(playlist);
            }
            else if (playlistChoice == 5)
            {
                playCurrentSongOfPlaylist(playlist);
            }
            else if (playlistChoice == 6)
            {
                pauseCurrentSongOfPlaylist(playlist);
            }
            else if (playlistChoice == 7)
            {
                goToNextSongOfPlaylist(playlist);
            }
            else if (playlistChoice == 8)
            {
                goToPreviousSongOfPlaylist(playlist);
            }
            else if (playlistChoice == 9)
            {
                break;
            }
            else
            {
                std::cout << "Invalid selection" << std::endl;
            }
        }
    }
}
