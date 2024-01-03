#include "creep-loader.h"

void CreepLoader::loadSprites()
{
    spritesheets[CreepType::MARINE] = new CreepSpritesheet();
    spritesheets[CreepType::MARINE]->spriteOffsetX = 55;
    spritesheets[CreepType::MARINE]->spriteOffsetY = 55;
    spritesheets[CreepType::MARINE]->walkingSpritesCount = 10;
    spritesheets[CreepType::MARINE]->walkingFramesCount = 30;

    spritesheets[CreepType::MARINE]->bars.first = al_load_bitmap("../assets/bars/default-bar-empty.png");
    spritesheets[CreepType::MARINE]->bars.second = al_load_bitmap("../assets/bars/default-bar-full.png");

    for(int i = 0; i < spritesheets[CreepType::MARINE]->walkingSpritesCount; i++)
    {
        std::string filename = "../assets/creeps/marine/walking-down-left-" + std::to_string(i + 1) + ".tga";
        spritesheets[CreepType::MARINE]->walkingSpritesFrontLeft.push_back(al_load_bitmap(filename.c_str()));

        filename = "../assets/creeps/marine/walking-down-right-" + std::to_string(i + 1) + ".tga";
        spritesheets[CreepType::MARINE]->walkingSpritesFrontRight.push_back(al_load_bitmap(filename.c_str()));

        filename = "../assets/creeps/marine/walking-up-left-" + std::to_string(i + 1) + ".tga";
        spritesheets[CreepType::MARINE]->walkingSpritesBackLeft.push_back(al_load_bitmap(filename.c_str()));

        filename = "../assets/creeps/marine/walking-up-right-" + std::to_string(i + 1) + ".tga";
        spritesheets[CreepType::MARINE]->walkingSpritesBackRight.push_back(al_load_bitmap(filename.c_str()));

        if(!spritesheets[CreepType::MARINE]->walkingSpritesFrontLeft[i])
            std::cout << "Error loading marine walking sprite front left " << i << std::endl;

        if(!spritesheets[CreepType::MARINE]->walkingSpritesFrontRight[i])
            std::cout << "Error loading marine walking sprite front right " << i << std::endl;

        if(!spritesheets[CreepType::MARINE]->walkingSpritesBackLeft[i])
            std::cout << "Error loading marine walking sprite back left " << i << std::endl;

        if(!spritesheets[CreepType::MARINE]->walkingSpritesBackRight[i])
            std::cout << "Error loading marine walking sprite back right " << i << std::endl;
    }
}