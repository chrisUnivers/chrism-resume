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
TEST_F(MainGameTest, woodlandsbiomeforest_createbiome_test) {
    std::unique_ptr<BiomesFactory> wdlsFactory;
    wdlsFactory = std::make_unique<WoodLandsBiomeFactory>();
    MainBiome mainBiomewdls;
    
    std::unique_ptr<MinecraftBiome> wdlsBiome = mainBiomewdls.createBiome(*wdlsFactory, BIOMEWDLS_FOREST);

    EXPECT_EQ(
        gmFxExpectedPLSB_.expected_biome_name_wdls_frs,
        wdlsBiome->getBiomeName()
    );
    EXPECT_EQ(
        gmFxExpectedPLSB_.expected_biome_id_four,
        wdlsBiome->getBiomeId()
    );
}
TEST_F(MainGameTest, spawnworld_useworldfactorynotrees__Test) {
    std::unique_ptr<WorldFactory> spnwldFactory;
    WorldFactoryUtils wldUtils;
    spnwldFactory = std::make_unique<SpawnWorldFactory>(wldUtils);

    std::vector<baseBiomeTplBiome> allBiomes{{BiomeTypes::BIOME_PLAINS_BIOME, gmWorldBiomesInputs_.trackBiomes_[0]}, {BiomeTypes::BIOME_WOODLANDS_BIOME, gmWorldBiomesInputs_.trackBiomes_[1]}};
    
    std::vector<treeTypeTpl> wldTrees{};

    std::unique_ptr<MinecraftWorldInfo> wldInfo = spnwldFactory->createWorldInfo(allBiomes, wldTrees, 0,gmWorldBiomesInputs_.worldNames_[0], WorldTypeNames::SPAWN_WORLD);
    
    EXPECT_EQ(
        gmFxExpectedPLSB_.expected_biome_name,
        wldInfo->worldBiomes_[0]->getBiomeName()
    );
}

TEST_F(MainGameTest, spawnworld_useworldfactoryaddtrees__Test) {
    std::unique_ptr<WorldFactory> spnwldFactory;
    WorldFactoryUtils wldUtils;
    spnwldFactory = std::make_unique<SpawnWorldFactory>(wldUtils);

    std::vector<baseBiomeTplBiome> allBiomes{{BiomeTypes::BIOME_PLAINS_BIOME, gmWorldBiomesInputs_.trackBiomes_[0]}, {BiomeTypes::BIOME_WOODLANDS_BIOME, gmWorldBiomesInputs_.trackBiomes_[1]}};
    
    std::vector<treeTypeTpl> wldTrees{std::tuple<int, WorldTreeType>(1, WorldTreeType::OAK_TREE), std::tuple<int, WorldTreeType>(3, WorldTreeType::SPRUCE_TREE)};

    std::unique_ptr<MinecraftWorldInfo> wldInfo = spnwldFactory->createWorldInfo(allBiomes, wldTrees, 4,gmWorldBiomesInputs_.worldNames_[0], WorldTypeNames::SPAWN_WORLD);
    
    EXPECT_EQ(
        gmFxExpectedPLSB_.expected_biome_name,
        wldInfo->worldBiomes_[0]->getBiomeName()
    );
}

TEST_F(MainGameTest, spawnworld_createworld__test) {
    std::unique_ptr<WorldFactory> spwnWldFactory;
    WorldFactoryUtils wldUtils;
    spwnWldFactory = std::make_unique<SpawnWorldFactory>(wldUtils);
    MainWorld mainWorld(std::move(spwnWldFactory));

    EXPECT_EQ(
        3,
        3
    );
}