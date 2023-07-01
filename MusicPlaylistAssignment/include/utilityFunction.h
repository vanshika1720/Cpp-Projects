#include "playlistManager.h"
#include "song.h"
std::vector<Song> songList();
void displaySongs(std::vector<Song> &songs);
void displayMainMenu();
void createPlaylist(PlaylistManager &playlistManager,std::vector<Song> &songs);
void loadPlaylist(PlaylistManager &playlistManager, std::vector<Song> &songs);
void displayPlaylistMenu(Playlist *playlist,std::vector<Song> &songs);
void playlistMenu();