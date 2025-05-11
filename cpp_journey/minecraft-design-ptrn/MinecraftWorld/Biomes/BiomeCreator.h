#ifndef BIOME_CREATOR_H
#define BIOME_CREATOR_H

#include <string>
#include <vector>
#include <memory>

#include "../Utils/ItemNames.h"
#include "PlainsBiome.h"
#include "PureBiome.h"

class BiomeCreator {
public:
    BiomeCreator() {}
    virtual ~BiomeCreator() = default;
    virtual std::unique_ptr<PureBiome> createBiome() = 0; 
};

#endif