#ifndef MINE_UTILS_H
#define MINE_UTILS_H


#include "ItemNames.h"


namespace MineUtils {
    int generateRandomId();
    std::string biome_type_from_name(const std::string& biome_name_asked);
}

#endif