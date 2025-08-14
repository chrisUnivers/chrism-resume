#ifndef MINECRAFT_BIOME_H
#define MINECRAFT_BIOME_H


#include "../Utils/ItemStructs.h"

class MinecraftBiome {    
public:
    virtual void createBiome(BiomeTypes type) const = 0; 
    virtual ~MinecraftBiome() {};
};
#endif // MINECRAFT_BIOME_H