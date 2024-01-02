#ifndef TOWER_ENGINE_H
#define TOWER_ENGINE_H

#include "../tower-type.enum.h"
#include "../entities/tower.h"
#include "../../player-economy.h"
#include <vector>
#include <map>
#include <iostream>

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
        TowerEngine();
        TowerType::TowerType currentSelection;
        bool placeTower(int posX, int posY, PlayerEconomy* playerEconomy);
        void attack();
        void coolDown();
        std::vector<TowerSlot*> towerSlots;

    private:
        static const int numberOfTowerLocations = 16;
        std::map<TowerType::TowerType, TowerSettings> towerSettings;

        int selectLocation(int posX, int posY);
        bool hasResourcesForPlacement(PlayerEconomy* playerEconomy);
};

#endif // TOWER_ENGINE_H