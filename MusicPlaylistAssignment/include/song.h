#ifndef SONG_H
#define SONG_H
#include <iostream>
#include "Isong.h"

class Song : public ISong
{
    std::string title;
public:
    Song(std::string title);
    std::string getTitle();
    bool play();
    bool pause();
};

#endif
