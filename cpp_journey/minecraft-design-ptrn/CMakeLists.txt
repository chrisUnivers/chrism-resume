cmake_minimum_required(VERSION 3.10.0)

set(This Minecraft)

project(${This} C CXX)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(MinecraftWorld)
add_subdirectory(testgame)