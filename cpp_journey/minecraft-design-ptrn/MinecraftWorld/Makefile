CC = g++
CCFLAGS = -std=c++17

biomeTest: Biomes/testBiomes.o Biomes/PlainsBiome.o Biomes/WoodLandsBiome.o Utils/MineUtils.o
	$(CC) $(CCFLAGS) Biomes/testBiomes.o Biomes/PlainsBiome.o Biomes/WoodLandsBiome.o Utils/MineUtils.o -o biomeTest

Biomes/testBiomes.o: Biomes/testBiomes.cpp
	$(CC) $(CCFLAGS) -c Biomes/testBiomes.cpp -o Biomes/testBiomes.o 

Utils/MineUtils.o: Utils/MineUtils.cpp
	$(CC) $(CCFLAGS) -c ./Utils/MineUtils.cpp -o Utils/MineUtils.o

Biomes/PlainsBiome.o: Biomes/PlainsBiome.cpp
	$(CC) $(CCFLAGS) -c ./Biomes/PlainsBiome.cpp -o Biomes/PlainsBiome.o

Biomes/WoodLandsBiome.o: Biomes/WoodLandsBiome.cpp
	$(CC) $(CCFLAGS) -c ./Biomes/WoodLandsBiome.cpp -o Biomes/WoodLandsBiome.o

clean:
	rm Biomes/*.o Utils/*.o biomeTest