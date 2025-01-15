# Game of Life

Inspiration by the mathematician J.H. Conway. The game is a simulation that models the life cycle of bacteria, providing entertainment wrapped up in what some would call mathematical elegance.

## Table of Contents
- [Dependencies](#dependencies)
- [Installation](#installation)
- [Rules](#rules-to-game-of-life)
- [Simulation Modes](#simulation-modes)
- [Future Enhancements](#future-enhancements)

## Dependencies
- Unix OS (I used Ubuntu 22.04)
- Install:
```bash
sudo apt install build-essentials
```

## Installation
1. Download the code to local machine
2. Install the dependencies listed above.
3. In the root directory:
    - Execute ```make```
    - Then ```./GameOfLife```
4. Follow the steps to in the application to simulate the life cycles of bacteria.

## Rules to Game of Life
1. A location that has one or fewer neighbors will be empty in the next generation. If a cell was in that location, it dies of loneliness.  (The fate of many a computer scientist...) 
2. A location with two neighbors remains stable.  If there was a cell, there’s still a cell.  If it was empty, it’s still empty. 
3. A location with three neighbors will contain a cell in the next generation.  If it currently has a cell, the cell lives on.  If it’s empty, a new cell is born. 
4. A location with four or more neighbors will be empty in the next generation due to overcrowding. 
5. The births and deaths that take one generation to the next must all take place simultaneously.  When computing a new generation, the births and deaths in that generation can not affect other births and deaths in that generation.  Not adhering to this guideline will really mess up your simulation, so be careful. An easy way to get around this is to have 2 versions of the grid.  One is for the current generation, and the other is for computing the next generation (based on the 
current generation) without side effects.  When you are done computing the next generation you can either copy it into the current generation grid, or just switch a reference.  (In the database community, this little hack is called shadow paging.)

## Simulation Modes
1. Classic mode:  All locations off the grid are considered to be empty.
2. Doughnut mode:  The grid is wrapped around itself horizontally and vertically, resulting in a torus (doughnut) shape.  In this mode, any reference off the right-hand-side is wrapped around to the left-most column of the same row and vice-versa. Any reference off the top wraps to the bottom in the same column.
3. Mirror Mode:  References off the grid are bounced back as though the wall were a mirror. This means the reflection of a cell could count as its own neighbor. For a corner cell, if it was occupied, its reflection would count as 3 neighbors...1 for the vertical reflection, l for the horizontal reflection, and 1 for the diagonal reflection.

## Future Enhancements
1. Build a GUI.
2. Have the simulation have more than 3 modes.
