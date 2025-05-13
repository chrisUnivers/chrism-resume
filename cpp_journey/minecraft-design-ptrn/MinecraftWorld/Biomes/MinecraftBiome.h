#ifndef MINECRAFT_BIOME_H
#define MINECRAFT_BIOME_H

#include "PureBiome.h"

class MinecraftBiome : public PureBiome {
public:
    virtual ~MinecraftBiome() = default;
};

#endif