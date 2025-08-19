#ifndef WORLD_FACTORY_H
#define WORLD_FACTORY_H

#include <iostream>
#include <memory>
#include "../Biomes/MinecraftBiome.h"
#include "MinecraftWorld.h"

struct MinecraftWorldInfo {
    int                                          worldId_;
    int                                          worldSeed_;
    WorldTypeNames                               worldType_;
    std::vector<std::unique_ptr<MinecraftBiome>> worldBiomes_;
    std::string                                  worldName_;
    MinecraftWorldInfo(int id, int seed, std::vector<std::unique_ptr<MinecraftBiome>>& biomes, std::string name, WorldTypeNames type) {
        worldId_ = id;
        worldSeed_ = seed;
        worldType_ = type;
        worldName_ = name;
        worldBiomes_.push_back(std::move(biomes[0]));

    };
};

using vecTplBiomes = std::tuple<int, BiomeVariationTypes>;
using baseBiomeTplBiome = std::tuple<BiomeTypes, vecTplBiomes>;
class WorldFactory {
public:
    virtual ~WorldFactory() = default;

    virtual std::unique_ptr<MinecraftWorldInfo> createWorldInfo(std::vector<baseBiomeTplBiome> allBiomes, std::string worldname, WorldTypeNames worldName) = 0;
};

#endif // WORLD_FACTORY_H