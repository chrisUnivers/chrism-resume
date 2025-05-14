#ifndef FOOD_H
#define FOOD_H

#include "PureFood.h"

class Food {
public:
    virtual ~Food() = default;
    virtual void CreateFood(std::string biome_name, std::unique_ptr<PureFood> &food) const = 0;
};

#endif