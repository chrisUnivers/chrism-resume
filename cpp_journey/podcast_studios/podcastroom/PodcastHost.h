#ifndef PODCAST_HOST_H
#define PODCAST_HOST_H

#include <string>
#include <string_view>

class PodcastHost {
private:
    friend class PodcastRoom;
    std::string first_name_;
    std::string last_name_;
    std::string phone_num_;
    std::string contact_email_;
    std::string host_id_;
    std::string host_social_handle_;
public:
    PodcastHost() = default;
    PodcastHost& SetFirstName(std::string_view fname) { 
        first_name_ = fname; 

        return *this; 
    };
    PodcastHost& SetLastName(std::string_view lname) {
        last_name_ = lname;
        return *this;
    }
    PodcastHost& SetPhoneNum(std::string_view phone_num) {
        phone_num_ = phone_num;
        return *this;
    }

    PodcastHost& SetEmail(std::string_view email) {
        contact_email_ = email;
        return *this;
    }
    PodcastHost& SetHostId(std::string_view id) {
        host_id_ = id;
        return *this;
    }
    PodcastHost& SetSocials(std::string_view socials) {
        host_social_handle_ = socials;
        return *this;
    }

    std::string getFirstName() const {
        return first_name_;
    }
    std::string getLastName() const {
        return last_name_;
    }
};

#endif // PODCAST_HOST_H