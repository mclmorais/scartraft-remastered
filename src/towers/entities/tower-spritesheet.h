#include <allegro5/allegro5.h>

class TowerSpritesheet
{
    public:
        static const int attackingSpritesCount = 5;
        ALLEGRO_BITMAP* baseSprite;
        ALLEGRO_BITMAP* attackingSprites[attackingSpritesCount];
    
};