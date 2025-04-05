#include "Music.h"

MusicTheme::MusicTheme() : music(nullptr) {}

MusicTheme::~MusicTheme() {
    stop();
    if (music) {
        Mix_FreeMusic(music);
        music = nullptr;
    }
}


void MusicTheme::play(const std::string& file) {
    stop();
    music = Mix_LoadMUS(file.c_str());
    if (music) {
        if (Mix_PlayMusic(music, -1) == -1)
            std::cerr << "Error playing music: " << Mix_GetError() << std::endl;
    }
    else{
        std::cerr << "Error loading music file: " << file << " SDL_mixer Error: " << Mix_GetError() << std::endl;
        return;
    }
}

void MusicTheme::stop() {
    if (Mix_PlayingMusic())
        Mix_HaltMusic();
}

void MusicTheme::toggle(const std::string& file) {
    if (Mix_PlayingMusic())
        stop();
    else
        play(file);
}

void MusicTheme::pause_resume() {
    if (!Mix_PlayingMusic()) return;

    if (Mix_PausedMusic())
        Mix_ResumeMusic();
    else
        Mix_PauseMusic();
}
