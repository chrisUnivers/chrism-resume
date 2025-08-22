#ifndef MINECRAFT_WORLD_H
#define MINECRAFT_WORLD_H

#include <vector>
#include <string>
#include "../Biomes/MainBiome.h"



class MinecraftWorld {
public:
    virtual ~MinecraftWorld() = default;
    
    virtual int getWorldId() const = 0;
    virtual std::string getWorldName() const = 0;
};
#endif // MINECRAFT_WORLD_H