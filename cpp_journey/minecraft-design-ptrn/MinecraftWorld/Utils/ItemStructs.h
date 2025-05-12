#ifndef ITEM_STRUCTS_H
#define ITEM_STRUCTS_H

#include <string>
/** * @brief struct for the biome blocks textures*/
struct BiomeTexture {
    std::string biomeBlocksSurface_;
    std::string biomeBlocksColour_;

    BiomeTexture(const std::string& biomeBlocksSurface, const std::string& bimomeBlocksColour) : biomeBlocksSurface_{biomeBlocksSurface}, biomeBlocksColour_{bimomeBlocksColour} {} 
};

class ItemPosition {
    double x_pos, y_pos, z_pos;
    ItemPosition(double x, double y, double z) : x_pos{x}, y_pos{y}, z_pos{z} {}
};

struct FoodEffect {
    double life_regen_multiple;
    // struct: potion
};

#endif 