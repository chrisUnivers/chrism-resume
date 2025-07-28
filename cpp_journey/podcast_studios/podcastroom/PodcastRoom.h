#ifndef PODCASTROOM_H
#define PODCASTROOM_H


#include "PodPodcast.h"
#include <string>
#include <iostream>


class PodcastRoom {
private:
    std::string podcast_floor_name_;
    std::string podcast_room_num_;
    PodPodcast running_pod_;
    bool prm_use_status_;
    // Addons
    std::string rao_control_setup_;
    std::string rao_seats_layout_;
    int rao_num_of_laptops_;
    
    
    friend class IBaseBuilder;
    friend class PodcastRoomBuilder;
    friend class PodPodcastBuilder;
    friend class RoomAddOnsBuilder;
    friend class PodcastHost;
    friend class PodPodcast;
    
    PodcastRoom() = default;
    
public:
    friend std::ostream& operator<<(std::ostream& out, const PodcastRoom& p) {
        auto print_value = [&](const auto& vl) { out << vl << " "; };

        out << "Room Info: ";
        print_value(p.podcast_floor_name_);
        print_value(p.podcast_room_num_);
        out << std::endl;

        out << "Podcast Info: ";
        print_value(p.running_pod_.getPCastName());
        print_value(p.running_pod_.getPCastDescr());
        out << std::endl;

        if (!p.running_pod_.hasHosts()) {
            out << "Hosted by: " << std::endl;
            for (const PodcastHost& host : p.running_pod_.getHosts()) {
                out << " " << host.getFirstName() << host.getLastName() << std::endl;
            }
        }
        return out;
    }

    int GetRunningPCastHosts() const { return running_pod_.pcast_hosts_.size(); }
    
    int GetRunningPCastGuests() const { return running_pod_.getGuestList().size(); }
    
    bool GetPodRoomStatus() { return prm_use_status_; }
    
    std::string GetRoomAddOnControlSetUp() { return rao_control_setup_; }

    std::string GetRunningPCastName() { return running_pod_.pcast_name_; }
};

#endif /* PODCASTROOM_H */