#include "plotter.h"

#define BUTTON_Y_SIZE 60
#define TOWER_BUTTON_X_START 715
#define TOWER_BUTTON_X_END TOWER_BUTTON_X_START + 60
#define BUNKER_BUTTON_Y_START 235
#define BUNKER_BUTTON_Y_END BUNKER_BUTTON_Y_START + BUTTON_Y_SIZE
#define TOWER_BUTTON_Y_START 295
#define TOWER_BUTTON_Y_END TOWER_BUTTON_Y_START + BUTTON_Y_SIZE
#define SIEGE_BUTTON_Y_START 365
#define SIEGE_BUTTON_Y_END SIEGE_BUTTON_Y_START + BUTTON_Y_SIZE

Plotter::Plotter(BitmapLoader* bitmapLoader)
{
    this->bitmapLoader = bitmapLoader;
}

void Plotter::createDisplay()
{
    auto icon256 = al_load_bitmap("../assets/icon/icon-256.png");
    auto icon128 = al_load_bitmap("../assets/icon/icon-128.png");
    auto icon64 = al_load_bitmap("../assets/icon/icon-64.png");
    auto icon48 = al_load_bitmap("../assets/icon/icon-48.png");
    auto icon32 = al_load_bitmap("../assets/icon/icon-32.png");

    ALLEGRO_BITMAP* icons[5] = {icon256, icon128, icon64, icon48, icon32};
    display = al_create_display(800, 600);
    al_set_window_title(display, "Scartraft 2");
    al_set_display_icons(display, 5, icons);
}

void Plotter::plotMainMenu(int variation)
{
    if (variation > 2)
        variation = 0;

    al_draw_bitmap(bitmapLoader->menuBackgrounds[variation], 0, 0, 0);
}

void Plotter::plotBackground()
{
    al_draw_bitmap(bitmapLoader->background, 0, 0, 0);
}

void Plotter::plotGameMenu(TowerType::TowerType selectedTower, PlayerEconomy* playerEconomy)
{
    al_draw_bitmap(bitmapLoader->gameMenu, 630, 0, 0);

    if (selectedTower != TowerType::None)
        al_draw_bitmap(bitmapLoader->beacons, 0, 0, 0);

    al_draw_bitmap(bitmapLoader->bunkerButton[selectedTower == TowerType::Bunker ? 1 : 0], 715, 235, 0);
    al_draw_bitmap(bitmapLoader->towerButton[selectedTower == TowerType::Turret ? 1 : 0], 715, 235 + 65, 0);
    al_draw_bitmap(bitmapLoader->siegeButton[selectedTower == TowerType::SiegeTank ? 1 : 0], 715, 235 + 130, 0);

    al_draw_bitmap(bitmapLoader->mineralIcon, 730, 175, 0);
    al_draw_bitmap(bitmapLoader->gasIcon, 730, 175 + 16, 0);

    al_draw_text(bitmapLoader->resourcesFont, al_map_rgb(255, 255, 255), 750, 175, 0, std::to_string(playerEconomy->minerals).c_str());
    al_draw_text(bitmapLoader->resourcesFont, al_map_rgb(255, 255, 255), 750, 175 + 16 + 2, 0, std::to_string(playerEconomy->gas).c_str());
}
