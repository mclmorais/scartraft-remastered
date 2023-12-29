#ifndef __PLOTTER_H__
#define __PLOTTER_H__

#include <allegro5/allegro.h>
#include "bitmap-loader.h"

class Plotter
{
    public:
        Plotter(BitmapLoader* bitmapLoader);
        void createDisplay();
        void plotMainMenu();
    	ALLEGRO_DISPLAY *display;

    private:
        BitmapLoader* bitmapLoader;

        ALLEGRO_DISPLAY* getDisplay();
};

#endif // __PLOTTER_H__