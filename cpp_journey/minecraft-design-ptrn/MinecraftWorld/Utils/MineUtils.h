#ifndef MINE_UTILS_H
#define MINE_UTILS_H

// #include "ItemNames.h"
#include <iostream>
#include <random>
#include <sstream>

namespace MineUtils {
    int generateRandomId() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> rndId;
        return (rndId(rng) < 0 ? -1 * rndId(rng) : rndId(rng));
    };
    double generateRandomDouble(double min_value, double max_value);
}

#endif