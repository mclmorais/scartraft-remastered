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

        al_draw_bitmap(towerLoader->spritesheets[tower->type]->baseSprite, tower->posX, tower->posY, 0);
    }
}