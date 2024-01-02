#ifndef TOWER_PLOTTER_H
#define TOWER_PLOTTER_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <map>
#include <vector>
#include "tower.h"
#include "tower-spritesheet.h"
#include "tower-loader.h"
#include "../engines/tower-engine.h" // TODO: trocar para tower slots
#include "../tower-status.enum.h"
#include <math.h>
class TowerPlotter
{
    public:
        TowerPlotter(TowerLoader* towerLoader, std::vector<TowerSlot*>* towerSlots);
        void plot();

    private:
        std::vector<TowerSlot*>* towerSlots;
        TowerLoader* towerLoader;
        int interpolateFrameToSprite(int currentFrame, int frameCount, int spriteCount);
};

#endif // TOWER_PLOTTER_H