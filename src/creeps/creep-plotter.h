#include "creep-loader.h"
#include "creep.h"
#include <list>
#include <math.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>


class CreepPlotter
{
    public:
        CreepPlotter(ALLEGRO_FONT* font, CreepLoader* creepLoader, std::list<Creep*>* creeps, std::vector<std::pair<int, int>>* creepCheckpoints);
        void plot();

    private:
        ALLEGRO_FONT* font;
        std::list<Creep*>* creeps;
        std::vector<std::pair<int, int>>* creepCheckpoints;
        CreepLoader* creepLoader;
        int interpolateFrameToSprite(int currentFrame, int frameCount, int spriteCount);
        double interpolateHealthToBar(int health, int maxHealth, int numberOfBars);
        void drawHealthBar(Creep* creep, CreepSpritesheet* spritesheet);
};