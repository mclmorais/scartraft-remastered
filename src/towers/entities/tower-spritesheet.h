#ifndef TOWER_SPRITESHEET_H
#define TOWER_SPRITESHEET_H

#include <allegro5/allegro5.h>

class TowerSpritesheet
{
    public:
        static const int attackingSpritesCount = 5;
        ALLEGRO_BITMAP* baseSprite;
        ALLEGRO_BITMAP* attackingSprites[attackingSpritesCount];
    
};

#endif // TOWER_SPRITESHEET_H