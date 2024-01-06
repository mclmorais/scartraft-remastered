#pragma once

#include "../directions.h"
#include <allegro5/allegro5.h>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
class CreepSpritesheet
{
  public:
    int walkingSpritesCount = 0;
    int innerSpriteHeight = 0;
    int spriteOffsetX = 0;
    int spriteOffsetY = 0;
    int numberOfBars = 10;
    std::map<Direction, std::vector<ALLEGRO_BITMAP*>> walkingSprites;
    std::vector<ALLEGRO_BITMAP*> walkingSpritesFrontLeft;
    std::vector<ALLEGRO_BITMAP*> walkingSpritesFrontRight;
    std::vector<ALLEGRO_BITMAP*> walkingSpritesBackLeft;
    std::vector<ALLEGRO_BITMAP*> walkingSpritesBackRight;
    std::pair<ALLEGRO_BITMAP*, ALLEGRO_BITMAP*> bars;
};