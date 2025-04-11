#ifndef MENU_H
#define MENU_H

#include<iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "0_0_game_state.h"
#include "3_Button.h"
#include "3_Music.h"
#include "3_Sound.h"
#include "4_Const_SDL_Color.h"
#include "4_Const_Maze_size.h"

class menu : public game_state{
private:
    SDL_Renderer* renderer;
    TTF_Font* font;
    SoundEffect* Sound;
    Button* Play;
    Button* Setting;
    Button* Help;
    Button* Quit;
    bool play_clicked;
    bool setting_clicked;
public:

    menu(SDL_Renderer* renderer, TTF_Font* font, SoundEffect* Sound);
    ~menu();
    bool play_clicked_();
    bool setting_clicked_();
    void handle_event(SDL_Event& event) override;
};
#endif // MENU_H
