#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H
#include <string>
#include "playlist.h"
#include <vector>
#include "iPlaylist.h"
class PlaylistManager
{
    std::vector<IPlaylist*> playlists;
public:
    PlaylistManager();
    PlaylistManager(IPlaylist* playlist):playlists{playlist}{};
    bool addPlaylist(IPlaylist* playlist);
    bool isEmpty();
    bool printPlaylists();
    Playlist* getPlaylist(std::string name);
};
#endif