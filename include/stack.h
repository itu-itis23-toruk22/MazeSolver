#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct Coordinate{
    int x;
    int y;
    struct Coordinate* next;
}NODE;

typedef struct Stack{
    NODE* top;
}STACK;

//Initialize coordinate
void init_coordinate(NODE*, int, int);

//Initialize stack
STACK* init_stack();

//Create new coordinate and insert to top
void push(STACK*, int, int);

//Delete top element of the stack
void pop(STACK*);

//Returns top element of the stack
NODE* peek(STACK*);

//Returns true if given node is in the stack
bool find(STACK*, NODE);

//Prints all elements of the stack
void print_stack(STACK*);

//Returns true if stack is empty
bool is_empty(STACK*);

//Delete all elements in the stack
void clear(STACK*);

//Delete the stack
void destroy_stack(STACK*);

#endif
