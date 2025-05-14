#ifndef PURE_BIOME_H
#define PURE_BIOME_H

#include <string>
#include <iostream>
#include <memory>
#include "../Utils/MineUtils.h"
#include "../Utils/ItemNames.h"
#include "../Utils/ItemStructs.h"
class PureBiome {
protected:
    // something like uuid can be used instead of a normal int.
    int          BiomeId_;
    BiomeNames    BiomeName_;
    std::unique_ptr<BiomeTexture> BiomeTexture_;
    // std::unique_ptr<BiomeTexture> BiomeTexture_;
    double       BiomeWorldPercentage_; 
public:
    virtual ~PureBiome() = default;
    std::string getBiomeColour() { 
        std::cout << "pure Biome ggt: " << std::endl; 
        return BiomeTexture_->biomeBlocksColour_;
    }
};

#endif