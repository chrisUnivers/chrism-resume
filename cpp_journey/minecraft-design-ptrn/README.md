# Repo Info
  * Factory Method design patterns from a minecraft perspective.

## To run
  * The project, currently only the biomes factory, is ran through a make file. To run simply type in the command line the following commands:
    + cd MinecraftWorld/
    + make
    + ./biomeTest
  * Currently the make file can only build one factory. Either biomeTest or foodTest.
    + the make file to run food factory test file is in `./make.md`. To run it replace current `Makefile` with it's content then use:
      1. cd MinecraftWorld/
      2. make clean
      3. make
      4. ./foodTest
  * The Biome Factory, in the Factory Method, works as intended.