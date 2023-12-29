#ifndef __PLOTTER_H__
#define __PLOTTER_H__

#include <allegro5/allegro.h>
#include "bitmap-loader.h"
enum TowerType {None=0, Bunker, Turret, SiegeTank};

class Plotter
{
    public:
        Plotter(BitmapLoader* bitmapLoader);
        void createDisplay();
        void plotMainMenu(int variation);
        void plotBackground();
        void plotGameMenu(ALLEGRO_MOUSE_STATE mouseState);
        TowerType checkHighlight(ALLEGRO_MOUSE_STATE mouseState);
    	ALLEGRO_DISPLAY *display;

    private:
        BitmapLoader* bitmapLoader;
};

#endif // __PLOTTER_H__