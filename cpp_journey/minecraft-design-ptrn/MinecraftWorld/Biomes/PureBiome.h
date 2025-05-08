#ifndef PURE_BIOME_H
#define PURE_BIOME_H

#include <string>
#include <vector>

#include "../Utils/ItemNames.h"

class PureBiome {
protected:
    int          BiomeId_;
    BiomeName    BiomeName_;
    BiomeTexture BiomeTexture_;
    std::string  BlockType_;
public:
    PureBiome() {}
    virtual ~PureBiome() = default;
};

#endif