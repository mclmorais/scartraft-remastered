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
    creepWaves[0]->spawnDelay = 15;
}