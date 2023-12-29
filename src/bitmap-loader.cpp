#include <string>
#include <iostream>
#include "bitmap-loader.h"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
void BitmapLoader::loadMenuBackgrounds()
{
    for (int i = 0; i < 3; i++) {
        std::string filename = "../assets/interface/main-menu/main-menu-" + std::to_string(i) + ".tga";
        std::cout << filename << std::endl;
        menuBackgrounds[i] = al_load_bitmap(filename.c_str());
        if(menuBackgrounds[i] == NULL) {
            std::cout << "Failed to load menu background " << i << std::endl;
        }
    }

}

void BitmapLoader::loadBackground()
{
    background = al_load_bitmap("../assets/backgrounds/background-terran.tga");
    if(background == NULL) {
        std::cout << "Failed to load background" << std::endl;
        exit(6);
    }
}

void BitmapLoader::loadGameMenu()
{
    gameMenu = al_load_bitmap("../assets/interface/game-menu/game-menu-1.tga");
    if(gameMenu == NULL) {
        std::cout << "Failed to load game menu" << std::endl;
        exit(6);
    }

    bunkerButton[0] = al_load_bitmap("../assets/interface/game-menu/button-bunker.tga");
    bunkerButton[1] = al_load_bitmap("../assets/interface/game-menu/button-bunker-highlight.tga");
    towerButton[0] = al_load_bitmap("../assets/interface/game-menu/button-tower.tga");
    towerButton[1] = al_load_bitmap("../assets/interface/game-menu/button-tower-highlight.tga");
    siegeButton[0] = al_load_bitmap("../assets/interface/game-menu/button-siege.tga");
    siegeButton[1] = al_load_bitmap("../assets/interface/game-menu/button-siege-highlight.tga");


}
