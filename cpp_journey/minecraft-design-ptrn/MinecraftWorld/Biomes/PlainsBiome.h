#ifndef PLAINS_BIOME_H
#define PLAINS_BIOME_H


#include "MinecraftBiome.h"

class PlainsBiome : public MinecraftBiome {
public:
    virtual int getBiomeId() const = 0;
    virtual std::string getBiomeName() const = 0;
    virtual BiomeTexture applyBiomeTexture() const = 0;
    virtual BiomeVariationTypes getBiomeUniqueType() const = 0;
    virtual double getbiomeWorldPercentage() const = 0;
    void createBiome(BiomeTypes type) const override {
    }
};

#endif // PLAINS_BIOME_H