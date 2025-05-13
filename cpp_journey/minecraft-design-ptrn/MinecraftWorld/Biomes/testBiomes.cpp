#include <iostream>


#include "PlainsBiome.h"
#include <memory>

int main() {
    // plains, ice plains, ice spike plains
    std::unique_ptr<PlainsBiome> biome = std::make_unique<PlainsBiome>();
    PureBiome* plains_biome = biome->CreateBiome("ice plains");
    std::cout << "plains biome surface: " << "genius" << std::endl;
    return 0;
}