#ifndef WOODLANDS_BIOME_H
#define WOODLANDS_BIOME_H

#include <string>
#include "../Utils/ItemNames.h"
#include "../Utils/ItemStructs.h"
#include "PureBiome.h"


class WoodLandsBiome : public PureBiome {
public:
    WoodLandsBiome();
    WoodLandsBiome(std::string biome_name, double world_percentage);
    BiomeTexture getBiomeTexture();

    virtual ~WoodLandsBiome() = default;
    PureBiome* getBiome() const override;
protected:
    BiomeTexture BiomeTexture_;
};

#endif