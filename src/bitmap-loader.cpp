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
