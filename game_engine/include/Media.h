#ifndef MEDIA_H
#define MEDIA_H

#include <stdio.h>
#include <SDL2/SDL_mixer.h>

class Media
{
    public:
        Media()= default;
        virtual ~Media();
        bool init(const char*);
        bool loadMusic(const char*);
        void play();
        void pause();
        void resume();
        void stop();
    protected:

    private:
        //The music that will be played
        Mix_Music* Music = NULL;
};

#endif // MEDIA_H
