#pragma once

#include <vector>

#include "creep-type.enum.h"
#include "creep-status.enum.h"
#include "creep-direction.enum.h"
#include "creep-terrain.enum.h"

struct CreepSettings {
        CreepType type;
        CreepTerrain terrain;
        int mineralReward;
        int gasReward;
        double health;
        double speed;
};

class Creep
{
    public:
        Creep(CreepSettings* creepSettings);

        CreepType type;
        CreepStatus status;

        int posX;
        int posY;
        CreepDirection direction;

        double health;
        double speed;
        double mineralReward;
        double gasReward;
};

class CreepWave
{
    public:
        void addCreep(CreepType type, int count);

        double spawnDelay;

    private:
        std::vector<CreepType> creepTypes;
};
