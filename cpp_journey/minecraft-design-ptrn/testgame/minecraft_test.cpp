#include "MainGameFx.h"


TEST_F(MainGameTest, maingametest_biome_factory_test_Test) {
    std::unique_ptr<BiomesFactory> factory;
    
    factory = std::make_unique<PlainsBiomeFactory>();

    
    auto biomeInfo_a = factory->createBiomeInfo(BIOMEPL_PLAINS);
    auto biomeInfo_b = factory->createBiomeInfo(BIOMEPL_PLAINS);
    EXPECT_EQ(
        1,
        biomeInfo_b->biomeId_
    );
    
    EXPECT_EQ(
        0,
        biomeInfo_a->biomeId_
    );

    EXPECT_EQ(
        gmFxExpectedPLSB_.expected_biome_name,
        biomeInfo_a->biomeName_
    );
}

TEST_F(MainGameTest, MainGameTest_createPlainsBiomePlains_Test) {
    std::unique_ptr<BiomesFactory> factory;
    factory = std::make_unique<PlainsBiomeFactory>();
    MainBiome mainBiome;
    
    std::unique_ptr<MinecraftBiome> plains = mainBiome.createBiome(*factory, BIOMEPL_PLAINS);
    
    EXPECT_EQ(
        gmFxExpectedPLSB_.expected_biome_name,
        plains->getBiomeName()
    );
}

TEST_F(MainGameTest, plainsbiomeice_createbiomeConfirmId_test) {
    std::unique_ptr<BiomesFactory> factory;
    factory = std::make_unique<PlainsBiomeFactory>();
    MainBiome mainBiome;

    std::unique_ptr<MinecraftBiome> plainsIce = mainBiome.createBiome(*factory, BIOMEPL_ICE);

    EXPECT_EQ(
        gmFxExpectedPLSB_.expected_biome_name_pl_ice,
        plainsIce->getBiomeName()
    );

    EXPECT_EQ(
        gmFxExpectedPLSB_.expected_biome_id_three,
        plainsIce->getBiomeId()
    );
}
    