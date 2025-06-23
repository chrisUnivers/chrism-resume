#include <random>
#include <iostream>

#include "generateWorld.h"


int MineCraftWorld::randId()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> rndId;
    return rndId(rng);
}