#ifndef MUSIC_H
#define MUSIC_H

#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>
using namespace std;

class MusicTheme {
private:
    Mix_Music* music;
public:
    MusicTheme();
    ~MusicTheme();
    void play(const std::string& file);
    void stop();
    void toggle(const string& file);
    void pause_resume();
};

#endif


