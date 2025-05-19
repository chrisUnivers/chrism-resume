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
    std::pair<std::string, std::string> biome_type_from_name(const std::string& biome_name_asked) {
        std::string s;
        std::string bio_name = "";
        std::stringstream parse_string(biome_name_asked);
        std::pair<std::string, std::string> bio_type_and_name;
        
        // woodlands flower forest
        while(std::getline(parse_string, s, ' ')) {
            if (BIOMETYPES_MAP.count(s)) {
                bio_type_and_name.first = s;
            } else {
                bio_name += s;
                bio_name += " ";
            }
        }
        bio_name.erase(bio_name.size() - 1);
        bio_type_and_name.second = bio_name;
        return bio_type_and_name;
    }
}
