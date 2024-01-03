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
        Creep(int id, int posX, int posY, CreepSettings* creepSettings);

        int id;

        CreepType type;
        CreepStatus status;

        double posX;
        double posY;
        CreepDirection direction;

        double health;
        double maxHealth;
        double speed;
        double mineralReward;
        double gasReward;

        double walkingTimer;
        int cornerTarget;

};

class CreepWave
{
    public:
        void addCreep(CreepType type, int count);
        std::vector<CreepType> creepTypes;
        double spawnDelay;


    private:
};
