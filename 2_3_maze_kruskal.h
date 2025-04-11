#ifndef MAZE_KRUSKAL_H
#define MAZE_KRUSKAL_H

#include <random>
#include "1_maze.h"
#include "4_Const_Maze_size.h"
#include "Section.h"

class kruskal_maze : public type_maze{
private:
    vector<section> edges;
    vector<int> parent;
    vector<int> rank_;
public:
    kruskal_maze();
    void init_sets();
    void init_edges();
    int find(int id);
    void unite(int id1, int id2);
    void generate_maze(maze& Maze, int row, int col) override;
};

#endif // MAZE_KRUSKAL_H
