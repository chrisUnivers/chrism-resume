#ifndef PLAINS_BIOME_H
#define PLAINS_BIOME_H

#include <string>
#include "../Utils/ItemNames.h"
#include "../Utils/ItemStructs.h"
#include "Biome.h"
#include "MinecraftBiome.h"

class PlainsBiome : public Biome {
public:
    PlainsBiome();
    virtual ~PlainsBiome() = default;
    void CreateBiome(std::string biome_name, std::unique_ptr<PureBiome>& biome) const override;
};


#endif