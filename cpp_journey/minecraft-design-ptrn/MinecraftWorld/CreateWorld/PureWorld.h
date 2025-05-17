#ifndef PURE_WORLD_H
#define PURE_WORLD_H


#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "../Utils/MineUtils.h"
#include "../Utils/ItemNames.h"
#include "../Utils/ItemStructs.h"

class PureWorld {
protected:
    int                           WorldId_;
    BiomeNames                    WorldName_;
    std::unique_ptr<WorldClimate> WorldClimate_;
    std::vector<PlainsBiome>      WorldPlainsBiomes_;
    std::vector<std::pair<std::string, int>> WorldCreationItems_;
public:
    virtual ~PureWorld() = default;
    double getWorldTemperature() { 
        std::cout << "The temperature is: " << std::endl; 
        return WorldClimate_->temperature;
    }
};

#endif