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
    MinecraftWorldInfo(int id, int seed, std::vector<std::unique_ptr<MinecraftBiome>>& biomes, std::string name, std::vector<WorldTree> trees, WorldTypeNames type) {
        worldId_ = id;
        worldSeed_ = seed;
        worldType_ = type;
        worldName_ = name;

        worldTrees_ = trees;
        worldBiomes_.push_back(std::move(biomes[0]));
        
    };
};

struct WorldTree {
    int              treeId_;
    std::string      treeName_;
    WorldTreeType    treeType_;
    double           plantRate_;
};

using vecTplBiomes = std::vector<std::tuple<int, BiomeVariationTypes>>;
class WorldFactory {
public:
    virtual ~WorldFactory() = default;

    virtual std::unique_ptr<MinecraftWorldInfo> createWorldInfo(std::vector<BiomeTypes> allBiomes, vecTplBiomes& numbiomes, std::vector<int>& numtrees, std::string worldname, WorldTypeNames worldName) = 0;
};

#endif // WORLD_FACTORY_H