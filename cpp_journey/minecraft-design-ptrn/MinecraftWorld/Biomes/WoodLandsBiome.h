#ifndef WOODLANDS_BIOME_H
#define WOODLANDS_BIOME_H


#include <string>
#include "../Utils/ItemNames.h"
#include "../Utils/ItemStructs.h"
#include "Biome.h"
#include "MinecraftBiome.h"

class WoodLandsBiome : public Biome {
public:
    WoodLandsBiome();
    virtual ~WoodLandsBiome() = default;
    void CreateBiome(std::string biome_name, std::unique_ptr<PureBiome>& biome) const override;
};

#endif