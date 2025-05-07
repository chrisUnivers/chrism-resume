
CC = g++
CCFLAGS = -std=c++17

output: kate.o base_C_construct.o drvd_c_construct.o snd_base_class.o
	g++ -std=c++17 kate.o base_C_construct.o drvd_c_construct.o snd_base_class.o -o output

kate.o: kate.cpp
	g++ -std=c++17 -c kate.cpp

base_C_construct.o: base_C_construct.cpp base_C_construct.h
	g++ -std=c++17 -c base_C_construct.cpp

drvd_c_construct.o: drvd_c_construct.cpp drvd_c_construct.h
	g++ -std=c++17 -c drvd_c_construct.cpp

snd_base_class.o: snd_base_class.cpp snd_base_class.h
	g++ -std=c++17 -c snd_base_class.cpp

clean:
	rm *.o output