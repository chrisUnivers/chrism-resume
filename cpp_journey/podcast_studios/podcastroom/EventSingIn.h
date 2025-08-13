#ifndef EVENT_SING_IN_H
#define EVENT_SING_IN_H


#include "StudioService.h"

class EventSingIn {
private:
    static int numSignedInPodcast_;
public:
    EventSingIn(IStudioService& signInEvent);
    
    static int getNumSignedInPodcast();
    
};

#endif // EVENT_SING_IN_H