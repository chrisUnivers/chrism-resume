// #ifndef PURE_WORLD_H
// #define PURE_WORLD_H

// #include <string>
// #include <iostream>
// #include <memory>
// #include <mutex>
// #include "../Utils/MineUtils.h"
// #include "../Utils/ItemNames.h"
// #include "../Utils/ItemStructs.h"
// #include "../Biomes/PlainsBiome.h"
// #include "../Trees/WoodLandTrees.h"

// class PureWorld {
// protected:
//     int                                          WorldId_;
//     std::string                                  WorldName_;
//     std::unique_ptr<WorldClimate>                WorldClimate_;
//     std::vector<std::unique_ptr<PureBiome>>      WorldPlainsBiomes_;
//     std::vector<std::pair<std::string, int>>     WorldCreationItems_;

//     std::vector<std::unique_ptr<PureTree>>       WorldTrees_;
//     std::vector<std::unique_ptr<PureBiome>>      WorldBiomes_;

// public:
//     PureWorld() {};
//     virtual ~PureWorld() = default;
//     double getWorldTemperature() { 
//         std::cout << "Temperature Temperature" << std::endl; 
//         return WorldClimate_->temperature;
//     }

//     void setClimate() {
//         WorldClimate_->temperature = 33.7;
//     }
// };

// #endif