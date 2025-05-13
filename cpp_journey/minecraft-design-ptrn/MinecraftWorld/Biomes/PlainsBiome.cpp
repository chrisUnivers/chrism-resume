#include <memory>

#include "PlainsBiome.h"

PlainsBiome::PlainsBiome(){}


PureBiome* PlainsBiome::CreateBiome(std::string biome_name) const {
    std::unique_ptr<PureBiome> rtdBiome = std::make_unique<PureBiome>();
    return rtdBiome.get();
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