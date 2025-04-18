#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "4_Const_SDL_Color.h"
using namespace std;

class Button{
private:
    SDL_Renderer* renderer;
    SDL_Rect rect;
    SDL_Color color;
    bool is_hovered;

public:
    Button();
    Button(int x, int y, int w, int h,
            SDL_Renderer* renderer, SDL_Color color);
    ~Button();

    bool is_hovered_() const;
    void render_button(const char* text,  TTF_Font*font) const;
    void render_button_music(const char* text,  TTF_Font*font, bool is_off) const;
    void check_button_hover(int mouse_x, int mouse_y);
};


#endif // BUTTON_H
