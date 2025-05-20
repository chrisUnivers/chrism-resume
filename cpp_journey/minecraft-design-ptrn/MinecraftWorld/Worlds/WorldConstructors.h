#ifndef WORLD_CONSTRUCTORS_H
#define WORLD_CONSTRUCTORS_H


#include <iostream>
#include <memory>

#include "MinecraftWorld.h"
#include "../Utils/ItemStructs.h"
#include "../Biomes/BiomeConstructors.h"
#include "../Food/FoodConstructors.h"
// #include "../Utils/defaultValues.h" 

class SpawnWorld : public MinecraftWorld {
public:
    SpawnWorld() : SpawnWorld(1, SPAWN_WORLD_WORLD) {};
    SpawnWorld(int instance_count, WorldNames world_name){
        std::vector<PlainsBiome> moveBiome;
        WorldId_ = MineUtils::generateRandomId();
        WorldClimate_ = std::make_unique<WorldClimate>(DEFAULT_TEMPERATURE);
        
    }
    
};


class NetheWorld : public MinecraftWorld {
public:
    NetheWorld() : NetheWorld(1, NETHER_WORLD_WORLD) {}
    NetheWorld(int instance_count, WorldNames world_name){
        std::vector<PlainsBiome> moveBiome;
        WorldId_ = MineUtils::generateRandomId();
        WorldClimate_ = std::make_unique<WorldClimate>(DEFAULT_TEMPERATURE);
    }
    
};

class EndWorld : public MinecraftWorld {
protected:
    // std::unique_ptr<PureCreature>  EndDragron_;

public:
    EndWorld() : EndWorld(1, END_WORLD_WORLD) {}
    EndWorld(int instance_count, WorldNames world_name){
        std::vector<PlainsBiome> moveBiome;
        WorldId_ = MineUtils::generateRandomId();
        WorldClimate_ = std::make_unique<WorldClimate>(DEFAULT_TEMPERATURE);
    }
    
};

#endif