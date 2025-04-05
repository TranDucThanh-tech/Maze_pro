#include "Sound.h"
#include <iostream>

Sound::Sound() : sound(nullptr){}

Sound::~Sound() {
    stop();
    if (sound) {
        Mix_FreeChunk(sound);
        sound = nullptr;
    }
}

void Sound::play(const std::string& file) {
    stop();
    sound = Mix_LoadWAV(file.c_str());
    if (sound ) {
        if (Mix_PlayChannel(-1, sound, 0) == -1)
          cerr << "Failed to play sound: " << Mix_GetError() << endl;
    }
    else{
        cerr << "Failed to load sound effect: " << file << " Error: " << Mix_GetError() << endl;
        return;
    }
}

void Sound::stop() {
    if (sound != nullptr) {
        Mix_HaltChannel(-1);
    }
}

void Sound::toggle(const std::string& file) {
    if (Mix_Playing(-1)) {
        stop();
    } else {
        play(file);
    }
}

void Sound::pause_resume() {
    if (Mix_Paused(-1)) {
        Mix_Resume(-1);
    } else {
        Mix_Pause(-1);
    }
}
