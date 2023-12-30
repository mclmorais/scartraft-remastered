#include "tower-plotter.h"

TowerPlotter::TowerPlotter(TowerLoader* towerLoader, std::vector<TowerSlot*>* towerSlots)
{
    this->towerSlots = towerSlots;
    this->towerLoader = towerLoader;
}

void TowerPlotter::plot()
{
    for(int i = 0; i < this->towerSlots->size(); i++)
    {
        if(!this->towerSlots->at(i)->isOccupied)
            continue;

        Tower* tower = this->towerSlots->at(i)->tower;
        TowerSpritesheet* spritesheet = this->towerLoader->spritesheets[tower->type];

        al_draw_bitmap(spritesheet->baseSprite, tower->posX + spritesheet->spriteOffsetX, tower->posY + spritesheet->spriteOffsetY, 0);
    }
}