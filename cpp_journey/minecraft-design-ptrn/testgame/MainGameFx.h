#ifndef MAIN_GAME_FX_H
#define MAIN_GAME_FX_H


#include <gtest/gtest.h>

#include "../MinecraftWorld/Biomes/MainBiome.h"

struct ExpectedPlainsBiomePlains {
    std::string expected_biome_name = "Plains";
    std::string expected_biome_name_pl_ice = "Plains ice"; 
    int expected_biome_id_three = 3;
};

class MainGameTest : public testing::Test{

public:
    ExpectedPlainsBiomePlains gmFxExpectedPLSB_;
};


#endif // MAIN_GAME_FX_H