#ifndef PLAYABLECHARACTER_H
#define PLAYABLECHARACTER_H
#include "GameObject.h"
#include "WindowProperty.h"
#include "components/ColliderComponent.h"
#include <iostream>
using namespace std;

class PlayableCharacter : public GameObject
{
    public:
        PlayableCharacter()= default;
        PlayableCharacter(const PlayableCharacter& other){
            this->init(other.x,other.y);
        }
        virtual ~PlayableCharacter()=default;
        void init(int,int);
        void update();
        void render();
        void keyEventListener();
        void onCollisionDetection(ColliderComponent);
    protected:

    private:
        int x,y;
        int MaxHeight, currentHeight;
        bool isMovingRight=false, isMovingLeft=false, isJumpingUp=false, isJumpingDown=false;
};

#endif // PLAYABLECHARACTER_H
