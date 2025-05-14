#include <iostream>

#include "PlainsBiome.h"
#include "WoodLandsBiome.h"
#include <memory>

int main() { 
    // plains, ice plains, ice spike plains
    std::unique_ptr<PlainsBiome> biome = std::make_unique<PlainsBiome>();
    std::unique_ptr<WoodLandsBiome> biome_wdls = std::make_unique<WoodLandsBiome>();
    std::unique_ptr<PureBiome> plains_biome; 
    std::unique_ptr<PureBiome> wdls_biome; 
    biome->CreateBiome("ice plains", plains_biome);
    biome_wdls->CreateBiome("flower forest", wdls_biome);
    // std::cout << "plains biome surface " << "returned" << std::endl;
    // std::string text_color = plains_biome->getBiomeColour();
    // std::cout << "the text_color: " << text_color << std::endl;
    std::string new_color = wdls_biome->getBiomeColour();
    std::cout << "Colorful biomes: " << new_color << std::endl;
    std::cout << "Biomes need a description!" << std::endl;
    return 0;
}