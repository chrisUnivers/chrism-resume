#include <iostream>

#include "PlainsBiome.h"

int main() {
    
    PlainsBiome* ol = new PlainsBiome();
    // PlainsBiome* ol = new PlainsBiome("ice spike", 8.8);

    std::cout << "plains biome surface: " << ol->getBiomeTexture().biomeBlocksSurface_ << std::endl;

    return 0;
}