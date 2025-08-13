#include "EventSingIn.h"

int EventSingIn::numSignedInPodcast_ = 0;

EventSingIn::EventSingIn(IStudioService& signInEvent) {
    signInEvent.initOutput([this, &signInEvent](const GoLiveEvent& goLive) { 
        goLive.outputConsole_ << goLive.goLiveMessage_ << std::endl;
        if (signInEvent.validSignedUpPodcast(goLive.info_.podCastId_)) {
            goLive.outputConsole_ << goLive.info_ << " just signed in!" << std::endl;
            numSignedInPodcast_++;
        }
    }); // for console output!
}

int EventSingIn::getNumSignedInPodcast() {
    return numSignedInPodcast_;
} 