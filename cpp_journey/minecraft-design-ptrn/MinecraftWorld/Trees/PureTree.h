#ifndef PURE_PURE_TREE_H
#define PURE_PURE_TREE_H

#include "../Utils/MineUtils.h"
#include "../Utils/ItemNames.h"
#include "../Utils/ItemStructs.h"
#include "../MinecraftItem/PureMinecraftItem.h"


class PureTree : public PureMinecraftItem {
protected:
    
    BiomeNames               ItemSpawnBiome_;
    std::vector<ItemNameEn>  TreeDropItems_;
    std::string              ItemSpawnBiomeName_;
public:
    virtual ~PureTree() = default;
    virtual int initItemInfo() const = 0;
    std::string getTreeBiomeName() { 
        std::cout << "Retrieved this tree's biome name: " << std::endl;

        return ItemSpawnBiomeName_;
    }
};

#endif