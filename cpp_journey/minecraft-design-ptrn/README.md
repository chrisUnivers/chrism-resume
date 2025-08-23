# Repo Info
  * Factory Method design patterns from a minecraft perspective.

## Repo Status for the MineCraftWorld Project
  * project name: `./MinecraftWorld`.
    + **Status of Project**: Works as intended and no know compile or run time issues.
    + The intent of this project was to use the Factory Method design pattern from a minecraft perspective. To this end, this was accomplished in with this commit `5b3d6d0`. However, all files were standalones but I wanted to make it more of a minecraft experience. This required having a way to create a minecraft world. Challenges found in `./MinecraftWorld/README`

## To run
  * The current state has been refactored. The non-refactored project was build using a `make file` the new refactored project uses `CMake` and `CMakeLists.txt` files. I have yet to get the multithreading code working with the refactored project, but it works totally fine in the old project which used a `make file`. Non-refactored project's commit: 66d0ada6f0be126f318287d9468a226febb9b891
  * Included in new commit(written for the Non-refactored project). The whole program runs as intended. One file `testWorld.cpp` is used to create the pretend minecraft world and initialize it with pretend minecraft items. To run use the following:
    + cd MinecraftWorld/
    + make
    + ./worldTest
## Road map/ next:
  + Implement meaningfull output and create more minecraft items.
    - Minecraft trees, creatures and more.
  + **Multithreading and concurrency**. Currently the program implements a simple concurrent process. This is done in the file `UniqueWorld.cpp`. The commit `d0c3ec4` has a starting point for the intended concurrent implementation, however, I decide to implement the simple case to have something working.