#ifndef PLAINS_BIOME_H
#define PLAINS_BIOME_H

#include <string>
#include "../Utils/ItemNames.h"
#include "../Utils/ItemStructs.h"
#include "Biome.h"


class PlainsBiome : public Biome {
public:
    PlainsBiome();

    virtual ~PlainsBiome() = default;
    PureBiome* CreateBiome(std::string biome_name) const override;
};


#endif