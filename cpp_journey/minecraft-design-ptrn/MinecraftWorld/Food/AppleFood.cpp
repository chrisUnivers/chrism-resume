#include <memory>

#include "AppleFood.h"
#include "../Utils/defaults.h"
#include "FoodConstructors.h"
#include <iostream>



AppleFood::AppleFood(){
}

void AppleFood::CreateFood(std::string food_name, std::unique_ptr<PureFood>& mFood) const {
    FoodItems food;
    if (FOODITEMS_MAP.count(food_name)) {food = FOODITEMS_MAP.at(food_name); }
    switch(food) {
    case FOOD_APPLE: {
        std::unique_ptr<AppleFood_Food> ol = std::make_unique<AppleFood_Food>(CRAFTED_ITEM, FOOD_APPLE, LIFE_REGEN);
        mFood = std::move(ol);
        break;
    }
    default:

        break;
    }    
}

//BIOME_FOREST_WDLS, BIOME_FLOWER_FOREST_WDLS, BIOME_BIRCH_FOREST_WDLS