#include "tower-loader.h"

void TowerLoader::loadSprites()
{
    spritesheets[TowerType::Bunker] = new TowerSpritesheet();
    spritesheets[TowerType::Bunker]->baseSprite = al_load_bitmap("../assets/towers/bunker/base.tga");
    if(!spritesheets[TowerType::Bunker]->baseSprite)
        std::cout << "Error loading base sprite" << std::endl;

    spritesheets[TowerType::Bunker]->attackingSprites[0] = al_load_bitmap("../assets/towers/bunker/attacking-1.tga");
    spritesheets[TowerType::Bunker]->attackingSprites[1] = al_load_bitmap("../assets/towers/bunker/attacking-2.tga");
    spritesheets[TowerType::Bunker]->attackingSprites[2] = al_load_bitmap("../assets/towers/bunker/attacking-3.tga");
    spritesheets[TowerType::Bunker]->attackingSprites[3] = al_load_bitmap("../assets/towers/bunker/attacking-4.tga");
    spritesheets[TowerType::Bunker]->attackingSprites[4] = al_load_bitmap("../assets/towers/bunker/attacking-5.tga");

    for (int i = 0; i < 5; i++)
    {
        if (!spritesheets[TowerType::Bunker]->attackingSprites[i])
            std::cout << "Error loading attacking sprite " << i << std::endl;
    }
}