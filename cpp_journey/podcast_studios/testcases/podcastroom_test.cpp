#include "../podcastroom/StudioRoom.h"

#include "PodRoomFxTest.h"

TEST_F(PodRoomTest, CreatePodcastRoom) {
    PodcastRoom room1 = PodcastRoomBuilder().SetUseStatus(true);
    bool expectedStatus = true;
    
    EXPECT_EQ(
        expectedStatus,
        room1.GetPodRoomStatus()
    );
}

TEST_F(PodRoomTest, GivePodcastName) {
    PodcastRoom room1 = PodcastRoomBuilder().SetUseStatus(true).MyPodcast().SetPodcastName(podName1Fx_);
    
    std::string expectedPCastName = "Morning-Podcast";
    EXPECT_EQ(
        expectedPCastName,
        
        room1.GetRunningPCastName()
    );
}

TEST_F(PodRoomTest, AddControlSetupAddon) {
    PodcastRoom room1 = PodcastRoomBuilder().SetUseStatus(true).MyAddOns().SetControlSetup(cntrsetup1Fx_);
    
    std::string expectedControls = "Modarn-Setup";
    EXPECT_EQ(
        expectedControls,
        room1.GetRoomAddOnControlSetUp()
    );
}

TEST_F(PodRoomTest, AddOneHostToPodcast) {
    PodcastRoom room1 = PodcastRoomBuilder().SetUseStatus(true).MyPodcast().SetPodcastName(podName1Fx_).SetPodcastDescription(podDescr1Fx_).SetPodcastHosts({&host1Fx_});
    int expecteNumPCastHosts = 1;

    EXPECT_EQ(
        expecteNumPCastHosts,
        room1.GetRunningPCastHosts()
    );
}

TEST_F(PodRoomTest, AddOneHostOneGuest) {
    
    PodcastRoom room1 = PodcastRoomBuilder().SetUseStatus(true).MyPodcast().SetPodcastHosts({&host1Fx_}).SetPodcastGuest({&guest1Fx_});

    EXPECT_EQ(
        1,
        room1.GetRunningPCastGuests()
    );
}

TEST_F(PodRoomTest, SetMultipleGuests) {
    PodcastRoom room1 = PodcastRoomBuilder().SetUseStatus(true).MyPodcast().SetPodcastHosts({&host1Fx_}).SetPodcastGuest({&guest1Fx_, &guest2Fx_});

    EXPECT_EQ(
        2,
        room1.GetRunningPCastGuests()
    );
}