#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
#include <vector>
#include "Isong.h"
#include "iPlaylist.h"
class Playlist : public IPlaylist
{
    std::string name;
    std::vector<ISong*> songs;
    int currentSongIndex = 0;
public:
    Playlist() : name("") {}
    Playlist(std::string name);
    std::string getName();
    bool isEmpty();
    bool addSong(ISong* song);
    bool moveSongUp(int index);
    bool moveSongDown(int index);
    bool printPlaylist();
    bool playCurrentSong(int index);
    bool pauseCurrentSong();
    bool goToNextSong();
    bool goToPreviousSong();
};

#endif
