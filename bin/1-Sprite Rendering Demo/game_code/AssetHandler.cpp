#include "AssetHandler.h"
#include "GameObject.h"
#include <iostream>
using namespace std;
GameObject ahri;
/**
    Initializes all Assets in the Game
    TODO:: Refactor to place all characters in a vector
*/
void AssetHandler::init(){
    ahri.addComponent<TransformComponent>(200,200,40,39);
    ahri.addComponent<SpriteRenderer>("assets/images/sprites/ahri.png",39,39,0,3,30);
}
/**
    Update function to call each asset's update function
*/
void AssetHandler::update(){
    ahri.update();
}
/**
    Render function to draw the game object to the screen
*/

void AssetHandler::render(){
    ahri.render();
}
/**
    Handles Key Events for game objects
*/
void AssetHandler::keyEventHandler(){
    if(WindowProperty::event.type == SDL_KEYDOWN){
        int x = ahri.getComponent<TransformComponent>().x();
        int y = ahri.getComponent<TransformComponent>().y();
        switch(WindowProperty::event.key.keysym.sym){
            case SDLK_a:
                ahri.getComponent<TransformComponent>().velocity.x = -1;
                ahri.getComponent<SpriteRenderer>().setLevel(1);
            break;
            case SDLK_d:
                ahri.getComponent<TransformComponent>().velocity.x = 1;
                ahri.getComponent<SpriteRenderer>().setLevel(2);
            break;
            case SDLK_w:
                ahri.getComponent<TransformComponent>().velocity.y = -1;
                ahri.getComponent<SpriteRenderer>().setLevel(3);
            break;
            case SDLK_s:
                ahri.getComponent<TransformComponent>().velocity.y = 1;
                ahri.getComponent<SpriteRenderer>().setLevel(0);
            break;
        }
    }
    if(WindowProperty::event.type == SDL_KEYUP){
        ahri.getComponent<TransformComponent>().velocity.x = 0;
        ahri.getComponent<TransformComponent>().velocity.y = 0;
    }
}


