#include "creep-engine.h"

void CreepEngine::planCheckpoints()
{
    this->creepCheckpoints.push_back({597+25, -61+25});
    this->creepCheckpoints.push_back({395+25, 40+25});
    this->creepCheckpoints.push_back({537+25, 112+25});
    this->creepCheckpoints.push_back({333+25, 214+25});
    this->creepCheckpoints.push_back({137+25, 116+25});
    this->creepCheckpoints.push_back({-5+25, 187+25});
    this->creepCheckpoints.push_back({333+25, 356+25});
    this->creepCheckpoints.push_back({473+25, 286+25});
    this->creepCheckpoints.push_back({593+25, 346+25});
    this->creepCheckpoints.push_back({193+25, 546+25});
}

void CreepEngine::planCreeps()
{
    creepSettings[MARINE] = {MARINE, LAND, 50, 0, 100, 0.7};
    creepSettings[HYDRALISK] = {HYDRALISK, LAND, 100, 20, 200, 1.2};
    creepSettings[THOR] = {THOR, LAND, 200, 100, 400, 0.8};
    creepSettings[VOID_RAY] = {VOID_RAY, AIR, 300, 200, 600, 0.6};
    creepSettings[COLOSSUS] = {COLOSSUS, LAND, 400, 300, 800, 0.4};
}

void CreepEngine::planWaves()
{
    creepWaves.push_back(new CreepWave());
    creepWaves[0]->addCreep(MARINE, 10);
    creepWaves[0]->spawnDelay = 1;
}

void CreepEngine::startWaveTimer()
{
    waveTimer = al_create_timer(1.0);
    al_start_timer(waveTimer);
}

void CreepEngine::spawnCreep(CreepSettings* creepSettings, int creepCount)
{
    creeps.push_back(new Creep(creepCheckpoints[0].first + 60 * creepCount, creepCheckpoints[0].second - 30 * creepCount, creepSettings));
}

void CreepEngine::manageWaves()
{

    for(auto creepWave : creepWaves)
    {
        if(al_get_timer_count(waveTimer) >= creepWave->spawnDelay)
        {
            std::cout << "Spawning creep wave" << std::endl;
            for(int i = 0; i < creepWave->creepTypes.size(); i++)
            {
                spawnCreep(&creepSettings[creepWave->creepTypes[i]], i);
            }
            creepWave->spawnDelay += 50;
        }
    }
}

void CreepEngine::moveCreeps()
{
    for(auto creep : creeps)
    {
        if(creep->status != ALIVE)
            return;

        auto currentDirection = creep->direction;

        auto targetCheckpoint = creepCheckpoints[creep->cornerTarget];

        if(creep->posX - targetCheckpoint.first > 0 && creep->posY - targetCheckpoint.second > 0)
            creep->direction = UP_LEFT;
        else if(creep->posX - targetCheckpoint.first < 0 && creep->posY - targetCheckpoint.second > 0)
            creep->direction = UP_RIGHT;
        else if(creep->posX - targetCheckpoint.first > 0 && creep->posY - targetCheckpoint.second < 0)
            creep->direction = DOWN_LEFT;
        else if(creep->posX - targetCheckpoint.first < 0 && creep->posY - targetCheckpoint.second < 0)
            creep->direction = DOWN_RIGHT;

        // checks if creep is within a minimum range of the checkpoint
        if(
            (creep->posX >= targetCheckpoint.first - 5 && creep->posX <= targetCheckpoint.first + 5) &&
            (creep->posY >= targetCheckpoint.second - 5 && creep->posY <= targetCheckpoint.second + 5) &&
            creep->cornerTarget < creepCheckpoints.size() - 1
        )
        {
            creep->cornerTarget++;
        }

        // if(
        //     (creep->posX >= targetCheckpoint.first + 5 || creep->posX >= targetCheckpoint.first - 5) &&
        //     (creep->posY >= targetCheckpoint.second + 5 || creep->posY >= targetCheckpoint.second - 5) &&
        //     creep->cornerTarget < creepCheckpoints.size() - 1
        // )
        // {
        //     creep->cornerTarget++;
        // }
    


        // if(creep->cornerTarget == 1 && creep->posX <= CORNER_1X && creep->posY >= CORNER_1Y)
        //     creep->direction = DOWN_RIGHT;
        // else if(creep->cornerTarget == 2 && creep->posX >= CORNER_2X && creep->posY >= CORNER_2Y)
        //     creep->direction = DOWN_LEFT;
        // else if(creep->cornerTarget == 3 && creep->posX == CORNER_3X && creep->posY == CORNER_3Y)
        //     creep->direction = UP_LEFT;
        // else if(creep->cornerTarget == 4 && creep->posX == CORNER_4X && creep->posY == CORNER_4Y)
        //     creep->direction = DOWN_LEFT;
        // else if(creep->cornerTarget == 5 && creep->posX == CORNER_5X && creep->posY == CORNER_5Y)
        //     creep->direction = DOWN_RIGHT;
        // else if(creep->cornerTarget == 6 && creep->posX == CORNER_6X && creep->posY == CORNER_6Y)
        //     creep->direction = UP_RIGHT;
        // else if(creep->cornerTarget == 7 && creep->posX == CORNER_7X && creep->posY == CORNER_7Y)
        //     creep->direction = DOWN_RIGHT;
        // else if(creep->cornerTarget == 8 && creep->posX == CORNER_8X && creep->posY == CORNER_8Y)
        //     creep->direction = DOWN_LEFT;


        // if(currentDirection != creep->direction && creep->cornerTarget < creepCheckpoints.size() - 1)
        // {
        //     creep->cornerTarget++;
        //     std::cout << "Corner target: " << creep->cornerTarget << std::endl;
        // }

        // transforms direction to string
        std::string directionString = "";
        switch(creep->direction)
        {
            case DOWN_LEFT:
                directionString = "DOWN_LEFT";
                break;
            case DOWN_RIGHT:
                directionString = "DOWN_RIGHT";
                break;
            case UP_LEFT:
                directionString = "UP_LEFT";
                break;
            case UP_RIGHT:
                directionString = "UP_RIGHT";
                break;
        }

        // std::cout << "Corner target: " << creep->cornerTarget << " Direction: " << directionString << " posX: " << creep->posX << " posY: " << creep->posY << std::endl;


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

        creep->walkingTimer++;
        if(creep->walkingTimer > 60)
            creep->walkingTimer = 0;
    }
}