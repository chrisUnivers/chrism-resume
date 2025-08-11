# Intro
  * This project demostrates more of my java skills. I uses the java Flow library to simulate publisher and subscriber events. The project implements the builder pattern to create objects of a class I call AR glasses. I then use reactive programming and concurrency to add these gifts to Santa's bags. The adding is done by an object of a class I call SantasCOOs, Chief Executive Officer, which makes sure that all AR gifts are both in good condition and added to Santa's bag. Santa then takes off when all gifts have been add. I also have some unit tests but not all methods are tested. Multithreading is setup in the `Main.java` file. The reactive programming part and the parrell programming logic is all implemented in the `cool.santa` package.
  * Since I'm using threads to show the output, the output does not always appear the same. For example both `output one` and `output two` are possible:
    * **Output One**
    *  Santa's coo (COO 0) added: An ar glasses gift in new condition to santa's bag
    * Santa's coo (COO 1): Ar glasses in good cannot be added to santa's bag. Santa can only give new gifts!
    * **Output Two**
    * Santa's coo (COO 1): Ar glasses in good cannot be added to santa's bag. Santa can only give new gifts!
    *  Santa's coo (COO 0) added: An ar glasses gift in new condition to santa's bag