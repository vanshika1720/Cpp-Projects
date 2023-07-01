#include <iostream>
#include "validateUserInput.h"
#include "utilityFunction.h"
void addSongToPlaylist(Playlist *playlist, std::vector<Song> &songLibrary)
{
    displaySongs(songLibrary);
    std::cout << "Enter song number to add: ";
    int songIndex;
    std::cin >> songIndex;
    if (validateUserInput(songIndex))
    {
        if (songIndex > 0 && songIndex <= songLibrary.size())
        {
            bool added = playlist->addSong(&songLibrary[songIndex - 1]);
            if (added)
            {
                std::cout << "Song successfully added to the playlist" << std::endl;
            }
        }
        else
        {
            std::cout << "Invalid Song Selection" << std::endl;
        }
    }

}

void moveSongUpWithinPlaylist(Playlist *playlist)
{
    if(playlist->isEmpty()){
        std::cout<<"Playlist is Empty"<<std::endl;
        return;
    }
    std::cout << "Enter song index to move up: ";
    int songIndex;
    std::cin >> songIndex;
    if (validateUserInput(songIndex))
    {
        playlist->moveSongUp(songIndex - 1);
    }
}

void moveSongDownWithinPlaylist(Playlist *playlist)
{
    if(playlist->isEmpty()){
        std::cout<<"Playlist is Empty"<<std::endl;
        return;
    }
    std::cout << "Enter song index to move down: ";
    int songIndex;
    std::cin >> songIndex;
    if (validateUserInput(songIndex))
    {
        playlist->moveSongDown(songIndex - 1);
    }
}
void printPlaylists(Playlist *playlist)
{
    std::cout << "Printing Playlist:" << std::endl;
    playlist->printPlaylist();
}
void playCurrentSongOfPlaylist(Playlist *playlist)
{
    if(playlist->isEmpty()){
        std::cout<<"Playlist is Empty"<<std::endl;
        return;
    }
    std::cout << "Enter song index to play: ";
    int songIndex;
    std::cin >> songIndex;
    if (validateUserInput(songIndex))
    {
        playlist->playCurrentSong(songIndex);
    }
}
void pauseCurrentSongOfPlaylist(Playlist *playlist)
{
    playlist->pauseCurrentSong();
}

void goToNextSongOfPlaylist(Playlist *playlist)
{
    playlist->goToNextSong();
}
void goToPreviousSongOfPlaylist(Playlist *playlist)
{
    playlist->goToPreviousSong();
}
