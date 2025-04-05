#ifndef SOUND_H
#define SOUND_H

#include <SDL_mixer.h>
#include <string>
using namespace std;

class Sound {
private:
    Mix_Chunk* sound;
public:
    Sound();
    ~Sound();
    void play(const std::string& file);
    void stop();
    void toggle(const std::string& file);
    void pause_resume();
};

#endif
