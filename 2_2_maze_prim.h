#ifndef MAZE_PRIM_H
#define MAZE_PRIM_H
#include <SDL.h>
#include "1_maze.h"

using namespace std;

struct section {
    int start_row, start_col, end_row, end_col;

    section() : start_row(0), start_col(0), end_row(0), end_col(0) {}

    void assign(int a, int b, int c, int d) {
        start_row = a;
        start_col = b;
        end_row = c;
        end_col = d;
    }
};

class maze_prim : public type_maze{
private:
    vector<section>edge;
public:
    void generate_maze(maze& Maze, int row, int col) override;
};
#endif
