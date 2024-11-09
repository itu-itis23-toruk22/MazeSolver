# MazeSolver

This project is a C program that solves a rectangular maze by reading its structure from a `.txt` file.<br>The program allows the user to specify the maze dimensions and uses a stack-based approach to find an exit path from a given start position. 

## Features

- **Maze Input from Text File:** The program reads the maze structure from a `.txt` file, which contains size of maze, entry point end quit point.
- **Random Maze:** The program randomly create maze according to file.
- **Stack-based Pathfinding:** Uses a stack data structure to backtrack and explore the maze, efficiently finding an exit if one exists.

## How It Works

1. **Input:**
   - The maze's dimentions are defined in a `.txt` file.
   - The program is create random maze where each cell is marked as either a path or a wall.

2. **Maze Structure:**
   - The program reads and represents the maze as a 2D grid, where walls and open paths are marked accordingly.

3. **Finding the Exit:**
   - The program starts at a specified entry point and explores each path using a stack to keep track of the route.
   - If a dead-end is encountered, the program backtracks using the stack until it finds an alternate path.
   - When an exit is found, the path is displayed; otherwise, a message indicates that no exit is available.

### License

This project licensed with MIT license.

