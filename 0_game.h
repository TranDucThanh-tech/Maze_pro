
#ifndef GAME_H
#define GAME_H
#include <bits/stdc++.h>
#include <SDL.h>
#include "1_maze.h"
#include "1_player.h"
#include "2_1_maze_dfs.h"
#include "2_2_maze_prim.h"

using namespace std;

class game{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    maze* Maze;
    player* Player;
    bool running;
public:
    game();
    ~game();
    void run();
    void handle_event(SDL_Event& event);
    void update();
    void render();
    void reset();
};
#endif // GAME_H
