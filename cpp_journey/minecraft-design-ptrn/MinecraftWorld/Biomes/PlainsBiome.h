#ifndef PLAINS_BIOME_H
#define PLAINS_BIOME_H

#include <string>
#include <vector>
#include <memory>

#include "../Utils/ItemNames.h"
#include "PureBiome.h"
#include "BiomeCreator.h"

class PlainsBiome : public BiomeCreator {
public:
    PlainsBiome() {}
    virtual ~PlainsBiome() = default;

    std::unique_ptr<PureBiome> createBiome(std::string biomeName);
};

#endif