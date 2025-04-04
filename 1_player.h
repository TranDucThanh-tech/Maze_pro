#ifndef PLAYER_H
#define PLAYER_H

#include "1_maze.h"
#include "Button.h"
#include "SDL_Color.h"
#include "Maze_size.h"
#include <string>

class player{
private:
    int x, y;
    bool now_playing;
    bool solved;
    maze* Maze;
    SDL_Renderer* renderer;
    Button* Win;
    Button* Lose;
    TTF_Font* font;
    int is_win;
public:
    player() = default;
    player(int x, int y,maze* Maze, SDL_Renderer* renderer);
    ~player();

    bool is_end();

    void move_player(string direction);

    void reset();

    void handle_event(SDL_Event& event);
};

#endif
