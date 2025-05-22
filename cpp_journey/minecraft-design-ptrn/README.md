# Repo Info
  * Factory Method design patterns from a minecraft perspective.
  * ***Using vscode*** + ***the console prints***. My brain likes using text editors, vscode, but I use wsl and I have yet to set up the debugging process/json files on it.

## Repo Status for the MineCraftWorld Project
  * project name: `./MinecraftWorld`.
    + **Status of Project**: Works as intended and no know compile or run time issues.
    + The intent of this project was to use the Factory Method design pattern from a minecraft perspective. To this end, this was accomplished in with this commit `5b3d6d0`. However, all files were standalones and want to make it more of a minecraft experience. This required have a way to create a minecraft world. Challenges found in `./MinecraftWorld/README`

## To run
  * Included in new commit. The whole program runs as intended. One file `testWorld.cpp` will be used to create the pretend minecraft world and initialize it with pretend minecraft items. To run use the following:
    + cd MinecraftWorld/
    + make
    + ./worldTest
## Road map/ next:
  + Implement meaningfull output and create more minecraft items.
    - Minecraft trees, creatures and more.
  + Implement asynchoronous concurrent processes
    - For things like biomes, two main futures need. One that the main thread will wait on, and another that will handle the creation of biomes. This second future will also have other async futures which will do the actual biome setup.