#include "bitmap-loader.h"
#include "creeps/creep-engine.h"
#include "creeps/creep-loader.h"
#include "creeps/creep-plotter.h"
#include "player/player-engine.h"
#include "player/player.h"
#include "plotter.h"
#include "towers/engines/tower-engine.h"
#include "towers/entities/tower-loader.h"
#include "towers/entities/tower-plotter.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <math.h>
#include <stdbool.h>

#define REFRESH_RATE 60
#define LEFTBUTTON 1

#define BUTTON_Y_SIZE 60
#define TOWER_BUTTON_X_START 715
#define TOWER_BUTTON_X_END TOWER_BUTTON_X_START + 60
#define BUNKER_BUTTON_Y_START 235
#define BUNKER_BUTTON_Y_END BUNKER_BUTTON_Y_START + BUTTON_Y_SIZE
#define TOWER_BUTTON_Y_START 295
#define TOWER_BUTTON_Y_END TOWER_BUTTON_Y_START + BUTTON_Y_SIZE
#define SIEGE_BUTTON_Y_START 365
#define SIEGE_BUTTON_Y_END SIEGE_BUTTON_Y_START + BUTTON_Y_SIZE
// TODO: retirar defines duplicados

void mainMenu(Plotter* plotter);
void game(Plotter* plotter);
void setSelection(ALLEGRO_MOUSE_STATE mouseState, TowerEngine* towerEngine);

int main()
{
    al_init();
    al_install_mouse();
    al_install_keyboard();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(10);
    al_init_primitives_addon();

    BitmapLoader* bitmapLoader = new BitmapLoader();
    bitmapLoader->loadMenuBackgrounds();
    bitmapLoader->loadBackground(); // TODO: mudar para quando o jogo de fato iniciar
    bitmapLoader->loadGameMenu();

    Plotter* plotter = new Plotter(bitmapLoader);

    plotter->createDisplay();

    mainMenu(plotter);
}

void mainMenu(Plotter* plotter)
{

    srand(time(NULL));

    int flag = 0;

    ALLEGRO_MOUSE_STATE mousestate;

    double fixedDownTime = 1.0f / REFRESH_RATE;
    double oldTime = al_current_time();
    double gameTime = al_current_time();
    while (true)
    {
        double downTime = al_current_time() - oldTime;
        al_rest(fixedDownTime - downTime);
        downTime = al_current_time() - oldTime;
        oldTime = al_current_time();

        if (oldTime - gameTime > downTime)
        {
            downTime += fixedDownTime * floor((oldTime - gameTime) / fixedDownTime);
        }

        double start_time = al_current_time();
        while (oldTime - gameTime >= 0)
        {
            gameTime += fixedDownTime;
            al_get_mouse_state(&mousestate);

            if (mousestate.buttons == LEFTBUTTON)
            {
                if (mousestate.x >= 554 && mousestate.x <= 743 && mousestate.y >= 332 && mousestate.y <= 393)
                {
                    game(plotter);
                }

                if (mousestate.x >= 590 && mousestate.x <= 730 && mousestate.y >= 470 && mousestate.y <= 510)
                {
                    exit(0);
                }
            }
            else if (mousestate.buttons == 0)
            {
                if (mousestate.x >= 554 && mousestate.x <= 743 && mousestate.y >= 332 && mousestate.y <= 393)
                    flag = 1;

                else if (mousestate.x >= 590 && mousestate.x <= 730 && mousestate.y >= 470 && mousestate.y <= 510)
                    flag = 2;
                else
                    flag = 0;
            }

            if (al_current_time() - start_time > fixedDownTime)
                break;

            plotter->plotMainMenu(flag);
            al_wait_for_vsync();
            al_flip_display();
        }
    }
}

