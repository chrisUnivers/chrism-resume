#include <memory>

#include "WoodLandsBiome.h"
#include "../Utils/defaults.h"
#include "BiomeConstructors.h"
#include <iostream>


WoodLandsBiome::WoodLandsBiome(){
}
// BIOME_FOREST_WDLS, BIOME_FLOWER_FOREST_WDLS, BIOME_BIRCH_FOREST_WDLS
void WoodLandsBiome::CreateBiome(std::string biome_name, std::unique_ptr<PureBiome>& mBiome) const {
    BiomeNames bio;
    if (WOODLANDSBIOME_MAP.count(biome_name)) {bio = WOODLANDSBIOME_MAP.at(biome_name);}
    switch (bio)
    {
    case BIOME_BIRCH_FOREST_WDLS: {
        std::unique_ptr<BiomeBirchForestWdls_Biome> ow = std::make_unique<BiomeBirchForestWdls_Biome>();
        std::cout << "birch forest biome" << std::endl;
        std::cout << "no change to texture: " << ow->getBiomeColour() << std::endl;
        mBiome = std::move(ow);
        break;
    }
    case BIOME_FLOWER_FOREST_WDLS: {
        std::unique_ptr<BiomeFlowerForestWdls_Biome> ow = std::make_unique<BiomeFlowerForestWdls_Biome>();
        std::cout << "flower forest biome" << std::endl;
        std::cout << "should be colourful: " << ow->getBiomeColour() << std::endl;
        mBiome = std::move(ow);
        break;
    }
    default:
        std::unique_ptr<BiomeWoodLands_Biome> ol = std::make_unique<BiomeWoodLands_Biome>();
        std::cout << "get forest biomes" << std::endl;
        mBiome = std::move(ol);
        break;
    }
}

//BIOME_FOREST_WDLS, BIOME_FLOWER_FOREST_WDLS, BIOME_BIRCH_FOREST_WDLS