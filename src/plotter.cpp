#include "plotter.h"

#define BUTTON_Y_SIZE 60
#define TOWER_BUTTON_X_START       715
#define TOWER_BUTTON_X_END         TOWER_BUTTON_X_START + 60
#define BUNKER_BUTTON_Y_START      235
#define BUNKER_BUTTON_Y_END        BUNKER_BUTTON_Y_START + BUTTON_Y_SIZE
#define TOWER_BUTTON_Y_START       295
#define TOWER_BUTTON_Y_END         TOWER_BUTTON_Y_START + BUTTON_Y_SIZE
#define SIEGE_BUTTON_Y_START       365
#define SIEGE_BUTTON_Y_END         SIEGE_BUTTON_Y_START + BUTTON_Y_SIZE


Plotter::Plotter(BitmapLoader* bitmapLoader)
{
    this->bitmapLoader = bitmapLoader;
}

void Plotter::createDisplay()
{
	display = al_create_display(800, 600);
	al_set_window_title(display, "Scartraft 2");
}

void Plotter::plotMainMenu(int variation)
{
    if(variation > 2) 
        variation = 0;
    
    al_draw_bitmap(bitmapLoader->menuBackgrounds[variation], 0, 0, 0);

}

void Plotter::plotBackground()
{
    al_draw_bitmap(bitmapLoader->background, 0, 0, 0);
    al_draw_bitmap(bitmapLoader->beacons, 0, 0, 0);
}

void Plotter::plotGameMenu(TowerType::TowerType selectedTower)
{
    al_draw_bitmap(bitmapLoader->gameMenu, 630, 0, 0);
	al_draw_bitmap(bitmapLoader->bunkerButton[selectedTower == TowerType::Bunker ? 1 : 0], 715, 235      , 0);
	al_draw_bitmap(bitmapLoader->towerButton[selectedTower == TowerType::Turret ? 1 : 0],  715, 235+65   , 0);
	al_draw_bitmap(bitmapLoader->siegeButton[selectedTower == TowerType::SiegeTank ? 1 : 0],  715, 235+130  , 0);
}


