#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <stdbool.h>
#include "bitmap-loader.h"
#include "plotter.h"

int main()
{
    al_init();
	al_install_mouse();
	al_install_keyboard();
	!al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(10);
	al_init_primitives_addon();

	BitmapLoader* bitmapLoader = new BitmapLoader();
	bitmapLoader->loadMenuBackgrounds();

	Plotter* plotter = new Plotter(bitmapLoader);

	plotter->createDisplay();
	plotter->plotMainMenu();

	while(true);
}
