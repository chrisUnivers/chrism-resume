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
    }// (CRAFTED_ITEM, FOOD_APPLE, LIFE_REGEN)
    AppleFood_Food(SpawnItem spaw_item, FoodItems food_item) : AppleFood_Food(spaw_item, food_item, NO_EFFECT) {}

    AppleFood_Food(SpawnItem spaw_item, FoodItems food_item, EffectName ef_name) {
        int food_id = MineUtils::generateRandomId();
        FoodItem_ = std::make_unique<FoodItem>(food_id, spaw_item, food_item);
        FoodItem_->foodName_ = FOODITEMSINV_MAP.count(food_item) ? FOODITEMSINV_MAP.at(food_item) : "";
        std::cout << "Food name is: " << FoodItem_->foodName_ << std::endl;
        FoodItem_->regenEffect_ = FOODREGEN_MAP.count(food_item) ? FOODREGEN_MAP.at(food_item) : 0.0;
        std::cout << "Food regen effect is: " << FoodItem_->regenEffect_ << std::endl;
        FoodItem_->itemPosition_ = std::make_unique<ItemPosition>(1.8, 3.8, 8.3); 
        std::cout << "Food position: " << FoodItem_->itemPosition_->x_pos << std::endl;
        // FoodItem_->itemPosition_->z_pos = 0.0; 
        // FoodItem_->itemPosition_->y_pos = 0.0;
        // FoodItem_->foodEffect_ = std::make_unique<FoodEffect>();
        // FoodItem_->foodEffect_->effectName_ = ef_name;
    }
};

#endif