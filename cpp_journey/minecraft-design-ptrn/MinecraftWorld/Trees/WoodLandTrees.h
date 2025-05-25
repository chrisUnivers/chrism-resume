#ifndef WOODLAND_BIOME_TREES_H
#define WOODLAND_BIOME_TREES_H

#include <string>
#include "Tree.h"
#include "MinecraftTree.h"

class WoodLandTrees : public Tree {
public:
    WoodLandTrees();
    virtual ~WoodLandTrees() = default;
    void CreateTree(std::string tree_name, std::unique_ptr<PureTree> &tree) const override;
};


#endif