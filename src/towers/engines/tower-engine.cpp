#include "tower-engine.h"

TowerEngine::TowerEngine()
{
    currentSelection = TowerType::None;

    towerSettings[TowerType::Bunker] = {TowerType::Bunker, 50};
    towerSettings[TowerType::Turret] = {TowerType::Turret, 80};
    towerSettings[TowerType::SiegeTank] = {TowerType::SiegeTank, 120};

    towerSlots.push_back(new TowerSlot(25, 75));
    towerSlots.push_back(new TowerSlot(25, 275));
    towerSlots.push_back(new TowerSlot(125, 175));
    towerSlots.push_back(new TowerSlot(125, 325));
    towerSlots.push_back(new TowerSlot(175, 475));
    towerSlots.push_back(new TowerSlot(225, 75));
    towerSlots.push_back(new TowerSlot(225, 225));
    towerSlots.push_back(new TowerSlot(225, 375));
    towerSlots.push_back(new TowerSlot(325, 125));
    towerSlots.push_back(new TowerSlot(325, 275));
    towerSlots.push_back(new TowerSlot(325, 525));
    towerSlots.push_back(new TowerSlot(375, 375));
    towerSlots.push_back(new TowerSlot(425, 475));
    towerSlots.push_back(new TowerSlot(475, 225));
    towerSlots.push_back(new TowerSlot(575, 275));
    towerSlots.push_back(new TowerSlot(575, 425));
}

bool TowerEngine::placeTower(int posX, int posY, PlayerEconomy* playerEconomy)
{
    if(currentSelection == TowerType::None)
        return false;

    int location = selectLocation(posX, posY);

    if(location == -1)
        return false;

    TowerSlot* slot = towerSlots.at(location);

    if(slot->isOccupied)
        return false;

    if(!hasResourcesForPlacement(playerEconomy))
        return false;
    
    slot->isOccupied = true;
    slot->tower = new Tower(slot->posX, slot->posY);
    slot->tower->type = currentSelection;

    playerEconomy->minerals -= towerSettings[currentSelection].cost;

    currentSelection = TowerType::None;

    std::cout << "Tower placed (pos. " << location << ") - " << playerEconomy->minerals << " minerals left" << std::endl;
    return true;
}

bool TowerEngine::hasResourcesForPlacement(PlayerEconomy* playerEconomy)
{
    return playerEconomy->minerals >= towerSettings[currentSelection].cost;
}

int TowerEngine::selectLocation(int posX, int posY)
{
    for(int i = 0; i < numberOfTowerLocations; i++)
    {
        if(posX >= towerSlots.at(i)->posX + 25 && posX <= towerSlots.at(i)->posX + 75)
        {
            if(posY >= towerSlots.at(i)->posY + 25 && posY <= towerSlots.at(i)->posY + 75)
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