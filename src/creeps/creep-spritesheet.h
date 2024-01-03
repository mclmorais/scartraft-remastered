#pragma once

#include <allegro5/allegro5.h>
#include <vector>
#include <iostream>

class CreepSpritesheet
{
    public:
        int walkingSpritesCount = 0;
        int walkingFramesCount = 0;
        int spriteOffsetX = 0;
        int spriteOffsetY = 0;
        std::vector<ALLEGRO_BITMAP*> walkingSpritesFrontLeft;
        std::vector<ALLEGRO_BITMAP*> walkingSpritesFrontRight;
        std::vector<ALLEGRO_BITMAP*> walkingSpritesBackLeft;
        std::vector<ALLEGRO_BITMAP*> walkingSpritesBackRight;
};