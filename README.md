# Game Of Life
The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970. The game is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves. It is Turing complete and can simulate a universal constructor or any other Turing machine. [wikipedia]



In the original version described by John Conway, the universe is defined on a two-dimensional grid of variable size, where each cell is a cell that can take two different states: dead or alive.
The passage from one state to the other is guided by the following rules of evolution:
- A cell that is dead at time t becomes alive at time t + 1 if and only if it has exactly 3 living cells in its vicinity.
- A cell that is alive at time t remains alive at time t + 1 if and only if it has exactly 2 living cells in its vicinity.
or 3 living cells in her neighborhood, or she dies.
- The neighborhood uses is the 8-neighborhood: for a given cell, its neighbors are the 8 cells
that surround him.

![gif1](https://upload.wikimedia.org/wikipedia/commons/0/07/Game_of_life_pulsar.gif)



**Compilation**

Once at the root of the project
```
make

```
to compile the program in *Graphic* mode.

To use the *Console* mode, you simply need to set MODE option
```
make MODE=TEXTE
```

Command Line
```
doxygen
```
allows you to generate the documentation in a doc directory, in html format.


Command Line
```
make dist
```
generate tarball project compressed file.

Command Line
```
make clean
```
simply removes the artifacts produced by the different commands above.


**Usage**

You have to start the game, passing a grid as an argument.

For example,
```
./bin/main ./grille/grille4.txt
```
Once in the game, several features are available to you:
 - The Enter key changes the grid (Left click also for the Graphic mode)
 - The n key is used to change the grid dynamically.
 - The c key activates/deactivates the cyclic edges.
 - The v key activates/deactivates cell aging
 - The q key exits the game (also right-click for graphics mode).


**Points to be aware of for use in Console mode**

 All grids, except those created to measure (i.e. Canon.txt and Canon.txt), display very well on terminals with size >= 80x24.
 For Exploder, you must use a terminal of size >= 85x34.
 And for Canon, you need to use a terminal of size >= 205x54.

**NB**

La grille Exploder.txt représente ce queThe Exploder.txt grid represents what is called an Exploder, and the Canon.txt grid represents a Gosper Glider Gun.

**PS**

Links to the git repositories : [ici](https://github.com/Fayssal404/Game_Of_Life/)

