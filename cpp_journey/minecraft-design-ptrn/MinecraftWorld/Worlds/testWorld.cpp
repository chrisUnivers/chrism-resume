#include <iostream>
#include <memory>
#include "UniqueWorld.h"

int main() {
    std::unique_ptr<UniqueWorld> world = std::make_unique<UniqueWorld>();
    std::unique_ptr<MinecraftWorld> uniq_world;
    WorldAttributes uniqWorld_attributes = WorldAttributes();
    int value = 6;
    std::pair<int, std::string> plainsBiome_info = {2, "ice spike plains"};
    std::pair<int, std::string> woodLandsBiome_info = {3, "woodlands flower forest"};
    std::pair<int, std::string> oakTree_info = {2, "spruce tree"}; // for apples
    std::pair<int, std::string> darkOakTree_info = {2, "dark oak tree"}; // for apples
    uniqWorld_attributes.BiomesAttributes_.emplace_back(plainsBiome_info);
    uniqWorld_attributes.BiomesAttributes_.emplace_back(woodLandsBiome_info);
    
    uniqWorld_attributes.TreesAttributes_.emplace_back(oakTree_info);
    uniqWorld_attributes.TreesAttributes_.emplace_back(darkOakTree_info);
    world->CreateWorld("this world's name_name", uniq_world, uniqWorld_attributes);

    
    
    std::cout << "back from create world" << std::endl;
    world->ListWorldItems(uniq_world);
    std::cout << "back from textures" << std::endl;
    return 0;
}