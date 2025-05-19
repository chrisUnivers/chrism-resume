CC = g++
CCFLAGS = -std=c++17

worldTest: Worlds/testWorld.o Biomes/PlainsBiome.o Biomes/WoodLandsBiome.o Worlds/UniqueWorld.o Utils/MineUtils.o
	$(CC) $(CCFLAGS) Worlds/testWorld.o Biomes/PlainsBiome.o Biomes/WoodLandsBiome.o Worlds/UniqueWorld.o Utils/MineUtils.o -o worldTest

Worlds/testWorld.o: Worlds/testWorld.cpp
	$(CC) $(CCFLAGS) -c Worlds/testWorld.cpp -o Worlds/testWorld.o

Utils/MineUtils.o: Utils/MineUtils.cpp
	$(CC) $(CCFLAGS) -c ./Utils/MineUtils.cpp -o Utils/MineUtils.o

Biomes/PlainsBiome.o: Biomes/PlainsBiome.cpp
	$(CC) $(CCFLAGS) -c ./Biomes/PlainsBiome.cpp -o Biomes/PlainsBiome.o

Biomes/WoodLandsBiome.o: Biomes/WoodLandsBiome.cpp
	$(CC) $(CCFLAGS) -c ./Biomes/WoodLandsBiome.cpp -o Biomes/WoodLandsBiome.o

Worlds/UniqueWorld.o: Worlds/UniqueWorld.cpp
	$(CC) $(CCFLAGS) -c ./Worlds/UniqueWorld.cpp -o Worlds/UniqueWorld.o

clean:
	rm Worlds/*.o Biomes/*.o Utils/*.o worldTest