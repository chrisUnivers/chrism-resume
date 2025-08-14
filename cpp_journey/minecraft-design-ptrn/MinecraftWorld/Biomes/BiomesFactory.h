#ifndef BIOMES_FACTORY_H
#define BIOMES_FACTORY_H

#include <iostream>
#include <memory>

#include "MinecraftBiome.h"
class BiomesFactory {
public:
    virtual ~BiomesFactory() = default;
    virtual std::unique_ptr<MinecraftBiomeInfo> createBiomeInfo(BiomeVariationTypes biomeName) const = 0;
};
#endif // BIOMES_FACTORY_H