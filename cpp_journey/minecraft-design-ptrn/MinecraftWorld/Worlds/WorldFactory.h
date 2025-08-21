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
    std::vector<WorldTree>                       worldTrees_;
    std::string                                  worldName_;
    MinecraftWorldInfo(int id, int seed, std::vector<std::unique_ptr<MinecraftBiome>>& biomes, std::string name, std::vector<WorldTree>& wldTrees, WorldTypeNames type) {
        worldId_ = id;
        worldSeed_ = seed;
        worldType_ = type;
        worldName_ = name;

        worldTrees_ = wldTrees;
        for ( auto& biome : biomes) { worldBiomes_.push_back(std::move(biomes[0])); }

    };
};

using vecTplBiomes = std::tuple<int, BiomeVariationTypes>;
using baseBiomeTplBiome = std::tuple<BiomeTypes, vecTplBiomes>;
using treeTypeTpl = std::tuple<int, WorldTreeType>;
class WorldFactory {
public:
    virtual ~WorldFactory() = default;

    virtual std::unique_ptr<MinecraftWorldInfo> createWorldInfo(std::vector<baseBiomeTplBiome> allBiomes, std::vector<treeTypeTpl>& treeTpls, int numOfAllTrees, std::string worldname, WorldTypeNames worldName) = 0;
};

#endif // WORLD_FACTORY_H