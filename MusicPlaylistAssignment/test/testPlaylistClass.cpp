#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "playlist.h"
#include "mockSong.h"

using ::testing::AtLeast;
using ::testing::Return;

class PlaylistTest : public ::testing::Test
{
protected:
  Playlist *playlist;
  MockSong *song1;
  MockSong *song2;
  void SetUp() override
  {
    playlist = new Playlist();
    song1 = new MockSong;
    song2 = new MockSong;
  }
  void TearDown() override
  {
    delete playlist;
    delete song1;
    delete song2;
  }
};

TEST_F(PlaylistTest, AddSongToEmptyPlaylist)
{
  std::string song1Title = "Song 1";
  EXPECT_CALL(*song1, getTitle()).WillRepeatedly(Return(song1Title));
  bool result = playlist->addSong(song1);
  EXPECT_TRUE(result);
}

TEST_F(PlaylistTest, AddDuplicateSongToPlaylist)
{
  std::string song1Title = "Song 1";
  EXPECT_CALL(*song1, getTitle()).WillRepeatedly(Return(song1Title));
  playlist->addSong(song1);
  bool result = playlist->addSong(song1);
  EXPECT_FALSE(result);
}

TEST_F(PlaylistTest, AddDifferentSongToPlaylist)
{
  std::string song1Title = "Song 1";
  std::string song2Title = "Song 2";
  EXPECT_CALL(*song1, getTitle()).WillRepeatedly(Return(song1Title));
  EXPECT_CALL(*song2, getTitle()).WillRepeatedly(Return(song2Title));
  bool result1 = playlist->addSong(song1);
  EXPECT_TRUE(result1);
  bool result2 = playlist->addSong(song2);
  EXPECT_TRUE(result2);
}

TEST_F(PlaylistTest, MoveSongUpToAValidIndex)
{
  std::string song1Title = "Song 1";
  EXPECT_CALL(*song1, getTitle()).WillRepeatedly(Return(song1Title));
  playlist->addSong(song1);
  std::string song2Title = "Song 2";
  EXPECT_CALL(*song2, getTitle()).WillRepeatedly(Return(song2Title));
  playlist->addSong(song2);
  bool result = playlist->moveSongUp(1);
  EXPECT_TRUE(result);
}

TEST_F(PlaylistTest, MoveSongUpToInvalidIndex)
{
  std::string song1Title = "Song 1";
  EXPECT_CALL(*song1, getTitle()).WillRepeatedly(Return(song1Title));
  playlist->addSong(song1);
  std::string song2Title = "Song 2";
  EXPECT_CALL(*song2, getTitle()).WillRepeatedly(Return(song2Title));
  playlist->addSong(song2);
  bool result = playlist->moveSongUp(2);
  EXPECT_FALSE(result);
}

TEST_F(PlaylistTest, MoveSongUpWhenAtTopIndex)
{
  playlist->addSong(song1);
  bool result = playlist->moveSongUp(0);
  EXPECT_FALSE(result);
}

TEST_F(PlaylistTest, MoveSongDownToAValidIndex)
{
  std::string song1Title = "Song 1";
  EXPECT_CALL(*song1, getTitle()).WillRepeatedly(Return(song1Title));
  playlist->addSong(song1);
  std::string song2Title = "Song 2";
  EXPECT_CALL(*song2, getTitle()).WillRepeatedly(Return(song2Title));
  playlist->addSong(song2);
  bool result = playlist->moveSongDown(0);
  EXPECT_TRUE(result);
}

TEST_F(PlaylistTest, MoveSongDownToInvalidIndex)
{
  std::string song1Title = "Song 1";
  EXPECT_CALL(*song1, getTitle()).WillRepeatedly(Return(song1Title));
  playlist->addSong(song1);
  std::string song2Title = "Song 2";
  EXPECT_CALL(*song2, getTitle()).WillRepeatedly(Return(song2Title));
  playlist->addSong(song2);
  bool result = playlist->moveSongDown(2);
  EXPECT_FALSE(result);
}

