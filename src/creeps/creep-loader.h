#pragma once

#include "../directions.h"
#include "creep-spritesheet.h"
#include "creep-type.enum.h"
#include <map>

class CreepLoader
{
  public:
    std::map<CreepType, CreepSpritesheet*> spritesheets;
    void loadSprites();
};