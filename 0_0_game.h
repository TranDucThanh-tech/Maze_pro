#ifndef GAME_H
#define GAME_H

#include "0_0_game_state.h"
#include "0_1_menu.h"
#include "0_2_play_game.h"
#include "0_3_setting.h"
#include "1_maze.h"
#include "1_player.h"
#include "3_Music.h"
#include "3_Sound.h"
#include "3_Time.h"
#include "4_Const_Maze_size.h"

using namespace std;


class game{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    game_state* Game_state;
    MusicTheme* Music;
    SoundEffect* Sound;
    TTF_Font* font;
    Time* time;
    bool running;
    bool* is_playing;

public:
    game();
    ~game();
    void run();
    void set_state(game_state* Game_state);
    void handle_event(SDL_Event& event);
};
#endif // GAME_H
