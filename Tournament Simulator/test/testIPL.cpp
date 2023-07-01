#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "tournament.h"
#include "iplTournament.h"

class IPLTournamentSimulatorTest : public ::testing::Test
{
protected:
    TournamentSimulator *tournament;
    std::vector<std::string> teamNames = {"Team1", "Team2", "Team3"};
    void SetUp()
    {
        tournament = new IPLTournamentSimulator();
    }
    void TearDown()
    {
        delete tournament;
    }
};
TEST_F(IPLTournamentSimulatorTest, generateFixtureValidInput)
{
    EXPECT_TRUE(tournament->generateFixture(3, teamNames));
}