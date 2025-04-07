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
    Button* Play;
    Button* Setting;
    Button* Quit;
    SDL_Renderer* renderer;
    TTF_Font* font;
    SoundEffect* Sound;
    bool play_clicked;
    bool setting_clicked;
public:

    menu(SDL_Renderer* renderer, TTF_Font* font, SoundEffect* Sound);
    ~menu();
    bool play_clicked_();
    bool setting_clicked_();
    void check_button_hover(Button* btn, int mouse_x, int mouse_y);
    void handle_event(SDL_Event& event) override;
};
#endif // MENU_H
