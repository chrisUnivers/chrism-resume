## Challenges
  * The individual programs, those in `./Biomes/` or `./Food/` are relatively simple to implement using the `Factory Method` in `Design Patterns`. The commit `5b3d6d0` works as intended for these individual files, for example `./Biomes/testBiomes.cpp`. 
  * The challenges come from:
    + putting everything together in the file `./Worlds/testWorld.cpp` since I'm trying to be some what realistic. This is mostly due changing the intial goals, commit `5b3d6d0`, of the project. Changing them require coming up with a new layout/architecture of the project. Although to a small extent, this challenge has been accomplished in the function `UniqueWorld::ListWorldItems` in `./Worlds/UniqueWorld.cpp`.

## Some design decisions
  * Although I used a lot of enums, found in `./Utils/ItemNames.h`, in my opinion from a design point of view it allows me to know which names can be used. This way I have one file to manage most of what would otherwise be strings. When a std::cout is needed a std::string can be used then.
  * I used what I'm calling the "reverse/inverse" map for food names instead of retrieving the key from a value since map does not provide a direct way to get keys from a value. There's probably a better way to do so, but I try to come up with my own solutions.
    + This can be found in the file: `./Food/FoodConstructros.h` in the `3rd constructor`
    + Since the "user" would only know things like "apple" I keep this option. However to keep strings to a minimum I uses enum. Thus, I need to go from a string to an enum. This back and forth resulted in this design decision.
  * Changed interaction with main program to put aside the otherwise required string processing.
    + I orginally intended for the main program to be input agnostic. However, this also requires a some what huge amount of processing the input. Thus, for now, I assume the inputs will be formatted.
  * The file/class `./Worlds/UniqueWorld.cpp` is only for testing purpose. Thus, an object of this class can not make changes to the created world. It can only ask for information to be printed. An example of this is the function `UniqueWorld::ListWorldItems` in `./Worlds/UniqueWorld.cpp`. The world and not the ***"testing"*** object handles all of its attributes.
  
### Design decisions to generate world:
  * Implementations came from thinking about the interaction with the main program. The main idea for the main program, `./Worlds/testWorld.cpp`, is to simulate the process of creating a minecraft world. This includes setting up the world with: `biomes, food items, creatures, trees and other minecraft items`. I use the `Factory Method` design pattern to generate these items. It works great since a world might need to create multiple items, so like 3 of the same biome. 
    + `UniqueWorld.cpp` is the file that will handle this input and then console log when items are created. All my code is written to keep things simple so the logic should be easy to follow.
  * More on `UniqueWorld.cpp`
      + The file `./CreateWorld/UniqueWorld.cpp`
        - The function `generate_biome`: receives name of biome, determines type of this biome from name. Then uses biome factory, following The Factory Method design, to genererate `icount` biomes of this type of biome. This minimizes the work the main program, `testWorld.cpp`, does. The implementation of the factory method, `./Biomes/PlainsBiome.cpp` for example, determines which biome to create from the name. The logic fore `generate_biome` in `UniqueWorld.cpp` is easy to follow.