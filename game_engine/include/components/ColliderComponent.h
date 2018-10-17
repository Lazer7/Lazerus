#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H
#include <string>
#include <SDL2/SDL.h>
#include "ComponentManager.h"

class ColliderComponent : public Component{
    public:
        SDL_Rect collider;
        std::string tag;

        TransformComponent* transformer;
        ColliderComponent(std::string tag){ this->tag=tag;}
        void init() override{
            if(!entity->hasComponent<TransformComponent>()){
                entity->addComponent<TransformComponent>();
            }
            transformer = &entity->getComponent<TransformComponent>();
        }
        void update() override{
            collider.x = (int) transformer->x();
            collider.y = (int) transformer->y();
            collider.w = transformer->getWidth();
            collider.h = transformer->getHeight();
        }
        bool collision(ColliderComponent otherObject){
            if(
               this->collider.x + this->collider.w >= otherObject.collider.x &&
               otherObject.collider.x + otherObject.collider.w >= this->collider.x &&
               this->collider.y + this->collider.h >= otherObject.collider.y &&
               otherObject.collider.y + otherObject.collider.h >= this->collider.y
               ){
                return true;
            }
            return false;
        }


};



#endif // COLLIDERCOMPONENT_H
