#include "creep-plotter.h"

CreepPlotter::CreepPlotter(CreepLoader* creepLoader, std::list<Creep*>* creeps, std::vector<std::pair<int, int>>* creepCheckpoints)
{
    this->creeps = creeps;
    this->creepLoader = creepLoader;
    this->creepCheckpoints = creepCheckpoints;
}

void CreepPlotter::plot()
{

    for(auto checkpoint : *this->creepCheckpoints)
    {
        al_draw_circle(checkpoint.first, checkpoint.second, 5, al_map_rgb(0, 200, 200), 2);
    }

   for(std::list<Creep*>::iterator it = this->creeps->begin(); it != this->creeps->end(); ++it)
   {
        Creep* creep = *it;
        al_draw_circle(creep->posX, creep->posY, 5, al_map_rgb(200, 0, 200), 2);
        al_draw_line(
            creep->posX, 
            creep->posY,
            creepCheckpoints->at(creep->cornerTarget).first, 
            creepCheckpoints->at(creep->cornerTarget).second,
            al_map_rgb(200, 0, 200),
            2
        );
       CreepSpritesheet* spritesheet = this->creepLoader->spritesheets[creep->type];
       
        auto frame = interpolateFrameToSprite(creep->walkingTimer, spritesheet->walkingFramesCount, spritesheet->walkingSpritesCount);
        // std::cout << "frame: " << frame << std::endl;
        ALLEGRO_BITMAP* sprite = nullptr;
        switch(creep->direction)
        {
            case DOWN_LEFT:
                sprite = spritesheet->walkingSpritesFrontLeft[frame];
                break;
            case DOWN_RIGHT:
                sprite = spritesheet->walkingSpritesFrontRight[frame];
                break;
            case UP_LEFT:
                sprite = spritesheet->walkingSpritesBackLeft[frame];
                break;
            case UP_RIGHT:
                sprite = spritesheet->walkingSpritesBackRight[frame];
                break;
        }

        if(sprite != nullptr)
            al_draw_bitmap(sprite, creep->posX - spritesheet->spriteOffsetX, creep->posY - spritesheet->spriteOffsetY, 0);
   }


}

int CreepPlotter::interpolateFrameToSprite(int currentFrame, int frameCount, int spriteCount)
{
    int selectedSprite = round((currentFrame % frameCount)* (spriteCount - 1) / (double)frameCount);

    // std::cout << "currentFrame: " << currentFrame << " frameCount: " << frameCount << " spriteCount: " << spriteCount << " selectedSprite: " << selectedSprite << std::endl;

    return selectedSprite;
}