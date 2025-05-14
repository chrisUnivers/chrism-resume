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
    int                           itemId_;      // random int generated
    double                        regen_effect_;
    SpawnItem                     spawnItem_;  // generated, crafted, or drop(leaves or apples)
    ItemTypes                     itemType_;
    ItemMake                      itemMake_;
    std::string                   itemName_;
    std::unique_ptr<ItemPosition> itemPosition_;
    FoodItem() : FoodItem("default-food-name") {};

    FoodItem(std::string food_name) : itemName_{food_name} {} 
};

struct FoodEffect {
    double life_regen_multiple;
    double duration;
    // struct: potion
};

#endif 