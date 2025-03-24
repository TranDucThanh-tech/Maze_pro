#ifndef GAME_H
#define GAME_H

#include "1_maze.h"
#include "1_player.h"
#include "2_1_maze_dfs.h"
#include "2_2_maze_prim.h"
#include "0_0_game_state.h"

using namespace std;


class game{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
    game_state* Game_state;
public:
    game();
    ~game();
    void run();
    void handle_event(SDL_Event& event);
    void update();
    void render();
    void reset();
    void set_state(game_state* Game_state);
};
#endif // GAME_H
