#ifndef PURE_BIOME_H
#define PURE_BIOME_H

#include <string>
#include <vector>

#include "../Utils/ItemNames.h"
#include "../Utils/ItemStructs.h"

class PureBiome {
protected:
    int          BiomeId_;
    BiomeName    BiomeName_;
    BiomeTexture BiomeTexture_;
    double      BiomeWorldPercentage_;
    
public:
    PureBiome() : BiomeTexture_("none", "none") {}
    virtual ~PureBiome() = default;

    virtual std::unique_ptr<PureBiome> getBiome() const;
};

#endif