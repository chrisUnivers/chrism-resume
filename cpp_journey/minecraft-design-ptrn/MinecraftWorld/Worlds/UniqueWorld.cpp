#include <memory>


#include <iostream>
#include "UniqueWorld.h"
// #include "WorldConstructors.h"
#include "../Utils/defaults.h"
#include "WorldConstructors.h"


BiomeTypes generate_biome(std::string biome_name);
void generate_plains_biome(PureWorld* world, int instance_count);
void handle_world_biomes(const WorldAttributes& attributes, std::unique_ptr<SpawnWorld>& world_new);
// void generate_woods_lands_biome(std::vector<WoodLandsBiome>& uqBiome, int instance_count, std::string biome_name);

UniqueWorld::UniqueWorld(){
}

void UniqueWorld::CreateWorld(const std::string& world_name, std::unique_ptr<PureWorld>& world, const WorldAttributes& attributes) const {
    
    std::cout << "this world is called: " << world_name << std::endl;
    
    std::unique_ptr<SpawnWorld> ol = std::make_unique<SpawnWorld>(); // need to create biomes, food, creatures for this world then move ol back to the calling world, in this case <world>
    double temperature = ol->getWorldTemperature();
    handle_world_biomes(attributes, ol);
    world = std::move(ol);

}

void handle_world_biomes(const WorldAttributes& attributes, std::unique_ptr<SpawnWorld>& world_new) {

    for (const auto& biome: attributes.BiomesAttributes_) {
        BiomeTypes bioType = generate_biome(biome.second);
        std::unique_ptr<SpawnWorld> world = std::make_unique<SpawnWorld>();
        switch(bioType) {
        case BIOME_PLAINS_BIOME: {
            generate_plains_biome(world.get(), biome.first);
            break;
        }
        case BIOME_WOODLANDS_BIOME: {
            generate_plains_biome(world.get(), biome.first);
            break;
        }
        default:
            std::cout << "New Biomes" << std::endl;
        }        
    }
}

void init_world_biomes(const std::vector<std::pair<int, std::string>>& biomes_info, std::unique_ptr<PureWorld>& world) {
    
}

/** @param biome_name name of the biome, plains biome or plains ice biome
 *  @return the enum Biome type, in this case plains is the type of biome
*/
BiomeTypes generate_biome(std::string biome_name) {
    BiomeTypes bioType;
    std::pair<std::string, std::string> bio_type_name = MineUtils::biome_type_from_name(biome_name); 
    // if the key is found in the map, assign its value.
    if (BIOMETYPES_MAP.count(bio_type_name.second)) {bioType = BIOMETYPES_MAP.at(bio_type_name.first);} else bioType = BIOME_PLAINS_BIOME; 
    return bioType;
    
}

/** @brief: receives name of biome, determines type of this biome from name. Then uses biome factory, following The Factory Method design, to genererate icount biomes of this type of biome. 
 * @attention: biome_name and not biome_type_name
*/
void generate_plains_biome(PureWorld* world, int instance_count) {
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