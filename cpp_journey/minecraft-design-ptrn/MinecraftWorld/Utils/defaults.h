#include <map>
#include <string>


#include "ItemNames.h"

const std::map<std::string, BiomeNames> PLAINSBIOME_MAP = {
    {"plains", BIOME_PLAINS},
    {"ice plains", BIOME_ICE_PLAINS},
    {"ice spike plains", BIOME_ICE_SPIKE_PLAINS}
};

const std::map<std::string, BiomeNames> WOODLANDSBIOME_MAP = {
    {"forest", BIOME_FOREST_WDLS},
    {"flower forest", BIOME_FLOWER_FOREST_WDLS},
    {"birch forest", BIOME_BIRCH_FOREST_WDLS}
}; // WoodLandsBiome 
//BIOME_FOREST_WDLS, BIOME_FLOWER_FOREST_WDLS, BIOME_BIRCH_FOREST_WDLS
