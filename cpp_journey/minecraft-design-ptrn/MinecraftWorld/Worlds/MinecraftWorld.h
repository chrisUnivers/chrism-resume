#ifndef MINECRAFT_WORLD_H
#define MINECRAFT_WORLD_H

#include "PureWorld.h"
#include "../Biomes/PlainsBiome.h"
#include "../Biomes/WoodLandsBiome.h"



class MinecraftWorld : public PureWorld {
public:
    MinecraftWorld() {};
    virtual ~MinecraftWorld() = default;

};

#endif