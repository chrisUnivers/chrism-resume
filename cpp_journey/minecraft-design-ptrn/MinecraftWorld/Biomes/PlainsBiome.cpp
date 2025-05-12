#include <memory>

#include "PlainsBiome.h"
#include "../Utils/MineUtils.h"
#include "../Utils/ItemNames.h"

PlainsBiome::PlainsBiome() : PlainsBiome::PlainsBiome("plains", 6.0) {
}

PlainsBiome::PlainsBiome(std::string biome_name, double world_percentage) {
    BiomeId_ = MineUtils::generateRandomId();
    BiomeWorldPercentage_ = world_percentage; // to be used in for world creation
    if (biome_name == "plains") {
        BiomeName_ = BIOME_PLAINS;
        BiomeTexture_ = BiomeTexture("default", "default");
    }
    else if (biome_name == "ice") {
        BiomeName_ = BIOME_ICE_PLAINS;
        BiomeTexture_ = BiomeTexture("ice", "ice_colour");
    }
    else if (biome_name == "ice spike") {
        BiomeName_ = BIOME_ICE_SPIKE_PLAINS;
        BiomeTexture_ = BiomeTexture("ice_spikes", "ice_colour");
    }
}

BiomeTexture PlainsBiome::getBiomeTexture() {
    return this->BiomeTexture_;
}

PureBiome* PlainsBiome::getBiome() const {
    std::unique_ptr<PlainsBiome> rtdBiome = std::make_unique<PlainsBiome>();
    return rtdBiome.get();
}


// BIOME_PLAINS, BIOME_ICE_PLAINS, BIOME_ICE_SPIKE_PLAINS,