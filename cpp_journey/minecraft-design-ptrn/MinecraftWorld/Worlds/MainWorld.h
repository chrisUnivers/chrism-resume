#ifndef MAIN_WORLD_H
#define MAIN_WORLD_H


#include <iostream>
#include "SpawnWorldFactory.h"
#include "SpawnWorld.h"
class MainWorld {
private:
    std::unique_ptr<WorldFactory> worldFactory_;
public:
    MainWorld(std::unique_ptr<WorldFactory> factory) : worldFactory_(std::move(factory)) {}; 
    std::unique_ptr<MinecraftWorld> createWorld(std::vector<baseBiomeTplBiome>& allBiomes, std::vector<treeTypeTpl>& trees, int ntrees, std::string worldname, WorldTypeNames worldtype) {
        switch (worldtype)
        {
        case WorldTypeNames::SPAWN_WORLD: {
            std::unique_ptr<MinecraftWorldInfo> worldInfo = worldFactory_->createWorldInfo(allBiomes, trees, ntrees, worldname, worldtype);
            return std::make_unique<SpawnWorld>(std::move(worldInfo));
        }
        default:
        
            std::cout << "The provided variation type is not valid" << std::endl;
            return nullptr;
        }
    }
    virtual ~MainWorld() = default;
};
#endif // MAIN_WORLD_H