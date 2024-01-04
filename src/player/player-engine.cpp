#include "player-engine.h"

void PlayerEngine::manageGameOver(Player* player)
{
    if(player->health <= 0)
    {
        player->isAlive = false;
    }
}