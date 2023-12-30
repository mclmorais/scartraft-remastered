#include "tower-engine.h"

TowerEngine::TowerEngine()
{
    currentSelection = TowerType::None;

    towerSettings[TowerType::Bunker] = {TowerType::Bunker, 50};
    towerSettings[TowerType::Turret] = {TowerType::Turret, 80};

    towerSlots.push_back(TowerSlot(50, 100));
    towerSlots.push_back(TowerSlot(50, 300));
    towerSlots.push_back(TowerSlot(150, 200));
    towerSlots.push_back(TowerSlot(150, 350));
    towerSlots.push_back(TowerSlot(200, 500));
    towerSlots.push_back(TowerSlot(250, 100));
    towerSlots.push_back(TowerSlot(250, 250));
    towerSlots.push_back(TowerSlot(250, 400));
    towerSlots.push_back(TowerSlot(350, 150));
    towerSlots.push_back(TowerSlot(350, 300));
    towerSlots.push_back(TowerSlot(350, 550));
    towerSlots.push_back(TowerSlot(400, 400));
    towerSlots.push_back(TowerSlot(450, 500));
    towerSlots.push_back(TowerSlot(500, 250));
    towerSlots.push_back(TowerSlot(600, 300));
    towerSlots.push_back(TowerSlot(600, 450));
}


bool TowerEngine::placeTower(int posX, int posY, PlayerEconomy* playerEconomy)
{
    if(currentSelection == TowerType::None)
        return false;

    int location = selectLocation(posX, posY);

    if(location == -1)
        return false;

    if(towerSlots.at(location).isOccupied)
        return false;

    if(!hasResourcesForPlacement(playerEconomy))
        return false;
    
    towerSlots.at(location).isOccupied = true;
    towerSlots.at(location).tower = new Tower(posX, posY);
    playerEconomy->minerals -= towerSettings[currentSelection].cost;
    return true;
}

bool TowerEngine::hasResourcesForPlacement(PlayerEconomy* playerEconomy)
{
    switch(currentSelection) {
        case TowerType::None:
            return false;
        case TowerType::Bunker:
            return playerEconomy->minerals >= towerSettings[currentSelection].cost;
    }
}

int TowerEngine::selectLocation(int posX, int posY)
{
    for(int i = 0; i < numberOfTowerLocations; i++)
    {
        if(posX >= towerSlots.at(i).posX && posX <= towerSlots.at(i).posX + 50)
        {
            if(posY >= towerSlots.at(i).posY && posY <= towerSlots.at(i).posY + 50)
            {
                return i;
            }
        }
    }
    return -1;
}

TowerSlot::TowerSlot(int posX, int posY)
{
    isOccupied = false;
    tower = nullptr;
    this->posX = posX;
    this->posY = posY;
}