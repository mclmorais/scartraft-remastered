#pragma once

#include "../player-economy.h"
#include "../player/player.h"
#include "creep.h"
#include <allegro5/timer.h>
#include <iostream>
#include <list>
#include <map>
#include <utility>
#include <vector>

#define CHECKPOINT_RANGE = 5

class CreepEngine
{
  private:
    std::vector<CreepWave*> creepWaves;
    std::map<CreepType, CreepSettings> creepSettings;
    void spawnCreep(CreepSettings* creepSettings, int creepCount);
    int currentWave;
    ALLEGRO_TIMER* waveTimer;
    int creepCounter = 0;

  public:
    ~CreepEngine();
    void planCreeps();
    void planWaves();
    void planCheckpoints();
    void moveCreeps();
    void startWaveTimer();
    void manageWaves();
    void manageDeadCreeps(PlayerEconomy* playerEconomy);
    void manageCreepEOL(Player* player);
    std::list<Creep*> creeps;
    std::vector<std::pair<int, int>> creepCheckpoints;
};