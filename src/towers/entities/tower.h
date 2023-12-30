#ifndef TOWER_H
#define TOWER_H

#include "../tower-type.enum.h"

class Tower
{
    public:
        Tower (int posX, int posY);
        TowerType::TowerType type;
        int posX;
        int posY;
        bool isActive;
        bool isAttacking;
};

struct TowerSettings {
    TowerType::TowerType type;
    int cost;
};

#endif // TOWER_H