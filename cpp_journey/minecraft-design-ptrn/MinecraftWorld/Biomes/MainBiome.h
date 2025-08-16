#ifndef MAIN_BIOME_H
#define MAIN_BIOME_H


#include <iostream>
#include "BiomesFactory.h"
#include "AllPlainsBiomes.h"

class MainBiome {
public: 
    std::unique_ptr<MinecraftBiome> createBiome(const BiomesFactory& factory, const BiomeVariationTypes& varType) {
        switch (varType)
        {
        case BiomeVariationTypes::BIOMEPL_PLAINS: {
            std::unique_ptr<MinecraftBiomeInfo> biomeInfo = factory.createBiomeInfo(varType);
        
            return std::make_unique<PlainsBiomePlains>(std::move(biomeInfo));
        }
        case BiomeVariationTypes::BIOMEPL_ICE: {
            std::unique_ptr<MinecraftBiomeInfo> biomeInfo = factory.createBiomeInfo(varType);

            return std::make_unique<PlainsBiomeIce>(std::move(biomeInfo));
        }
        default:
            std::cout << "The provided variation type is not valid" << std::endl;

        }
    }
    virtual ~MainBiome() = default;
};
#endif // MAIN_BIOME_H