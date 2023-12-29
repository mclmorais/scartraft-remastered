#ifndef __BITMAP_LOADER_H__
#define __BITMAP_LOADER_H__

#include <string>
#include "allegro5/allegro.h"

class BitmapLoader
{

    public:
        void loadMenuBackgrounds();
        ALLEGRO_BITMAP* menuBackgrounds[3];

    private:
        void loadSprites(int numberOfSprites, std::string spriteName, ALLEGRO_BITMAP* sprites[]);
};

#endif // __BITMAP_LOADER_H__