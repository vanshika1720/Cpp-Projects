#include <iostream>
#include "playlist.h"

Playlist::Playlist(std::string name)
{
    this->name = name;
}

std::string Playlist::getName()
{
    return name;
}
bool Playlist::isEmpty(){
    return songs.empty();
}
bool Playlist::addSong(ISong *song)
{
    for (auto &s : songs)
    {
        if (s->getTitle() == song->getTitle())
        {
            std::cout << "Song already exists in playlist." << std::endl;
            return false;
        }
    }
    songs.push_back(song);
    return true;
}

bool Playlist::moveSongUp(int index)
{
    if (index == 0)
    {
        std::cout << "This song is already at the top of the playlist\n";
        return false;
    }
    if (index > 0 && index < songs.size())
    {
        std::swap(songs[index], songs[index - 1]);
        std::cout << "Song moved up within the playlist!" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Invalid song index. Please enter a valid song index within the playlist range." << std::endl;
        return false;
    }
}

bool Playlist::moveSongDown(int index)
{
    if (index == songs.size() - 1)
    {
        std::cout << "This song is already at the bottom of the playlist\n";
        return false;
    }
    if (index < songs.size() - 1)
    {
        std::swap(songs[index], songs[index + 1]);
        std::cout << "Song moved down within the playlist!" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Invalid song index. Please enter a valid song index within the playlist range." << std::endl;
        return false;
    }
}

bool Playlist::printPlaylist()
{
    if (songs.empty())
    {
        std::cout << "Playlist is empty!" << std::endl;
        return false;
    }
    std::cout << "Playlist: " << name << std::endl;
    for (int i = 0; i < songs.size(); i++)
    {
        std::cout << i + 1 << ". " << songs[i]->getTitle() << std::endl;
    }
    return true;
}

bool Playlist::playCurrentSong(int index)
{
    if (songs.empty())
    {
        std::cout << "Playlist is empty!" << std::endl;
        return false;
    }
    if (index <= 0 || index > songs.size())
    {
        std::cout << "Invalid song index." << std::endl;
        return false;
    }
    songs[index - 1]->play();
    currentSongIndex = index;
    return true;
}

bool Playlist::pauseCurrentSong()
{
    if (currentSongIndex == 0)
    {
        std::cout << "No song is currently playing. Cannot pause." << std::endl;
        return false;
    }
    songs[currentSongIndex - 1]->pause();
    return true;
}

bool Playlist::goToNextSong()
{
    if (songs.empty())
    {
        std::cout << "Playlist is empty!" << std::endl;
        return false;
    }
    if (currentSongIndex >= songs.size())
    {
        std::cout << "No more songs in playlist." << std::endl;
        return false;
    }
    currentSongIndex++;
    playCurrentSong(currentSongIndex);
    return true;
}

bool Playlist::goToPreviousSong()
{
    if (songs.empty())
    {
        std::cout << "Playlist is empty!" << std::endl;
        return false;
    }
    if (currentSongIndex <=1)
    {
        std::cout << "Already at first song in playlist." << std::endl;
        return false;
    }
    currentSongIndex--;
    playCurrentSong(currentSongIndex);
    return true;
}

