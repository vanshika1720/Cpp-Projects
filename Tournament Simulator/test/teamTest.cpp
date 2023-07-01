#include"gtest/gtest.h"
#include"gmock/gmock.h"
#include"team.h"
#include "mockPlayer.h"
class TeamTest :public ::testing::Test{
    protected:
    MockPlayer player1;
    MockPlayer player2;
    Team *team1;
    std::string teamName;
    void SetUp(){
        teamName = "RR";
        team1 = new Team(teamName);
    }
    void TearDown() {
        delete team1;
    }
};

TEST_F(TeamTest,addingPlayerTest){
    EXPECT_TRUE(team1->addPlayerInTeam(&player1));
    EXPECT_TRUE(team1->addPlayerInTeam(&player2));
}
TEST_F(TeamTest,displayPlayerTest){
    team1->addPlayerInTeam(&player1);
    team1->addPlayerInTeam(&player2);
    EXPECT_CALL(player1,getPlayerName()).WillOnce(::testing::Return("f"));
    EXPECT_CALL(player2,getPlayerName()).WillOnce(::testing::Return("r"));
    EXPECT_CALL(player1,getPlayerAge()).WillOnce(::testing::Return(1));
    EXPECT_CALL(player2,getPlayerAge()).WillOnce(::testing::Return(2));
    EXPECT_TRUE(team1->displayPlayersInTeam("RR"));
}

TEST_F(TeamTest,gettingTeamNameTest){
   EXPECT_EQ(team1->getTeamName(),"RR"); 
}