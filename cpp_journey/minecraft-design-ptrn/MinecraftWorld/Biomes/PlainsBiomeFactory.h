#ifndef PLAINS_BIOME_FACTORY_H
#define PLAINS_BIOME_FACTORY_H


#include "BiomesFactory.h"

class PlainsBiomeFactory : public BiomesFactory {
public:
    std::unique_ptr<MinecraftBiomeInfo> createBiomeInfo(BiomeVariationTypes biometype) const override {
        return std::make_unique<MinecraftBiomeInfo>(3, "plains biome", BiomeVariationTypes::BIOME_PLAINS, BiomeTexture{"solid", "green"}, 58.4);
    }
};
#endif // PLAINS_BIOME_FACTORY_H