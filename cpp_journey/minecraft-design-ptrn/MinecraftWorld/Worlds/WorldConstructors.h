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
    SpawnWorld() : SpawnWorld(1, SPAWN_WORLD_WORLD, DEFAULT_WORLD_NAME) {};
    SpawnWorld(std::string world_name) : SpawnWorld(1, SPAWN_WORLD_WORLD, world_name) {};
    SpawnWorld(int instance_count, WorldTypeNames world_type_name, std::string world_name){
        std::vector<PlainsBiome> moveBiome;
        WorldId_ = MineUtils::generateRandomId();

        WorldClimate_ = std::make_unique<WorldClimate>(DEFAULT_TEMPERATURE);
    }

    void setPlainsBiome(std::unique_ptr<PureBiome>& mBiome) {
        std::lock_guard<std::mutex> lock(plains_biome_mutex);
        WorldPlainsBiomes_.emplace_back(std::move(mBiome));
    }
    void setWorldTree(std::unique_ptr<PureTree>& mTree) {
        std::lock_guard<std::mutex> lock(woodLands_trees_mutex);
        WorldTrees_.emplace_back(std::move(mTree));
    }
    void getPlainsBiomeTexture(int nth_bio) const override {
        std::cout << "world plains biomes count is: " << WorldPlainsBiomes_.size() << std::endl;
        if (WorldPlainsBiomes_.size() > nth_bio) {
            std::string bio_colour = WorldPlainsBiomes_[nth_bio]->getBiomeColour();
            std::cout << "The " << nth_bio << " colour is: " << bio_colour << std::endl;
        }
    }
    void setClimate() {
        WorldClimate_->temperature = 33.7;
    }
protected:
    mutable std::mutex plains_biome_mutex;
    // mutex for trees in different biomes.
    mutable std::mutex woodLands_trees_mutex;
};


class NetheWorld : public MinecraftWorld {
public:
    NetheWorld() : NetheWorld(1, NETHER_WORLD_WORLD) {}
    NetheWorld(int instance_count, WorldTypeNames world_type_name){
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
    EndWorld(int instance_count, WorldTypeNames world_type_name){
        std::vector<PlainsBiome> moveBiome;
        WorldId_ = MineUtils::generateRandomId();
        WorldClimate_ = std::make_unique<WorldClimate>(DEFAULT_TEMPERATURE);
    }
    
};

#endif