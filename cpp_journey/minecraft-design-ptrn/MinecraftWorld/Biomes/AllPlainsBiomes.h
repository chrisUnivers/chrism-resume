#ifndef ALL_PLAINS_BIOMES_H
#define ALL_PLAINS_BIOMES_H


#include "PlainsBiome.h"

class PlainsBiomePlains : public PlainsBiome {
private:
    std::unique_ptr<MinecraftBiomeInfo> uniqueBiomeInfo_;
public:
    PlainsBiomePlains(std::unique_ptr<MinecraftBiomeInfo> info) : PlainsBiome(std::move(info)) {}; 
    
    ~PlainsBiomePlains() {}

};
class PlainsBiomeIce : public PlainsBiome {
private:
    std::unique_ptr<MinecraftBiomeInfo> uniqueBiomeInfo_;
public:
    PlainsBiomeIce(std::unique_ptr<MinecraftBiomeInfo> info) : PlainsBiome(std::move(info)) {};

    ~PlainsBiomeIce() {};
};
#endif //ALL_PLAINS_BIOMES_H