#ifndef AUTHO_INFO_H
#define AUTHO_INFO_H

#include <map>
#include <string>
#include <vector>
#include <memory>
#include "PodPodcast.h"

inline std::map<std::string, PodPodcast> & getSignedUpPodcasts() {
    static std::map<std::string, PodPodcast> signedUpPodcasts_;
    return signedUpPodcasts_;
}

inline std::string SetOfficialPodcats(const PodPodcast& podcastO) {
    auto & sdpPodcasts = getSignedUpPodcasts();
    sdpPodcasts.emplace(podcastO.getPodcastId(), podcastO);
    return podcastO.getPodcastId();
}


inline std::vector<std::string> & getOnPremise() {
    static std::vector<std::string> onPremiseAuthoIds_;
    return onPremiseAuthoIds_;
}

inline void SetOnPremise(std::string& podcastId) {
    auto & pdcOnPremise = getOnPremise();
    pdcOnPremise.emplace_back(podcastId);
}

inline int getSizeSignedUpPodcasts() {
    auto & sdpPodcasts = getSignedUpPodcasts();
    return sdpPodcasts.size();
}

inline std::string getSpecificPodcastId(int podcast_s) {
    auto & sdpPodcasts = getSignedUpPodcasts();
} 
#endif // AUTHO_INFO_H