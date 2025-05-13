#include <memory>

#include "PlainsBiome.h"
#include "../Utils/defaults.h"
#include "BiomeConstructors.h"
#include <iostream>


PlainsBiome::PlainsBiome(){
}

PureBiome* PlainsBiome::CreateBiome(std::string biome_name) const {
    BiomeNames bio;
    if (PLAINSBIOME_MAP.count(biome_name)) {bio = PLAINSBIOME_MAP.at(biome_name);}
    std::unique_ptr<BiomePlains_Biome> ol;
    switch (bio)
    {
    case BIOME_ICE_PLAINS: {
        std::unique_ptr<BiomeIcePlains_Biome> ol = std::make_unique<BiomeIcePlains_Biome>();
        std::cout << "ice plains biome" << std::endl;
        std::string text_color = ol->getBiomeColour();
        std::cout << "the text color: " << text_color << std::endl;
        return ol.get();
    }
    case BIOME_ICE_SPIKE_PLAINS: {
        std::unique_ptr<BiomeIceSpikePlains_Biome> ol = std::make_unique<BiomeIceSpikePlains_Biome>();
        std::cout << "ice spike plains biome" << std::endl;
        // ol->getBiomeColour();
        return ol.get();
    }
    default:
        std::unique_ptr<BiomePlains_Biome> ol = std::make_unique<BiomePlains_Biome>();
        std::cout << "plains biome" << std::endl;
        return ol.get();
    }
}

// BiomeId_ = MineUtils::generateRandomId();
//     BiomeWorldPercentage_ = world_percentage; // to be used in for world creation
//     if (biome_name == "plains") {
//         BiomeName_ = BIOME_PLAINS;
//         BiomeTexture_ = BiomeTexture("default", "default");
//     }
//     else if (biome_name == "ice") {
//         BiomeName_ = BIOME_ICE_PLAINS;
//         BiomeTexture_ = BiomeTexture("ice", "ice_colour");
//     }
//     else if (biome_name == "ice spike") {
//         BiomeName_ = BIOME_ICE_SPIKE_PLAINS;


// BIOME_PLAINS, BIOME_ICE_PLAINS, BIOME_ICE_SPIKE_PLAINS,