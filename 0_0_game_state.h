#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <iostream>
#include <SDL.h>
using namespace std;

class game_state{
public:
    virtual ~game_state() = default;
    virtual void handle_event(SDL_Event& event) = 0;
    virtual void render() = 0;
};

#endif // GAME_STATE_H
