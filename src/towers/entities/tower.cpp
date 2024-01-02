#include "tower.h"

Tower::Tower (int posX, int posY, TowerSettings* towerSettings)
{
    isActive = true;
    isAttacking = false;
    this->posX = posX;
    this->posY = posY;
    attackSpeed = towerSettings->attackSpeed;
    attackDuration = 60.0 / towerSettings->attackSpeed; // TODO: transformar em define
    range = towerSettings->range;
    cooldownTimer = 0;
    // TODO: fazer plotar animação de ataque baseado em attack duration, mapeando frame 1-N em timer 0-duration
}

