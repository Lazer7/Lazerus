#ifndef WINDOWPROPERTY_H
#define WINDOWPROPERTY_H

#include <iostream>
#include <fstream>
#include <string>
#include "FileManager.h"
#include <SDL.h>
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

        static SDL_Window* window;
        static SDL_Surface* screen_surface;
        static SDL_Renderer* renderer;
        static SDL_Event event;

        static WindowValue windowValue;
        static const int WindowHeight;
        static const int WindowWidth;
        static const std::string title;

        static bool init();
        static void setDefaultWindowProperty();
        static void setWindowProperty(WindowValue);
        static void setWindowProperty(int,int,float,float,int,bool);
        static void resizeWindowEvent();
        static float getWidthDisposition();
        static float getHeightDisposition();
};

#endif // WINDOWPROPERTY_H
