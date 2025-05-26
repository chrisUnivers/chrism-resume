#ifndef MINE_UTILS_H
#define MINE_UTILS_H


#include <iostream>
#include "ItemNames.h"

namespace MineUtils {
    int generateRandomId();
    std::pair<std::string, std::string> biome_type_from_name(const std::string& biome_name_asked);
    std::pair<std::string, std::string> fn_type_from_name(const std::string& input_item_name, const MinecraftItemTypes known_item_type);
    double generateRandomDouble(double min_value, double max_value);
}

#endif