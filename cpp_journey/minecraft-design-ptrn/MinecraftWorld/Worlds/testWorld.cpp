#include <iostream>
#include <memory>
#include "UniqueWorld.h"

int main() {
    std::unique_ptr<UniqueWorld> world = std::make_unique<UniqueWorld>();
    std::unique_ptr<PureWorld> uniq_world;
    WorldAttributes uniqWorld_attributes = WorldAttributes();
    
    std::pair<int, std::string> plainsBiome_info = {2, "ice spike plains"};
    std::pair<int, std::string> woodLandsBiome_info = {3, "flower forest woodLands"};
    std::pair<int, std::string> oakTree_info = {80, "oak tree"}; // for apples
    std::pair<int, std::string> darkOakTree_info = {80, "dark oak tree"}; // for apples
    uniqWorld_attributes.BiomesAttributes_.emplace_back(plainsBiome_info);
    uniqWorld_attributes.BiomesAttributes_.emplace_back(woodLandsBiome_info);

    uniqWorld_attributes.TreesAttributes_.emplace_back(oakTree_info);
    uniqWorld_attributes.TreesAttributes_.emplace_back(darkOakTree_info);
    world->CreateWorld("this world's name_name", uniq_world, uniq_world_attributes);
    std::cout << "back from create world" << std::endl;
    
    return 0;
}