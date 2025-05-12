#include <random>
#include "MineUtils.h"


namespace MineUtils {
    int generateRandomId() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> rndId;
        return rndId(rng);
    }
}