void game(Plotter* plotter)
{

    auto mainFont = al_load_font("../assets/fonts/prototype.ttf", 18, 0);
    auto healthFont = al_load_font("../assets/fonts/prototype.ttf", 10, 0);

    std::cout << "Player init:";
    Player* player = new Player();
    std::cout << " ok" << std::endl;

    std::cout << "PlayerEngine init:";
    PlayerEngine* playerEngine = new PlayerEngine();
    std::cout << " ok" << std::endl;

    std::cout << "TowerLoader init:";
    TowerLoader* towerLoader = new TowerLoader();
    towerLoader->loadSprites();
    std::cout << " ok" << std::endl;

    std::cout << "PlayerEconomy init:";
    PlayerEconomy* playerEconomy = new PlayerEconomy();
    playerEconomy->gas = 500;
    playerEconomy->minerals = 500;
    std::cout << " ok" << std::endl;

    std::cout << "CreepEngine init:";
    CreepEngine* creepEngine = new CreepEngine();
    creepEngine->planCreeps();
    creepEngine->planWaves();
    creepEngine->planCheckpoints();
    creepEngine->startWaveTimer();
    std::cout << " ok" << std::endl;

    std::cout << "CreepLoader init:";
    CreepLoader* creepLoader = new CreepLoader();
    creepLoader->loadSprites();
    std::cout << " ok" << std::endl;

    std::cout << "CreepPlotter init:";
    CreepPlotter* creepPlotter = new CreepPlotter(healthFont, creepLoader, &creepEngine->creeps, &creepEngine->creepCheckpoints);
    std::cout << " ok" << std::endl;

    std::cout << "TowerEngine init:";
    TowerEngine* towerEngine = new TowerEngine(&creepEngine->creeps);
    std::cout << " ok" << std::endl;

    std::cout << "TowerPlotter init:";
    TowerPlotter* towerPlotter = new TowerPlotter(towerLoader, &towerEngine->towerSlots);
    std::cout << " ok" << std::endl;

    ALLEGRO_MOUSE_STATE mouseState;
    ALLEGRO_KEYBOARD_STATE keyboardState;
    double fixedDownTime = 1.0f / REFRESH_RATE;
    double oldTime = al_current_time();
    double gameTime = al_current_time();

    bool debug = false;

    while (true)
    {
        double downTime = al_current_time() - oldTime;
        al_rest(fixedDownTime - downTime);
        downTime = al_current_time() - oldTime;
        oldTime = al_current_time();

        if (oldTime - gameTime > downTime)
        {
            downTime += fixedDownTime * floor((oldTime - gameTime) / fixedDownTime);
        }

        double start_time = al_current_time();
        while (oldTime - gameTime >= 0)
        {
            al_get_keyboard_state(&keyboardState);

            // toggle debug if key D is pressed
            if (al_key_down(&keyboardState, ALLEGRO_KEY_D))
            {
                if (!debug)
                {
                    debug = true;
                    std::cout << "Debug mode on" << std::endl;
                }
            }
            else
            {
                if (debug)
                {
                    debug = false;
                    std::cout << "Debug mode off" << std::endl;
                }
            }

            gameTime += fixedDownTime;
            al_get_mouse_state(&mouseState);

            setSelection(mouseState, towerEngine);
            towerEngine->attack();
            towerEngine->coolDown();

            creepEngine->manageWaves();
            creepEngine->moveCreeps();
            creepEngine->manageDeadCreeps(playerEconomy);
            creepEngine->manageCreepEOL(player);

            playerEngine->manageGameOver(player);

            if (!player->isAlive)
            {
                std::cout << "Game Over" << std::endl;

                std::cout << "TowerEngine deinit:";
                delete towerEngine;
                std::cout << " ok" << std::endl;

                std::cout << "CreepEngine deinit:";
                delete creepEngine;
                std::cout << " ok" << std::endl;

                std::cout << "TowerLoader deinit:";
                delete towerLoader;
                std::cout << " ok" << std::endl;

                std::cout << "CreepLoader deinit:";
                delete creepLoader;
                std::cout << " ok" << std::endl;

                std::cout << "PlayerEngine deinit:";
                delete playerEngine;
                std::cout << " ok" << std::endl;

                std::cout << "PlayerEconomy deinit:";
                delete playerEconomy;
                std::cout << " ok" << std::endl;

                std::cout << "Player deinit:";
                delete player;
                std::cout << " ok" << std::endl;

                std::cout << "TowerPlotter deinit:";
                delete towerPlotter;
                std::cout << " ok" << std::endl;

                std::cout << "CreepPlotter deinit:";
                delete creepPlotter;
                std::cout << " ok" << std::endl;

                return;
            }

            // TODO: pensar se verificação de botão deveria ficar aqui mesmo
            if (mouseState.buttons == LEFTBUTTON)
                towerEngine->placeTower(mouseState.x, mouseState.y, playerEconomy);

            if (al_current_time() - start_time > fixedDownTime)
                break;

            plotter->plotBackground();
            plotter->plotGameMenu(towerEngine->currentSelection);
            towerPlotter->plot(debug);
            creepPlotter->plot(debug);
            al_wait_for_vsync();
            al_flip_display();
        }
    }
}

// TODO: passar para uma classe que faz o handling de status de botões
void setSelection(ALLEGRO_MOUSE_STATE mouseState, TowerEngine* towerEngine)
{
    if (mouseState.buttons != LEFTBUTTON)
        return;

    if (mouseState.x < TOWER_BUTTON_X_START || mouseState.x > TOWER_BUTTON_X_END)
        return;

    if (mouseState.y > BUNKER_BUTTON_Y_START && mouseState.y < BUNKER_BUTTON_Y_END)
    {
        towerEngine->currentSelection != TowerType::Bunker&& std::cout << "Bunker selected" << std::endl;
        towerEngine->currentSelection = TowerType::Bunker;
    }

    if (mouseState.y > TOWER_BUTTON_Y_START && mouseState.y < TOWER_BUTTON_Y_END)
    {
        towerEngine->currentSelection != TowerType::Turret&& std::cout << "Turret selected" << std::endl;
        towerEngine->currentSelection = TowerType::Turret;
    }

    if (mouseState.y > SIEGE_BUTTON_Y_START && mouseState.y < SIEGE_BUTTON_Y_END)
    {
        towerEngine->currentSelection != TowerType::SiegeTank&& std::cout << "Siege Tank selected" << std::endl;
        towerEngine->currentSelection = TowerType::SiegeTank;
    }
}
