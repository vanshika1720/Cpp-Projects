#include "iTeam.h"
#include"gmock/gmock.h"
class MockTeam:public ITeam{
    public:
    MOCK_METHOD0(getTeamName,std::string());
};