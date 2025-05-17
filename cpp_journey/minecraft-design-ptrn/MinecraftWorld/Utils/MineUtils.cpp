#include <random>
#include <sstream>
#include "MineUtils.h"
#include "defaults.h"

namespace MineUtils {
    int generateRandomId() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> rndId;
        return rndId(rng);
    };

    /** @brief Parse the string return type of biome name. */
    std::string biome_type_from_name(const std::string& biome_name_asked) {
        std::string s;
        std::string biome_type_name;
        std::stringstream parse_string(biome_name_asked);
        
        while(std::getline(parse_string, s, ' ')) {
            if (BIOMETYPES_MAP.count(s)) {biome_type_name = s;}
        }
        return biome_type_name;
    }
}
