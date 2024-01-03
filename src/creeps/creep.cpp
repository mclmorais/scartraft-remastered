#include "creep.h"

Creep::Creep(CreepSettings* creepSettings)
{
    this->type = creepSettings->type;
    this->status = ALIVE;
    this->posX = 0;
    this->posY = 0;
    this->direction = DOWN_LEFT;
    this->health = creepSettings->health;
    this->speed = creepSettings->speed;
    this->mineralReward = creepSettings->mineralReward;
    this->gasReward = creepSettings->gasReward;
}

void CreepWave::addCreep(CreepType type, int count)
{
    for (int i = 0; i < count; i++)
    {
        this->creepTypes.push_back(type);
    }
}