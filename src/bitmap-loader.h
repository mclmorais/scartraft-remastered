#ifndef __BITMAP_LOADER_H__
#define __BITMAP_LOADER_H__

#include "allegro5/allegro.h"
#include <string>

class BitmapLoader
{

  public:
    void loadMenuBackgrounds();
    void loadBackground();
    void loadGameMenu();
    ALLEGRO_BITMAP* menuBackgrounds[3];
    ALLEGRO_BITMAP* background;
    ALLEGRO_BITMAP* gameMenu;
    ALLEGRO_BITMAP* bunkerButton[2];
    ALLEGRO_BITMAP* towerButton[2];
    ALLEGRO_BITMAP* siegeButton[2];
    ALLEGRO_BITMAP* beacons;

  private:
    void loadSprites(int numberOfSprites, std::string spriteName, ALLEGRO_BITMAP* sprites[]);
};

#endif // __BITMAP_LOADER_H__