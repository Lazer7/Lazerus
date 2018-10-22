#include "assetHandler.h"
#include "list"
#include "PlayableCharacter.h"
kiss_button button ={0};
kiss_label label ={0};
std::list<PlayableCharacter> gameObjects;
int i = 4;
/**
    Initializes all Assets in the Game
    TODO:: Refactor to place all characters in a vector
*/
void assetHandler::init(){
    char* message = "HELLO";
    kiss_label_new(&label,&WindowProperty::window,message,0,0);
    kiss_button_new(&button,&WindowProperty::window, "MORE AHRI!",200,100,150,50);
    button.font.font=TTF_OpenFont( "assets/fonts/standard.ttf", 30 );

}
/**
    Update function to call each asset's update function
*/
void assetHandler::update(){
    button.rect.h = 50*WindowProperty::getHeightDisposition();
    button.rect.w = 150*WindowProperty::getWidthDisposition();
    button.rect.x = 200*WindowProperty::getWidthDisposition();
    button.rect.y = 200*WindowProperty::getHeightDisposition();
    button.textx = 220 *WindowProperty::getWidthDisposition();
    button.texty = 220 *WindowProperty::getHeightDisposition();
    list<PlayableCharacter>::iterator it;
    for(it= gameObjects.begin(); it!= gameObjects.end(); ++it){
        it->update();
    }
    if(i!=100){
        label.text[i]='a';
        i++;
    }

}
/**
    Render function to draw the game object to the screen
*/

void assetHandler::render(){
    kiss_button_draw(&button, WindowProperty::renderer);
    kiss_label_draw(&label,WindowProperty::renderer);
    list<PlayableCharacter>::iterator it;
    for(it= gameObjects.begin(); it!= gameObjects.end(); ++it){
        it->render();
    }
}
/**
    Handles Key Events for game objects
*/
void assetHandler::keyEventHandler(){
    int draw = 0;
    int quit = 0;
    button_event(&button, &WindowProperty::event, &draw, &quit);
    list<PlayableCharacter>::iterator it;
    for(it= gameObjects.begin(); it!= gameObjects.end(); ++it){
        it->keyEventListener();
    }
}

void assetHandler::button_event(kiss_button *button, SDL_Event *e, int *draw,
                  int *quit)
{
    if (kiss_button_event(button, e, draw)){
        PlayableCharacter ahri;
        ahri.init(200,400);
        gameObjects.push_back(ahri);
    }

}
