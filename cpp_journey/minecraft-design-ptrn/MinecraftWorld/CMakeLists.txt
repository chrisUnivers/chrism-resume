cmake_minimum_required(VERSION 3.10.0)

set(This MinecraftPlayLib)

set(Headers
    UniqueWorld.h
)

set(Sources
    UniqueWorld.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(Biomes)
add_subdirectory(Utils)
