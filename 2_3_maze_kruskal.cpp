#include "2_3_maze_kruskal.h"

kruskal_maze :: kruskal_maze() {
    parent = vector<int>(row_size * col_size);
    rank_ = vector<int>(row_size * col_size, 0);
    init_sets();
    init_edges();
}

void kruskal_maze :: init_sets() {
    int n = row_size * col_size;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

void kruskal_maze :: init_edges() {
    for(int i = 1; i < row_size-1; i += 2) {
        for (int j = 1; j < col_size-1; j += 2) {
            if (i + 2 < row_size) edges.push_back(section(i, j, i + 2, j));
            if (j + 2 < col_size) edges.push_back(section(i, j, i, j + 2));
        }
    }
}

int kruskal_maze :: find(int id) {
    if(parent[id] != id)
        parent[id] = find(parent[id]);
    return parent[id];
}


void kruskal_maze :: unite(int id1, int id2) {
    int rootX = find(id1);
    int rootY = find(id2);

    if(rank_[rootX] > rank_[rootY]) {
        parent[rootY] = rootX;
    }
    else if (rank_[rootX] < rank_[rootY]) {
        parent[rootX] = rootY;
    }
    else {
        parent[rootY] = rootX;
        rank_[rootX]++;
    }
}


void kruskal_maze :: generate_maze(maze& Maze, int row, int col) {
    random_device rd;
    mt19937 g(rd());
    shuffle(edges.begin(), edges.end(), g);
    for (auto edge : edges) {
        int id1 = edge.start_row * col_size + edge.start_col;
        int id2 = edge.end_row * col_size + edge.end_col;

        if (find(id1) == find(id2)) continue;
        unite(id1, id2);

        int mid_row = (edge.start_row + edge.end_row) >> 1;
        int mid_col = (edge.start_col + edge.end_col) >> 1;
        Maze.way[edge.start_row][edge.start_col] = WAY;
        Maze.way[edge.end_row][edge.end_col] = WAY;
        Maze.way[mid_row][mid_col] = WAY;

        Maze.draw_cell( Maze.renderer, edge.start_row, edge.start_col, red);
        Maze.draw_cell( Maze.renderer, edge.end_row, edge.end_col, red);
        Maze.draw_cell( Maze.renderer, mid_row, mid_col , red);
        SDL_RenderPresent( Maze.renderer);
        SDL_Delay(10);
        Maze.draw_cell( Maze.renderer, edge.start_row, edge.start_col, black);
        Maze.draw_cell( Maze.renderer, edge.end_row, edge.end_col, black);
        Maze.draw_cell( Maze.renderer, mid_row, mid_col , black);
    }
}











