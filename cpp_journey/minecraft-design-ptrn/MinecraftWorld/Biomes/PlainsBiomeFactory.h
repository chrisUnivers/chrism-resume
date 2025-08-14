#ifndef PLAINS_BIOME_FACTORY_H
#define PLAINS_BIOME_FACTORY_H

#include "../Utils/StaticUtils.h"
#include "BiomesFactory.h"

#include "../Utils/defaultStructs.h"
class PlainsBiomeFactory : public BiomesFactory {
public:
    std::unique_ptr<MinecraftBiomeInfo> createBiomeInfo(BiomeVariationTypes biometype) const override {
        switch (biometype) {
        case BiomeVariationTypes::BIOMEPL_PLAINS: {
            int id = StaticUtils::addIdToPlainsBiome();
            return std::make_unique<MinecraftBiomeInfo>(id, CV_BIOMENAME_BIOMEPL_PLAINS, BIOMEPL_PLAINS, BiomeTexture{BlocksSurface::sd, BlockColour::gr}, 0.0);
        }
        case BiomeVariationTypes::BIOMEPL_ICE: {
            return nullptr;
        }
        default:
            std::cout << "Provided type does not match a valid typo" << std::endl;
            
            return nullptr;
        }
    }
    
};
#endif // PLAINS_BIOME_FACTORY_H