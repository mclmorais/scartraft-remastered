#include "tower-engine.h"

TowerEngine::TowerEngine()
{
    currentSelection = TowerType::None;

    towerSettings[TowerType::Bunker] = {TowerType::Bunker, 50, 0, 20, 100, 1};
    towerSettings[TowerType::Turret] = {TowerType::Turret, 80, 0, 40, 150, 0.8};
    towerSettings[TowerType::SiegeTank] = {TowerType::SiegeTank, 120, 60, 400, 120, 0.4};

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
    slot->tower = new Tower(slot->posX, slot->posY, &towerSettings[currentSelection]);
    slot->tower->type = currentSelection;
    slot->tower->status = READY;

    playerEconomy->minerals -= towerSettings[currentSelection].mineralCost;

    currentSelection = TowerType::None;

    std::cout << "Tower placed (pos. " << location << ") - " << playerEconomy->minerals << " minerals left" << std::endl;
    return true;
}

void TowerEngine::attack()
{
    for(int i = 0; i < towerSlots.size(); i++)
    {
        TowerSlot* slot = towerSlots.at(i);
        if(!slot->isOccupied)
            continue;

        Tower* tower = slot->tower;
        if(tower->status == READY)
        {
            std::cout << "Tower " << i << " is attacking" << std::endl;
            // TODO: reduz vida do creep aqui
            tower->status = COOLING_DOWN;
        }
    }
}

void TowerEngine::coolDown()
{
    for(int i = 0; i < towerSlots.size(); i++)
    {
        TowerSlot* slot = towerSlots.at(i);
        if(!slot->isOccupied)
            continue;

        Tower* tower = slot->tower;
        if(tower->status == COOLING_DOWN)
        {
            tower->cooldownTimer++;
            // std::cout << "Tower " << i << " is cooling down (" << tower->cooldownTimer << "/" << tower->attackDuration << ")" << std::endl; 

            if(tower->cooldownTimer >= tower->attackDuration)
            {
                // std::cout << "Tower " << i << " is ready" << std::endl;
                tower->cooldownTimer = 0;
                tower->status = READY;
            }
        }
    }
}

bool TowerEngine::hasResourcesForPlacement(PlayerEconomy* playerEconomy)
{
    return playerEconomy->minerals >= towerSettings[currentSelection].mineralCost;
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