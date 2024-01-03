#include "creep-plotter.h"

CreepPlotter::CreepPlotter(ALLEGRO_FONT* font, CreepLoader* creepLoader, std::list<Creep*>* creeps, std::vector<std::pair<int, int>>* creepCheckpoints)
{
    this->creeps = creeps;
    this->creepLoader = creepLoader;
    this->creepCheckpoints = creepCheckpoints;
    this->font = font;
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

    auto barSize = spritesheet->numberOfBars * al_get_bitmap_width(spritesheet->bars.first);
    auto barOffset = barSize / 2;

    // std::cout << "health: " << creep->health << " maxHealth: " << creep->maxHealth << " numberOfBars: " << spritesheet->numberOfBars << std::endl;
    // std::cout << "interpolatedValue: " << interpolatedValue << std::endl;

    for(int i = 0; i < spritesheet->numberOfBars; i++) {
        auto alpha = std::min(1.0, (interpolatedValue - i));

        // std::cout << "bar " << i << " alpha: " << alpha << std::endl;

        if(alpha < 1)
        al_draw_bitmap(spritesheet->bars.first, creep->posX - barOffset + 4 * i, creep->posY - 25, 0);

        if(alpha > 0)
            al_draw_tinted_bitmap(spritesheet->bars.second, al_map_rgba_f(alpha, alpha, alpha, alpha), creep->posX - barOffset + 4 * i, creep->posY - 25, 0);
    }
    
            al_draw_text(this->font, al_map_rgb(255, 255, 255), creep->posX - barOffset - 10, creep->posY - 25 - 2, ALLEGRO_ALIGN_CENTER, std::to_string((int)creep->health).c_str());
}

double CreepPlotter::interpolateHealthToBar(int health, int maxHealth, int numberOfBars)
{
    return health * numberOfBars / (double)maxHealth;
}