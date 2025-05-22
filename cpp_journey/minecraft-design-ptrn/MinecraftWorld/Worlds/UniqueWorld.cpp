#include <memory>


#include <iostream>
#include "UniqueWorld.h"
// #include "WorldConstructors.h"
#include "../Utils/defaults.h"
#include "WorldConstructors.h"

BiomeTypes generate_biome(std::string biome_name);
void generate_plains_biome(PureWorld* world, int instance_count, std::string bio_name);
void generate_woodLands_biome(PureWorld* world, int instance_count, std::string bio_name);
template<typename T>
void handle_world_biomes(const T& attributes, std::unique_ptr<SpawnWorld> world_new);
void handle_world_creatures(const WorldAttributes& attributes, std::unique_ptr<SpawnWorld>& world_new);

UniqueWorld::UniqueWorld(){
}

void UniqueWorld::CreateWorld(const std::string& world_name, std::unique_ptr<PureWorld>& world, const WorldAttributes& attributes) const {
    
    std::cout << "this world is called: " << world_name << std::endl;
    std::unique_ptr<SpawnWorld> ol = std::make_unique<SpawnWorld>(world_name); // need to create biomes, food, creatures for this world then move ol back to the calling world, in this case <world>
    double temperature = ol->getWorldTemperature();
    std::future<void> biomes_future = std::async(std::launch::async, handle_world_biomes<WorldAttributes>, attributes, std::move(ol));
    // handle_world_biomes(attributes, ol);
    world = std::move(ol);

}

/** @param world the world to print its minecraft items
*/
void UniqueWorld::ListWorldItems(std::unique_ptr<PureWorld>&world) const {
    world->getPlainsBiomeTexture(0);
}

// Could pass in std::vector<std::pair<int, std::string>> which is what the function needs, attributes.BiomesAttributes_, but WorldAttributes keeps the function parameters more simple.
template<typename T>
void handle_world_biomes(const T& attributes, std::unique_ptr<SpawnWorld> world_new) {

    for (const auto& biome: attributes.BiomesAttributes_) {
        BiomeTypes bioType = generate_biome(biome.second); // biome.second is the name of the biome: ice spike plains.
        std::unique_ptr<SpawnWorld> world = std::make_unique<SpawnWorld>();
        switch(bioType) {
        case BIOME_PLAINS_BIOME: {
            generate_plains_biome(world_new.get(), biome.first, biome.second); // biome.first is the number of biomes to create.
            break;
        }
        case BIOME_WOODLANDS_BIOME: {
            // generate_plains_biome(world.get(), biome.first);
            break;
        }
        default:
            std::cout << "New Biomes" << std::endl;
        }        
    }
}

void handle_world_creatures(const WorldAttributes& attributes, std::unique_ptr<SpawnWorld>& world_new) {
    /** Currently the Classes for Creatures have not be created yet. */
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
void generate_plains_biome(PureWorld* world, int instance_count, std::string bio_name) {
    for (int i = 0; i < instance_count; i++) {
        std::unique_ptr<PlainsBiome> biome = std::make_unique<PlainsBiome>();
        std::unique_ptr<PureBiome> plains_biome; 
        // biome->CreateBiome("ice plains", plains_biome);
        biome->CreateBiome(bio_name, plains_biome);
        world->setPlainsBiome(plains_biome);
        // double bio_temperature = world->getWorldTemperature();
        // std::cout << "the temperature is: " << world->getWorldTemperature() << std::endl;
    }
}

void generate_woodLands_biome(PureWorld* world, int instance_count, std::string bio_name) {
    for (int i = 0; i < instance_count; i++) {
        std::unique_ptr<WoodLandsBiome> biome = std::make_unique<WoodLandsBiome>();
        std::unique_ptr<PureBiome> woodLands_biome; 
        biome->CreateBiome("ice plains", woodLands_biome);
        // world->setPlainsBiome(plains_biome);
        std::cout << "the temperature is: " << world->getWorldTemperature() << std::endl;
    }
}


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