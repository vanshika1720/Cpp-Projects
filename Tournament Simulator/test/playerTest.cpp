#include "player.h"
#include <iostream>
#include "gtest/gtest.h"
class PlayerTest : public ::testing ::Test
{
protected:
    Player *player1;
    std::string playerName;
    int playerAge;
    void SetUp() override{
        playerName = "j";
        playerAge = 2;
        player1 = new Player(playerName,playerAge);
    }
    void TearDown() override{
        delete player1;
    }
};

TEST_F(PlayerTest, gettingPlayerName)
{
    std::string expectedResult = "j";
    std::string actualResult = player1->getPlayerName();
    EXPECT_EQ(actualResult, expectedResult);
}
TEST_F(PlayerTest, gettingPlayerAge)
{
    int expectedResult=2;
    int actualResult = player1->getPlayerAge();
    EXPECT_EQ(actualResult, expectedResult);
}