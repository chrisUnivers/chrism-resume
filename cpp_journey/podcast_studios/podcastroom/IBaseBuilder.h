#ifndef I_BaseBuilder_H
#define I_BaseBuilder_H


#include "PodcastRoom.h"

class IBaseBuilder {
protected:
    PodcastRoom& prm_;
public:
    explicit IBaseBuilder(PodcastRoom& prm) : prm_(prm) {}
    operator PodcastRoom() {
        if (!prm_.prm_use_status_) {
            std::cout << "room must be free to use" << std::endl;
        }
        return std::move(prm_);
    }
    RoomAddOnsBuilder MyAddOns();
    PodPodcastBuilder MyPodcast();
};

#endif /* I_BaseBuilder_H */