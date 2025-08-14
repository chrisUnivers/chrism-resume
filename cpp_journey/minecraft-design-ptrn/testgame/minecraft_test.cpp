#include "MainGameFx.h"


TEST_F(MainGameTest, maingametest_biome_factory_test_Test) {
    std::unique_ptr<BiomesFactory> factory;
    
    factory = std::make_unique<PlainsBiomeFactory>();

    
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
        gmFxExpectedPLSB_.expected_biome_name,
        biomeInfo1->biomeName_
    );
}

TEST_F(MainGameTest, MainGameTest_createPlainsBiomePlains_Test) {
    std::unique_ptr<BiomesFactory> factory;
    factory = std::make_unique<PlainsBiomeFactory>();
    auto biomeInfo1 = factory->createBiomeInfo(BIOMEPL_PLAINS);
    auto biomeInfo3 = factory->createBiomeInfo(BIOMEPL_PLAINS);
    
    // std::unique_ptr<PlainsBiome> firstBiome = std::make_unique<UniqueBiome>(std::move(biomeInfo1));

    EXPECT_EQ(
        3,
        6
    );
}