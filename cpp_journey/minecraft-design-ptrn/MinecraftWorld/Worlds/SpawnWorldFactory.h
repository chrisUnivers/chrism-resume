#ifndef SPAWN_WORLD_FACTORY_H
#define SPAWN_WORLD_FACTORY_H

#include "WorldFactory.h"
#include <numeric>
#include "../Utils/MineUtils.h"
#include "WorldFactoryUtils.h"


using vecPtrBiomes = std::vector<std::unique_ptr<MinecraftBiome>>;
class SpawnWorldFactory : public WorldFactory {
public:
    WorldFactoryUtils factoryUtils_;
    
    SpawnWorldFactory(WorldFactoryUtils utils) : factoryUtils_(utils) {};
    
    std::unique_ptr<MinecraftWorldInfo> createWorldInfo(std::vector<int>& numbiomes, std::string worldname, WorldTypeNames worldtype) override { 
        switch (worldtype) {
        case WorldTypeNames::SPAWN_WORLD: {
            int id = MineUtils::generateRandomId();
            int seed = MineUtils::generateRandomId();
            vecPtrBiomes uniqueBiomes;
            factoryUtils_.createWorldBiomes(uniqueBiomes, BiomeTypes::BIOME_PLAINS_BIOME, BiomeVariationTypes::BIOMEPL_PLAINS, numbiomes[0]);
            
            return std::make_unique<MinecraftWorldInfo>(id, seed, uniqueBiomes, worldname, worldtype);
        }
        default:
            std::cout << "Provided type does not match a valid type" << std::endl;
            return nullptr;
        }   
    }
};
#endif // SPAWN_WORLD_FACTORY_H