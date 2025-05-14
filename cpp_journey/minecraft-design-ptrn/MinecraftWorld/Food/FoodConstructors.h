#ifndef FOOD_CONSTRUCTORS_H
#define FOOD_CONSTRUCTORS_H

#include <memory>
#include "MinecraftFood.h"
#include "../Utils/ItemStructs.h"
#include "../Utils/MineUtils.h"
#include <iostream>

class AppleFood_Food : public MinecraftFood {
public:
    AppleFood_Food() : AppleFood_Food(0) {}
    AppleFood_Food(int food_id){
        FoodItem_ = std::make_unique<FoodItem>();
        FoodId_ = food_id;
    }
    AppleFood_Food(SpawnItem spaw_item) {
        int food_id = 
        FoodItem_ = std::make_unique<FoodItem>(food_id, spaw_item, FOOD_APPLE);
        // FoodItem(int food_id, SpawnItem spawn_item, FoodItems food_item)
    }
};

#endif