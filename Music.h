#ifndef MUSIC_H
#define MUSIC_H

#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>
using namespace std;

class MusicTheme {
private:
    Mix_Music* music;
    bool is_off;
public:
    MusicTheme();
    ~MusicTheme();
    bool is_off_();
    void play(const std::string& file);
    void stop();
    void pause_resume();
};

#endif


