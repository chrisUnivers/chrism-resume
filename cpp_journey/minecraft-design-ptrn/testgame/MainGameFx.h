#ifndef MAIN_GAME_FX_H
#define MAIN_GAME_FX_H


#include <gtest/gtest.h>
#include "../MinecraftWorld/Biomes/PlainsBiomeFactory.h"
#include "../MinecraftWorld/Biomes/AllPlainsBiomes.h"

struct ExpectedPlainsBiomePlains {
    std::string expected_biome_name = "Plains";
};

class MainGameTest : public testing::Test{

public:
    ExpectedPlainsBiomePlains gmFxExpectedPLSB_;
};


#endif // MAIN_GAME_FX_H