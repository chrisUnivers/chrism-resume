#ifndef ITEM_STRUCTS_H
#define ITEM_STRUCTS_H


#include <string>
#include <memory>
#include "ItemNames.h"
// #include "defaults.h"
/** * @brief struct for the biome blocks textures*/
struct BiomeTexture {
    std::string biomeBlocksSurface_;
    std::string biomeBlocksColour_;
    BiomeTexture() : BiomeTexture("default", "default") {};
    
    BiomeTexture(const std::string& biomeBlocksSurface, const std::string& bimomeBlocksColour) : biomeBlocksSurface_{biomeBlocksSurface}, biomeBlocksColour_{bimomeBlocksColour} {} // stored as strings since std::vectors requires a lot of memory. This means that I would need to create a method to process the string. since not a vector can't index biome_surf[0] or biome_surf[1]
};

struct ItemPosition {
    double x_pos;
    double y_pos;
    double z_pos;
    ItemPosition() : ItemPosition(0.0, 0.0, 0.0) {};
    ItemPosition(double x, double y, double z) : x_pos{x}, y_pos{y}, z_pos{z} {}
};

struct FoodEffect {
    EffectName effectName_;
    double duration;
    FoodEffect() : effectName_{NO_EFFECT} {};
    // struct: potion
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
    FoodItem() : FoodItem(0, GENERATED_ITEM, FOOD_FOOD) {};

    FoodItem(const int food_id, const SpawnItem spawn_item, const FoodItems food_item) : foodItemId_{food_id}, spawnItem_{spawn_item}, foodItem_{food_item} {
        
    }
};

struct WorldClimate {
    double temperature;

    WorldClimate() : WorldClimate(18.0) {};
    WorldClimate(double world_temperature) : temperature{world_temperature} {}
};

#endif 