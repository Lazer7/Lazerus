#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "AssetHandler.h"
#include "WindowProperty.h"
#include "GUI/kiss_sdl.h"

/** Made by the singular entity known as Lazer (Github:Lazer7) */
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
