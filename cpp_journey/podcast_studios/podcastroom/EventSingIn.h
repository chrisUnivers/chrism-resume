#ifndef EVENT_SING_IN_H
#define EVENT_SING_IN_H

#include "StudioService.h"
class EventSingIn {
private:
    int numSignedInPodcast_;
    
public:
    EventSingIn(IStudioService& signInEvent) : numSignedInPodcast_{} {}
};

#endif // EVENT_SING_IN_H