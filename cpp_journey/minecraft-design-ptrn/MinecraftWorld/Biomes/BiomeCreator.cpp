#include "BiomeCreator.h"
#include <map>
#include <functional>

std::unique_ptr<PureBiome> BiomeCreator::createBiome() {
    std::map<std::string, std::function<void()>> map_plain_biomes = {
        "plains", []( ){}
    };
}
// Product* createProductA() { return new ConcreateProductA; }