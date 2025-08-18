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

    void createWorldBiomes(std::vector<std::unique_ptr<MinecraftBiome>>& vBiomes, std::vector<BiomeTypes> allBiomes, vecTplBiomes nbiomes) override {
        for (BiomeTypes bioType: allBiomes) {
            switch(bioType) {
            case BiomeTypes::BIOME_PLAINS_BIOME: {

                for (auto bio_count : nbiomes) {
                    auto[numOfB, bvartype] = bio_count;
                    switch(bvartype) {
                    case BiomeVariationTypes::BIOMEPL_PLAINS: {
                        std::unique_ptr<BiomesFactory> bFactory;
                        int countPlainsBiomes = numOfB;
                        bFactory = std::make_unique<PlainsBiomeFactory>();
                        addBiome(*bFactory, numOfB, bvartype, vBiomes);
                    }
                    default:
                        break;
                    }
                }
                

            }
            }
        }
        
    }
};
#endif // WORLD_FACTORY_UTILS_H