#ifndef TOWER_H
#define TOWER_H

#include "../tower-status.enum.h"
#include "../tower-type.enum.h"

struct TowerSettings
{
    TowerType::TowerType type;
    int mineralCost;
    int gasCost;
    double damage;
    double range;
    double attackSpeed;
};

class Tower
{
  public:
    Tower(int posX, int posY, TowerSettings* towerSettings);
    TowerType::TowerType type;
    TowerStatus status;
    int posX;
    int posY;
    bool isActive;
    bool isAttacking;
    double range;
    double damage;
    double attackSpeed;
    double attackDuration;
    double cooldownTimer;
};

#endif // TOWER_H