#ifndef POD_PODCAST_H
#define POD_PODCAST_H

#include <vector>
#include "PodcastHost.h"
#include "PodcastRoom.h"

struct PodGuest {
    std::string first_name_;
    std::string last_name_;
    std::string contact_email_;
    std::string social_handle_;
};

struct PodcastSummary {
    std::string podName;
    std::string csvHostsName;
    std::string usedRoom;
    std::string startTime;
    std::string endTime;
};

class PodPodcast {
private:
    friend class IBaseBuilder;
    friend class RoomAddOnsBuilder;
    friend class PodPodcastBuilder; 
    friend class PodcastRoomBuilder;
    friend class PodcastRoom;
    
    std::string pcast_name_;
    std::string pcast_description_;
    std::string pcast_type_;
    
    std::vector<PodcastHost> pcast_hosts_;
    std::string pcast_schedule_;
    std::vector<PodGuest> pcast_guests_;
    std::string pcast_id_;
    PodcastRoom pcast_room_;
    PodPodcast() = default;
public:
    friend std::ostream& operator<<(std::ostream& out, const PodPodcast& p) {
        auto print_value = [&](const auto& vl) { out << vl << " "; };

        out << "Room Info: ";
        print_value(p.pcast_name_);
        print_value(p.pcast_room_.GetRoomNum());
        out << std::endl;

        out << "Podcast Info: ";
        print_value(p.pcast_id_);
        print_value(p.pcast_description_);
        out << std::endl;

        if (!p.pcast_hosts_.empty()) {
            out << "Hosted by: " << std::endl;
            for (const PodcastHost& host : p.pcast_hosts_) {
                out << " " << host.getFirstName() << host.getLastName() << std::endl;
            }
        }
        return out;
    }
    
    void SetPCastName(std::string_view pcast_name) {
        pcast_name_ = pcast_name; 
    }
    void SetPCastDescirpt(std::string_view pcast_descr) {
        pcast_description_ = pcast_descr; 
    }
    void SetPCastType(std::string_view floor_name) {
        pcast_type_ = floor_name;
    
    }

    void SetPCastHost(const PodcastHost host) {
        pcast_hosts_.push_back(host);
    }
    void SetPCastGuest(const PodGuest guest) {
        pcast_guests_.push_back(guest); 
    }
    void SetPCastSchedule(std::string_view schedule) {
        pcast_schedule_ = schedule;
    }
    void SetPCastId(std::string_view id) {
        pcast_id_ = id;
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
    int getHostCount() const {
        return pcast_hosts_.size();
    }
    int getGuestsCount() const {
        return pcast_guests_.size();
    }

    std::string getControlRoomSetup() {
        return pcast_room_.GetRoomAddOnControlSetUp();
    }
    bool getPodcastLiveStatus() {
        return pcast_room_.GetPodRoomStatus();
    }
};

#endif // POD_PODCAST_H