cmake_minimum_required(VERSION 3.10.0)

set(This MinecraftPlayLib)

set(Headers
    CoolWorld.h
)

set(Sources
    CoolWorld.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(Biomes)
add_subdirectory(Utils)
add_subdirectory(Worlds)