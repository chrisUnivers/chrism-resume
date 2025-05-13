#ifndef BIOME_H
#define BIOME_H

#include "PureBiome.h"

class Biome {
public:
    virtual ~Biome() = default;
    virtual PureBiome* CreateBiome(std::string biome_name) const = 0;
};

#endif