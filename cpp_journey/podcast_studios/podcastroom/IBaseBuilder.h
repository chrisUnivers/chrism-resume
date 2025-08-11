#ifndef I_BaseBuilder_H
#define I_BaseBuilder_H


#include "StudioPodcast.h"

class IBaseBuilder {
protected:
    StudioPodcast& basePCast_;
public:
    explicit IBaseBuilder(StudioPodcast& pcast) : basePCast_(pcast) {}
    operator StudioPodcast&() {
        if (basePCast_.pcast_hosts_.empty()) {
            std::cout << "Podcast must have a host" << std::endl;
        }
        return std::move(basePCast_);
    }
    RoomAddOnsBuilder MyAddOns();
    PodcastRoomBuilder MyPodcastRoom();
    
};

#endif /* I_BaseBuilder_H */