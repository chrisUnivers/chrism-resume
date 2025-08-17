#ifndef I_WORLD_FACTORY_UTILS_H
#define I_WORLD_FACTORY_UTILS_H


#include "../Biomes/MainBiome.h"

class IWorldFactoryUtils {
public: 
    virtual void addBiome(BiomesFactory& bfactory, int countB, BiomeVariationTypes varType, std::vector<std::unique_ptr<MinecraftBiome>>& vBio) = 0;
    virtual void createWorldBiomes(std::vector<std::unique_ptr<MinecraftBiome>>& vBiomes, BiomeTypes bioType, BiomeVariationTypes bVarType, int nbiomas) = 0;
};
#endif // I_WORLD_FACTORY_UTILS_H