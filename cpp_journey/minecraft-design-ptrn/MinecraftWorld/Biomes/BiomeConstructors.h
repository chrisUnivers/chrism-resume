#ifndef BIOMES_CONSTRUCTORS_H
#define BIOMES_CONSTRUCTORS_H

#include <memory>
#include "MinecraftBiome.h"
#include "../Utils/ItemStructs.h"
// BIOME_ICE_SPIKE_PLAINS

class BiomePlains : public MinecraftBiome {
public:
    BiomePlains() : BiomePlains(0, BIOME_PLAINS) {}
    BiomePlains(int biome_id, BiomeName biome_name){
        BiomeId_ = biome_id;
        BiomeName_ = biome_name;
        BiomeTexture_ = std::make_unique<BiomeTexture>("solid ice", "clear baby-blue");
        BiomeWorldPercentage_ = 3.0;
    }
};

class BiomeIcePlains : public MinecraftBiome {
public:
    BiomeIcePlains() : BiomeIcePlains(0, BIOME_ICE_PLAINS) {}
    BiomeIcePlains(int biome_id, BiomeName biome_name){
        BiomeId_ = biome_id;
        BiomeName_ = biome_name;
        BiomeTexture_ = std::make_unique<BiomeTexture>("solid-ice snow", "clear baby-blue");
        BiomeWorldPercentage_ = 3.0;
    }
};

class BiomeIceSpikePlains : public MinecraftBiome {
public:
    BiomeIceSpikePlains() : BiomeIceSpikePlains(0, BIOME_ICE_SPIKE_PLAINS) {}
    BiomeIceSpikePlains(int biome_id, BiomeName biome_name){
        BiomeId_ = biome_id;
        BiomeName_ = biome_name;
        BiomeTexture_ = std::make_unique<BiomeTexture>("solid-ice ice-spikes snow", "clear baby-blue");
        BiomeWorldPercentage_ = 3.0;
    }
};
// int          BiomeId_;
// BiomeName    BiomeName_;
// BiomeTexture BiomeTexture_;
// double       BiomeWorldPercentage_; 

#endif