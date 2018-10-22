#ifndef ASSETHANDLER_H
#define ASSETHANDLER_H
#include <list>
#include <components/Components.h>
#include "Media.h"
#include "WindowProperty.h"


class assetHandler
{
    public:
        assetHandler(){};
        void init();
        void update();
        void render();
        void keyEventHandler();
        void button_event(kiss_button *button, SDL_Event *e, int *draw,
                  int *quit);
    private:
        Media music;
        int frameStart;

};

#endif // ASSETHANDLER_H
