#ifndef WORLD_H
#define WORLD_H

#include <future>
#include <thread>
#include "PureWorld.h"
#include "MinecraftWorld.h"


class World {
public:
    virtual ~World() = default;
    virtual void CreateWorld(const std::string& world_name, std::unique_ptr<MinecraftWorld>&world, WorldAttributes attributes) const = 0;
    virtual void ListWorldItems(std::unique_ptr<MinecraftWorld>&world) const = 0;
};
#endif