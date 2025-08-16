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
            return std::make_unique<MinecraftBiomeInfo>(id, CV_BIOMENAME_BIOMEPL_PLAINS, BIOMEPL_PLAINS, BiomeTexture{BlocksSurface::sd, BlockColour::gr}, WorldTakeUp::plp);
        }
        case BiomeVariationTypes::BIOMEPL_ICE: {
            int id = StaticUtils::addIdToPlainsBiome();

            return std::make_unique<MinecraftBiomeInfo>(id, CV_BIOMENAME_BIOMEPL_ICE, BIOMEPL_ICE, BiomeTexture{BlocksSurface::sis, BlockColour::sw}, WorldTakeUp::pl_ice);
        }
        default:
            std::cout << "Provided type does not match a valid typo" << std::endl;
            
            return nullptr;
        }
    }
    
};
#endif // PLAINS_BIOME_FACTORY_H