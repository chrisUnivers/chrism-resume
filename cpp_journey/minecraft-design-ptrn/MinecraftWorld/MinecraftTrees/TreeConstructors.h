#ifndef TREE_CONSTRUCTORS_H
#define TREE_CONSTRUCTORS_H

#include <memory>
#include "MinecraftTree.h"
#include "../Utils/ItemStructs.h"
#include <iostream>

class SpruceTree_Tree : public MinecraftTree {
public:
    SpruceTree_Tree() : SpruceTree_Tree(0, BIOME_PLAINS) {}
    SpruceTree_Tree(int biome_id, BiomeNames biome_name){
        ItemSpawnBiome_ = BIOME_WINDSWEPT_HILLS;
    }
};

#endif