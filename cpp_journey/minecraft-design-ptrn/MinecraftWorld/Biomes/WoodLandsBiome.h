#ifndef WOODLANDS_BIOME_H
#define WOODLANDS_BIOME_H

#include <string>
#include <vector>

#include "../Utils/ItemNames.h"
#include "PureBiome.h"

class WoodLandsBiome : public PureBiome {
public:
    WoodLandsBiome();
    WoodLandsBiome(std::string biome_name, double world_percentage);
    PureBiome* getBiome() const override;
    virtual ~WoodLandsBiome() = default;
};

#endif