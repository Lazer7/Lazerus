#include "WindowProperty.h"

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
    WindowValue scale;
    std::ifstream data("data/WindowScreen.dat",std::ios::binary);
    // checks if file exist
    if(data.is_open()) {
        data.read((char *) &scale,sizeof(scale));
        windowValue=scale;
        return true;
    }
    // If not initialize with default data
    else {
        setDefaultWindowProperty();
        std::ifstream data("data/WindowScreen.dat",std::ios::binary);
        if(data.is_open()){
            data.read((char *) &scale,sizeof(scale));
        }
        return true;

    }
    data.close();
    return false;
}
/**
    Set Window Properties with scale values
*/
void WindowProperty::setWindowProperty(WindowValue scale) {
    remove("data/WindowScreen.dat");
    std::ofstream out("data/WindowScreen.dat",std::ios::binary);
    out.write((char*) &scale, sizeof(scale));
//    int attributes = GetFileAttributes("data/WindowScreen.dat");
//    if((attributes & FILE_ATTRIBUTE_HIDDEN)==0) {
//        SetFileAttributes("data/WindowScreen.dat", attributes + FILE_ATTRIBUTE_HIDDEN);
//    }
    windowValue=scale;
    out.close();
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
