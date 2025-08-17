#ifndef WORLD_FACTORY_H
#define WORLD_FACTORY_H

#include <iostream>
#include <memory>
#include "../Biomes/MinecraftBiome.h"
#include "MinecraftWorld.h"

struct MinecraftWorldInfo {
    int                                          worldId_;
    int                                          worldSeed_;
    std::vector<std::unique_ptr<MinecraftBiome>> worldBiomes_;
    std::string                                  worldName_;
    WorldTypeNames                               worldType_;
    MinecraftWorldInfo(int id, int seed, const std::vector<std::unique_ptr<MinecraftBiome>>& biomes, std::string name, WorldTypeNames type) {
        worldId_ = id;
        worldSeed_ = seed;
        // worldBiomes_ = biomes;
        worldName_ = name;
        worldType_ = type;
        
    };
};
class WorldFactory {
public:
    virtual ~WorldFactory() = default;

    virtual std::unique_ptr<MinecraftWorldInfo> createWorldInfo(std::vector<int>& numbiomes, std::string worldname, WorldTypeNames worldName) = 0;
};
#endif // WORLD_FACTORY_H