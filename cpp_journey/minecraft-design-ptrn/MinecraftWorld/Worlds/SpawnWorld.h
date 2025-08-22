#ifndef SPAWN_WORLD_H
#define SPAWN_WORLD_H

#include "WorldFactory.h"
#include "MinecraftWorld.h"

class SpawnWorld : public MinecraftWorld {
private:
    std::unique_ptr<MinecraftWorldInfo> worldInfo_;
public:
    SpawnWorld(std::unique_ptr<MinecraftWorldInfo> info) : worldInfo_(std::move(info)) {};
    
    int getWorldId() const override {
        return worldInfo_->worldId_;
    }
    
    std::string getWorldName() const override {
        return worldInfo_->worldName_;
    }
    

    std::vector<std::unique_ptr<MinecraftBiome>>::const_iterator getWorldBiome() const override {
        return worldInfo_->worldBiomes_.cbegin();
    }

    std::vector<WorldTree>::iterator getWorldTress() const override {
        return worldInfo_->worldTrees_.begin();
    }
    
    ~SpawnWorld() = default;
};
#endif // SPAWN_WORLD_H