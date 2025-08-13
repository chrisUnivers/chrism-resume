#ifndef PODCAST_EVENTS_H
#define PODCAST_EVENTS_H


#include <map>
#include "PodcastRoom.h"
#include "IStudioService.h"

class StudioService : public IStudioService {
public:
    std::map<std::string, PodcastInfo> signedInPodcasts_;
    PodastGoLiveCallback podcastGoesLiveCall_{};
    void initOutput(PodastGoLiveCallback goLiveCall) override {
        podcastGoesLiveCall_ = goLiveCall;
    }
    int validSignedUpPodcast(std::string id) override { return signedInPodcasts_.count(id); }
};

#endif //PODCAST_EVENTS_H