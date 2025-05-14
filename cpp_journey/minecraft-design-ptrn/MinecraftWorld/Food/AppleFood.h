#ifndef APPLE_FOOD_H
#define APPLE_FOOD_H

#include <string>
#include "../Utils/ItemNames.h"
#include "../Utils/ItemStructs.h"
#include "Food.h"
#include "MinecraftFood.h"

class AppleFood : public Food {
public:
    AppleFood();
    virtual ~AppleFood() = default;
    void CreateFood(std::string food_name, std::unique_ptr<PureFood>& food) const override;
};


#endif