#ifndef MAIN_BIOME_H
#define MAIN_BIOME_H


#include <iostream>
#include "BiomesFactory.h"
#include "AllPlainsBiomes.h"
#include "AllWoodLandsBiomes.h"
class MainBiome {
public: 
    std::unique_ptr<MinecraftBiome> createBiome(const BiomesFactory& factory, const BiomeVariationTypes& varType) {
        switch (varType)
        {
        case BiomeVariationTypes::BIOMEPL_PLAINS: {
            std::unique_ptr<MinecraftBiomeInfo> biomeInfo = factory.createBiomeInfo(varType);
            // std::unique_ptr<PlainsBiomePlains> biome = std::make_unique<PlainsBiomePlains>(std::move(biomeInfo));
            return std::make_unique<PlainsBiomePlains>(std::move(biomeInfo));
        }
        case BiomeVariationTypes::BIOMEPL_ICE: {
            std::unique_ptr<MinecraftBiomeInfo> biomeInfo = factory.createBiomeInfo(varType);

            return std::make_unique<PlainsBiomeIce>(std::move(biomeInfo));
        }
        case BiomeVariationTypes::BIOMEWDLS_FOREST: {
            std::unique_ptr<MinecraftBiomeInfo> wdlsBioInfo = factory.createBiomeInfo(varType);

            return std::make_unique<WoodLandsBiomeForest>(std::move(wdlsBioInfo));
        }
        default:
            std::cout << "The provided variation type in MainBiome is not valid" << std::endl;
            return nullptr;
        }
    }
    virtual ~MainBiome() = default;
};
#endif // MAIN_BIOME_H