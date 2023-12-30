#ifndef TOWER_LOADER_H
#define TOWER_LOADER_H

#include <allegro5/allegro5.h>
#include <map>
#include "tower-spritesheet.h"
#include <iostream>
#include "../tower-type.enum.h"

class TowerLoader
{
    static const int bunkerAttackingSpritesCount = 5;
    static const int turretAttackingSpritesCount = 2;
    static const int siegeAttackingSpritesCount = 6;

    public:
        std::map<TowerType::TowerType, TowerSpritesheet*> spritesheets;
        void loadSprites();
        
};

#endif // TOWER_LOADER_H