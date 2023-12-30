#include "tower-loader.h"

void TowerLoader::loadSprites()
{
    spritesheets[TowerType::Bunker] = new TowerSpritesheet();
    spritesheets[TowerType::Bunker]->spriteOffsetX = 0;
    spritesheets[TowerType::Bunker]->spriteOffsetY = 0;
    spritesheets[TowerType::Bunker]->baseSprite = al_load_bitmap("../assets/towers/bunker/base.tga");
    if(!spritesheets[TowerType::Bunker]->baseSprite)
        std::cout << "Error loading bunker base sprite" << std::endl;

    for (int i = 0; i < bunkerAttackingSpritesCount; i++)
    {
        std::string filename = "../assets/towers/bunker/attacking-" + std::to_string(i + 1) + ".tga";
        spritesheets[TowerType::Bunker]->attackingSprites[i] = al_load_bitmap(filename.c_str());

        if (!spritesheets[TowerType::Bunker]->attackingSprites[i])
            std::cout << "Error loading bunker attacking sprite " << i << std::endl;
    }

    spritesheets[TowerType::Turret] = new TowerSpritesheet();
    spritesheets[TowerType::Turret]->spriteOffsetX = 20;
    spritesheets[TowerType::Turret]->spriteOffsetY = 10;
    spritesheets[TowerType::Turret]->baseSprite = al_load_bitmap("../assets/towers/turret/base.tga");
    if(!spritesheets[TowerType::Turret]->baseSprite)
        std::cout << "Error loading turret base sprite" << std::endl;

    for (int i = 0; i < turretAttackingSpritesCount; i++)
    {
        std::string filename = "../assets/towers/turret/attacking-" + std::to_string(i + 1) + ".tga";
        spritesheets[TowerType::Turret]->attackingSprites[i] = al_load_bitmap(filename.c_str());

        if (!spritesheets[TowerType::Turret]->attackingSprites[i])
            std::cout << "Error loading turret attacking sprite " << i << std::endl;
    }

    spritesheets[TowerType::SiegeTank] = new TowerSpritesheet();
    spritesheets[TowerType::SiegeTank]->spriteOffsetX = -5;
    spritesheets[TowerType::SiegeTank]->spriteOffsetY = -5;
    spritesheets[TowerType::SiegeTank]->baseSprite = al_load_bitmap("../assets/towers/siege/base.tga");
    if(!spritesheets[TowerType::SiegeTank]->baseSprite)
        std::cout << "Error loading siege base sprite" << std::endl;

    for (int i = 0; i < siegeAttackingSpritesCount; i++)
    {
        std::string filename = "../assets/towers/siege/attacking-" + std::to_string(i + 1) + ".tga";
        spritesheets[TowerType::SiegeTank]->attackingSprites[i] = al_load_bitmap(filename.c_str());

        if (!spritesheets[TowerType::SiegeTank]->attackingSprites[i])
            std::cout << "Error loading siege attacking sprite " << i << std::endl;
    }
    

}