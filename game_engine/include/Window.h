#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "assetHandler.h"
#include "WindowProperty.h"


class Window
{
    public:
        Window();
        virtual ~Window();
        void loadingScreen();
        void handleEvents();
        void render();
        void update();
        bool running(){return WindowProperty::isRunning;}
        void loadMedia(std:: string);
        void capFrameRate(int);
        void stop(){WindowProperty::isRunning = false;}
    private:
        assetHandler asset;
};

#endif // WINDOW_H
