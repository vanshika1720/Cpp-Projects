#ifndef MOCKSONG_H
#define MOCKSONG_H
#include <gmock/gmock.h>
#include "Isong.h"
class MockSong : public ISong
{
public:
    MOCK_METHOD0(getTitle, std::string());
    MOCK_METHOD0(play, bool());
    MOCK_METHOD0(pause, bool());
};
#endif
