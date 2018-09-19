#include "Window.h"
int main( int argc, char* args[] )
{
    int frameStart;
    Window game;
    while(game.running()){
        frameStart = SDL_GetTicks();
        game.handleEvents();
        game.render();
        game.update();
        game.capFrameRate(frameStart);
    }
    game.~Window();
	return 0;
}
