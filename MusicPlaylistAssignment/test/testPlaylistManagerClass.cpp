#include <gtest/gtest.h>
#include "playlist.h"
#include "playlistManager.h"
#include "mockPlaylist.h"

using ::testing::AtLeast;
using ::testing::Return;

class PlaylistManagerTest : public ::testing::Test
{
protected:
    PlaylistManager playlistManager;
    MockPlaylist *mockPlaylist;
    void SetUp() override
    {
        mockPlaylist = new MockPlaylist;
    }
    void TearDown() override
    {
        delete mockPlaylist;
    }
};

TEST_F(PlaylistManagerTest, AddingPlaylistToEmptyManager)
{
    std::string playlistName = "NewPlaylist";
    EXPECT_CALL(*mockPlaylist, getName())
        .WillRepeatedly(Return(playlistName));
    bool result = playlistManager.addPlaylist(mockPlaylist);
    EXPECT_TRUE(result);
}

TEST_F(PlaylistManagerTest, AddPlaylistDuplicateName)
{

    EXPECT_CALL(*mockPlaylist, getName())
        .WillRepeatedly(Return("Playlist1"));
    playlistManager.addPlaylist(mockPlaylist);
    MockPlaylist *duplicatePlaylist = new MockPlaylist;
    EXPECT_CALL(*duplicatePlaylist, getName())
        .WillRepeatedly(Return("Playlist1"));
    bool result = playlistManager.addPlaylist(duplicatePlaylist);
    EXPECT_FALSE(result);
    delete duplicatePlaylist;
}

TEST(PlaylistmanagerTest, IsEmptyEmptyPlaylistManager)
{
    PlaylistManager manager;
    bool result = manager.isEmpty();
    EXPECT_TRUE(result);
}

TEST_F(PlaylistManagerTest, PrintPlaylistsEmptyPlaylistManager)
{
    bool result = playlistManager.printPlaylists();
    EXPECT_FALSE(result);
}

TEST_F(PlaylistManagerTest, PrintPlaylistsNonEmptyPlaylistManager)
{
    MockPlaylist mockPlaylist1;
    std::string playlist1Name = "Playlist 1";
    std::string playlist2Name = "Playlist 2";
    EXPECT_CALL(*mockPlaylist, getName()).WillRepeatedly(Return(playlist1Name));
    EXPECT_CALL(mockPlaylist1, getName()).WillRepeatedly(Return(playlist2Name));
    playlistManager.addPlaylist(mockPlaylist);
    playlistManager.addPlaylist(&mockPlaylist1);
    bool result = playlistManager.printPlaylists();
    EXPECT_TRUE(result);
}

TEST_F(PlaylistManagerTest, GetPlaylistNonExistingPlaylist)
{
    std::string playlistName = "NonExistingPlaylist";
    EXPECT_CALL(*mockPlaylist, getName()).WillRepeatedly(::testing::Return("ExistingPlaylist"));
    playlistManager.addPlaylist(mockPlaylist);
    Playlist* result = playlistManager.getPlaylist(playlistName);
    EXPECT_EQ(result, nullptr);
}