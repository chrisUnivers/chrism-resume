#ifndef POD_PODCAST_H
#define POD_PODCAST_H


#include <vector>
#include "PodcastHost.h"

struct PodGuest {
    std::string first_name_;
    std::string last_name_;
    std::string contact_email_;
    std::string social_handle_;
};

class PodPodcast {
private:
    friend class PodcastRoom;
    std::string pcast_name_;
    std::string pcast_description_;
    std::string pcast_type_;
    
    std::vector<PodcastHost> pcast_hosts_;
    std::string pcast_schedule_;
    std::vector<PodGuest> pcast_guests_;
    std::string pcast_id_;
    PodPodcast() = default;
public:
    PodPodcast& SetPCastName(std::string_view pcast_name) {
        pcast_name_ = pcast_name; 
        return *this; 
    }
    PodPodcast& SetPCastDescirpt(std::string_view pcast_descr) {
        pcast_description_ = pcast_descr; 
        return *this; 
    }
    PodPodcast& SetPCastType(std::string_view floor_name) {
        pcast_type_ = floor_name;
        return *this; 
    
    }

    PodPodcast& SetPCastHost(const PodcastHost host) {
        pcast_hosts_.push_back(host);
        return *this;
    }
    PodPodcast& SetPCastGuest(const PodGuest guest) {
        pcast_guests_.push_back(guest);
        return *this;
    }
    PodPodcast& SetPCastSchedule(std::string_view schedule) {
        pcast_schedule_ = schedule;
        return *this;
    }
    PodPodcast& SetPCastId(std::string_view id) {
        pcast_id_ = id;
        return *this;
    }

    std::string getPCastName() const {
        return pcast_name_;
    }
    std::string getPCastDescr() const {
        return pcast_description_;
    }
    bool hasHosts() const {
        return pcast_hosts_.empty();
    }

    std::vector<PodcastHost> getHosts() const {
        return pcast_hosts_;
    }
    std::vector<PodGuest> getGuestList() const {
        return pcast_guests_;
    }
};

#endif // POD_PODCAST_H