#ifndef MUSIC_H
#define MUSIC_H

#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>
#include <map>
using namespace std;

class MusicTheme {
private:
    Mix_Music* music;

public:
    MusicTheme();
    ~MusicTheme()
    bool load(const string& filePath);

    void play();
    void resume();
    void pause();
    void stop();

};

class Sounds {
private:
    map<string, Mix_Chunk*> soundEffects;

public:
    bool load(const string& name, const string& filePath);
    ~Sounds();

    void play(const string& name);
    void play();
    void stopAll();
    bool isPlaying();
};

