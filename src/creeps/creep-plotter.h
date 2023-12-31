#include "../constants.h"
#include "creep-loader.h"
#include "creep.h"
#include <algorithm>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <list>
#include <math.h>

class CreepPlotter
{
  public:
    CreepPlotter(ALLEGRO_FONT* font, CreepLoader* creepLoader, std::list<Creep*>* creeps,
                 std::vector<std::pair<int, int>>* creepCheckpoints);
    void plot(bool debug);

  private:
    ALLEGRO_FONT* font;
    std::list<Creep*>* creeps;
    std::vector<std::pair<int, int>>* creepCheckpoints;
    CreepLoader* creepLoader;
    int interpolateFrameToSprite(int currentFrame, int frameCount, int spriteCount);
    void drawHealthBar(Creep* creep, CreepSpritesheet* spritesheet);
};
