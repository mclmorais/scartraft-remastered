#include "tower-plotter.h"

TowerPlotter::TowerPlotter(TowerLoader* towerLoader, std::vector<TowerSlot*>* towerSlots)
{
    this->towerSlots = towerSlots;
    this->towerLoader = towerLoader;
}

void TowerPlotter::plot(bool debug)
{
    for(int i = 0; i < this->towerSlots->size(); i++)
    {
        if(!this->towerSlots->at(i)->isOccupied)
        {
            if(debug)
                al_draw_circle(this->towerSlots->at(i)->posX, this->towerSlots->at(i)->posY, 5, al_map_rgb(255,0,0), 2);
            continue;
        }

        Tower* tower = this->towerSlots->at(i)->tower;
        TowerSpritesheet* spritesheet = this->towerLoader->spritesheets[tower->type];

        ALLEGRO_BITMAP* sprite = nullptr;
        switch(tower->status) {
            case READY:
                sprite = spritesheet->baseSprite;
                break;
            case COOLING_DOWN:
                int frame = interpolateFrameToSprite(tower->cooldownTimer, spritesheet->attackFramesCount, spritesheet->attackingSpritesCount);
                sprite = (frame != -1) ? spritesheet->attackingSprites[frame] : spritesheet->baseSprite;
                break;
        }

        // std::cout << "sprite: " << sprite << std::endl;

        if(sprite != nullptr)
            al_draw_bitmap(sprite, tower->posX + spritesheet->spriteOffsetX, tower->posY + spritesheet->spriteOffsetY, 0);

        if(debug)
        {
            al_draw_circle(tower->posX, tower->posY, tower->range, al_map_rgb(127, 127, 127), 2);
            al_draw_circle(tower->posX, tower->posY, 5, al_map_rgb(0,200,0), 2);
        }

    }
}

int TowerPlotter::interpolateFrameToSprite(int currentFrame, int frameCount, int spriteCount)
{
    if(currentFrame > frameCount)
        return -1;

    int selectedSprite = round(currentFrame * (spriteCount - 1) / (double)frameCount);

    // std::cout << "currentFrame: " << currentFrame << " frameCount: " << frameCount << " spriteCount: " << spriteCount << " selectedSprite: " << selectedSprite << std::endl;

    return selectedSprite;
}