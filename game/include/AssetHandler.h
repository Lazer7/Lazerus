#ifndef ASSETHANDLER_H
#define ASSETHANDLER_H
#include <list>
#include <components/Components.h>
#include "Media.h"
#include "WindowProperty.h"


class AssetHandler
{
    public:
        AssetHandler(){};
        void init();
        void update();
        void render();
        void keyEventHandler();
    private:
        Media music;
        int frameStart;

};

#endif // ASSETHANDLER_H
