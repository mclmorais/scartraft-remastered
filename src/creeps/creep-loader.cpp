#include "creep-loader.h"

void CreepLoader::loadSprites()
{
    auto emptyBar = al_load_bitmap("../assets/bars/default-bar-empty.png");
    auto fullBar = al_load_bitmap("../assets/bars/default-bar-full.png");

    spritesheets[CreepType::MARINE] = new CreepSpritesheet();
    spritesheets[CreepType::MARINE]->spriteOffsetX = 53;
    spritesheets[CreepType::MARINE]->spriteOffsetY = 59;
    spritesheets[CreepType::MARINE]->walkingSpritesCount = 10;
    spritesheets[CreepType::MARINE]->numberOfBars = 4;
    spritesheets[CreepType::MARINE]->innerSpriteHeight = 25;

    spritesheets[CreepType::MARINE]->bars.first = emptyBar;
    spritesheets[CreepType::MARINE]->bars.second = fullBar;



    for(int i = 0; i < spritesheets[CreepType::MARINE]->walkingSpritesCount; i++)
    {
        
        for(auto direction : directions)
        {
            std::string filename = "../assets/creeps/marine/" + direction.second + "/marine-" + direction.second + "-" + std::to_string(i + 1) + ".tga";
            spritesheets[CreepType::MARINE]->walkingSprites[direction.first].push_back(al_load_bitmap(filename.c_str()));

            if(!spritesheets[CreepType::MARINE]->walkingSprites[direction.first][i])
                std::cout << "Error loading marine walking sprite " << direction.second << " " << i << std::endl;
        }
    }

    spritesheets[CreepType::COLOSSUS] = new CreepSpritesheet();
    spritesheets[CreepType::COLOSSUS]->spriteOffsetX = 60;
    spritesheets[CreepType::COLOSSUS]->spriteOffsetY = 70;
    spritesheets[CreepType::COLOSSUS]->walkingSpritesCount = 15;
    spritesheets[CreepType::COLOSSUS]->numberOfBars = 20;
    spritesheets[CreepType::COLOSSUS]->innerSpriteHeight = 75;
    
    spritesheets[CreepType::COLOSSUS]->bars.first = emptyBar;
    spritesheets[CreepType::COLOSSUS]->bars.second = fullBar;

    for(int i = 0; i < spritesheets[CreepType::COLOSSUS]->walkingSpritesCount; i++)
    {
        for(auto direction : directions)
        {
            std::string filename = "../assets/creeps/colossus/" + direction.second + "/colossus-" + direction.second + "-" + std::to_string(i + 1) + ".tga";
            spritesheets[CreepType::COLOSSUS]->walkingSprites[direction.first].push_back(al_load_bitmap(filename.c_str()));

            if(!spritesheets[CreepType::COLOSSUS]->walkingSprites[direction.first][i])
                std::cout << "Error loading colossus walking sprite " << direction.second << " " << i << std::endl;
        }
    }

    spritesheets[CreepType::HYDRALISK] = new CreepSpritesheet();
    spritesheets[CreepType::HYDRALISK]->spriteOffsetX = 65;
    spritesheets[CreepType::HYDRALISK]->spriteOffsetY = 70;
    spritesheets[CreepType::HYDRALISK]->walkingSpritesCount = 17;
    spritesheets[CreepType::HYDRALISK]->numberOfBars = 10;
    spritesheets[CreepType::HYDRALISK]->innerSpriteHeight = 60;

    spritesheets[CreepType::HYDRALISK]->bars.first = emptyBar;
    spritesheets[CreepType::HYDRALISK]->bars.second = fullBar;

    for(int i = 0; i < spritesheets[CreepType::HYDRALISK]->walkingSpritesCount; i++)
    {
        for(auto direction : directions)
        {
            std::string filename = "../assets/creeps/hydralisk/" + direction.second + "/hydralisk-" + direction.second + "-" + std::to_string(i + 1) + ".tga";
            spritesheets[CreepType::HYDRALISK]->walkingSprites[direction.first].push_back(al_load_bitmap(filename.c_str()));

            if(!spritesheets[CreepType::HYDRALISK]->walkingSprites[direction.first][i])
                std::cout << "Error loading hydra walking sprite " << direction.second << " " << i << std::endl;
        }
    }

    spritesheets[CreepType::THOR] = new CreepSpritesheet();
    spritesheets[CreepType::THOR]->spriteOffsetX = 63;
    spritesheets[CreepType::THOR]->spriteOffsetY = 63;
    spritesheets[CreepType::THOR]->walkingSpritesCount = 15;
    spritesheets[CreepType::THOR]->numberOfBars = 15;
    spritesheets[CreepType::THOR]->innerSpriteHeight = 55;


    spritesheets[CreepType::THOR]->bars.first = emptyBar;
    spritesheets[CreepType::THOR]->bars.second = fullBar;

    for(int i = 0; i < spritesheets[CreepType::THOR]->walkingSpritesCount; i++)
    {
        for(auto direction : directions)
        {
            std::string filename = "../assets/creeps/thor/" + direction.second + "/thor-" + direction.second + "-" + std::to_string(i + 1) + ".tga";
            spritesheets[CreepType::THOR]->walkingSprites[direction.first].push_back(al_load_bitmap(filename.c_str()));

            if(!spritesheets[CreepType::THOR]->walkingSprites[direction.first][i])
                std::cout << "Error loading thor walking sprite " << direction.second << " " << i << std::endl;
        }
    }

    spritesheets[CreepType::VOID_RAY] = new CreepSpritesheet();
    spritesheets[CreepType::VOID_RAY]->spriteOffsetX = 70;
    spritesheets[CreepType::VOID_RAY]->spriteOffsetY = 75;
    spritesheets[CreepType::VOID_RAY]->walkingSpritesCount = 27;
    spritesheets[CreepType::VOID_RAY]->numberOfBars = 15;
    spritesheets[CreepType::VOID_RAY]->innerSpriteHeight = 110;

    spritesheets[CreepType::VOID_RAY]->bars.first = emptyBar;
    spritesheets[CreepType::VOID_RAY]->bars.second = fullBar;

    for(int i = 0; i < spritesheets[CreepType::VOID_RAY]->walkingSpritesCount; i++)
    {
        for(auto direction : directions)
        {
            // TODO: tirar espaço
            std::string filename = "../assets/creeps/void-ray/" + direction.second + "/void ray-" + direction.second + "-" + std::to_string(i + 1) + ".tga";
            spritesheets[CreepType::VOID_RAY]->walkingSprites[direction.first].push_back(al_load_bitmap(filename.c_str()));

            if(!spritesheets[CreepType::VOID_RAY]->walkingSprites[direction.first][i])
                std::cout << "Error loading void ray walking sprite " << direction.second << " " << i << std::endl;
        }
    }





}