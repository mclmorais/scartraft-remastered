#include "creep-plotter.h"

CreepPlotter::CreepPlotter(ALLEGRO_FONT* font, CreepLoader* creepLoader, std::list<Creep*>* creeps, std::vector<std::pair<int, int>>* creepCheckpoints)
{
    this->creeps = creeps;
    this->creepLoader = creepLoader;
    this->creepCheckpoints = creepCheckpoints;
    this->font = font;
}

void CreepPlotter::plot(bool debug)
{

    if(debug)
    {
        for(int i = 0; i < creepCheckpoints->size() - 1; i++)
        {
            if(i < creepCheckpoints->size() - 1)
                al_draw_line(
                    creepCheckpoints->at(i).first, 
                    creepCheckpoints->at(i).second, 
                    creepCheckpoints->at(i + 1).first, 
                    creepCheckpoints->at(i + 1).second, 
                    al_map_rgb(0, 200, 200), 
                    2
                );
            al_draw_circle(creepCheckpoints->at(i).first, creepCheckpoints->at(i).second, 2, al_map_rgb(0, 200, 200), 2);
        }
    }


    for(std::list<Creep*>::iterator it = this->creeps->begin(); it != this->creeps->end(); ++it)
    {
        Creep* creep = *it;

       CreepSpritesheet* spritesheet = this->creepLoader->spritesheets[creep->type];
       
        auto frame = interpolateFrameToSprite(creep->walkingTimer, creep->totalWalkingTimer, spritesheet->walkingSprites[creep->direction].size());
        
        ALLEGRO_BITMAP* sprite = spritesheet->walkingSprites[creep->direction][frame];

        if(sprite != nullptr)
        {
            al_draw_bitmap(sprite, creep->posX - spritesheet->spriteOffsetX, creep->posY - spritesheet->spriteOffsetY, 0);

            if(debug)
            {
                // draw frame number as "FX/Y"
                al_draw_text(this->font, al_map_rgb(255, 255, 255), creep->posX, creep->posY + 20, ALLEGRO_ALIGN_CENTER, (std::to_string(frame) + "/" + std::to_string(spritesheet->walkingSpritesCount)).c_str());
                al_draw_rectangle(
                    creep->posX - al_get_bitmap_width(sprite) / 2.0,
                    creep->posY - al_get_bitmap_height(sprite) / 2.0,
                    creep->posX + al_get_bitmap_width(sprite) / 2.0,
                    creep->posY + al_get_bitmap_height(sprite) / 2.0,
                    al_map_rgb(255, 0, 0),
                    1 
                );
                al_draw_line(
                    creep->posX,
                    creep->posY - al_get_bitmap_height(sprite) / 2.0,
                    creep->posX,
                    creep->posY + al_get_bitmap_height(sprite) / 2.0,
                    al_map_rgb(255, 255, 0),
                    1
                );

                al_draw_line(
                    creep->posX - al_get_bitmap_width(sprite) / 2.0,
                    creep->posY,
                    creep->posX + al_get_bitmap_width(sprite) / 2.0,
                    creep->posY,
                    al_map_rgb(255, 255, 0),
                    1
                );
            }

            if(debug)
            {
                al_draw_circle(creep->posX, creep->posY, 2, al_map_rgb(200, 0, 200), 2);
                al_draw_line(
                    creep->posX, 
                    creep->posY,
                    creepCheckpoints->at(creep->cornerTarget).first, 
                    creepCheckpoints->at(creep->cornerTarget).second,
                    al_map_rgba(200, 0, 200, 127),
                    1
                );
            }
        }



    }

    for(std::list<Creep*>::iterator it = this->creeps->begin(); it != this->creeps->end(); ++it)
        drawHealthBar(*it, this->creepLoader->spritesheets[(*it)->type]);
}

int CreepPlotter::interpolateFrameToSprite(int currentFrame, int frameCount, int spriteCount)
{
    int selectedSprite = round((currentFrame % frameCount)* (spriteCount - 1) / (double)frameCount);

    // std::cout << "currentFrame: " << currentFrame << " frameCount: " << frameCount << " spriteCount: " << spriteCount << " selectedSprite: " << selectedSprite << std::endl;

    return selectedSprite;
}

void CreepPlotter::drawHealthBar(Creep* creep, CreepSpritesheet* spritesheet)
{
    auto interpolatedValue = creep->health * spritesheet->numberOfBars / (double)creep->maxHealth;

    auto barSize = spritesheet->numberOfBars * (al_get_bitmap_width(spritesheet->bars.first) - 2);
    auto barOffset = barSize / 2.0;

    // std::cout << "health: " << creep->health << " maxHealth: " << creep->maxHealth << " numberOfBars: " << spritesheet->numberOfBars << std::endl;
    // std::cout << "interpolatedValue: " << interpolatedValue << std::endl;

    for(int i = 0; i < spritesheet->numberOfBars; i++) {
        auto alpha = std::min(1.0, (interpolatedValue - i));

        // std::cout << "bar " << i << " alpha: " << alpha << std::endl;

        if(alpha < 1)
        al_draw_bitmap(spritesheet->bars.first, creep->posX - barOffset + (4 * i), creep->posY - spritesheet->innerSpriteHeight, 0);

        if(alpha > 0)
            al_draw_tinted_bitmap(spritesheet->bars.second, al_map_rgba_f(alpha, alpha, alpha, alpha), creep->posX - barOffset + 4 * i, creep->posY - spritesheet->innerSpriteHeight, 0);
    }
    
            al_draw_text(this->font, al_map_rgb(255, 255, 255), creep->posX - barOffset - 10, creep->posY - spritesheet->innerSpriteHeight - 2, ALLEGRO_ALIGN_CENTER, std::to_string((int)creep->health).c_str());
}
