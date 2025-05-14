#ifndef BIOME_H
#define BIOME_H

#include "PureBiome.h"

class Biome {
public:
    virtual ~Biome() = default;
    virtual void CreateBiome(std::string biome_name, std::unique_ptr<PureBiome> &biome) const = 0;
};

#endif