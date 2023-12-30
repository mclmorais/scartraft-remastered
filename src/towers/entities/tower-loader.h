#ifndef TOWER_LOADER_H
#define TOWER_LOADER_H

#include <allegro5/allegro5.h>
#include <map>
#include "tower-spritesheet.h"
#include <../tower-type.enum.h>

class TowerLoader
{
    public:
        std::map<TowerType::TowerType, TowerSpritesheet*> spritesheets;
        void loadSprites();
        
};

#endif // TOWER_LOADER_H