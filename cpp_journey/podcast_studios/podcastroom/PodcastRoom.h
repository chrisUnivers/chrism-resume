#ifndef PODCASTROOM_H
#define PODCASTROOM_H

#include <string>
#include <iostream>

class PodcastRoom {
private:
    std::string podcast_floor_name_;
    std::string podcast_room_num_;

    
    bool prm_use_status_;
    // Addons
    std::string rao_control_setup_;
    std::string rao_seats_layout_;
    int rao_num_of_laptops_;
    
    friend class PodcastHost;
    friend class PodPodcast;

    friend class PodPodcastBuilder;
    friend class RoomAddOnsBuilder;
    friend class PodcastRoomBuilder;
    
    PodcastRoom() = default;
    
public:
    bool GetPodRoomStatus() { return prm_use_status_; }

    std::string GetRoomAddOnControlSetUp() { return rao_control_setup_; }
    std::string GetRoomNum() const {
        return podcast_room_num_;
    }
};

#endif /* PODCASTROOM_H */