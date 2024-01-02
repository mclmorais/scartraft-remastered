#ifndef TOWER_SPRITESHEET_H
#define TOWER_SPRITESHEET_H

#include <allegro5/allegro5.h>
#include <vector>

class TowerSpritesheet
{
    public:
        int attackingSpritesCount = 0;
        int spriteOffsetX = 0;
        int spriteOffsetY = 0;
        int attackFramesCount = 0;
        ALLEGRO_BITMAP* baseSprite;
        std::vector<ALLEGRO_BITMAP*> attackingSprites;
};

#endif // TOWER_SPRITESHEET_H