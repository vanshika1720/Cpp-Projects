#ifndef MOCKPLAYLIST_H
#define MOCKPLAYLIST_H
#include <gmock/gmock.h>
#include "iPlaylist.h"
class MockPlaylist:public IPlaylist{
    public:
    MOCK_METHOD0(getName,std::string());
};
#endif
