#include <iostream>


#include "WoodLandTrees.h"
#include <memory>

int main() { 
    // plains, ice plains, ice spike plains
    std::unique_ptr<WoodLandTrees> biome = std::make_unique<WoodLandTrees>();
    std::unique_ptr<PureTree> spruce_tree;
    biome->CreateTree("Spruce tree", spruce_tree);
    std::cout << "The tree's name in test is: " << spruce_tree->getItemInfoName() << std::endl;
    std::cout << "Biomes need a description!" << std::endl;
    return 0;
}