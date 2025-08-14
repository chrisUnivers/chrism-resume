#ifndef STATIC_UTILS_H
#define STATIC_UTILS_H


#include <vector>

namespace StaticUtils {
    inline std::vector<int>& getAllPlainsBiomeIds() {
        static std::vector<int> allPlainsBiomeIds_;
        return allPlainsBiomeIds_;
    }
    inline int addIdToPlainsBiome() {
        auto & plBiomeIds = getAllPlainsBiomeIds();
        int newId = plBiomeIds.size();
        plBiomeIds.emplace_back(newId);
        return newId;
    }
};
#endif // STATIC_UTILS_H