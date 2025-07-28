#include "../podcastroom/StudioRoom.h"

#include "PodRoomFxTest.h"

TEST_F(PodRoomTest, PodcastPodBuilder) {
    PodcastRoom room1 = PodcastRoomBuilder().SetUseStatus(true);
    bool expectedStatus = true;
    
    EXPECT_EQ(
        expectedStatus,
        room1.GetPodRoomStatus()
    );
}

TEST_F(PodRoomTest, RoomAddOnsBuilder) {
    PodcastRoom room1 = PodcastRoomBuilder().SetUseStatus(true).MyAddOns().SetControlSetup(podcastInputs_[podCount_].podCntrlSetupFx_[podCount_]).MyPodcast().SetPodcastName("Morning-Podcast");
    
    std::string expectedControls = "Modarn-Setup";
    std::string expectedPCastName = "Morning-Podcast";
    EXPECT_EQ(
        expectedControls,
        room1.GetRoomAddOnControlSetUp()
    );
    EXPECT_EQ(
        expectedPCastName,
        room1.GetRunningPCastName()
    );
}

TEST_F(PodRoomTest, PodPodcastBuilder) {
    PodcastHost host = PodcastHost().SetFirstName(podcastInputs_[podCount_].hostInputsFx_[0].fNameT_).SetLastName(podcastInputs_[podCount_].hostInputsFx_[0].lNameT_).SetEmail(podcastInputs_[podCount_].hostInputsFx_[0].emailT_).SetPhoneNum(podcastInputs_[podCount_].hostInputsFx_[0].phoneNumT_);
    PodcastRoom room1 = PodcastRoomBuilder().SetUseStatus(true).MyAddOns().SetControlSetup(podcastInputs_[podCount_].podCntrlSetupFx_[0]).MyPodcast().SetPodcastName("Morning-Podcast").SetPodcastDescription("A podcast about mindful thinking!").SetPodcastHosts({&host});
    int expecteNumPCastHosts = 1;

    EXPECT_EQ(
        expecteNumPCastHosts,
        room1.GetRunningPCastHosts()
    );
}

TEST_F(PodRoomTest, SetPodcastGuest_PodPodcastBuilder) {
    PodcastHost host = PodcastHost().SetFirstName("Host1").SetLastName("Tech").SetPhoneNum("250-638-386").SetEmail("host1email@gmail.com");
    PodGuest guestOne = {"gfName", "glName", "gcEmail", "gsHandle"};
    PodcastRoom room1 = PodcastRoomBuilder().SetUseStatus(true).MyPodcast().SetPodcastHosts({&host}).SetPodcastGuest({&guestOne});

    EXPECT_EQ(
        1,
        room1.GetRunningPCastGuests()
    );
}