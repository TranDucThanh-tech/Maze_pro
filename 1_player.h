#ifndef PLAYER_H
#define PLAYER_H

#include "1_maze.h"
#include <string>
#include "SDL_Color.h"
using namespace std;

class player{
private:
    int x, y;
    maze* Maze;
    SDL_Renderer* renderer;
public:
    player() = default;
    player(int x, int y,maze* Maze, SDL_Renderer* renderer);
    ~player() = default;

    void move_player(string direction);

    void handle_event(SDL_Event& event);
    void reset();
};

#endif
