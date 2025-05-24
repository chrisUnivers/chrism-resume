#ifndef TREE_CONSTRUCTORS_H
#define TREE_CONSTRUCTORS_H

#include <memory>
#include <iostream>
#include "MinecraftTree.h"
#include "../Utils/ItemStructs.h"
#include "../Utils/MineUtils.h"

class SpruceTree_Tree : public MinecraftTree {
public:
    SpruceTree_Tree() : SpruceTree_Tree(0, BIOME_PLAINS) {}
    SpruceTree_Tree(int biome_id, BiomeNames biome_name){
        std::vector<ItemNameEn> treedropitems = {SPRUCE_TREE_LEAVES};
        SpruceTree_Tree(biome_id, biome_name, treedropitems);
    }
    SpruceTree_Tree(int biome_id, BiomeNames biome_name, std::vector<ItemNameEn>  dropItems) {
        ItemSpawnBiome_ = BIOME_WINDSWEPT_HILLS;
        ItemSpawnBiomeName_ = SPRUCE_TREE_BIOME_NAME;
        TreeDropItems_ = dropItems;
    }
    
    
    int initItemInfo() {
        ItemInfo_.ItemId_ = MineUtils::generateRandomId();
        ItemInfo_.ItemName_ = TREE_SPRUCE;
        ItemInfo_.ItemNameName_ = SPRUCE_TREE_NAME;
        ItemInfo_.ItemSpwnPos_.x_pos = MineUtils::generateRandomDouble(-800, 800);
        ItemInfo_.ItemSpwnPos_.y_pos = MineUtils::generateRandomDouble(0.3, 100);
        ItemInfo_.ItemSpwnPos_.z_pos = MineUtils::generateRandomDouble(-800, 800);
        return 0;
    }
};

class Jungle_Tree : public MinecraftTree {
public:
    Jungle_Tree() {
        Jungle_Tree(0, BIOME_JUNGLE_WDLS);
    }
    Jungle_Tree(int biome_id, BiomeNames biome_name){
        std::vector<ItemNameEn> treedropitems = {JUNGLE_TREE_LEAVES};
        Jungle_Tree(biome_id, BIOME_JUNGLE_WDLS, treedropitems);
    }
    Jungle_Tree(int biome_id, BiomeNames biome_name, std::vector<ItemNameEn> dropItems) {
        ItemSpawnBiome_ = BIOME_JUNGLE_WDLS;
        ItemSpawnBiomeName_ = JUNGLE_TREE_BIOME_NAME;
        TreeDropItems_ = dropItems;
    }
    
    
    int initItemInfo() {
        ItemInfo_.ItemId_ = MineUtils::generateRandomId();
        ItemInfo_.ItemName_ = TREE_JUNGLE;
        ItemInfo_.ItemNameName_ = JUNGLE_TREE_NAME;
        ItemInfo_.ItemSpwnPos_.x_pos = MineUtils::generateRandomDouble(-800, 800);
        ItemInfo_.ItemSpwnPos_.y_pos = MineUtils::generateRandomDouble(0.3, 100);
        ItemInfo_.ItemSpwnPos_.z_pos = MineUtils::generateRandomDouble(-800, 800);
        return 0;
    }
};

#endif