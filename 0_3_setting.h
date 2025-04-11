#ifndef SETIING_H
#define SETTING_H

#include <iostream>
#include "0_0_game_state.h"
#include "3_Button.h"
#include "3_Music.h"
#include "3_Sound.h"
#include "4_Const_Maze_size.h"

class setting : public game_state{
private:
    SDL_Renderer* renderer;
    TTF_Font* font;
    MusicTheme* Music;
    SoundEffect* Sound;
    Button* SOUNDS;
    Button* MUSIC;
    Button* BACK;

public:
    setting(SDL_Renderer* renderer,TTF_Font* font, MusicTheme* Music, SoundEffect* Sound);
    ~setting();
    void handle_event(SDL_Event& event) override;
};

#endif // SETIING_H
