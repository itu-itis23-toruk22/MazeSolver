#include "../include/maze.h"
#include <time.h>

int main(){

    srand(time(NULL));

    const char* inputFile = "../input/maze.txt";
    MAZE* m = read_maze_file(inputFile);

    print_maze(m);

    STACK* result = calculate(m);

    print_stack(result);
    destroy_stack(result);
    destroy_maze(m);

    return 0;
}
