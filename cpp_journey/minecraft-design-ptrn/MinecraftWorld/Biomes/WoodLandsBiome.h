#ifndef WOODLANDS_BIOME_H
#define WOODLANDS_BIOME_H

#include <string>
#include <vector>
#include <memory>

#include "../Utils/ItemNames.h"
#include "BiomeCreator.h"

class WoodLandsBiome : public PureBiome {
public:
    WoodLandsBiome();
    WoodLandsBiome(std::string biome_name, double world_percentage);
    std::unique_ptr<PureBiome> getBiome() const;
    virtual ~WoodLandsBiome() = default;
};

#endif