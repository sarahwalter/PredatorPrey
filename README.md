# PredatorPrey
A predator prey simulation written in C++

This program simulates a predator-prey situation, where Doodlebugs represent the predators and Ants are the prey. 
The simulation contains 100 randomly placed Ants and 5 randomly placed Doodlebugs.
Each turn, the Doodlebugs and Ants move at random. If the Doodlebugs land on an Ant, they eat them, preventing starvation and resetting the time to death counter.
Ants eat background vegetation and die after 10 moves regardless of what they eat.
Both Ants and Doodlebugs have a time to breed counter that controls their reproduction.

Use make all to easily compile the program if operating in a Unix/Linux environment.
