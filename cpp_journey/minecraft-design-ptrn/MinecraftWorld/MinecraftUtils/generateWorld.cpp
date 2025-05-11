#include <random>
#include <iostream>

#include "generateWorld.h"
#include "./Blocks/DiamondBlock.h"

void MineCraftWorld::generateDiamonds() {
    for (int i = 0; i < TOTAL_NUMBER_OF_DIAMONDS; i++) {
        worldBlockIds_->emplace_back(randId());
        DiamondBlock(worldBlockIds_[worldBlockIds_->size() -1 ]);
    }
}

int MineCraftWorld::randId()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> rndId;
    return rndId(rng);
}