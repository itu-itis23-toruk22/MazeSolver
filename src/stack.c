#include "../include/stack.h"
#include "stdio.h"


void init_coordinate(NODE* c, int x, int y){
    c->x = x;
    c->y = y;
}

STACK* init_stack(){
    STACK* s = (STACK*) malloc(sizeof(STACK));
    s->top = NULL;
    return s;
}

void push(STACK* s, int x, int y){
    NODE* new_coordinate = (NODE*) malloc(sizeof(NODE));
    init_coordinate(new_coordinate, x, y);

    if(is_empty(s)){
        new_coordinate->next = NULL;
        s->top = new_coordinate;
        return;
    }
    new_coordinate->next = s->top;
    s->top = new_coordinate;
}

void pop(STACK* s){
    if(is_empty(s)){
        return;
    }
    NODE* tmp = s->top;
    s->top = s->top->next;
    free(tmp);
}

NODE* peek(STACK* s){
    if(is_empty(s)){
        return NULL;
    }
    return s->top;
}

bool find(STACK* s, NODE point){
    NODE* tmp = s->top;
    while(tmp != NULL){
        if(tmp->x == point.x && tmp->y == point.y){
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

void print_stack(STACK* s){
    NODE* tmp = s->top;
    for(int i = 0; tmp != NULL; i++){
        printf("%d->(%d,%d)\n", i, tmp->x, tmp->y);
        tmp = tmp->next;
    }
}

bool is_empty(STACK* s){
    return s->top == NULL;
}

void clear(STACK* s){
    while(!is_empty(s)){
        pop(s);
    }
}

void destroy_stack(STACK* s){
    clear(s);
    free(s);
}