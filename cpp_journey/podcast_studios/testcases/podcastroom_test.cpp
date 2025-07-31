#include "../podcastroom/StudioRoom.h"

#include "PodRoomFxTest.h"

TEST_F(PodRoomTest, AddOneHostToPodcast_PodPodcastBuilder) {
    PodPodcast pcast1 = PodPodcastBuilder().SetPodcastHosts({&host1Fx_});
    bool expectedStatus = true;
    
    EXPECT_EQ(
        expectedStatus,
        pcast1.getHostCount()
    );
}

TEST_F(PodRoomTest, GivePodcastName_PodPodcastBuilder) {
    PodPodcast pcast1 = PodPodcastBuilder().SetPodcastHosts({&host1Fx_}).SetPodcastName(podName1Fx_);
    
    std::string expectedPCastName = "Morning-Podcast";
    EXPECT_EQ(
        expectedPCastName,
        pcast1.getPCastName()
    );
}

TEST_F(PodRoomTest, AddControlSetupAddon_RoomAddOnsBuilder) {
    PodPodcast pcast1 = PodPodcastBuilder().SetPodcastHosts({&host1Fx_}).MyAddOns().SetControlSetup(cntrsetup1Fx_);
    std::string expectedControls = "Modarn-Setup";
    EXPECT_EQ(
        expectedControls,
        pcast1.getControlRoomSetup()
    );
}

TEST_F(PodRoomTest, CreatePodcastRoom_PodcastRoomBuilder) {
    PodPodcast pcast1 = PodPodcastBuilder().SetPodcastHosts({&host1Fx_}).SetPodcastName(podName1Fx_).MyPodcastRoom().SetUseStatus(true);
    bool expecteUseStatus = true;

    EXPECT_EQ(
        expecteUseStatus,
        pcast1.getPodcastLiveStatus()
    );
}

TEST_F(PodRoomTest, AddOneHostOneGuest_PodPodcastBuilder) {
    PodPodcast pcast1 = PodPodcastBuilder().SetPodcastHosts({&host1Fx_}).SetPodcastName(podName1Fx_).SetPodcastGuest({&guest1Fx_});
    EXPECT_EQ(
        1,
        pcast1.getGuestsCount()
    );
}

TEST_F(PodRoomTest, SetMultipleGuests_PodPodcastBuilder) {
    PodPodcast pcast1 = PodPodcastBuilder().SetPodcastHosts({&host1Fx_}).SetPodcastName(podName1Fx_).SetPodcastGuest({&guest1Fx_, &guest2Fx_});
    EXPECT_EQ(
        2,
        pcast1.getGuestsCount()
    );
}

TEST_F(PodRoomTest, AddOnePodcastToStudio_AuthoInfo_SetOfficialPodcats) {
    PodPodcast pcast1 = PodPodcastBuilder().SetPodcastHosts({&host1Fx_}).SetPodcastName(podName1Fx_).SetPodcastGuest({&guest1Fx_}).SetPodcastId("podcast1Id");
    
    std::string mId = SetOfficialPodcats(pcast1);
    std::string expectedId = "podcast1Id";
    
    EXPECT_EQ(
        expectedId,
        SetOfficialPodcats(pcast1)
    );
}

TEST_F(PodRoomTest, TwoPodcastsAdded_AuthoInfo_SetOfficialPodcats) {
    PodPodcast pcast2 = PodPodcastBuilder().SetPodcastHosts({&host2Fx_}).SetPodcastName(podName2Fx_).SetPodcastGuest({&guest2Fx_}).SetPodcastId("podcast2Id");
    
    std::string mId = SetOfficialPodcats(pcast2);
    std::string expectedId = "podcast2Id";
    int expectedSize = 2;
    EXPECT_EQ(
        expectedId,
        SetOfficialPodcats(pcast2)
    );
    EXPECT_EQ(
        expectedSize,
        getSizeSignedUpPodcasts() 
    );
}