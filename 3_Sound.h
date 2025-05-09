#ifndef SOUND_EFFECT_H
#define SOUND_EFFECT_H

#include <SDL.h>
#include <SDL_mixer.h>
#include <string>
using namespace std;

class SoundEffect {
private:
    Mix_Chunk* sound;
    bool is_off;
public:
    SoundEffect();
    ~SoundEffect();
    bool is_off_() const;
    bool loadFromFile(const string& path);
    void play(int loops = 0) const;
    void stop();
    void pause_resume();
};

#endif
