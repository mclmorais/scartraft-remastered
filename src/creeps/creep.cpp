#include "creep.h"

Creep::Creep(int posX, int posY, CreepSettings* creepSettings)
{
    this->type = creepSettings->type;
    this->status = ALIVE;
    this->posX = posX;
    this->posY = posY;
    this->direction = DOWN_LEFT;
    this->health = creepSettings->health;
    this->speed = creepSettings->speed;
    this->mineralReward = creepSettings->mineralReward;
    this->gasReward = creepSettings->gasReward;
    this->cornerTarget = 1;
}

void CreepWave::addCreep(CreepType type, int count)
{
    for (int i = 0; i < count; i++)
    {
        this->creepTypes.push_back(type);
    }
}