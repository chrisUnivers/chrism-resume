#include <memory>

#include "UniqueWorld.h"
#include "../Utils/defaults.h"
#include "WorldConstructors.h"
#include <iostream>



UniqueWorld::UniqueWorld(){
}

void UniqueWorld::CreateWorld(const std::string& world_name, std::unique_ptr<PureWorld>& world, const WorldAttributes& attributes) const {
    generate_biome(attributes.BiomesAttributes_.first, attributes.BiomesAttributes_.second);
}

// std::unique_ptr<WorldOne_One> ol = std::make_unique<WorldOne_One>(1, WORLD_ONE_WORLD, vBiome);
/** @brief: receives name of biome, determines type of this biome from name. Then uses biome factory, following The Factory Method design, to genererate icount biomes of this type of biome.
 * @param biome_name the name of this biome. The name contains the type of biome 'plains ice biome or ice plains biomme' the type is plains 
 * @param icount how many biomes of this type to create. the function
*/
void generate_biome(int icount, std::string biome_name) {
    BiomeTypes bioType;
    std::string bio_type_name = MineUtils::biome_type_from_name(biome_name); // plains, plains ice, plains ice spikes or woodlands flower forest. Only need plains or woodlands, so type of biome name.
    
    std::cout << "biome type name: " << bio_type_name << std::endl;
    return;
    if (BIOMETYPES_MAP.count(bio_type_name)) {bioType = BIOMETYPES_MAP.at(bio_type_name);} /**Need to change implementation below. I now only care about the type and not so much the name of the biome. This helps keep this function small since I would only be using the types and not the names of biomes. Need to use the MineUtils::biome_type_from_name function. */
    switch(bioType) {
    case BIOME_PLAINS_BIOME: {
        std::vector<PlainsBiome> vBiome;
        generate_plains_biome(vBiome, icount, biome_name);
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
void generate_plains_biome(std::vector<PlainsBiome>& uqBiome, int instance_count, std::string biome_name) {
    for (int i = 0; i < instance_count; i++) {
        std::unique_ptr<PlainsBiome> biome = std::make_unique<PlainsBiome>();
        std::unique_ptr<PureBiome> plains_biome; 
        biome->CreateBiome(biome_name, plains_biome);
        uqBiome.emplace_back(*plains_biome);
    }
}

void generate_woods_lands_biome(std::vector<WoodLandsBiome>& uqBiome, int instance_count, std::string biome_name) {}