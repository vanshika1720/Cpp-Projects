#include "iPlayer.h"
#include"gmock/gmock.h"
class MockPlayer:public IPlayer{
    public:
    MOCK_METHOD0(getPlayerName,std::string());
    MOCK_METHOD0(getPlayerAge,int());
};