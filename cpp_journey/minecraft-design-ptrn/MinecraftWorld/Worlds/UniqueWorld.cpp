#include <memory>


#include <iostream>
#include "UniqueWorld.h"
// #include "WorldConstructors.h"
#include "../Utils/defaults.h"


void generate_biome(int icount, std::string biome_name);
void generate_plains_biome(std::vector<std::unique_ptr<PureBiome>>& uqBiome, int instance_count, std::string biome_name);
void generate_woods_lands_biome(std::vector<WoodLandsBiome>& uqBiome, int instance_count, std::string biome_name);

UniqueWorld::UniqueWorld(){
}

void UniqueWorld::CreateWorld(const std::string& world_name, std::unique_ptr<PureWorld>& world, const WorldAttributes& attributes) const {
    std::cout << "this world is called: " << world_name << std::endl;
    generate_biome(attributes.BiomesAttributes_.first, attributes.BiomesAttributes_.second);
}


/** @brief: unlike generate_biome_cool, this method assumes the biome name it receives will be in the maps used below. Less cool but fast to implement.*/
void generate_biome(int icount, std::string biome_name) {
    BiomeTypes bioType;
    std::pair<std::string, std::string> bio_type_name = MineUtils::biome_type_from_name(biome_name); // plains, plains ice, plains ice spikes or woodlands flower forest. Only need plains or woodlands, so type of biome name.
    std::string mstr = "biomes";
    std::cout << "biome type: " << bio_type_name.first << std::endl;
    if (BIOMETYPES_MAP.count(bio_type_name.second)) {bioType = BIOMETYPES_MAP.at(bio_type_name.first);} // if the key is found in the map, assign its value.
    std::cout << "length of biome type is: " << mstr.size() << std::endl;

    switch(bioType) {
    case BIOME_PLAINS_BIOME: {
        std::vector<std::unique_ptr<PureBiome>> vBiome;
        generate_plains_biome(vBiome, icount, biome_name);
        for (const auto& bio_me : vBiome) {
            std::cout << "Getting the colours of the each bio_me" << std::endl;
            bio_me->getBiomeColour();
        }
        break;
    }
    case BIOME_WOODLANDS_BIOME: {
        std::vector<WoodLandsBiome> vBiome;
        generate_woods_lands_biome(vBiome, icount, biome_name);
        break;
    }
    default:
        std::cout << "New Biomes" << std::endl;
    }
}


// std::unique_ptr<WorldOne_One> ol = std::make_unique<WorldOne_One>(1, WORLD_ONE_WORLD, vBiome);
/** @brief: receives name of biome, determines type of this biome from name. Then uses biome factory, following The Factory Method design, to genererate icount biomes of this type of biome.*/

/**The cool version of the method: genearte_biome. For this to work, need to implement an ordering system. For now using default generate_biome. */
void cool_generate_biome(int icount, std::string biome_name) {
    BiomeTypes bioType;
    // std::string bio_type_name = MineUtils::biome_type_from_name(biome_name); // plains, plains ice, plains ice spikes or woodlands flower forest. Only need plains or woodlands, so type of biome name.
    
    // std::cout << "biome type name: " << bio_type_name << std::endl;
    // if (BIOMETYPES_MAP.count(bio_type_name)) {bioType = BIOMETYPES_MAP.at(bio_type_name);} 
    /**Need to change implementation below. I now only care about the type and not so much the name of the biome. This helps keep this function small since I would only be using the types and not the names of things. Need to use the MineUtils::biome_type_from_name function. */
    switch(bioType) {
    case BIOME_PLAINS_BIOME: {
        std::vector<std::unique_ptr<PureBiome>> vBiome;
        generate_plains_biome(vBiome, icount, biome_name);
        vBiome[0]->getBiomeColour();
        break;
    }
    case BIOME_WOODLANDS_BIOME: {
        std::vector<WoodLandsBiome> vBiome;
        generate_woods_lands_biome(vBiome, icount, biome_name);
        break;
    }
    default:
        std::cout << "New Biomes" << std::endl;
    }
}

/** @attention: biome_name and not biome_type_name  */
void generate_plains_biome(std::vector<std::unique_ptr<PureBiome>>& uqBiome, int instance_count, std::string biome_name) {
    for (int i = 0; i < instance_count; i++) {
        std::unique_ptr<PlainsBiome> biome = std::make_unique<PlainsBiome>();
        std::unique_ptr<PureBiome> plains_biome; 
        biome->CreateBiome("ice plains", plains_biome);
        uqBiome.emplace_back(std::move(plains_biome));
    }
}

void generate_woods_lands_biome(std::vector<WoodLandsBiome>& uqBiome, int instance_count, std::string biome_name) {}