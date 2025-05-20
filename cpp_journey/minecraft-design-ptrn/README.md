# Repo Info
  * Factory Method design patterns from a minecraft perspective.
  * **Excuse** the console prints. My brain likes using text editors, vscode, but I use wsl and I have yet to set up the debug on it.

## To run
  * Included in new commit. The whole program runs as intended. One file `testWorld.cpp` will be used to create the pretend minecraft world and initialize it with pretend minecraft items. To run use the following:
    + cd MinecraftWorld/
    + make
    + ./worldTest
  * Road map/ next:
    + Implement meaningfull output.
    + Use multithreading to simulate some things taking longer to be initialized. This will be accomplished by sleeping part of the program for a few seconds.