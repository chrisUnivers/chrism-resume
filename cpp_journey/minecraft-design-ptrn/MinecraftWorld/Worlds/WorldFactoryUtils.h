#ifndef WORLD_FACTORY_UTILS_H
#define WORLD_FACTORY_UTILS_H


#include "IWorldFactoryUtils.h"
class WorldFactoryUtils : IWorldFactoryUtils {
public:
    void addBiome(BiomesFactory& bfactory, int countB, BiomeVariationTypes varType, std::vector<std::unique_ptr<MinecraftBiome>>& vBio) override{
        std::unique_ptr<MinecraftBiome> plpB;
        MainBiome mainB;
        for (int i = 0; i < countB; i++) {
            plpB = mainB.createBiome(bfactory, varType);
            vBio.push_back(std::move(plpB));
        }
    }

    void createWorldBiomes(std::vector<std::unique_ptr<MinecraftBiome>>& vBiomes, std::vector<baseBiomeTplBiome> allBiomes) override {
        int s = allBiomes.size();
        for (int i = 0; i < s; i++) {
            auto[baseType, varBioCountTpl] = allBiomes[i];

            switch(baseType) {
            case BiomeTypes::BIOME_PLAINS_BIOME: {
                std::unique_ptr<BiomesFactory> factory = std::make_unique<PlainsBiomeFactory>();
                processBiomes(varBioCountTpl, vBiomes, *factory);
                break;
            }
            case BiomeTypes::BIOME_WOODLANDS_BIOME: {
                std::unique_ptr<BiomesFactory> factory = std::make_unique<WoodLandsBiomeFactory>();
                processBiomes(varBioCountTpl, vBiomes, *factory);
                break;
            }
            default:
                std::cout << "WorldFactoryUtils: createWorldBiomes. " << std::endl;
                break;
            }
        }
    }
    void processBiomes(vecTplBiomes varBioCountTpl, std::vector<std::unique_ptr<MinecraftBiome>>& vBiomes, BiomesFactory& bFactory) {
        auto[numOfB, bvartype] = varBioCountTpl;
        switch(bvartype) {
        case BiomeVariationTypes::BIOMEPL_PLAINS: {
            addBiome(bFactory, numOfB, bvartype, vBiomes);
            break;
        }
        case BiomeVariationTypes::BIOMEWDLS_FOREST: {
            addBiome(bFactory, numOfB, bvartype, vBiomes);
            break;
        }
        default:
            std::cout << "WorldFactoryUtils: processBiomes" << std::endl;
            break;
        }
    }
    void createWorldTree(std::vector<treeTypeTpl>& vecTreeTpl, std::vector<WorldTree>& vTrees) {
        double plantrate = 8.0;
        std::string treename = "";
        
        auto tree_init = [&vTrees](std::string name, double rate, WorldTreeType type, int numTrees){
            for (int v = 0; v < numTrees; v++) {  vTrees.push_back({WorldTree{MineUtils::generateRandomId(), name, type, rate}}); };
        };
        
        for (auto treeTpl : vecTreeTpl) {
            auto[numTrees, treeType] = treeTpl;
            switch(treeType) {
            case WorldTreeType::OAK_TREE: {
                treename = "Oak tree";
                plantrate = 63.3;
                tree_init(treename, plantrate, treeType, numTrees);
                break;
            }
            case WorldTreeType::SPRUCE_TREE: {
                treename = "Spruce tree";
                plantrate = 57.6;
                tree_init(treename, plantrate, treeType, numTrees);
                break;
            }
            case WorldTreeType::BIRCH_TREE: {
                treename = "Birch tree";
                plantrate = 64.8;
                tree_init(treename, plantrate, treeType, numTrees);
                break;
            }
            default: 
                throw std::invalid_argument("SpawnWorld Factory had problems creating world trees with the given arguments");
            }
        }
    }        
};
#endif // WORLD_FACTORY_UTILS_H