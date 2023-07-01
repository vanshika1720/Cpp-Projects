#ifndef PLAYLISTMENU_H
#define PLAYLISTMENU_H
#include "playlist.h"
#include "song.h"

void addSongToPlaylist(Playlist *playlist,std::vector<Song> &songs);
void moveSongUpWithinPlaylist(Playlist *playlist);
void moveSongDownWithinPlaylist(Playlist *playlist);
void printPlaylists(Playlist *playlist);
void playCurrentSongOfPlaylist(Playlist *playlist);
void pauseCurrentSongOfPlaylist(Playlist *playlist);
void goToNextSongOfPlaylist(Playlist *playlist);
void goToPreviousSongOfPlaylist(Playlist *pplaylist);
#endif