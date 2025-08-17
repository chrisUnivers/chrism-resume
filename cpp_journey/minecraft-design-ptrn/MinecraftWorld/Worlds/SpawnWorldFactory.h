#ifndef SPAWN_WORLD_FACTORY_H
#define SPAWN_WORLD_FACTORY_H

#include "WorldFactory.h"
#include <numeric>

#include "../Utils/MineUtils.h"
#include "../Biomes/MainBiome.h"

using vecPtrBiomes = std::vector<std::unique_ptr<MinecraftBiome>>;
class SpawnWorldFactory : public WorldFactory {
private:
    void addBiome(BiomesFactory& bfactory, int countB, BiomeVariationTypes varType, vecPtrBiomes& vBio) {
        std::unique_ptr<MinecraftBiome> plpB;
        MainBiome mainB;
        for (int i = 0; i < countB; i++) {
            plpB = mainB.createBiome(bfactory, varType);
            vBio.push_back(std::move(plpB));
        }
    }
    void createWorldBiomes(vecPtrBiomes& vBiomes, BiomeTypes bioType, BiomeVariationTypes bVarType, int nbiomas) {
        switch(bioType) {
        case BiomeTypes::BIOME_PLAINS_BIOME: {

            switch(bVarType) {
            case BiomeVariationTypes::BIOMEPL_PLAINS: {
                std::unique_ptr<BiomesFactory> bFactory;
                bFactory = std::make_unique<PlainsBiomeFactory>();
                addBiome(*bFactory, nbiomas, bVarType, vBiomes);
            }
            default:
                break;
            }

        }
        }
    }
public:
    std::unique_ptr<MinecraftWorldInfo> createWorldInfo(std::vector<int>& numbiomes, std::string worldname, WorldTypeNames worldtype) override {
        switch (worldtype) {
        case WorldTypeNames::SPAWN_WORLD: {
            int id = MineUtils::generateRandomId();
            int seed = MineUtils::generateRandomId();
            vecPtrBiomes uniqueBiomes;
            
            createWorldBiomes(uniqueBiomes, BiomeTypes::BIOME_PLAINS_BIOME, BiomeVariationTypes::BIOMEPL_PLAINS, numbiomes[0]);
            return std::make_unique<MinecraftWorldInfo>(id, seed, uniqueBiomes, worldname, worldtype);
        }
        default:
            std::cout << "Provided type does not match a valid type" << std::endl;
            return nullptr;
        }   
    }
};
#endif // SPAWN_WORLD_FACTORY_H