#ifndef WORLD_H
#define WORLD_H


#include "PureWorld.h"

class World {
public:
    virtual ~World() = default;
    virtual void CreateWorld(const std::string& world_name, std::unique_ptr<PureWorld>&world) const = 0;
};

#endif