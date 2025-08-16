#ifndef WOODLANDS_BIOME_H
#define WOODLANDS_BIOME_H

#include "MinecraftBiome.h"
#include "WoodLandsBiomeFactory.h"

class WoodLandsBiome : public MinecraftBiome {
private:
    std::unique_ptr<MinecraftBiomeInfo> wdlsBiomeInfo_;
public:
    WoodLandsBiome(std::unique_ptr<MinecraftBiomeInfo> info) : wdlsBiomeInfo_(std::move(info)) {};

    int getBiomeId() const override {
        return wdlsBiomeInfo_->biomeId_;
    }
    
    
    BiomeTexture applyBiomeTexture() const override {
        return wdlsBiomeInfo_->biomeTexture_;
    }
    
    std::string getBiomeName() const override {
        return wdlsBiomeInfo_->biomeName_;
    }

    BiomeVariationTypes getBiomeUniqueType() const override {
        return wdlsBiomeInfo_->biomeUniqueType_;
    }

    double getbiomeWorldPercentage () const override {
        return wdlsBiomeInfo_->biomeWorldPercentage_;
    }
};

#endif // WOODLANDS_BIOME_H