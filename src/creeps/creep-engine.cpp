#include "creep-engine.h"

void CreepEngine::planCreeps()
{
    creepSettings[MARINE] = {MARINE, LAND, 50, 0, 100, 1};
    creepSettings[HYDRALISK] = {HYDRALISK, LAND, 100, 20, 200, 1.2};
    creepSettings[THOR] = {THOR, LAND, 200, 100, 400, 0.8};
    creepSettings[VOID_RAY] = {VOID_RAY, AIR, 300, 200, 600, 0.6};
    creepSettings[COLOSSUS] = {COLOSSUS, LAND, 400, 300, 800, 0.4};
}

void CreepEngine::planWaves()
{
    creepWaves.push_back(new CreepWave());
    creepWaves[0]->addCreep(MARINE, 10);
    creepWaves[0]->spawnDelay = 5;
}

void CreepEngine::startWaveTimer()
{
    waveTimer = al_create_timer(1.0);
    al_start_timer(waveTimer);
}

void CreepEngine::spawnCreep(CreepSettings* creepSettings)
{
    creeps.push_back(new Creep(creepSettings));
}

void CreepEngine::manageWaves()
{
    for(auto creepWave : creepWaves)
    {
        if(al_get_timer_count(waveTimer) >= creepWave->spawnDelay)
        {
            std::cout << "Spawning creep wave" << std::endl;
            for(auto creepType : creepWave->creepTypes)
            {
                spawnCreep(&creepSettings[creepType]);
            }
        }
    }
}

void CreepEngine::moveCreeps()
{
    for(auto creep : creeps)
    {
        if(creep->status != ALIVE)
            return;

        if(creep->posX == CORNER_1X && creep->posY == CORNER_1Y)
            creep->direction = DOWN_RIGHT;
        else if(creep->posX == CORNER_2X && creep->posY == CORNER_2Y)
            creep->direction = DOWN_LEFT;
        else if(creep->posX == CORNER_3X && creep->posY == CORNER_3Y)
            creep->direction = UP_LEFT;
        else if(creep->posX == CORNER_4X && creep->posY == CORNER_4Y)
            creep->direction = DOWN_LEFT;
        else if(creep->posX == CORNER_5X && creep->posY == CORNER_5Y)
            creep->direction = DOWN_RIGHT;
        else if(creep->posX == CORNER_6X && creep->posY == CORNER_6Y)
            creep->direction = UP_RIGHT;
        else if(creep->posX == CORNER_7X && creep->posY == CORNER_7Y)
            creep->direction = DOWN_RIGHT;
        else if(creep->posX == CORNER_8X && creep->posY == CORNER_8Y)
            creep->direction = DOWN_LEFT;

        switch(creep->direction)
        {
            case DOWN_LEFT:
                creep->posX -= creep->speed;
                creep->posY += creep->speed / 2.0;
                break;
            case DOWN_RIGHT:
                creep->posX += creep->speed;
                creep->posY += creep->speed / 2.0;
                break;
            case UP_LEFT:
                creep->posX -= creep->speed;
                creep->posY -= creep->speed / 2.0;
                break;
            case UP_RIGHT:
                creep->posX += creep->speed;
                creep->posY -= creep->speed / 2.0;
                break;
        }
    }
}