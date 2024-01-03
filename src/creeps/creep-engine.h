#pragma once

#include <list>
#include <vector>
#include <map>
#include <utility>
#include "creep.h"
#include <allegro5/timer.h>
#include <iostream>

#define CHECKPOINT_RANGE = 5

class CreepEngine
{
    private:
        std::vector<CreepWave*> creepWaves;
        std::map<CreepType, CreepSettings> creepSettings;
        void spawnCreep(CreepSettings* creepSettings, int creepCount);
        int currentWave;
        ALLEGRO_TIMER* waveTimer;
    public:
        void planCreeps();
        void planWaves();
        void planCheckpoints();
        void moveCreeps();
        void startWaveTimer();
        void manageWaves(); // TODO: continuar aqui
        std::list<Creep*> creeps;
        std::vector<std::pair<int, int>> creepCheckpoints;
        
};