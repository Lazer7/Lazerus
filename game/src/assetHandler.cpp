#include "assetHandler.h"
kiss_button button ={0};
kiss_textbox textbox1 = {0};
int textbox_width, textbox_height;
kiss_array a1;
kiss_window window1;
/**
    Initializes all Assets in the Game
    TODO:: Refactor to place all characters in a vector
*/
void assetHandler::init(){
	textbox_width = 250;
	textbox_height = 250;
	kiss_array_new(&a1);
    kiss_array_append(&WindowProperty::objects, ARRAY_TYPE, &a1);
    button.font.font=TTF_OpenFont( "assets/fonts/standard.ttf", 30 );
    kiss_button_new(&button, &WindowProperty::window, "HELLO",300,200,200,100);
    kiss_window_new(&window1, NULL, NULL, 1, 0, 0, 100,100);
    kiss_textbox_new(&textbox1, &window1, 1, &a1, 50, 50,textbox_width, textbox_height);
    window1.visible = 1;
}
/**
    Update function to call each asset's update function
*/
void assetHandler::update(){
    button.rect.h =  100*WindowProperty::getHeightDisposition();
    button.rect.w = 200*WindowProperty::getWidthDisposition();
    //printf("%d %d", button.rect.h,button.rect.w);

}
/**
    Render function to draw the game object to the screen
*/

void assetHandler::render(){
    kiss_button_draw(&button, WindowProperty::renderer);
    kiss_textbox_draw(&textbox1, WindowProperty::renderer);
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
