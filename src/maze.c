#include "../include/maze.h"

MAZE* init_maze(int x, int y){
    MAZE* m = (MAZE*) malloc(sizeof(MAZE));
    m->x_limit = x;
    m->y_limit = y;
    m->walls = (bool*) malloc(sizeof(bool) * x * y);

    return m;
}

void create_walls(MAZE* m){
    for(int i = 0; i < m->y_limit; i++){
        for(int j = 0; j < m->x_limit; j++){
            m->walls[i * m->x_limit + j] = rand() % 2 == 0;
        }
    }

    m->walls[m->entry.y * m->x_limit + m->entry.x] = false;
    m->walls[m->quit.y * m->x_limit + m->quit.x] = false;
}

bool check_walls(MAZE* m, NODE point){
    if(point.x >= m->x_limit || point.y >= m->y_limit || point.x < 0 || point.y < 0){
        return true;//duvar var
    }
    return m->walls[point.y * m->x_limit + point.x];
}

void print_maze(MAZE* m){
    for(int i = m->y_limit - 1; i >= 0; i--){
        for(int j = 0; j < m->x_limit; j++){
            printf("%s", m->walls[i*m->x_limit + j] ? "+" : " ");
        }
        printf("\n");
    }
}

MAZE* read_maze_file(const char* filename){
    FILE* fptr = fopen(filename, "r");
    
    if(fptr == NULL){
        printf("File can not opened\n");
        return NULL;
    }

    int x_limit, y_limit;
    int entry_x, entry_y;
    int quit_x, quit_y;
    fscanf(fptr, "%d %d", &x_limit, &y_limit);
    fscanf(fptr, "%d %d", &entry_x, &entry_y);
    fscanf(fptr, "%d %d", &quit_x, &quit_y);


    MAZE* m = init_maze(x_limit, y_limit);
    
    NODE entry, quit;
    entry.x = entry_x;
    entry.y = entry_y;
    quit.x = quit_x;
    quit.y = quit_y;

    m->entry = entry;
    m->quit = quit;

    create_walls(m); 

    fclose(fptr);
    return m;
}

void destroy_maze(MAZE* m){
    free(m->walls);
    free(m);
}

STACK* calculate(MAZE* m){
    int move[] = {0, -1 , 0, 1};
    STACK* stack = init_stack();
    push(stack, m->entry.x, m->entry.y);

    while(stack->top->x != m->quit.x || stack->top->y != m->quit.y){
        int move_x;
        int move_y;
        bool flag = false; 
        for(int i = 0; i < 4; i++){
            move_x = move[i];
            move_y = move[(i + 1) % 4];
            
            NODE new_node;
            new_node.x = stack->top->x + move_x;
            new_node.y = stack->top->y + move_y;

            if(check_walls(m, new_node)){
                continue;
            }

            if(find(stack, new_node)){
                continue;
            }
            push(stack, stack->top->x + move_x, stack->top->y + move_y);
            flag = true;
            break;
        }

        if(!flag){
            m->walls[stack->top->y * m->x_limit + stack->top->x] = true;
            pop(stack);

            if(is_empty(stack)){
                printf("No Solution!\n");
                return stack;
            }
        }       
    }
    return stack;
}