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

    double generateRandomDouble(double min_value, double max_value) { //https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_real_distribution<> rndDouble(min_value, max_value);
        return rndDouble(rng);
    }


    /** @return std::pair<string, string> type_name: 1st = type.  */
    std::pair<std::string, std::string> biome_type_from_name(const std::string& biome_name_asked) {
        std::string s;
        std::string bio_name = "";
        std::stringstream parse_string(biome_name_asked);
        std::pair<std::string, std::string> bio_type_and_name;
        
        // woodlands flower forest
        while(std::getline(parse_string, s, ' ')) {
            if (BIOMETYPES_MAP.count(s)) {
                bio_type_and_name.first = s; // woodlands for example
            } else {
                bio_name += s;
                bio_name += " ";
            }
        }
        bio_name.erase(bio_name.size() - 1);
        bio_type_and_name.second = bio_name;
        return bio_type_and_name;
    }

    /** @return std::pair<string, string> 1st: type_enum and 2nd: name of item(spruce tree) */
    std::pair<std::string, std::string> fn_type_from_name(const std::string& input_item_name, const MinecraftItemTypes known_item_type) {
        std::string s;
        std::string common_name = "";
        std::stringstream parse_string(input_item_name);
        std::pair<std::string, std::string> type_and_name;
        
        // woodlands flower forest
        while(std::getline(parse_string, s, ' ')) {
            switch(known_item_type) {
            case BIOME: {
                if (BIOMETYPES_MAP.count(s)) {
                    type_and_name.first = s; // woodlands for example
                } else {
                    common_name += s;
                    common_name += " ";
                }
                break;
            }
            case TREE: {
                if (TREETYPES_MAP.count(s)) {
                    type_and_name.first = s; // woodlands for example
                } else {
                    common_name += s;
                    common_name += " ";
                }
                // woodlands for example
                break;
            }
            default:
                std::cout << "MineUtils parsed the input" << std::endl;
                break;
            }
        }
        common_name.erase(common_name.size() - 1); // remove space at the end.
        type_and_name.second = common_name;
        return type_and_name;
    }
}
