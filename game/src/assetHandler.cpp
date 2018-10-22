#include "assetHandler.h"
kiss_button button ={0};
kiss_label label ={0};

int i = 4;
/**
    Initializes all Assets in the Game
    TODO:: Refactor to place all characters in a vector
*/
void assetHandler::init(){
    char* message = "HELLO";
    kiss_label_new(&label,&WindowProperty::window,message,0,0);
    kiss_button_new(&button,&WindowProperty::window, "CRASH!",200,200,100,50);
    button.font.font=TTF_OpenFont( "assets/fonts/standard.ttf", 30 );

}
/**
    Update function to call each asset's update function
*/
void assetHandler::update(){
    button.rect.h =  50*WindowProperty::getHeightDisposition();
    button.rect.w = 100*WindowProperty::getWidthDisposition();
    button.rect.x = 200*WindowProperty::getWidthDisposition();
    button.rect.y = 200*WindowProperty::getHeightDisposition();
    button.textx = 220 *WindowProperty::getWidthDisposition();
    button.texty = 220 *WindowProperty::getHeightDisposition();
    label.text[i]='a';
    i++;
}
/**
    Render function to draw the game object to the screen
*/

void assetHandler::render(){
    kiss_button_draw(&button, WindowProperty::renderer);
    kiss_label_draw(&label,WindowProperty::renderer);

}
/**
    Handles Key Events for game objects
*/
void assetHandler::keyEventHandler(){
    int draw = 0;
    int quit = 0;

    button_event(&button, &WindowProperty::event, &draw, &quit);
}

void assetHandler::button_event(kiss_button *button, SDL_Event *e, int *draw,
                  int *quit)
{
    if (kiss_button_event(button, e, draw))
        WindowProperty::isRunning=false;
}
