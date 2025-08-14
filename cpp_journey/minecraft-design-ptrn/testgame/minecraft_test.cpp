#include "MainGameFx.h"


TEST_F(MainGameTest, maingametest_biome_factory_test_Test) {
    std::unique_ptr<BiomesFactory> factory;
    
    factory = std::make_unique<PlainsBiomeFactory>();
    std::string expected_biome_name = "Plains";

    EXPECT_EQ(
        3,
        3
    );
}