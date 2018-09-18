#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "WindowProperty.h"


class Window
{
    public:
        Window();
        virtual ~Window();
        void handleEvents();
        void render();
        void update();
        bool running(){return isRunning;}
        void loadMedia(std:: string);
        void capFrameRate(int);

    private:
        bool isRunning;
};

#endif // WINDOW_H
