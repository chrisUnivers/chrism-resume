## Some design decisions
  * Although I used a lot of enums, found in `./Utils/ItemNames.h`, in my opinion from a design point of view it allows me to know which names can be used. This way I have one file to manage most of what would otherwise be strings. When a std::cout is need a std::string can be used then.

  * Used the "reverse/inverse" map for food names instead of retrieving the key from a value since map does not provide a direct way to get keys from a value. There's probably a better way to do so, but I try to come up with my own solutions for this project.
    + Since the "user" would only know things like "apple" I keep this option. However to keep strings to a minimum I uses enum. Thus, I need to go from a string to an enum. This back and forth resulted in this design decision.
  
  ### Design decisions to generate world:
    * Implementations came from thinking about the interaction with the main program/`testGenerateWorld.cpp` this file does not exit yet.
      + `./CreateWorld/UniqueWorld.cpp`
      + The function `generate_biome`: receives name of biome, determines type of this biome from name. Then uses biome factory, following The Factory Method design, to genererate `icount` biomes of this type of biome. This minimizes the work the main program, `testGenerateWorld`, does. The implementation of the factory method, `./Biomes/PlainsBiome.cpp` for example, determines which biome to create from the name. 