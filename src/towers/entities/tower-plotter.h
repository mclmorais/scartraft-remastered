#ifndef TOWER_PLOTTER_H
#define TOWER_PLOTTER_H

#include <allegro5/allegro5.h>
#include <map>
#include <vector>
#include "tower.h"
#include "tower-spritesheet.h"
#include "tower-loader.h"
#include "../engines/tower-engine.h" // TODO: trocar para tower slots
class TowerPlotter
{
    public:
        TowerPlotter(TowerLoader* towerLoader, std::vector<TowerSlot>* towerSlots);
        void plot();

    private:
        std::vector<TowerSlot>* towerSlots;
        TowerLoader* towerLoader;
};

#endif // TOWER_PLOTTER_H