TEST_F(PlaylistTest, MoveSongDownWhenAtBottomIndex)
{
  playlist->addSong(song1);
  bool result = playlist->moveSongDown(0);
  EXPECT_FALSE(result);
}

TEST_F(PlaylistTest, PrintEmptyPlaylist)
{
  bool result = playlist->printPlaylist();
  EXPECT_FALSE(result);
}

TEST_F(PlaylistTest, PrintNonEmptyPlaylist)
{
  std::string song1Title = "Song 1";
  std::string song2Title = "Song 2";
  EXPECT_CALL(*song1, getTitle()).WillRepeatedly(Return(song1Title));
  EXPECT_CALL(*song2, getTitle()).WillRepeatedly(Return(song2Title));
  playlist->addSong(song1);
  playlist->addSong(song2);
  bool result = playlist->printPlaylist();
  EXPECT_TRUE(result);
}

TEST_F(PlaylistTest, PlayCurrentSongInvalidIndex)
{
  bool result = playlist->playCurrentSong(-1);
  EXPECT_FALSE(result);
}

TEST_F(PlaylistTest, PlayCurrentSongValidIndex)
{
  playlist->addSong(song1);
  EXPECT_CALL(*song1, play()).Times(1);
  bool result1 = playlist->playCurrentSong(1);
  EXPECT_TRUE(result1);
}

TEST_F(PlaylistTest, PauseCurrentSongWhenNoSongPlaying)
{
  bool result = playlist->pauseCurrentSong();
  EXPECT_FALSE(result);
}

TEST_F(PlaylistTest, PauseCurrentPlayingSong)
{
  playlist->addSong(song1);
  EXPECT_CALL(*song1, play());
  playlist->playCurrentSong(1);
  EXPECT_CALL(*song1, pause()).Times(1);
  bool result = playlist->pauseCurrentSong();
  EXPECT_TRUE(result);
}

TEST_F(PlaylistTest, GoToNextSongOfValidIndex)
{
  std::string song1Title = "Song 1";
  EXPECT_CALL(*song1, getTitle()).WillRepeatedly(Return(song1Title));
  playlist->addSong(song1);
  std::string song2Title = "Song 2";
  EXPECT_CALL(*song2, getTitle()).WillRepeatedly(Return(song2Title));
  playlist->addSong(song2);
  EXPECT_CALL(*song1, play());
  bool result = playlist->goToNextSong();
  EXPECT_TRUE(result);
}

TEST_F(PlaylistTest, GoToNextSongOfInvalidIndex)
{
  playlist->addSong(song1);
  EXPECT_CALL(*song1,play());
  playlist->playCurrentSong(1);
  bool result = playlist->goToNextSong();
  EXPECT_FALSE(result);
}

TEST_F(PlaylistTest, GoToPreviousSongOfValidIndex)
{
  std::string song1Title = "Song 1";
  EXPECT_CALL(*song1, getTitle()).WillRepeatedly(Return(song1Title));
  playlist->addSong(song1);
  std::string song2Title = "Song 2";
  EXPECT_CALL(*song2, getTitle()).WillRepeatedly(Return(song2Title));
  playlist->addSong(song2);
  EXPECT_CALL(*song2, play());
  playlist->playCurrentSong(2);
  bool result = playlist->goToPreviousSong();
  EXPECT_TRUE(result);
}

TEST_F(PlaylistTest, GoToPreviousSongOfInvalidIndex)
{
  playlist->addSong(song1);
  EXPECT_CALL(*song1,play());
  playlist->playCurrentSong(1);
  bool result = playlist->goToPreviousSong();
  EXPECT_FALSE(result);
}

TEST_F(PlaylistTest,PlaylistIsEmpty){
  EXPECT_TRUE(playlist->isEmpty());
}

TEST_F(PlaylistTest,PlaylistIsNonEmpty){
  playlist->addSong(song1);
  EXPECT_FALSE(playlist->isEmpty());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}