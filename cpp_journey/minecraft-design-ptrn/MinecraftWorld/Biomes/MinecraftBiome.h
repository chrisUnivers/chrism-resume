#ifndef MINECRAFT_BIOME_H
#define MINECRAFT_BIOME_H

#include "../Utils/defaultStructs.h"
#include "../Utils/ItemStructs.h"
#include "../Utils/StaticUtils.h"
class MinecraftBiome {    
public:
    virtual int getBiomeId() const = 0;
    virtual BiomeTexture applyBiomeTexture() const = 0;
    virtual std::string getBiomeName() const = 0;
    virtual BiomeVariationTypes getBiomeUniqueType() const = 0;
    virtual double getbiomeWorldPercentage() const = 0;
    virtual ~MinecraftBiome() = default;
};
#endif // MINECRAFT_BIOME_H