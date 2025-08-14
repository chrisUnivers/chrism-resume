#include "MainGameFx.h"


TEST_F(MainGameTest, maingametest_biome_factory_test_Test) {
    std::unique_ptr<BiomesFactory> factory;
    factory = std::make_unique<PlainsBiomeFactory>();
    std::string expected_biome_name = "Plains";

    
    auto biomeInfo1 = factory->createBiomeInfo(BIOMEPL_PLAINS);
    auto biomeInfo3 = factory->createBiomeInfo(BIOMEPL_PLAINS);
    EXPECT_EQ(
        1,
        biomeInfo3->biomeId_
    );
    
    EXPECT_EQ(
        0,
        biomeInfo1->biomeId_
    );

    EXPECT_EQ(
        expected_biome_name,
        biomeInfo1->biomeName_
    );
}