#ifndef BIOMES_CONSTRUCTORS_H
#define BIOMES_CONSTRUCTORS_H

#include <memory>
#include "MinecraftBiome.h"
#include "../Utils/ItemStructs.h"
#include <iostream>

class BiomePlains_Biome : public MinecraftBiome {
public:
    BiomePlains_Biome() : BiomePlains_Biome(0, BIOME_PLAINS) {}
    BiomePlains_Biome(int biome_id, BiomeNames biome_name){
        BiomeId_ = biome_id;
        BiomeName_ = biome_name;
        BiomeTexture_ = std::make_unique<BiomeTexture>("default", "default");
        BiomeWorldPercentage_ = 3.0;
    }
};

class BiomeIcePlains_Biome : public MinecraftBiome {
public:
    BiomeIcePlains_Biome() : BiomeIcePlains_Biome(0, BIOME_ICE_PLAINS) {}
    BiomeIcePlains_Biome(int biome_id, BiomeNames biome_name){
        BiomeId_ = biome_id;
        BiomeName_ = biome_name;
        BiomeTexture_ = std::make_unique<BiomeTexture>("solid-ice snow", "clear baby-blue");
        std::cout << "texture colour: " << BiomeTexture_->biomeBlocksColour_ << std::endl;
        BiomeWorldPercentage_ = 3.0;
    }
};

class BiomeIceSpikePlains_Biome : public MinecraftBiome {
public:
    BiomeIceSpikePlains_Biome() : BiomeIceSpikePlains_Biome(0, BIOME_ICE_SPIKE_PLAINS) {}
    BiomeIceSpikePlains_Biome(int biome_id, BiomeNames biome_name){
        BiomeId_ = biome_id;
        BiomeName_ = biome_name;
        BiomeTexture_ = std::make_unique<BiomeTexture>("solid-ice ice-spikes snow", "clear baby-blue");
        BiomeWorldPercentage_ = 3.0;
    }
};

class BiomeWoodLands_Biome : public MinecraftBiome {
public:
    BiomeWoodLands_Biome() : BiomeWoodLands_Biome(0, BIOME_FOREST_WDLS) {}
    BiomeWoodLands_Biome(int biome_id, BiomeNames biome_name){
        BiomeId_ = biome_id;
        BiomeName_ = biome_name;
        BiomeTexture_ = std::make_unique<BiomeTexture>("default", "default");
        BiomeWorldPercentage_ = 3.0;
    }
};

class BiomeFlowerForestWdls_Biome : public MinecraftBiome {
public:
    BiomeFlowerForestWdls_Biome() : BiomeFlowerForestWdls_Biome(0, BIOME_FLOWER_FOREST_WDLS) {}
    BiomeFlowerForestWdls_Biome(int biome_id, BiomeNames biome_name){
        BiomeId_ = biome_id;
        BiomeName_ = biome_name;
        BiomeTexture_ = std::make_unique<BiomeTexture>("default", "colourful");
        std::cout << "flower biome texture colour: " << BiomeTexture_->biomeBlocksColour_ << std::endl;
        BiomeWorldPercentage_ = 3.0;
    }
};

class BiomeBirchForestWdls_Biome : public MinecraftBiome {
public:
    BiomeBirchForestWdls_Biome() : BiomeBirchForestWdls_Biome(0, BIOME_BIRCH_FOREST_WDLS) {}
    BiomeBirchForestWdls_Biome(int biome_id, BiomeNames biome_name){
        BiomeId_ = biome_id;
        BiomeName_ = biome_name;
        BiomeTexture_ = std::make_unique<BiomeTexture>("default", "default");
        std::cout << "forest texture colour: " << BiomeTexture_->biomeBlocksColour_ << std::endl;
        BiomeWorldPercentage_ = 3.0;
    }
};


// BIOME_FOREST_WDLS, WOODLANDS
// BIOME_FLOWER_FOREST_WDLS,
// BIOME_SNOWY_PLAINS_WDLS,
// int          BiomeId_;
// BiomeName    BiomeName_;
// BiomeTexture BiomeTexture_;
// double       BiomeWorldPercentage_; 

#endif