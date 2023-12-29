#include "plotter.h"

Plotter::Plotter(BitmapLoader* bitmapLoader)
{
    this->bitmapLoader = bitmapLoader;
}

void Plotter::createDisplay()
{
	display = al_create_display(800, 600);
	al_set_window_title(display, "Scartraft 2");
}

void Plotter::plotMainMenu()
{
    al_draw_bitmap(bitmapLoader->menuBackgrounds[0], 0, 0, 0);
    al_wait_for_vsync();
    al_flip_display();
}

