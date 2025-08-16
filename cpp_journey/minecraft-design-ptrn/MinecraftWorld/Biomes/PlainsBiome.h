#ifndef PLAINS_BIOME_H
#define PLAINS_BIOME_H

#include "MinecraftBiome.h"
#include "PlainsBiomeFactory.h"

class PlainsBiome : public MinecraftBiome {
private:
    std::unique_ptr<MinecraftBiomeInfo> uniqueBiomeInfo_;
public:
    PlainsBiome(std::unique_ptr<MinecraftBiomeInfo> info) : uniqueBiomeInfo_(std::move(info)) {};

    int getBiomeId() const override {
        return uniqueBiomeInfo_->biomeId_;
    }
    
    BiomeTexture applyBiomeTexture() const override {
        return uniqueBiomeInfo_->biomeTexture_;
    }
    
    std::string getBiomeName() const override {
        return uniqueBiomeInfo_->biomeName_;
    }

    BiomeVariationTypes getBiomeUniqueType() const override {
        return uniqueBiomeInfo_->biomeUniqueType_;
    }

    double getbiomeWorldPercentage () const override {
        return uniqueBiomeInfo_->biomeWorldPercentage_;
    }
};

#endif // PLAINS_BIOME_H