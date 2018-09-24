#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include <string>
#include "../components/ComponentManager.h"
#include <typeinfo>
/**
    Abstract Game Object class that will hold all components of a game object
*/
class GameObject
{
    public:
            // Constructor
        GameObject():entityHandler(this->manager.addEntity()){};
        virtual ~GameObject(){
            manager.destroyEntities();
        }
        // Add and Get Components
        template <typename T,typename... Args> void addComponent(Args... args){
            entityHandler.addComponent<T>(args...);
        }
        template <typename T> T& getComponent(){
            return entityHandler.getComponent<T>();

        }

        // Component Manager
        Manager manager;
        Entity& entityHandler;

        virtual void update(){
            manager.refresh();
            manager.update();
        };
        virtual void render(){
            manager.draw();
        };
};

#endif // GAMEOBJECT_H
