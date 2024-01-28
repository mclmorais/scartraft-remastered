#include "creep-engine.h"

void CreepEngine::planCheckpoints()
{
    this->creepCheckpoints.push_back({617, -31});
    this->creepCheckpoints.push_back({415, 70});
    this->creepCheckpoints.push_back({555, 140});
    this->creepCheckpoints.push_back({353, 243});
    this->creepCheckpoints.push_back({160, 145});
    this->creepCheckpoints.push_back({22, 218});
    this->creepCheckpoints.push_back({353, 385});
    this->creepCheckpoints.push_back({495, 315});
    this->creepCheckpoints.push_back({615, 375});
    this->creepCheckpoints.push_back({198, 581});
}

void CreepEngine::planCreeps()
{
    creepSettings[MARINE] = {MARINE, LAND, 50, 0, 100, 12, 1, 40};
    creepSettings[HYDRALISK] = {HYDRALISK, LAND, 100, 20, 200, 12, 1.5, 68};
    creepSettings[THOR] = {THOR, LAND, 200, 100, 400, 8, 2, 60};
    creepSettings[VOID_RAY] = {VOID_RAY, AIR, 300, 200, 600, 6, 2, 108};
    creepSettings[COLOSSUS] = {COLOSSUS, LAND, 400, 300, 800, 10, 5, 60};
}

void CreepEngine::planWaves()
{
    creepWaves.push_back(new CreepWave());
    creepWaves[0]->addCreep(MARINE, 2);
    creepWaves[0]->addCreep(HYDRALISK, 2);
    creepWaves[0]->addCreep(THOR, 2);
    creepWaves[0]->addCreep(VOID_RAY, 2);
    creepWaves[0]->addCreep(COLOSSUS, 2);
    creepWaves[0]->spawnDelay = 1;
}

void CreepEngine::startWaveTimer()
{
    waveTimer = al_create_timer(1.0);
    al_start_timer(waveTimer);
}

void CreepEngine::spawnCreep(CreepSettings* creepSettings, int creepCount)
{
    std::cout << "Spawning creep " << creepCounter << " of type " << creepSettings->type << std::endl;
    creeps.push_back(new Creep(++creepCounter, creepCheckpoints[0].first + 60 * creepCount, creepCheckpoints[0].second - 30 * creepCount,
                               creepSettings));
}

void CreepEngine::manageWaves()
{

    for (auto creepWave : creepWaves)
    {
        if (al_get_timer_count(waveTimer) >= creepWave->spawnDelay)
        {
            std::cout << "Spawning creep wave" << std::endl;
            for (int i = 0; i < creepWave->creepTypes.size(); i++)
            {
                spawnCreep(&creepSettings[creepWave->creepTypes[i]], i);
            }
            creepWave->spawnDelay += 50;
        }
    }
}

void CreepEngine::moveCreeps()
{
    for (auto creep : creeps)
    {
        if (creep->status != ALIVE)
            continue;

        auto targetCheckpoint = creepCheckpoints[creep->cornerTarget];

        if (creep->posX - targetCheckpoint.first > 0 && creep->posY - targetCheckpoint.second > 0)
            creep->direction = UP_LEFT;
        else if (creep->posX - targetCheckpoint.first < 0 && creep->posY - targetCheckpoint.second > 0)
            creep->direction = UP_RIGHT;
        else if (creep->posX - targetCheckpoint.first > 0 && creep->posY - targetCheckpoint.second < 0)
            creep->direction = DOWN_LEFT;
        else if (creep->posX - targetCheckpoint.first < 0 && creep->posY - targetCheckpoint.second < 0)
            creep->direction = DOWN_RIGHT;

        // checks if creep is within a minimum range of the checkpoint
        if ((creep->posX >= targetCheckpoint.first - 1 && creep->posX <= targetCheckpoint.first + 1) &&
            (creep->posY >= targetCheckpoint.second - 1 && creep->posY <= targetCheckpoint.second + 1) &&
            creep->cornerTarget < creepCheckpoints.size())
        {
            creep->posX = targetCheckpoint.first;
            creep->posY = targetCheckpoint.second;
            creep->cornerTarget++;
        }

        switch (creep->direction)
        {
        case DOWN_LEFT:
            creep->posX -= 0.1 * creep->speed;
            creep->posY += 0.1 * creep->speed / 2.0;
            break;
        case DOWN_RIGHT:
            creep->posX += 0.1 * creep->speed;
            creep->posY += 0.1 * creep->speed / 2.0;
            break;
        case UP_LEFT:
            creep->posX -= 0.1 * creep->speed;
            creep->posY -= 0.1 * creep->speed / 2.0;
            break;
        case UP_RIGHT:
            creep->posX += 0.1 * creep->speed;
            creep->posY -= 0.1 * creep->speed / 2.0;
            break;
        }

        creep->walkingTimer++;
        if (creep->walkingTimer > creep->totalWalkingTimer)
            creep->walkingTimer = 0;
    }
}

void CreepEngine::manageDeadCreeps(PlayerEconomy* playerEconomy)
{

    auto it = creeps.begin();

    int i = 0;

    while (it != creeps.end())
    {
        auto creep = *it;

        if (creep->status == ALIVE && creep->health <= 0)
        {
            std::cout << "Creep defeated" << std::endl;
            creep->status = DYING;
            creep->deathPosX = creep->posX;
            creep->deathPosY = creep->posY;
            playerEconomy->minerals += creep->mineralReward;
            playerEconomy->gas += creep->gasReward;
        }
        else if (creep->status == DYING)
        {
            if (++creep->deathTimer >= creep->deathDuration)
            {
                std::cout << "Creep is dead" << std::endl;
                creep->status = DEAD;
            }
        }
        else if (creep->status == DEAD)
        {
            std::cout << "Removing creep" << std::endl;
            it = creeps.erase(it);
            std::cout << "Creep removed" << std::endl;
            delete creep;
            std::cout << "Creep deleted" << std::endl;
            continue;
        }

        ++it;
    }
}

void CreepEngine::manageCreepEOL(Player* player)
{
    auto it = creeps.begin();

    while (it != creeps.end())
    {
        auto creep = *it;

        if (creep->cornerTarget == creepCheckpoints.size())
        {
            std::cout << "Creep reached end of line" << std::endl;
            player->health -= creep->damage;
            std::cout << "Player damaged by " << creep->damage << "; health is now " << player->health << std::endl;
            it = creeps.erase(it);
            delete creep;
        }

        ++it;
    }
}

CreepEngine::~CreepEngine()
{
    std::cout << std::endl;
    "Deinitializing creeps: ";
    for (auto creep : creeps)
    {
        std::cout << creep->id << " ";
        delete creep;
    }
    std::cout << std::endl;
}