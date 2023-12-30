#ifndef __PLOTTER_H__
#define __PLOTTER_H__

#include <allegro5/allegro.h>
#include "tower-type.enum.h"
#include "bitmap-loader.h"

class Plotter
{
    public:
        Plotter(BitmapLoader* bitmapLoader);
        void createDisplay();
        void plotMainMenu(int variation);
        void plotBackground();
        void plotGameMenu(ALLEGRO_MOUSE_STATE mouseState);
        TowerType::TowerType checkHighlight(ALLEGRO_MOUSE_STATE mouseState);
    	ALLEGRO_DISPLAY *display;

    private:
        BitmapLoader* bitmapLoader;
};

#endif // __PLOTTER_H__