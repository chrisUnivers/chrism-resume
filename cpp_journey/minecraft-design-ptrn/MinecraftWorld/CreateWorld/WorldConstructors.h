#ifndef WORLD_CONSTRUCTORS_H
#define WORLD_CONSTRUCTORS_H

#include <memory>
#include "MinecraftWorld.h"
#include "../Utils/ItemStructs.h"
#include <iostream>


class WorldOne_One : public MinecraftWorld {
public:
    WorldOne_One() : WorldOne_One(1, WORLD_ONE_WORLD) {}
    WorldOne_One(int instance_count, WorldNames world_name){
        WorldId_ = MineUtils::generateRandomId();
        WorldClimate_ = std::make_unique<WorldClimate>(DEFAULT_TEMPERATURE);

        for (int i = 0; i < instance_count; i++) {
            std::unique_ptr<PlainsBiome> biome = std::make_unique<PlainsBiome>();
            std::unique_ptr<PureBiome> plains_biome; 
            biome->CreateBiome("ice plains", plains_biome);
            WorldPlainsBiomes_.emplace_back(*plains_biome);
        }
    }
};

#endif