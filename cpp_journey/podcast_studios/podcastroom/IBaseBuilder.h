#ifndef I_BaseBuilder_H
#define I_BaseBuilder_H


#include "PodPodcast.h"

class IBaseBuilder {
protected:
    PodPodcast& basePCast_;
public:
    explicit IBaseBuilder(PodPodcast& pcast) : basePCast_(pcast) {}
    operator PodPodcast&() {
        if (basePCast_.pcast_hosts_.empty()) {
            std::cout << "Podcast must have a host" << std::endl;
        }
        return std::move(basePCast_);
    }
    RoomAddOnsBuilder MyAddOns();
    PodcastRoomBuilder MyPodcastRoom();
    
};

#endif /* I_BaseBuilder_H */