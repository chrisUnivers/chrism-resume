

#include <iostream>
#include "WoodLandTrees.h"
#include "../Utils/defaults.h"
#include "TreeConstructors.h"



WoodLandTrees::WoodLandTrees() {
}

void WoodLandTrees::CreateTree(std::string tree_name, std::unique_ptr<PureTree> &mtree) const {
    ItemNameEn tree;
    if (WDLSBIOMETREE_MAP.count(tree_name)) {tree = WDLSBIOMETREE_MAP.at(tree_name);}
    std::unique_ptr<SpruceTree_Tree> ol;
    switch (tree)
    {
    case TREE_SPRUCE: {
        std::unique_ptr<SpruceTree_Tree> ol = std::make_unique<SpruceTree_Tree>();
        
        std::cout << "Spruce tree constructed" << std::endl;
        std::string text_color = ol->getTreeBiomeName();
        std::cout << "the spawn biome of the tree: " << text_color << std::endl;
        int initInfo = ol->initItemInfo();
        mtree = std::move(ol);
        break;
    }
    case BIOME_ICE_SPIKE_PLAINS: {
        // std::unique_ptr<BiomeIceSpikePlains_Biome> ol = std::make_unique<BiomeIceSpikePlains_Biome>();
        // std::cout << "ice spike plains biome" << std::endl;
        // mBiome = std::move(ol);
        break;
    }
    default:
        std::unique_ptr<Jungle_Tree> ol = std::make_unique<Jungle_Tree>();
        // std::cout << "plains biome" << std::endl;
        mtree = std::move(ol);
    }
}
