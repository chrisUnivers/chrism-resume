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

    void createWorldBiomes(std::vector<std::unique_ptr<MinecraftBiome>>& vBiomes, std::vector<baseBiomeTplBiome> allBiomes) override {
        int s = allBiomes.size();
        for (int i = 0; i < s; i++) {
            auto[baseType, varBioCountTpl] = allBiomes[i];

            switch(baseType) {
            case BiomeTypes::BIOME_PLAINS_BIOME: {
                std::unique_ptr<BiomesFactory> factory = std::make_unique<PlainsBiomeFactory>();
                processBiomes(varBioCountTpl, vBiomes, *factory);
                break;
            }
            case BiomeTypes::BIOME_WOODLANDS_BIOME: {
                std::unique_ptr<BiomesFactory> factory = std::make_unique<WoodLandsBiomeFactory>();
                processBiomes(varBioCountTpl, vBiomes, *factory);
                break;
            }
            default:
                std::cout << "WorldFactoryUtils: Provided type does not match a valid biome type. " << std::endl;
                break;
            }
        }
    }

    void processBiomes(vecTplBiomes varBioCountTpl, std::vector<std::unique_ptr<MinecraftBiome>>& vBiomes, BiomesFactory& bFactory) {
        auto[numOfB, bvartype] = varBioCountTpl;
        switch(bvartype) {
        case BiomeVariationTypes::BIOMEPL_PLAINS: {
            addBiome(bFactory, numOfB, bvartype, vBiomes);
            break;
        }
        default:
            std::cout << "WorldFactoryUtils: processBiomes" << std::endl;
            break;
        }
    }
        
};
#endif // WORLD_FACTORY_UTILS_H