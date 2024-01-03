#include "tower-engine.h"

TowerEngine::TowerEngine(std::list<Creep*>* creeps)
{
    currentSelection = TowerType::None;

    towerSettings[TowerType::Bunker] = {TowerType::Bunker, 50, 0, 20, 100, 1};
    towerSettings[TowerType::Turret] = {TowerType::Turret, 80, 0, 40, 150, 0.8};
    towerSettings[TowerType::SiegeTank] = {TowerType::SiegeTank, 120, 60, 400, 120, 0.4};

    towerSlots.push_back(new TowerSlot(75, 125));
    towerSlots.push_back(new TowerSlot(75, 325));
    towerSlots.push_back(new TowerSlot(175, 225));
    towerSlots.push_back(new TowerSlot(175, 375));
    towerSlots.push_back(new TowerSlot(225, 525));
    towerSlots.push_back(new TowerSlot(275, 125));
    towerSlots.push_back(new TowerSlot(275, 275));
    towerSlots.push_back(new TowerSlot(275, 425));
    towerSlots.push_back(new TowerSlot(375, 175));
    towerSlots.push_back(new TowerSlot(375, 325));
    towerSlots.push_back(new TowerSlot(375, 575));
    towerSlots.push_back(new TowerSlot(425, 425));
    towerSlots.push_back(new TowerSlot(475, 525));
    towerSlots.push_back(new TowerSlot(525, 275));
    towerSlots.push_back(new TowerSlot(625, 325));
    towerSlots.push_back(new TowerSlot(625, 475));

    this->creeps = creeps;
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
    for(auto towerSlot: towerSlots)
    {
        if(!towerSlot->isOccupied)
            continue;

        Tower* tower = towerSlot->tower;

        if(tower->status != READY)
            continue;

        for(auto creep: *creeps)
        {
            if(creep->health <= 0)
                continue;

            double distX = tower->posX - creep->posX;
            double distY = tower->posY - creep->posY;
            double distance = sqrt(pow(distX, 2) + pow(distY, 2));

            if(tower->range >= distance)
            {
                std::cout << "Tower " << tower->type << " is attacking creep " << creep->type << std::endl;
                creep->health -= tower->damage;
                tower->status = COOLING_DOWN;
                break;
            }

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
        if(posX >= towerSlots.at(i)->posX - 25 && posX <= towerSlots.at(i)->posX + 25)
        {
            if(posY >= towerSlots.at(i)->posY - 25 && posY <= towerSlots.at(i)->posY + 25)
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