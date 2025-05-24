#ifndef PURE_WORLD_H
#define PURE_WORLD_H

#include <string>
#include <iostream>
#include <memory>
#include <mutex>
#include "../Utils/MineUtils.h"
#include "../Utils/ItemNames.h"
#include "../Utils/ItemStructs.h"
#include "../Biomes/PlainsBiome.h"
#include "../Trees/WoodLandTrees.h"

class PureWorld {
protected:
    int                                          WorldId_;
    std::string                                  WorldName_;
    std::unique_ptr<WorldClimate>                WorldClimate_;
    std::vector<std::unique_ptr<PureBiome>>      WorldPlainsBiomes_;
    std::vector<std::pair<std::string, int>>     WorldCreationItems_;

    std::vector<std::unique_ptr<PureTree>>       WorldTrees_;
    std::vector<std::unique_ptr<PureBiome>>      WorldBiomes_;

    mutable std::mutex plains_biome_mutex;
    // mutex for trees in different biomes.
    mutable std::mutex woodLands_trees_mutex;
    public:
    PureWorld() {};
    virtual ~PureWorld() = default;
    double getWorldTemperature() { 
        std::cout << "Temperature Temperature" << std::endl; 
        return WorldClimate_->temperature;
    }

    void setPlainsBiome(std::unique_ptr<PureBiome>& mBiome) {
        std::lock_guard<std::mutex> lock(plains_biome_mutex);
        WorldPlainsBiomes_.emplace_back(std::move(mBiome));
    }
    void setWorldTree(std::unique_ptr<PureTree>& mTree) {
        std::lock_guard<std::mutex> lock(woodLands_trees_mutex);
        WorldTrees_.emplace_back(std::move(mTree));
    }
    void getPlainsBiomeTexture(int nth_bio) {
        std::cout << "world plains biomes count is: " << WorldPlainsBiomes_.size() << std::endl;
        if (WorldPlainsBiomes_.size() > nth_bio) {
            std::string bio_colour = WorldPlainsBiomes_[nth_bio]->getBiomeColour();
            std::cout << "The " << nth_bio << " colour is: " << bio_colour << std::endl;
        }
    }
    void setClimate() {
        WorldClimate_->temperature = 33.7;
    }
};

#endif