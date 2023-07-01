#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "song.h"

using ::testing::AtLeast;
using ::testing::Return;

class SongTest:public ::testing::Test
{
protected:
    Song* song;
    std::string song1Title;
    void SetUp() override
    {
      song1Title = "Song 1";
      song = new Song(song1Title);   
    }
    void TearDown() override{
        delete song;
    }
};

TEST_F(SongTest, WhenCalledThenReturnTitle)
{
    std::string retrievedTitle = song->getTitle();
    EXPECT_EQ(retrievedTitle, song1Title);
}

TEST_F(SongTest, WhenPlayCalledThenReturnTrue)
{
    bool result = song->play();
    EXPECT_TRUE(result);
}

TEST_F(SongTest, WhenPauseCalledThenReturnTrue)
{
    bool result = song->pause();
    EXPECT_TRUE(result);
}