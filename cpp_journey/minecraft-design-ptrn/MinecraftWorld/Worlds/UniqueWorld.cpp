#include <memory>


#include <iostream>
#include "UniqueWorld.h"
// #include "WorldConstructors.h"
#include "../Utils/defaults.h"
#include "WorldConstructors.h"


BiomeTypes generate_biome(std::string biome_name);
void generate_plains_biome(std::unique_ptr<PureWorld>& world, int instance_count);
void generate_woods_lands_biome(std::vector<WoodLandsBiome>& uqBiome, int instance_count, std::string biome_name);

UniqueWorld::UniqueWorld(){
}

void UniqueWorld::CreateWorld(const std::string& world_name, std::unique_ptr<PureWorld>& world, const WorldAttributes& attributes) const {
    
    std::cout << "this world is called: " << world_name << std::endl;
    
    std::unique_ptr<SpawnWorld> ol = std::make_unique<SpawnWorld>(); // need to create biomes, food, creatures for this world then move ol back to the calling world, in this case <world>
    double temperature = ol->getWorldTemperature();
    handle_world_biomes(attributes, ol);
    world = std::move(ol);

}

void handle_world_biomes(const WorldAttributes& attributes, std::unique_ptr<SpawnWorld>& world) {

    for (const auto& biome: attributes.BiomesAttributes_) {
        BiomeTypes bioType = generate_biome(biome.second);
        switch(bioType) {
        case BIOME_PLAINS_BIOME: {
            generate_plains_biome(world, biome.first);
            break;
        }
        case BIOME_WOODLANDS_BIOME: {
            generate_plains_biome(world, biome.first);
            break;
        }
        default:
            std::cout << "New Biomes" << std::endl;
        }        
    }
}

void init_world_biomes(const std::vector<std::pair<int, std::string>>& biomes_info, std::unique_ptr<PureWorld>& world) {
    
}

/** @brief: unlike generate_biome_cool, this method assumes the biome name it receives will be in the maps used below. Less cool but fast to implement.*/
BiomeTypes generate_biome(std::string biome_name) {
    BiomeTypes bioType;
    std::pair<std::string, std::string> bio_type_name = MineUtils::biome_type_from_name(biome_name); 
    // if the key is found in the map, assign its value.
    if (BIOMETYPES_MAP.count(bio_type_name.second)) {bioType = BIOMETYPES_MAP.at(bio_type_name.first);} 
    return bioType;
    
}

/** @brief: receives name of biome, determines type of this biome from name. Then uses biome factory, following The Factory Method design, to genererate icount biomes of this type of biome. 
 * @attention: biome_name and not biome_type_name
*/
void generate_plains_biome(std::unique_ptr<PureWorld>& world, int instance_count) {
    for (int i = 0; i < instance_count; i++) {
        std::unique_ptr<PlainsBiome> biome = std::make_unique<PlainsBiome>();
        std::unique_ptr<PureBiome> plains_biome; 
        biome->CreateBiome("ice plains", plains_biome);
        world->setPlainsBiome(plains_biome);
    }
}

void generate_woods_lands_biome(std::vector<WoodLandsBiome>& uqBiome, int instance_count, std::string biome_name) {}


void init_world_food(const std::vector<std::pair<int, std::string>>& biomes_info) {
    for (const auto& biome: biomes_info) {
        // generate_food(biome.first, biome.second);
    }
}


void init_world_trees(const std::vector<std::pair<int, std::string>>& biomes_info) {
    for (const auto& biome: biomes_info) {
        // generate_trees(biome.first, biome.second);
    }
}

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