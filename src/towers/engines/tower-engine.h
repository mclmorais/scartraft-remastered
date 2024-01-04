#ifndef TOWER_ENGINE_H
#define TOWER_ENGINE_H

#include "../tower-type.enum.h"
#include "../entities/tower.h"
#include "../../player-economy.h"
#include "../../creeps/creep.h"
#include <vector>
#include <map>
#include <list>
#include <iostream>
#include "math.h"

class TowerSlot
{
    public:
        TowerSlot(int posX, int posY);
        bool isOccupied;
        Tower* tower;
        int posY;
        int posX;
};

class TowerEngine
{
    public:
        TowerEngine(std::list<Creep*>* creeps);
        ~TowerEngine();
        TowerType::TowerType currentSelection;
        bool placeTower(int posX, int posY, PlayerEconomy* playerEconomy);
        void attack();
        void coolDown();
        std::vector<TowerSlot*> towerSlots;

    private:
        std::list<Creep*>* creeps;
        static const int numberOfTowerLocations = 16;
        std::map<TowerType::TowerType, TowerSettings> towerSettings;

        int selectLocation(int posX, int posY);
        bool hasResourcesForPlacement(PlayerEconomy* playerEconomy);
};

#endif // TOWER_ENGINE_H