#include <iostream>
#include <memory>
#include "UniqueWorld.h"

int main() {
    std::unique_ptr<UniqueWorld> world = std::make_unique<UniqueWorld>();
    std::unique_ptr<PureWorld> uniq_world;
    WorldAttributes uniq_world_attributes = WorldAttributes();
    
    std::pair<int, std::string> plains_biome_info = {2, "plains ice biome"};
    uniq_world_attributes.BiomesAttributes_ = plains_biome_info;
    world->CreateWorld("this world", uniq_world, uniq_world_attributes);
    std::cout << "back from create world" << std::endl;
    
    return 0;
}