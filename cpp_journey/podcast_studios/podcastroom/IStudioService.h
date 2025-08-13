#ifndef I_STUDIO_SRV_H //StudioService
#define I_STUDIO_SRV_H


#include "PodcastCalls.h"

class IStudioService {
public:
    virtual ~IStudioService() = default;
    virtual void initOutput(PodastGoLiveCallback) = 0;
    virtual int validSignedUpPodcast(std::string id) = 0;
};
#endif // I_STUDIO_SRV_H