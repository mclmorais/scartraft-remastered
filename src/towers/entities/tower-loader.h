#ifndef TOWER_LOADER_H
#define TOWER_LOADER_H

#include "../tower-type.enum.h"
#include "tower-spritesheet.h"
#include <allegro5/allegro5.h>
#include <iostream>
#include <map>

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