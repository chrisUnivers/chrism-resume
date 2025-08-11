#ifndef EVENT_CALLABLE_H
#define EVENT_CALLABLE_H


#include <functional>

#include "StudioPodcast.h"

struct GoLiveEvent {
    PodcastInfo info_;
    std::ostream& outputConsole_;
    std::string goLiveMessage_;
};

typedef std::function<void(const GoLiveEvent&)> PodastGoLiveCallback;

#endif // EVENT_CALLABLE_H