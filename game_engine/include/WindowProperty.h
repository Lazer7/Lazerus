#ifndef WINDOWPROPERTY_H
#define WINDOWPROPERTY_H

#include "GUI/kiss_sdl.h"
#include <iostream>
#include <fstream>
#include <string>
#include "FileManager.h"
#include <SDL2/SDL.h>
/** Made by the singular entity known as Lazer (Github:Lazer7) */
class WindowValue{
    public:
        int width;
        int height;
        int FPS;
        float Wscale,Hscale;
        bool fullscreen;
};

class WindowProperty
{
    public:
        // SDL Resources
        static SDL_Surface* screen_surface;
        static SDL_Renderer* renderer;
        static SDL_Event event;

        // KISS GUI Resources
        static kiss_array objects;
        static kiss_window window;

        // Checking if program is still alive
        static bool isRunning;

        // Window Property Values
        static WindowValue windowValue;
        static const int WindowHeight;
        static const int WindowWidth;
        static std::string title;

        static bool init();
        static void setDefaultWindowProperty();
        static void setWindowProperty(WindowValue);
        static void setWindowProperty(int,int,float,float,int,bool);
        static void resizeWindowEvent();
        static float getWidthDisposition();
        static float getHeightDisposition();



};

#endif // WINDOWPROPERTY_H
