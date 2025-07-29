#ifndef POD_ROOM_FX_TEST_H
#define POD_ROOM_FX_TEST_H

#include "../podcastroom/PodPodcast.h"
#include <vector>
#include <gtest/gtest.h>

class PodRoomTest : public testing::Test {
protected:
    using mStr = std::string;
    PodRoomTest() {
        HostInputTest h1 = HostInputTest("Host1", "Tech", "250-638-386", "hostnew@gmail.com", "", "");
        GuestTest g1 = GuestTest("gfName", "glName", "gcEmail", "gsHandle");
        GuestTest g2 = GuestTest("gTwo_fName", "gTwo_lName", "gTwo_email", "gTwo_sHandle");
        host1Fx_ = PodcastHost().SetFirstName(h1.fNameT_).SetLastName(h1.lNameT_).SetEmail(h1.emailT_).SetPhoneNum(h1.phoneNumT_);
        guest1Fx_ = {g1.fNameT_, g1.lNameT_, g1.emailT_, g1.socialsT_};
        guest2Fx_ = {g2.fNameT_, g2.lNameT_, g2.emailT_, g2.socialsT_};
        cntrsetup1Fx_ = "Modarn-Setup";
        podDescr1Fx_ = "A podcast about mindful thinking!";
        podName1Fx_ = "Morning-Podcast";

    }
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
    PodcastHost host1Fx_;
    PodGuest guest1Fx_;
    PodGuest guest2Fx_;

    mStr cntrsetup1Fx_;
    mStr podDescr1Fx_ ;
    mStr podName1Fx_  ;
};
#endif //POD_ROOM_FX_TEST_H