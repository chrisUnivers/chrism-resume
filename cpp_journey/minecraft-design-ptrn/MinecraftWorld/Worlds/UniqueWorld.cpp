#include <memory>


#include <iostream>
#include "UniqueWorld.h"
// #include "WorldConstructors.h"
#include "../Utils/defaults.h"
#include "WorldConstructors.h"

BiomeTypes generate_biome(std::string biome_name);
template<typename oI, typename oStr>
void generate_plains_biome(std::unique_ptr<SpawnWorld>& world, oI instance_count, oStr bio_name);
void generate_woodLands_biome(PureWorld* world, int instance_count, std::string bio_name);
template<typename T>
std::unique_ptr<SpawnWorld> handle_world_biomes(const T& attributes, std::unique_ptr<SpawnWorld> world_new);
void handle_world_creatures(const WorldAttributes& attributes, std::unique_ptr<SpawnWorld>& world_new);

ItemNameEn generate_tree(std::string tree_name);
template<typename S>
std::unique_ptr<SpawnWorld> handle_world_trees(const S& attributes, std::unique_ptr<SpawnWorld> world_new);
void generate_spruce_biome(std::unique_ptr<SpawnWorld>& world, int instance_count, std::string bio_name);

UniqueWorld::UniqueWorld(){
}

void UniqueWorld::CreateWorld(const std::string& world_name, std::unique_ptr<PureWorld>& world, const WorldAttributes& attributes) const {
    
    std::cout << "this world is called: " << world_name << std::endl;
    std::unique_ptr<SpawnWorld> ol = std::make_unique<SpawnWorld>(world_name);
    
    /** NOTE: Each handle_something_function() has it's own future for concurrency. */
    std::future<std::unique_ptr<SpawnWorld>> biomes_future = std::async(handle_world_biomes<WorldAttributes>, attributes, std::move(ol));
    
    ol = std::move(biomes_future.get()); // update ol with created biomes

    // std::future<std::unique_ptr<SpawnWorld>> trees_future = std::async(handle_world_trees<WorldAttributes>, attributes, std::move(ol));
    
    // ol = std::move(trees_future.get()); // update ol with created trees
   
    world = std::move(ol);
}

/** @param world the world to print its minecraft items
*/
void UniqueWorld::ListWorldItems(std::unique_ptr<PureWorld>&world) const {
    world->getPlainsBiomeTexture(0);
}


/** @note only one thread works in this function to create biomes.
 *  @return return the world passed in since it has been changed and the futures do not allow to pass values by reference.
 */
template<typename T>
std::unique_ptr<SpawnWorld> handle_world_biomes(const T& attributes, std::unique_ptr<SpawnWorld> world_new) {

    std::vector<std::future<void>> gen_future; // vector of futures to generate biomes.
    const std::vector<std::pair<int, std::string>>::iterator this_itor = attributes.BiomesAttributes_.begin();
    const std::vector<std::pair<int, std::string>>::iterator end_itor = attributes.BiomesAttributes_.end();
    while ((this_itor != end_itor)) {
        if (gen_future.size <= LIMIT_THREAD_USE) {
            int num_biomes = (*this_itor).first;
            std::string name_biome = (*this_itor).second;
            BiomeTypes bioType = generate_biome(name_biome);
            switch(bioType) {
            case BIOME_PLAINS_BIOME: {
                gen_future.push_back(std::async(generate_plains_biome<int, std::string>, std::move(world_new), num_biomes, name_biome));// generate plains biomes for world_new.
                break;
            }
            case BIOME_WOODLANDS_BIOME: {
                // generate_woodLands_biome(world_new, num__biomes, bio__name) // generate woodLands biomes for this world.
                break;
            }
            default:
                std::cout << "New Biomes" << std::endl;
            }

            std::advance(this_itor, ITOR_ADVANCE);
        }
        else {
            for (auto vec_itor = gen_future.begin(); vec_itor != gen_future.end(); vec_itor++) {
                world_new->setPlainsBiome(vec_itor->get()); // get biome create by this thread and add it to the world.
                vec_itor = gen_future.erase(vec_itor);
            }
        }
        
    }
    return world_new;
}

template<typename S>
std::unique_ptr<SpawnWorld> handle_world_trees(const S& attributes, std::unique_ptr<SpawnWorld> world_new) {

    for (const auto& tree: attributes.TreesAttributes_) {
        ItemNameEn treeType = generate_tree(tree.second); // tree.second is the name of the tree: ice spike plains.
        int num__trees = tree.first;
        std::string tree__name = tree.second;
        switch(treeType) {
        case TREE_SPRUCE: {
            generate_spruce_tree(world_new, num__spcTrees, tree__name); // generate spruce trees for world_new.
            break;
        }
        case TREE_JUNGLE: {
            // generate_jungle_trees(world_new, num__trees, tree__name) // generate jungle trees for this world.
            break;
        }
        default:
            std::cout << "New Trees" << std::endl;
        }
    }
    return world_new;
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
    
ItemNameEn generate_tree(std::string tree_name) {

}

/** @param world the reference to the world passed in.
 *  @attention Will modify the biome values of this object.
*/
template<typename oI, typename oStr>
void generate_plains_biome(std::unique_ptr<SpawnWorld>& world, oI instance_count, oStr bio_name) {
    for (int i = 0; i < instance_count; i++) {
        std::unique_ptr<PlainsBiome> biome = std::make_unique<PlainsBiome>();
        std::unique_ptr<PureBiome> plains_biome; 
        // biome->CreateBiome("ice plains", plains_biome);
        biome->CreateBiome(bio_name, plains_biome);
        world->setPlainsBiome(plains_biome); // A mutex is used on this function.
        // double bio_temperature = world->getWorldTemperature();
        // std::cout << "the temperature is: " << world->getWorldTemperature() << std::endl;
    }
}

void generate_spruce_biome(std::unique_ptr<SpawnWorld>& world, int instance_count, std::string bio_name) {}

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