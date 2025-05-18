## Key observations
  * The individual programs, those in `./Biomes/` or `./Food/` are relatively simple to implement using the `Factory Method` in `Design Patterns`. The commit `5b3d6d0` works as intended for these individual files, for example `./Biomes/testBiomes.cpp`. The challenge comes from putting everything together in the file `./Worlds/UniqueWorld.cpp` since I'm trying to be some what realistic.

## Some design decisions
  * Although I used a lot of enums, found in `./Utils/ItemNames.h`, in my opinion from a design point of view it allows me to know which names can be used. This way I have one file to manage most of what would otherwise be strings. When a std::cout is needed a std::string can be used then.

  * I used what I'm calling the "reverse/inverse" map for food names instead of retrieving the key from a value since map does not provide a direct way to get keys from a value. There's probably a better way to do so, but I try to come up with my own solutions.
    + This can be found in the file: `./Food/FoodConstructros.h` in the `3rd constructor`
    + Since the "user" would only know things like "apple" I keep this option. However to keep strings to a minimum I uses enum. Thus, I need to go from a string to an enum. This back and forth resulted in this design decision.
  
### Design decisions to generate world:
  * Implementations came from thinking about the interaction with the main program. The main idea for the main program, `./Worlds/testWorld.cpp`, is to simulate the process of creating a minecraft world. This includes setting up the world with: `biomes, food items, creatures, trees and other minecraft items`. I use the `Factory Method` design pattern to generate these items. It works great since a world might need to create multiple items, so like 3 of the same biome. 
    + `UniqueWorld.cpp` is the file that will handle this input and then console log when items are created. All my code is written to keep things simple so the logic should be easy to follow.
  * More one `UniqueWorld.cpp`
      + The file `./CreateWorld/UniqueWorld.cpp`
        - The function `generate_biome`: receives name of biome, determines type of this biome from name. Then uses biome factory, following The Factory Method design, to genererate `icount` biomes of this type of biome. This minimizes the work the main program, `testWorld.cpp`, does. The implementation of the factory method, `./Biomes/PlainsBiome.cpp` for example, determines which biome to create from the name. The logic fore `generate_biome` in `UniqueWorld.cpp` is easy to follow.