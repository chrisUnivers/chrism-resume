#ifndef PODCAST_EVENTS_H
#define PODCAST_EVENTS_H


#include "PodcastRoom.h"
#include "IStudioService.h"
#include "StudioPodcast.h"

class StudioService : public IStudioService {
public:
    std::map<std::string, PodcastInfo> signedInPodcasts_;
    
    int validSignedUpPodcast(std::string id) override { return signedInPodcasts_.count(id); }
};

#endif //PODCAST_EVENTS_H