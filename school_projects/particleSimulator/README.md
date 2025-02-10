## Notes
* This folder contains code for a particle simimulator assignment I implemented. It implements the following integration methods: euler, symplectic_euler, and verlet methods to calculate the position and velocity in the next timestep. It uses penalty methods for ground collision. 
* The entire project code base(a visual studio solutio) is over one gigabyte(due to external libraries for animation). Can provide if needed. 
* These libraries include glm, linear algebra library and more files to render the animation on screen.
* I implemented the physics and how things are drawen.

**Limitation**
* the project is parameter dependent. So the given parameter will influence the animation. See `cubeVideoInput.tcl` for input file example.
* collpse at the limitation with using penality methods for ground collisions.
* Simple cube video: https://youtu.be/Q6kt_Zpq0w4?si=nal4e_jYLwOEsUmy
* simple spring video: https://youtu.be/wyOIVbX0Dvg?si=aT326yEq1VWIXhrr