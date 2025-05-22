#ifndef UNIQUE_WORLD_H
#define UNIQUE_WORLD_H

#include <thread>
#include <string>
#include <future>
#include <chrono>
#include "World.h"
#include "MinecraftWorld.h"
#include "../Utils/ItemStructs.h"
#include "../Biomes/PlainsBiome.h"
#include "../Utils/ItemNames.h"
#include "PureWorld.h"

class UniqueWorld : public World {
public:
    UniqueWorld();
    virtual ~UniqueWorld() = default;
    void CreateWorld(const std::string& world_name, std::unique_ptr<PureWorld>& world, const WorldAttributes& attributes) const override;
    void ListWorldItems(std::unique_ptr<PureWorld>&world) const override;
};

#endif