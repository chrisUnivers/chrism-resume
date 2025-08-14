#include <memory>

#include "PlainsBiome.h"
#include "../Utils/defaults.h"
#include "BiomeConstructors.h"
#include <iostream>



PlainsBiome::PlainsBiome(){
}

void PlainsBiome::CreateBiome(std::string biome_name, std::unique_ptr<PureBiome>& mBiome) const {
    BiomeNames bio;
    if (PLAINSBIOME_MAP.count(biome_name)) {bio = PLAINSBIOME_MAP.at(biome_name);}
    std::unique_ptr<BiomePlains_Biome> ol;
    switch (bio)
    {
    case BIOME_ICE_PLAINS: {
        std::unique_ptr<BiomeIcePlains_Biome> ol = std::make_unique<BiomeIcePlains_Biome>();
        // std::cout << "ice plains biome" << std::endl;
        std::string text_color = ol->getBiomeColour();
        // std::cout << "the text color: " << text_color << std::endl;
        mBiome = std::move(ol);
        break;
    }
    case BIOME_ICE_SPIKE_PLAINS: {
        std::unique_ptr<BiomeIceSpikePlains_Biome> ol = std::make_unique<BiomeIceSpikePlains_Biome>();
        // std::cout << "ice spike plains biome" << std::endl;
        mBiome = std::move(ol);
        break;
    }
    default:
        std::unique_ptr<BiomePlains_Biome> ol = std::make_unique<BiomePlains_Biome>();
        // std::cout << "plains biome" << std::endl;
        mBiome = std::move(ol);
    }
}