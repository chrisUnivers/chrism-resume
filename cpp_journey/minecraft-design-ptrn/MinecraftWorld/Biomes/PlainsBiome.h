#ifndef PLAINS_BIOME_H
#define PLAINS_BIOME_H

#include <string>
#include <vector>

#include "../Utils/ItemNames.h"
#include "../Utils/ItemStructs.h"
#include "PureBiome.h"

class PlainsBiome : public PureBiome {
public:
    PlainsBiome();
    PlainsBiome(std::string biome_name, double world_percentage);
    BiomeTexture getBiomeTexture();

    virtual ~PlainsBiome() = default;
    PureBiome* getBiome() const override;
protected:
    BiomeTexture BiomeTexture_;
};


#endif