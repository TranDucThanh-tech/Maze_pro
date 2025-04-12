#ifndef PLAYER_H
#define PLAYER_H

#include "1_maze.h"
#include "3_Button.h"
#include "4_Const_SDL_Color.h"
#include "4_Const_Maze_size.h"
#include "4_Const_Player_status.h"
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
    SoundEffect* Sound;
    int is_win;
public:
    player() = default;
    player(maze* Maze, SDL_Renderer* renderer, TTF_Font* font, SoundEffect* Sound);
    ~player();

    bool is_end();
    void move_player(const string& direction);
    void reset();
    void handle_event(SDL_Event& event);
};

#endif
