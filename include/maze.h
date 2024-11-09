#ifndef MAZE_H
#define MAZE_H

#include "stack.h"
#include <stdio.h>

typedef struct Maze{
    NODE entry;
    NODE quit;
    int x_limit;
    int y_limit;
    bool* walls;
}MAZE;

//Read file and create maze
MAZE* read_maze_file(const char* filename);

//Create maze without walls
MAZE* init_maze(int, int);

//Add walls to maze
void create_walls(MAZE*);

//Returns status of wall
bool check_walls(MAZE*, NODE);

//Prints maze
void print_maze(MAZE*);

//Deallocate all memory in maze
void destroy_maze(MAZE*);

//Calculate valid solution and returns steps to exit
STACK* calculate(MAZE*);

#endif