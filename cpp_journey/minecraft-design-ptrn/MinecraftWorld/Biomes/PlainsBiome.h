#ifndef PLAINS_BIOME_H
#define PLAINS_BIOME_H

#include <string>
#include <vector>
#include <memory>

#include "../Utils/ItemNames.h"
#include "BiomeCreator.h"

class PlainsBiome : public PureBiome {
public:
    PlainsBiome();
    PlainsBiome(std::string biome_name, double world_percentage);
    std::unique_ptr<PureBiome> getBiome() const;
    virtual ~PlainsBiome() = default;
};

#endif