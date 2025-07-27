#include "../podcastroom/StudioRoom.h"

#include <gtest/gtest.h>

TEST(builder_test, PodcastPodBuilder) {
    PodcastRoom room1 = PodcastRoomBuilder().SetUseStatus(true);
    bool expectedStatus = true;
    
    EXPECT_EQ(
        expectedStatus,
        room1.GetPodRoomStatus()
    );
}

TEST(builder_test, RoomAddOnsBuilder) {
    PodcastRoom room1 = PodcastRoomBuilder().SetUseStatus(true).MyAddOns().SetControlSetup("Modarn-Setup").MyPodcast().SetPodcastName("Morning-Podcast");
    
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

TEST(builder_test, PodPodcastBuilder) {
    PodcastHost host = PodcastHost().SetFirstName("Maya").SetLastName("Tech").SetPhoneNum("250-638-386").SetEmail("mayawithtech@gmail.com");
    PodcastRoom room1 = PodcastRoomBuilder().SetUseStatus(true).MyAddOns().SetControlSetup("Modarn-Setup").MyPodcast().SetPodcastName("Morning-Podcast").SetPodcastDescription("A podcast about mindful thinking!");
    int expecteNumPCastHosts = 1;

    EXPECT_EQ(
        expecteNumPCastHosts,
        room1.GetRunningPCastHosts()
    );
}

TEST(builder_test, SetPodcastGuest_PodPodcastBuilder) {
    PodcastHost host = PodcastHost().SetFirstName("Maya").SetLastName("Tech").SetPhoneNum("250-638-386").SetEmail("mayawithtech@gmail.com");
    PodGuest guestOne = {"gfName", "glName", "gcEmail", "gsHandle"};
    PodcastRoom room1 = PodcastRoomBuilder().SetUseStatus(true);
}