#pragma once

#include <list>
#include <vector>
#include <map>
#include "creep.h"

class CreepEngine
{
    private:
        std::vector<CreepWave*> creepWaves;
        std::map<CreepType, CreepSettings> creepSettings;
        void spawnCreep(CreepSettings* creepSettings);
        int currentWave;
    public:
        void planCreeps();
        void planWaves();

        void manageWaves(); // TODO: continuar aqui
        std::list<Creep*> creeps;
        
};