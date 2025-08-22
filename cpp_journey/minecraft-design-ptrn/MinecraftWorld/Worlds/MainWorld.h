#ifndef MAIN_WORLD_H
#define MAIN_WORLD_H


#include <iostream>
#include "SpawnWorldFactory.h"

class MainWorld {
private:
    std::unique_ptr<WorldFactory> worldFactory_;
public: 
    MainWorld(std::unique_ptr<WorldFactory> factory) : worldFactory_(std::move(factory)) {};
    std::unique_ptr<MinecraftWorld> createWorld() {
        
    }
    virtual ~MainWorld() = default;
};
#endif // MAIN_WORLD_H