#ifndef MAIN_GAME_FX_H
#define MAIN_GAME_FX_H


#include <gtest/gtest.h>
#include "../MinecraftWorld/Worlds/MainWorld.h"
#include "../MinecraftWorld/Biomes/MainBiome.h"

struct ExpectedPlainsBiomePlains {
    std::string expected_biome_name = "Plains";
    std::string expected_biome_name_pl_ice = "Plains ice"; 
    std::string expected_biome_name_wdls_frs = "WoodLands forest";
    std::string expected_wld_name = "cool world";
    int expected_biome_id_three = 3;
    int expected_biome_id_four = 4;
};
struct WorldInput {
    std::vector<std::tuple<int, BiomeVariationTypes>> trackBiomes_{std::tuple<int, BiomeVariationTypes>(1, BiomeVariationTypes::BIOMEPL_PLAINS), std::tuple<int, BiomeVariationTypes>(3, BiomeVariationTypes::BIOMEWDLS_FOREST)};
    std::vector<std::string> worldNames_{"cool world"};
};

class MainGameTest : public testing::Test{

public:
    ExpectedPlainsBiomePlains gmFxExpectedPLSB_;
    WorldInput gmWorldBiomesInputs_;  
};

#endif // MAIN_GAME_FX_H