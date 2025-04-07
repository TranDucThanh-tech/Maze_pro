#include "Sound.h"
#include <iostream>

SoundEffect::SoundEffect() : sound(nullptr),  is_off(false) {}

SoundEffect::~SoundEffect() {
    if (sound) {
        Mix_FreeChunk(sound);
        sound = nullptr;
    }
}

bool SoundEffect::loadFromFile(const string& path) {
    if(is_off) return false;
    if (sound) {
        Mix_FreeChunk(sound);
        sound = nullptr;
    }

    sound = Mix_LoadWAV(path.c_str());
    if (!sound) {
        cout << "Failed to load sound: " << Mix_GetError() << "\n";
        return false;
    }
    return true;
}

void SoundEffect::play(int loops) {
    if (is_off || !sound) return;
    int channel = Mix_PlayChannel(-1, sound, loops);
    if (channel == -1) {
        cout << "Failed to play sound: " << Mix_GetError() << "\n";
    }
}

void SoundEffect::stop() {
    Mix_HaltChannel(-1);
    is_off = true;
}

void SoundEffect::pause_resume() {
    if (is_off) {
        int channel = Mix_PlayChannel(-1, sound, 0);
        if (channel == -1)
            cout << "Failed to resume sound: " << Mix_GetError() << "\n";
    }
    else
        Mix_Pause(-1);
    is_off = !is_off;
}


