#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "tournament.h"
#include "fifaTournament.h"
#include "mockTeam.h"
class TournamentSimulatorTest : public ::testing::Test
{
protected:
    TournamentSimulator *tournament;
    MockTeam *team1;
    MockTeam *team2;
    std::string name1 = "RR";
    std::string name2 = "CSK";

    void SetUp()
    {
        tournament = new FifaTournamentSimulator();
        team1 = new MockTeam;
        team2 = new MockTeam;
    }
    void TearDown()
    {
        delete tournament;
        delete team1;
        delete team2;
    }
};

TEST_F(TournamentSimulatorTest, AddingTeamInTournamentSimulatorTest)
{
    EXPECT_CALL(*team1, getTeamName()).WillRepeatedly(testing::Return("RR"));
    EXPECT_CALL(*team2, getTeamName()).WillRepeatedly(testing::Return("CSK"));
    EXPECT_TRUE(tournament->addTeam(team1));
    EXPECT_TRUE(tournament->addTeam(team2));
}

TEST_F(TournamentSimulatorTest, gettingTeams)
{
    EXPECT_CALL(*team1, getTeamName()).WillRepeatedly(testing::Return("RR"));
    EXPECT_CALL(*team2, getTeamName()).WillRepeatedly(testing::Return("CSK"));
    EXPECT_TRUE(tournament->addTeam(team1));
    EXPECT_TRUE(tournament->addTeam(team2));
    EXPECT_EQ(2, tournament->getTeams().size());
}

TEST_F(TournamentSimulatorTest, settingTeamNames)
{
    EXPECT_TRUE(tournament->setTeamNames(name1));
    EXPECT_TRUE(tournament->setTeamNames(name2));
    EXPECT_EQ(2, tournament->getTeamNames().size());
}

TEST_F(TournamentSimulatorTest, gettingTeamNames)
{
    tournament->setTeamNames(name1);
    tournament->setTeamNames(name2);
    EXPECT_EQ(name1, tournament->getTeamNames()[0]);
    EXPECT_EQ(name2, tournament->getTeamNames()[1]);
}

TEST_F(TournamentSimulatorTest, clearTeamNames)
{
    tournament->setTeamNames(name1);
    tournament->setTeamNames(name2);
    EXPECT_TRUE(tournament->clearTeamNames());
    EXPECT_EQ(0, tournament->getTeamNames().size());
}


TEST_F(TournamentSimulatorTest, addWinnerOfRoundTest)
{
    EXPECT_TRUE(tournament->addWinnerOfRound(name1));
    EXPECT_TRUE(tournament->addWinnerOfRound(name2));
    EXPECT_EQ(2, tournament->getWinnerOfRound().size());
}

TEST_F(TournamentSimulatorTest, getWinnerOfRound)
{
    tournament->addWinnerOfRound(name1);
    tournament->addWinnerOfRound(name2);
    EXPECT_EQ(name1, tournament->getWinnerOfRound()[0]);
    EXPECT_EQ(name2, tournament->getWinnerOfRound()[1]);
}

TEST_F(TournamentSimulatorTest, clearWinnerOfRound)
{
    tournament->addWinnerOfRound(name1);
    tournament->addWinnerOfRound(name2);
    EXPECT_TRUE(tournament->clearWinnerOfRound());
    EXPECT_EQ(0,tournament->getWinnerOfRound().size());
}







