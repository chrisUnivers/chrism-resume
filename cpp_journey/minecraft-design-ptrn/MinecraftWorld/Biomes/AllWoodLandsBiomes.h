#ifndef ALL_WOODLANDS_BIOMES_H
#define ALL_WOODLANDS_BIOMES_H


#include "WoodLandsBiome.h"

class WoodLandsBiomeForest : public WoodLandsBiome {
private:
    std::unique_ptr<MinecraftBiomeInfo> wdlsBiomeInfo_;
public:
    WoodLandsBiomeForest(std::unique_ptr<MinecraftBiomeInfo> info) : WoodLandsBiome(std::move(info)) {}; 
    
    virtual ~WoodLandsBiomeForest() = default;

};

#endif //ALL_WOODLANDS_BIOMES_H