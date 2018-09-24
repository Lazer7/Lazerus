#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "Components.h"
#include "SDL_image.h"
#include "SDL.h"


class SpriteRenderer : public Component
{
    private:
        // Height and Width of image
        int srcHeight,srcWidth;
        // Position of the image on the frame
        TransformComponent* transformer;
        SDL_Rect srcRect, destRect;
        SDL_Texture* spriteSheetTexture;
        // Animation variables
        bool animated = false;
        int frames = 0;
        int speed = 100;

    public:
        // Overloaded Constructors
        SpriteRenderer(const char* spriteSheet){
            setTexture(spriteSheet);
        };

        SpriteRenderer(const char* spriteSheet,int srcWidth, int srcHeight){
            setTexture(spriteSheet);
            this->srcWidth=srcWidth;
            this->srcHeight=srcHeight;
        };
        SpriteRenderer(const char* spriteSheet,int srcWidth, int srcHeight, int frames, int speed){
            setTexture(spriteSheet);
            this->srcWidth=srcWidth;
            this->srcHeight=srcHeight;
            animated = true;
            this->frames = frames;
            speed = speed;
        };
        ~SpriteRenderer(){
            SDL_DestroyTexture(this->spriteSheetTexture);
            this->spriteSheetTexture = NULL;
        }
        void setTexture(const char* spriteSheet){
            SDL_Surface* tempSurface = IMG_Load(spriteSheet);
            spriteSheetTexture = SDL_CreateTextureFromSurface(WindowProperty::renderer, tempSurface);
            srcWidth = tempSurface->w;
            srcHeight = tempSurface->h;
            SDL_FreeSurface(tempSurface);
        }
        void init() override
        {
            if(!entity->hasComponent<TransformComponent>()){
                entity->addComponent<TransformComponent>();
            }
            transformer = &entity->getComponent<TransformComponent>();
            srcRect.x = srcRect.y = 0;
            srcRect.w = srcWidth;
            srcRect.h = srcHeight;
            destRect.w = transformer->width;
            destRect.h = transformer->height;
        }
        void update() override
        {
            if(animated)
            {
                srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks()/speed)%frames);
            }
            destRect.w = transformer->getWidth();
            destRect.h = transformer->getHeight();
            destRect.x = (int)transformer->x();
            destRect.y = (int)transformer->y();
        }
        void draw() override
        {
            SDL_RenderCopy(WindowProperty::renderer,spriteSheetTexture,&srcRect,&destRect);
        }

};

#endif // SPRITERENDERER_H
