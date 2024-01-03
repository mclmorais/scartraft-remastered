#pragma once

#include <list>
#include <vector>
#include <map>
#include "creep.h"
#include <allegro5/timer.h>
#include <iostream>

#define START_POS_X 597+25
#define START_POS_Y -61+25

#define CORNER_1X 395+25
#define CORNER_1Y 40+25

#define CORNER_2X 537+25
#define CORNER_2Y 112+25

#define CORNER_3X 333+25
#define CORNER_3Y 214+25

#define CORNER_4X 137+25
#define CORNER_4Y 116+25

#define CORNER_5X -5+25
#define CORNER_5Y 187+25

#define CORNER_6X 333+25
#define CORNER_6Y 356+25

#define CORNER_7X 473+25
#define CORNER_7Y 286+25

#define CORNER_8X 593+25
#define CORNER_8Y 346+25

#define CORNER_9X 193+25
#define CORNER_9Y 546+25


class CreepEngine
{
    private:
        std::vector<CreepWave*> creepWaves;
        std::map<CreepType, CreepSettings> creepSettings;
        void spawnCreep(CreepSettings* creepSettings);
        int currentWave;
        ALLEGRO_TIMER* waveTimer;
    public:
        void planCreeps();
        void planWaves();
        void moveCreeps();
        void startWaveTimer();
        void manageWaves(); // TODO: continuar aqui
        std::list<Creep*> creeps;
        
};