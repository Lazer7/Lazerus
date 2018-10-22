#include "Window.h"
/** Made by the singular entity known as Lazer (Github:Lazer7) */
int cnt=0;
int draw = 1;
/**
    Window Initialization: Sets the attributes of the game window
    @param width of the screen
    @param height of the screen
    @param title of the screen
    @param fullscreen is a boolean to make the game fullscreen or not
*/
Window::Window() {
    if( SDL_Init(SDL_INIT_EVERYTHING) == 0 && WindowProperty::init()){
        // Set flag to notify the system is running
        char *cTitle = new char[WindowProperty::title.length()+1];
        strcpy(cTitle,WindowProperty::title.c_str());
        kiss_array_new(&WindowProperty::objects);

        // Creates the window using KISS Library
        kiss_window_new(&WindowProperty::window,cTitle, NULL, 0,
                    SDL_WINDOWPOS_UNDEFINED,
                    SDL_WINDOWPOS_UNDEFINED,
                    WindowProperty::windowValue.width,
                    WindowProperty::windowValue.height);
        // Creates the renderer
        WindowProperty::renderer = kiss_init(WindowProperty::window.window,
                                             &WindowProperty::objects,
                                             WindowProperty::windowValue.width,
                                             WindowProperty::windowValue.height);
        // Sets the Window to be visible on the user screen
        WindowProperty::window.visible=1;
        // Set background to white
        SDL_SetRenderDrawColor(WindowProperty::renderer,255,255,255,255);
        int frameStart = SDL_GetTicks();
        // Load Loading Screen
        while( 2000>(SDL_GetTicks()-frameStart)&& WindowProperty::isRunning)this->loadingScreen();
        asset.init();
    }
    else{
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        WindowProperty::isRunning = false;
    }

}

/**
* Window's Deconstructor
* Free up all KISS and SDL Libraries
*/
Window::~Window() {
    //Destroy window
    kiss_clean(&WindowProperty::objects);
//    WindowProperty::window = NULL;
    WindowProperty::renderer = NULL;
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
/**
* Displays the Loading Screen
*/
void Window:: loadingScreen(){
    SDL_RenderClear(WindowProperty::renderer);
    SDL_Surface* tempSurface = IMG_Load("assets/images/logo/logo.png");
    SDL_Texture* spriteSheetTexture = SDL_CreateTextureFromSurface(WindowProperty::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    SDL_RenderCopy(WindowProperty::renderer,spriteSheetTexture,NULL,NULL);
    SDL_RenderPresent(WindowProperty::renderer);
    this->handleEvents();
}

/**
    Handles any input or outputs that occurs in the window
*/
void Window:: handleEvents() {
    SDL_PollEvent(&WindowProperty::event);
    kiss_window_event(&WindowProperty::window, &WindowProperty::event, &draw);
    switch(WindowProperty::event.type){
        case SDL_QUIT:
            WindowProperty::isRunning=false;
            break;
        default:
            WindowProperty::resizeWindowEvent();
            asset.keyEventHandler();
            break;
    }
}
/**
    Renders game assets to the screen
*/
void Window:: render() {
    SDL_RenderClear(WindowProperty::renderer);
    kiss_window_draw(&WindowProperty::window, WindowProperty::renderer);
    asset.render();
    SDL_RenderPresent(WindowProperty::renderer);
}
/**
    Updates the game assets
*/
void Window:: update() {
    asset.update();
}
/**
    Caps the Game Frame Rate
    @param FPS the frame per second
    @param frameStart the starting frame time
*/
void Window:: capFrameRate(int frameStart) {
    int FPS = WindowProperty::windowValue.FPS;
    int frameTime = SDL_GetTicks() - frameStart;

    printf("Frame Started %d\n", cnt );
    cnt++;
    if((1000/FPS)> frameTime){
        SDL_Delay((1000/FPS) - frameTime);
    }
}

