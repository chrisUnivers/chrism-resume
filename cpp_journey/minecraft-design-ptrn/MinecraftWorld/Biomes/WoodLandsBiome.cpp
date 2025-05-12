#include <memory>

#include "WoodLandsBiome.h"
#include "../Utils/ItemNames.h"

WoodLandsBiome::WoodLandsBiome() : WoodLandsBiome::WoodLandsBiome("birch forest", 3.0) {}

WoodLandsBiome::WoodLandsBiome(std::string biome_name, double world_percentage) {
    BiomeId_ = MineUtils::generateRandomId();
    BiomeWorldPercentage_ = world_percentage; // to be used in for world creation
    if (biome_name == "birch forest") {
        BiomeName_ = BIOME_BIRCH_FOREST_WDLS;
        BiomeTexture_ = BiomeTexture("default", "default");
    }
    else if (biome_name == "flower forest") {
        BiomeName_ = BIOME_FLOWER_FOREST_WDLS;
        BiomeTexture_ = BiomeTexture("flowers", "default");
    }
    else if (biome_name == "dark forest") {
        BiomeName_ = BIOME_DARK_FOREST_WDLS;
        BiomeTexture_ = BiomeTexture("default", "dark_default");
    }
}

std::unique_ptr<PureBiome> WoodLandsBiome::getBiome() const {
    std::unique_ptr<WoodLandsBiome> rtdBiome = std::make_unique<WoodLandsBiome>();
    return rtdBiome;
}


//BIOME_FOREST_WDLS, BIOME_FLOWER_FOREST_WDLS, BIOME_BIRCH_FOREST_WDLS