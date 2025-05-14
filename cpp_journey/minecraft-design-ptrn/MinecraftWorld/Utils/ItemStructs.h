#ifndef ITEM_STRUCTS_H
#define ITEM_STRUCTS_H


#include <string>
#include "ItemNames.h"
/** * @brief struct for the biome blocks textures*/
struct BiomeTexture {
    std::string biomeBlocksSurface_;
    std::string biomeBlocksColour_;
    BiomeTexture() : BiomeTexture("default", "default") {};
    
    BiomeTexture(const std::string& biomeBlocksSurface, const std::string& bimomeBlocksColour) : biomeBlocksSurface_{biomeBlocksSurface}, biomeBlocksColour_{bimomeBlocksColour} {} // stored as strings since std::vectors requires a lot of memory. This means that I would need to create a method to process the string. since not a vector can't index biome_surf[0] or biome_surf[1]
};

struct ItemPosition {
    double x_pos, y_pos, z_pos;
    ItemPosition(double x, double y, double z) : x_pos{x}, y_pos{y}, z_pos{z} {}
};

struct FoodItem {
    int                           foodItemId_;      // random int generated
    double                        regenEffect_;
    SpawnItem                     spawnItem_;  // generated, crafted, or drop(leaves or apples)
    FoodItems                     foodItem_;
    ItemTypes                     itemType_;
    std::string                   foodName_;
    std::unique_ptr<ItemPosition> itemPosition_;
    std::unique_ptr<FoodEffect>   foodEffect_;
    FoodItem() : FoodItem(0, GENERATED_ITEM, FOOD_FOOD, NO_EFFECT) {};

    FoodItem(int food_id, SpawnItem spawn_item, FoodItems food_item, EffectName ef_name) : foodItemId_{food_id}, spawnItem_{spawn_item}, foodItem_{food_item} {
        foodName_ = FOODITEMSINV_MAP.count(food_item) ? FOODITEMSINV_MAP.at(food_item) : "";
        regenEffect_ = FOODREGEN_MAP.count(food_item) ? FOODREGEN_MAP.at(food_item) : 0.0;
        itemPosition_->x_pos = 0.0; itemPosition_->y_pos = 0.0; itemPosition_->z_pos = 0.0; // set to player's height when not in plyrs invetory.
        foodEffect_->effectName_ = ef_name;
    }
};

struct FoodEffect {
    EffectName effectName_;
    double duration;
    FoodEffect() : effectName_{NO_EFFECT} {};
    // struct: potion
};

#endif 