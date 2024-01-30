#ifndef __PLOTTER_H__
#define __PLOTTER_H__

#include "bitmap-loader.h"
#include "player-economy.h"
#include "towers/tower-type.enum.h"

#include <allegro5/allegro.h>

class Plotter
{
  public:
    Plotter(BitmapLoader* bitmapLoader);
    void createDisplay();
    void plotMainMenu(int variation);
    void plotBackground();
    void plotGameMenu(TowerType::TowerType selectedTower, PlayerEconomy* playerEconomy);
    TowerType::TowerType checkHighlight(ALLEGRO_MOUSE_STATE mouseState);
    ALLEGRO_DISPLAY* display;

  private:
    BitmapLoader* bitmapLoader;
};

#endif // __PLOTTER_H__