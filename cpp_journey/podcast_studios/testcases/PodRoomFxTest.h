#ifndef POD_ROOM_FX_TEST_H
#define POD_ROOM_FX_TEST_H

#include "../podcastroom/PodPodcast.h"
#include <vector>
#include <gtest/gtest.h>
class PodRoomTest : public testing::Test {
protected:
    using mStr = std::string;
    PodRoomTest() {
        HostInputTest host1 = HostInputTest("Host1", "Tech", "250-638-386", "hostnew@gmail.com", "", "");
        GuestTest g1 = GuestTest("gfName", "glName", "gcEmail", "gsHandle");
        GuestTest g2 = GuestTest("gTwo_fName", "gTwo_lName", "gTwo_email", "gTwo_sHandle");
        mStr setPcast1 = "Modarn-Setup";
        podcastInputs_[podCount_].hostInputsFx_.emplace_back(host1);    // First Podcast
        podcastInputs_[podCount_].guestInputsFx_.emplace_back(g1);       // First Podcast
        podcastInputs_[podCount_].guestInputsFx_.emplace_back(g2);       // First Podcast
        podcastInputs_[podCount_].podCntrlSetupFx_.emplace_back(setPcast1); // First Podcast
    }

    struct HostInputTest;
    struct GuestTest;
    struct PodCastInputTest {
        std::vector<HostInputTest> hostInputsFx_;
        std::vector<GuestTest>     guestInputsFx_;
        std::vector<mStr>          podCntrlSetupFx_;
    };
    struct HostInputTest{
        mStr fNameT_ {};
        mStr lNameT_ {};
        mStr phoneNumT_ {};
        mStr emailT_ {};
        mStr socialsT_ {};
        mStr idT_ {};
        HostInputTest(mStr fN, mStr lN, mStr phn, mStr em, mStr soc, mStr id) : fNameT_(fN), lNameT_(lN), phoneNumT_(phn), emailT_(em), socialsT_(soc), idT_(id) { }
    };
    struct GuestTest {
        mStr fNameT_ {};
        mStr lNameT_ {};
        mStr emailT_ {};
        mStr socialsT_ {};
        GuestTest(mStr fN, mStr lN, mStr em, mStr soc) : fNameT_(fN), lNameT_(lN), emailT_(em), socialsT_(soc) { }
    };
    int podCount_ = 0;
    std::map<int, PodCastInputTest> podcastInputs_   {};
};
#endif //POD_ROOM_FX_TEST_H