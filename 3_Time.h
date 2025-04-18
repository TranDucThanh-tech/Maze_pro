#ifndef TIME_H
#define TIME_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <fstream>
#include <string>
#include "4_Const_SDL_Color.h"
using namespace std;

class Time {
private:
    SDL_Renderer* renderer;
    TTF_Font* font;
    int x, y;
    Uint32 start_time;
    Uint32 current_time;
    Uint32 best_time;

public:
    Time(SDL_Renderer* renderer, TTF_Font* font);
    ~Time() = default;
    void start();
    void stop();
    bool update_best_time();
    void update_current_time();
    void render_current_time(const int x, const int y) const;
    void render_best_time(const int x, const int y) const;
};
#endif // TIME_H
