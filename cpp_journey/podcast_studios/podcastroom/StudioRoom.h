#ifndef POD_ROOM_H
#define POD_ROOM_H

#include <iostream>
#include <string>


#include "IBaseBuilder.h"

#include <string_view>
#include <vector>

class IBaseBuilder;
class PodcastRoomBuilder;
class RoomAddOnsBuilder;
class PodPodcastBuilder;

class PodcastRoomBuilder : public IBaseBuilder {
private:
    PodcastRoom podcast_room_;

public:
    PodcastRoomBuilder() : IBaseBuilder(podcast_room_) {}

    PodcastRoomBuilder& SetUseStatus(bool use_status) { prm_.prm_use_status_ = use_status; return *this; }

    PodcastRoomBuilder& SetPodFloorName(std::string_view floor_name ) { prm_.podcast_floor_name_ = floor_name; return *this; }

    PodcastRoomBuilder& SetPodRoomNum(std::string_view room_num) { prm_.podcast_room_num_ = room_num; return *this; }
};

class RoomAddOnsBuilder : public IBaseBuilder {
public:
    explicit RoomAddOnsBuilder(PodcastRoom& prm) : IBaseBuilder(prm) {}

    RoomAddOnsBuilder& SetControlSetup(std::string_view control_setup) { prm_.rao_control_setup_ = control_setup; return *this; }
    
    RoomAddOnsBuilder& SetSeatLayOut(std::string_view layout) { prm_.rao_seats_layout_ = layout; return *this; }
    
    RoomAddOnsBuilder& SetNumOfLaptops(int num_laptops) { prm_.rao_num_of_laptops_ = num_laptops; return *this; }

};
RoomAddOnsBuilder IBaseBuilder::MyAddOns() { return RoomAddOnsBuilder(prm_); }


class PodPodcastBuilder : public IBaseBuilder {
private:
    int validate_guests(std::vector<PodGuest const *> &guests) {
        int valid = 0;
        if(guests.empty()) {
        } else {
            for (const PodGuest* guest : guests) {
                prm_.running_pod_.SetPCastGuest(*guest);
            }
            valid = 1;
        }
        return valid;
    }
    int validate_hosts(std::vector<PodcastHost const *> &hosts) {
        int valid = 0;
        if (hosts.empty()) {
        } else {
            for (const PodcastHost* host : hosts) {
                prm_.running_pod_.SetPCastHost(*host);
            }
            valid = 1;
        }
        return valid;
    }
    public:
    explicit PodPodcastBuilder(PodcastRoom& prm) : IBaseBuilder(prm) {}
    
    PodPodcastBuilder& SetPodcastName(std::string_view podcast_name) { prm_.running_pod_.SetPCastName(podcast_name) ; return *this; }
    
    PodPodcastBuilder& SetPodcastDescription(std::string_view pod_descrp) { prm_.running_pod_.SetPCastDescirpt(pod_descrp); return *this; }
    
    PodPodcastBuilder& SetPodcastHosts(std::vector<PodcastHost const *> hosts = {}) { int v = validate_hosts(hosts); return *this; }
    
    PodPodcastBuilder& SetPodcastGuest(std::vector<PodGuest const *> guests = {}) { int v = validate_guests(guests); return *this; }

    PodPodcastBuilder& SetPodcastType(std::string_view pcast_type) { prm_.running_pod_.SetPCastType(pcast_type); return *this; }

    PodPodcastBuilder& SetPodcastId(std::string_view pcast_id) { prm_.running_pod_.SetPCastId(pcast_id); return *this; }

    PodPodcastBuilder& SetPodcastSchedule(std::string_view pcast_schedule) { prm_.running_pod_.SetPCastSchedule(pcast_schedule); return *this; }
};
PodPodcastBuilder IBaseBuilder::MyPodcast() { return PodPodcastBuilder(prm_); }

#endif