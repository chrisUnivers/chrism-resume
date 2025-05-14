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
};


const std::map<std::string, FoodItems> FOODITEMS_MAP = {
    {"apple", FOOD_APPLE},
    {"diamond-apple", FOOD_DIAMOND_APPLE},
    {"wheat", FOOD_WHEAT},
    {"potato", FOOD_POTATO},
    {"chicken", FOOD_CHICKEN}
};

const std::map<FoodItems, std::string> FOODITEMSINV_MAP = {
    {FOOD_APPLE, "apple"},
    {FOOD_DIAMOND_APPLE, "diamond-apple"},
    {FOOD_WHEAT, "wheat"},
    {FOOD_POTATO, "potato"},
    {FOOD_CHICKEN, "chicken"}
};

const std::map<FoodItems, double> FOODREGEN_MAP = {
    {FOOD_APPLE, 8.8},
    {FOOD_WHEAT, 0.0},
    {FOOD_POTATO, 1.0},
    {FOOD_CHICKEN, 1.0}
};
