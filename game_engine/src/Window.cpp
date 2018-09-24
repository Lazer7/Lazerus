#include "Window.h"
int cnt=0;

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
        this->isRunning=true;
        // Creates the window
        WindowProperty::window = SDL_CreateWindow( WindowProperty::title.c_str(),
                                                     SDL_WINDOWPOS_UNDEFINED,
                                                     SDL_WINDOWPOS_UNDEFINED,
                                                     WindowProperty::windowValue.width,
                                                     WindowProperty::windowValue.height,
                                                     SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );
        SDL_Surface *surface;     // Declare an SDL_Surface to be filled in with pixel data from an image file
        surface = IMG_Load("assets/logo.png");
        SDL_SetWindowIcon(WindowProperty::window, surface);
        SDL_FreeSurface(surface);
        WindowProperty::renderer = SDL_CreateRenderer(WindowProperty::window, -1 ,0);
        if( WindowProperty::window != NULL && WindowProperty::renderer != NULL){
            // Set background to white
            SDL_SetRenderDrawColor(WindowProperty::renderer,255,255,255,255);
        }
        else{
            // Error has occurred stop systems
            printf( "Something could not be created! SDL_Error: %s\n", SDL_GetError() );
            this->isRunning = false;
        }
        int frameStart = SDL_GetTicks();
        while( 2000>(SDL_GetTicks()-frameStart)&& isRunning)this->loadingScreen();
    }
    else{
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        this->isRunning = false;
    }

}
Window::~Window() {
    //Destroy window
    SDL_DestroyRenderer( WindowProperty::renderer );
    SDL_DestroyWindow( WindowProperty::window );
    WindowProperty::window = NULL;
    WindowProperty::renderer = NULL;
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

void Window:: loadingScreen(){
    SDL_RenderClear(WindowProperty::renderer);
    SDL_Surface* tempSurface = IMG_Load("assets/images/logo/Lazerus.png");
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
    switch(WindowProperty::event.type){
        case SDL_QUIT:
            isRunning=false;
            break;
        default:
            WindowProperty::resizeWindowEvent();
            break;
    }
}
/**
    Renders game assets to the screen
*/
void Window:: render() {
    SDL_RenderClear(WindowProperty::renderer);
    SDL_RenderPresent(WindowProperty::renderer);
}
/**
    Updates the game assets
*/
void Window:: update() {
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

