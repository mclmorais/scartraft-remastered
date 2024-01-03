#include "creep-loader.h"
#include "creep.h"
#include <list>
#include <math.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>


class CreepPlotter
{
    public:
        CreepPlotter(CreepLoader* creepLoader, std::list<Creep*>* creeps, std::vector<std::pair<int, int>>* creepCheckpoints);
        void plot();

    private:
        std::list<Creep*>* creeps;
        std::vector<std::pair<int, int>>* creepCheckpoints;
        CreepLoader* creepLoader;
        int interpolateFrameToSprite(int currentFrame, int frameCount, int spriteCount);
};