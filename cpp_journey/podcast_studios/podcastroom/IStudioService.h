#ifndef I_STUDIO_SRV_H //StudioService
#define I_STUDIO_SRV_H


#include <iostream>
#include <map>
class IStudioService {
public:
    virtual ~IStudioService() = default;
    virtual int validSignedUpPodcast(std::string id) = 0;
};

#endif // I_STUDIO_SRV_H