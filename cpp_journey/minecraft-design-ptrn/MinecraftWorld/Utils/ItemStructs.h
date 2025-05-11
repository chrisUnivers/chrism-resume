#ifndef ITEM_STRUCTS_H
#define ITEM_STRUCTS_H

#include <string>
/**
 * @param biomeBlocksSurface The biome surface of the blocks
 * @param bimomeBlocksColour The biome colour of the blocks
 */
struct BiomeTexture {
    std::string biomeBlocksSurface_;
    std::string biomeBlocksColour_;

    BiomeTexture(const std::string& biomeBlocksSurface, const std::string& bimomeBlocksColour) : biomeBlocksSurface_{biomeBlocksSurface}, biomeBlocksColour_{bimomeBlocksColour} {} 
};

#endif 