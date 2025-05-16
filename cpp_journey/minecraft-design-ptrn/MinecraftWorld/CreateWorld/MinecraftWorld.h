#ifndef MINECRAFT_WORLD_H
#define MINECRAFT_WORLD_H

#include "PureWorld.h"
#include "../Biomes/PlainsBiome.h"

class MinecraftWorld : public PureWorld {
public:
    virtual ~MinecraftWorld() = default;
};

#endif