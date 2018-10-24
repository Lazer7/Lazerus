#include "AssetHandler.h"
#include "GameObject.h"
#include <iostream>
using namespace std;
GameObject ahri;
GameObject wall;
GameObject text;
bool hasCollided = false;
/**
    Initializes all Assets in the Game
    TODO:: Refactor to place all characters in a vector
*/
void AssetHandler::init(){
    ahri.addComponent<TransformComponent>(200,200,40,39);
    ahri.addComponent<SpriteRenderer>("assets/images/sprites/ahri.png",39,39,0,3,30);
    ahri.addComponent<ColliderComponent>("Ahri");
    wall.addComponent<TransformComponent>(400,200,100,100);
    wall.addComponent<SpriteRenderer>("assets/images/sprites/wall.png",200,200);
    wall.addComponent<ColliderComponent>("Wall");
}
/**
    Update function to call each asset's update function
*/
void AssetHandler::update(){
    ahri.update();
    wall.update();
    if(ahri.getComponent<ColliderComponent>().collision(wall.getComponent<ColliderComponent>())){
        text.addComponent<TransformComponent>(100,100,300,100);
        text.addComponent<SpriteRenderer>("assets/images/sprites/collision.png",500,100);
        hasCollided=true;
        text.update();
    }
    else if(hasCollided) {
        text.getComponent<SpriteRenderer>().~SpriteRenderer();
        hasCollided=false;
    }

}
/**
    Render function to draw the game object to the screen
*/

void AssetHandler::render(){
    ahri.render();
    wall.render();
    if(hasCollided){
        text.render();
    }
}
/**
    Handles Key Events for game objects
*/
void AssetHandler::keyEventHandler(){
    if(WindowProperty::event.type == SDL_KEYDOWN){
        switch(WindowProperty::event.key.keysym.sym){
            case SDLK_a:
                ahri.getComponent<TransformComponent>().velocity.x = -2;
                ahri.getComponent<SpriteRenderer>().setLevel(1);
            break;
            case SDLK_d:
                ahri.getComponent<TransformComponent>().velocity.x = 2;
                ahri.getComponent<SpriteRenderer>().setLevel(2);
            break;
            case SDLK_w:
                ahri.getComponent<TransformComponent>().velocity.y = -2;
                ahri.getComponent<SpriteRenderer>().setLevel(3);
            break;
            case SDLK_s:
                ahri.getComponent<TransformComponent>().velocity.y = 2;
                ahri.getComponent<SpriteRenderer>().setLevel(0);
            break;
        }
    }
    if(WindowProperty::event.type == SDL_KEYUP){
        ahri.getComponent<TransformComponent>().velocity.x = 0;
        ahri.getComponent<TransformComponent>().velocity.y = 0;
    }
}


