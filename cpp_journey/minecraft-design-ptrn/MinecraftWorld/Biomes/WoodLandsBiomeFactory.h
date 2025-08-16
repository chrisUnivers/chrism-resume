#ifndef WOODLANDS_BIOME_FACTORY_H
#define WOODLANDS_BIOME_FACTORY_H


#include "BiomesFactory.h"

class WoodLandsBiomeFactory : public BiomesFactory {
public:
    std::unique_ptr<MinecraftBiomeInfo> createBiomeInfo(BiomeVariationTypes biometype) const override {

        switch (biometype) {
        case BiomeVariationTypes::BIOMEWDLS_FOREST: {
            int id = StaticUtils::addIdToPlainsBiome();
            
            return std::make_unique<MinecraftBiomeInfo>(id, CV_BIOMENAME_BIOMEWDLS_FRS, BIOMEWDLS_FOREST, BiomeTexture{BlocksSurface::sdg, BlockColour::gr}, WorldTakeUp::wdls_bf);
        }
        default:
            std::cout << "Provided type does not match a valid type" << std::endl;
            return nullptr;
        }
        
    }
};
#endif // WOODLANDS_BIOME_FACTORY_H