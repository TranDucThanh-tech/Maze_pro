#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "SDL_Color.h"
using namespace std;

class Button{
private:
    SDL_Rect rect;
    TTF_Font* font;
    bool is_hovered;
    SDL_Color color;
    SDL_Renderer* renderer;
public:
    Button();
    Button(int x, int y, int w, int h, SDL_Renderer* renderer, SDL_Color color);
    ~Button();

    bool is_hovered_();

    void render_button(const char* text,  TTF_Font*font);

    void check_button_hover(int mouse_x, int mouse_y);
};

#endif // BUTTON_H
