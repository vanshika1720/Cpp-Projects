#include "playlistManager.h"
#include <iostream>

PlaylistManager::PlaylistManager() {}
bool PlaylistManager::addPlaylist(IPlaylist *playlist)
{
    for (auto &p : playlists)
    {
        if (p->getName() == playlist->getName())
        {
            std::cout << "Playlist with name '" << playlist->getName() << "' already exists." << std::endl;
            return false;
        }
    }
    playlists.push_back(playlist);
    return true;
}

bool PlaylistManager::isEmpty()
{
    return playlists.empty();
}

bool PlaylistManager::printPlaylists()
{
    if (playlists.empty())
    {
        std::cout << "No playlists have been created yet." << std::endl;
        return false;
    }
    std::cout << "Existing playlists:" << std::endl;
    for (auto playlist : playlists)
    {
        std::cout << "- " << playlist->getName() << std::endl;
    }
    return true;
}

Playlist *PlaylistManager::getPlaylist(std::string name)
{
    for (auto playlist : playlists)
    {
        if (playlist->getName() == name)
        {
            return (Playlist *)playlist;
        }
    }
    return nullptr;
}