CC = g++
CCFLAGS = -std=c++17


foodTest: Food/testFood.o Food/AppleFood.o Utils/MineUtils.o
	$(CC) $(CCFLAGS) Food/testFood.o Food/AppleFood.o Utils/MineUtils.o -o foodTest

Food/testFood.o: Food/testFood.cpp
	$(CC) $(CCFLAGS) -c Food/testFood.cpp -o Food/testFood.o 

Utils/MineUtils.o: Utils/MineUtils.cpp
	$(CC) $(CCFLAGS) -c ./Utils/MineUtils.cpp -o Utils/MineUtils.o

Food/AppleFood.o: Food/AppleFood.cpp
	$(CC) $(CCFLAGS) -c ./Food/AppleFood.cpp -o Food/AppleFood.o

clean:
	rm Food/*.o Utils/*.o foodTest