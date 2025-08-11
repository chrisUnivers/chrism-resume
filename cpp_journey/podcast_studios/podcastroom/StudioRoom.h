#ifndef STUDIO_ROOM_H
#define STUDIO_ROOM_H

#include <iostream>
#include <string>


#include "IBaseBuilder.h"

#include <string_view>
#include <vector>

class IBaseBuilder;
class PodcastRoomBuilder;
class RoomAddOnsBuilder;
class StudioPodcastBuilder;

class PodcastRoomBuilder : public IBaseBuilder {
public:
    PodcastRoomBuilder(StudioPodcast& pcast) : IBaseBuilder(pcast) {}

    PodcastRoomBuilder& SetUseStatus(bool use_status) { basePCast_.pcast_room_.prm_use_status_ = use_status; return *this; }

    PodcastRoomBuilder& SetPodFloorName(std::string_view floor_name ) { basePCast_.pcast_room_.podcast_floor_name_ = floor_name; return *this; }

    PodcastRoomBuilder& SetPodRoomNum(std::string_view room_num) { basePCast_.pcast_room_.podcast_room_num_ = room_num; return *this; }
};
PodcastRoomBuilder IBaseBuilder::MyPodcastRoom() { return PodcastRoomBuilder(basePCast_); }

class RoomAddOnsBuilder : public IBaseBuilder {
public:
    explicit RoomAddOnsBuilder(StudioPodcast& pcast) : IBaseBuilder(pcast) {}
    RoomAddOnsBuilder& SetControlSetup(std::string_view control_setup) { basePCast_.pcast_room_.rao_control_setup_ = control_setup; return *this; }
    RoomAddOnsBuilder& SetSeatLayOut(std::string_view layout) { basePCast_.pcast_room_.rao_seats_layout_ = layout; return *this; }
    RoomAddOnsBuilder& SetNumOfLaptops(int num_laptops) { basePCast_.pcast_room_.rao_num_of_laptops_ = num_laptops; return *this; }

};
RoomAddOnsBuilder IBaseBuilder::MyAddOns() { return RoomAddOnsBuilder(basePCast_); }

class StudioPodcastBuilder : public IBaseBuilder {
private:
    StudioPodcast podcast_;
    int validated_add_guests(std::vector<PodGuest const *> &guests) {
        int valid = 0;
        if(guests.empty()) {
            
        } else {
            for (const PodGuest* guest : guests) {
                basePCast_.SetPCastGuest(*guest);
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
                basePCast_.SetPCastHost(*host);
            }
            valid = 1;
        }
        return valid;
    }
public:
    StudioPodcastBuilder() : IBaseBuilder(podcast_) {}
    
    StudioPodcastBuilder& SetPodcastName(std::string_view podcast_name) { basePCast_.SetPCastName(podcast_name) ; return *this; }
    
    StudioPodcastBuilder& SetPodcastDescription(std::string_view pod_descrp) { basePCast_.SetPCastDescirpt(pod_descrp); return *this; }
    
    StudioPodcastBuilder& SetPodcastHosts(std::vector<PodcastHost const *> hosts = {}) { int v = validate_hosts(hosts); return *this; }
    
    StudioPodcastBuilder& SetPodcastGuest(std::vector<PodGuest const *> guests = {}) { int v = validated_add_guests(guests); return *this; }

    StudioPodcastBuilder& SetPodcastType(std::string_view pcast_type) { basePCast_.SetPCastType(pcast_type); return *this; }

    StudioPodcastBuilder& SetPodcastId(std::string_view pcast_id) { basePCast_.SetPCastId(pcast_id); return *this; }

    StudioPodcastBuilder& SetPodcastSchedule(std::string_view pcast_schedule) { basePCast_.SetPCastSchedule(pcast_schedule); return *this; }
};

#endif