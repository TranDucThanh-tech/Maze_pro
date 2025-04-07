#ifndef MENU_H
#define MENU_H

#include<iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "0_0_game_state.h"
#include "Button.h"
#include "SDL_Color.h"
#include "Maze_size.h"
#include "Music.h"
#include "Sound.h"

class menu : public game_state{
private:
    SDL_Renderer* renderer;
    TTF_Font* font;
    SoundEffect* Sound;
    Button* Play;
    Button* Setting;
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
