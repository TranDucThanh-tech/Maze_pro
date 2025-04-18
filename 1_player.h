#ifndef PLAYER_H
#define PLAYER_H

#include "1_maze.h"
#include "3_Button.h"
#include "3_Time.h"
#include "4_Const_SDL_Color.h"
#include "4_Const_Maze_size.h"
#include "4_Const_Player_status.h"


class player{
private:
    int x, y;
    maze* Maze;
    SDL_Renderer* renderer;
    Button* Win;
    Button* Lose;
    Button* Record;
    TTF_Font* font;
    SoundEffect* Sound;
    Time* time;
    bool solved;
    int result;
    bool* is_playing;
public:
    player() = default;
    player(maze* Maze, SDL_Renderer* renderer, TTF_Font* font, SoundEffect* Sound, Time* time, bool* is_playing);
    ~player();
    bool is_end() const;
    void move_player(const string& direction);
    void reset();
    void handle_event(SDL_Event& event);
};

#endif
