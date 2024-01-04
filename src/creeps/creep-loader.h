#pragma once

#include <map>
#include "creep-type.enum.h"
#include "creep-spritesheet.h"
#include "../directions.h"

class CreepLoader
{
    public:
        std::map<CreepType, CreepSpritesheet*> spritesheets;
        void loadSprites();
};