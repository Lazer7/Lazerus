#include "WindowProperty.h"

// Static window properties
const std::string WindowProperty::title="Lazerus Game Engine";
const int WindowProperty::WindowHeight = 500;
const int WindowProperty::WindowWidth = 500;
WindowValue WindowProperty::windowValue;
SDL_Window* WindowProperty::window = NULL;
SDL_Surface* WindowProperty::screen_surface = NULL;
SDL_Renderer* WindowProperty::renderer = NULL;
SDL_Event WindowProperty::event;


/**
    Initialize Window settings from the WindowScreen.dat file
*/
bool WindowProperty::init() {

    try{
        windowValue=FileManager::read<WindowValue>("data/WindowScreen.dat");
    }
    catch(const char* msg){
        setDefaultWindowProperty();
    }
    return true;
}
/**
    Set Window Properties with scale values
*/
void WindowProperty::setWindowProperty(WindowValue scale) {
    FileManager::write("data/WindowScreen.dat",scale);
    windowValue=scale;
}
/**
    Set Window Properties with scale values
*/
void WindowProperty::setWindowProperty(int w,int h,float Ws,float Hs, int FPS, bool fullscreen) {
    WindowValue scale;
    scale.fullscreen=fullscreen;
    scale.width=w;
    scale.height=h;
    scale.Wscale = Ws;
    scale.Hscale = Hs;
    scale.FPS = FPS;
    setWindowProperty(scale);
}
/**
    Reset Window Properties
*/
void WindowProperty::setDefaultWindowProperty() {
    WindowValue scale;
    scale.fullscreen=false;
    scale.width=WindowProperty::WindowWidth;
    scale.height=WindowProperty::WindowHeight;
    scale.Wscale = 1;
    scale.Hscale = 1;
    scale.FPS = 60;
    setWindowProperty(scale);
}
/**
    Change Window setting based on window event actions
*/
void WindowProperty::resizeWindowEvent() {
    if(event.type == SDL_WINDOWEVENT){
        switch(event.window.event){
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            if(event.window.data1 < WindowProperty::WindowWidth || event.window.data2 < WindowProperty::WindowHeight) {
                WindowProperty::setDefaultWindowProperty();
                SDL_SetWindowSize(window,WindowProperty::WindowWidth,WindowProperty::WindowHeight);
            }
            else{
                float wScale = (float)(event.window.data1) / (float)WindowProperty::WindowWidth;
                float hScale = (float)(event.window.data2) / (float)WindowProperty::WindowHeight;
                WindowProperty::setWindowProperty(event.window.data1,
                                                     event.window.data2,
                                                     wScale,
                                                     hScale,
                                                     WindowProperty::windowValue.FPS,
                                                     WindowProperty::windowValue.fullscreen);
            }
        break;
        }
    }
}
/**
    Get the window's width distortion based on the orignal size
*/
float WindowProperty::getWidthDisposition() {
    return (float)WindowProperty::windowValue.width/ (float)WindowProperty::WindowWidth;
}
/**
    Get the window's height distortion based on the orignal size
*/
float WindowProperty::getHeightDisposition() {
    return (float)WindowProperty::windowValue.height/ (float)WindowProperty::WindowHeight;
}
