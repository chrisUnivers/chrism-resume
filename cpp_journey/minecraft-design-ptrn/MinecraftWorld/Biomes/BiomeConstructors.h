#ifndef BIOMES_CONSTRUCTORS_H
#define BIOMES_CONSTRUCTORS_H


#include "MinecraftBiome.h"
// BIOME_ICE_PLAINS
// BIOME_ICE_SPIKE_PLAINS

class BiomePlains : public MinecraftBiome {
public:
    
};

class BiomeIcePlains : public MinecraftBiome {
public:
    BiomeIcePlains() : BiomeIcePlains(0, BIOME_PLAINS) {}
    BiomeIcePlains(int biome_id, BiomeName biome_name){
        BiomeId_ = biome_id;
        BiomeName_ = biome_name;
        BiomeTexture_ = BiomeTexture("solid ice", "clear baby-blue");
        BiomeWorldPercentage_ = 3.0;
    }
};
// int          BiomeId_;
// BiomeName    BiomeName_;
// BiomeTexture BiomeTexture_;
// double       BiomeWorldPercentage_; 

#endif