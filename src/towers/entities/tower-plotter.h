#ifndef TOWER_PLOTTER_H
#define TOWER_PLOTTER_H

#include "../engines/tower-engine.h" // TODO: trocar para tower slots
#include "../tower-status.enum.h"
#include "tower-loader.h"
#include "tower-spritesheet.h"
#include "tower.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <map>
#include <math.h>
#include <vector>
class TowerPlotter
{
  public:
    TowerPlotter(TowerLoader* towerLoader, std::vector<TowerSlot*>* towerSlots);
    void plot(bool debug);

  private:
    std::vector<TowerSlot*>* towerSlots;
    TowerLoader* towerLoader;
    int interpolateFrameToSprite(int currentFrame, int frameCount, int spriteCount);
};

#endif // TOWER_PLOTTER_H