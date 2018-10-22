#include "Media.h"
/** Made by the singular entity known as Lazer (Github:Lazer7) */
// Audio settings
int audio_rate = 22050;
Uint16 audio_format = AUDIO_S16SYS;
int audio_channels = 2;
/**
    Media Player Deconstructor
*/
Media::~Media() {
    Mix_FreeMusic(Music);
    Music=NULL;
    Mix_Quit();
}
/**
    Initializes Media Player with standard settings
    @param musicFile the music file (mp3 or wav format)
*/
bool Media:: init(const char* musicFile) {
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }
    Mix_QuerySpec(&audio_rate, &audio_format, &audio_channels);
    return loadMusic(musicFile);
}
/**
    Loads specified Music File
    @param musicFile the music file (mp3 or wav format)
*/
bool Media::loadMusic(const char* musicFile) {
    //Load music
    Music = Mix_LoadMUS( musicFile );
    if( Music == NULL ) {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }

    return true;
}
/**
    Plays the Music
*/
void Media::play() {
    if(Mix_PlayingMusic()==0) {
        Mix_PlayMusic(Music, -1);
    }
}
/**
    Pauses the Music
*/
void Media::pause() {
    Mix_PauseMusic();
}
/**
    Resumes the Music
*/
void Media::resume() {
    Mix_ResumeMusic();
}
/**
    Stops/Resets the Music
*/
void Media::stop() {
    Mix_HaltMusic();
}
