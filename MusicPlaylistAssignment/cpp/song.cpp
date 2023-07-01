#include "song.h"
#include <iostream>

Song::Song(std::string title)
{
    this->title = title;
}

std::string Song::getTitle()
{
    return title;
}

bool Song::play()
{
    std::cout << "Playing " << title << std::endl;
    return true;
}

bool Song::pause()
{
    std::cout << "Pausing " << title << std::endl;
    return true;
}
