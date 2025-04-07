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
    Button* SOUNDS;
    Button* MUSIC;
    Button* BACK;
    SDL_Renderer* renderer;
    TTF_Font* font;
    MusicTheme* Music;
    SoundEffect* Sound;
public:
    setting(SDL_Renderer* renderer,TTF_Font* font, MusicTheme* Music, SoundEffect* Sound);
    ~setting();
    void handle_event(SDL_Event& event) override;
};

#endif // SETIING_H
