#ifndef FOOD_CONSTRUCTORS_H
#define FOOD_CONSTRUCTORS_H

#include <memory>
#include "MinecraftFood.h"
#include "../Utils/ItemStructs.h"
#include "../Utils/MineUtils.h"
#include <iostream>

class AppleFood_Food : public MinecraftFood {
public:
    AppleFood_Food() : AppleFood_Food(GENERATED_ITEM, FOOD_FOOD) {}
    AppleFood_Food(SpawnItem spaw_item) {
        int food_id = MineUtils::generateRandomId();
        FoodItem_ = std::make_unique<FoodItem>(food_id, spaw_item, FOOD_APPLE);
        // FoodItem(int food_id, SpawnItem spawn_item, FoodItems food_item)
    }
    AppleFood_Food(SpawnItem spaw_item, FoodItems food_item) : AppleFood_Food(spaw_item, food_item, NO_EFFECT) {}

    AppleFood_Food(SpawnItem spaw_item, FoodItems food_item, EffectName ef_name) {
        int food_id = MineUtils::generateRandomId();
        FoodItem_ = std::make_unique<FoodItem>(food_id, spaw_item, food_item, ef_name);
    }
};

#endif