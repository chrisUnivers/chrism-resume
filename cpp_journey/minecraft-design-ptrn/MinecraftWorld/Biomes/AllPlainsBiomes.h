#ifndef ALL_PLAINS_BIOMES_H
#define ALL_PLAINS_BIOMES_H


#include "PlainsBiome.h"

class PlainsBiomePlains : public PlainsBiome {
private:
    std::unique_ptr<MinecraftBiomeInfo> uniqueBiomeInfo_;
public:
    PlainsBiomePlains(std::unique_ptr<MinecraftBiomeInfo> info) : uniqueBiomeInfo_(std::move(info)) {}; 
    

    int getBiomeId() const override {
        return uniqueBiomeInfo_->biomeId_;
    }
    
    std::string getBiomeName() const override {
        return uniqueBiomeInfo_->biomeName_;
    }
    
    BiomeTexture applyBiomeTexture() const override {
        return uniqueBiomeInfo_->biomeTexture_;
    }
    
    BiomeVariationTypes getBiomeUniqueType() const override{
        return uniqueBiomeInfo_->biomeUniqueType_;
    }

    double getbiomeWorldPercentage () const override {
        return uniqueBiomeInfo_->biomeWorldPercentage_;
    }

    ~PlainsBiomePlains() {}
};

#endif //ALL_PLAINS_BIOMES_H