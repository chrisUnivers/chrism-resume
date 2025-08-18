#ifndef WORLD_FACTORY_UTILS_H
#define WORLD_FACTORY_UTILS_H


#include "IWorldFactoryUtils.h"
class WorldFactoryUtils : IWorldFactoryUtils {
public:
    void addBiome(BiomesFactory& bfactory, int countB, BiomeVariationTypes varType, std::vector<std::unique_ptr<MinecraftBiome>>& vBio) override{
        std::unique_ptr<MinecraftBiome> plpB;
        MainBiome mainB;
        for (int i = 0; i < countB; i++) {
            plpB = mainB.createBiome(bfactory, varType);
            vBio.push_back(std::move(plpB));
        }
    }

    void createWorldBiomes(std::vector<std::unique_ptr<MinecraftBiome>>& vBiomes, BiomeTypes bioType, BiomeVariationTypes bVarType, int nbiomes) override {
        switch(bioType) {
        case BiomeTypes::BIOME_PLAINS_BIOME: {
            switch(bVarType) {
                
            case BiomeVariationTypes::BIOMEPL_PLAINS: {
                std::unique_ptr<BiomesFactory> bFactory;
                int countPlainsBiomes = nbiomes;
                bFactory = std::make_unique<PlainsBiomeFactory>();
                addBiome(*bFactory, nbiomes, bVarType, vBiomes);
            }
            default:
                break;
            }

        }
        }
    }
};
#endif // WORLD_FACTORY_UTILS_H