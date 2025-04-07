#ifndef SETIING_H
#define SETTING_H

#include <iostream>
#include "0_0_game_state.h"
#include "Button.h"
#include "Maze_size.h"
#include "Music.h"
#include "Sound.h"

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
