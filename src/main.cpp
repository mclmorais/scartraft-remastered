#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <stdbool.h>
#include <math.h>
#include "bitmap-loader.h"
#include "plotter.h"
#include <iostream>
#include "towers/entities/tower-loader.h"
#include "towers/entities/tower-plotter.h"
#include "towers/engines/tower-engine.h"

#define REFRESH_RATE 60
#define LEFTBUTTON 1

void mainMenu(Plotter* plotter);
void game(Plotter* plotter);

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

	ALLEGRO_MOUSE_STATE		mousestate;

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
					// _CrtDumpMemoryLeaks();
					exit(1);

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

	std::cout << "TowerLoader init:";
	TowerLoader* towerLoader = new TowerLoader();
	towerLoader->loadSprites();
	std::cout << " ok" << std::endl;

	std::cout << "TowerEngine init:";
	TowerEngine* towerEngine = new TowerEngine();
	std::cout << " ok" << std::endl;

	std::cout << "TowerPlotter init:";
	TowerPlotter* towerPlotter = new TowerPlotter(towerLoader, &towerEngine->towerSlots);
	std::cout << " ok" << std::endl;

	PlayerEconomy* playerEconomy = new PlayerEconomy();
	playerEconomy->gas = 500;
	playerEconomy->minerals = 500;
	

	ALLEGRO_MOUSE_STATE mouseState;
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
			al_get_mouse_state(&mouseState);
			
			towerEngine->placeTower(mouseState.x, mouseState.y, playerEconomy);


			if (al_current_time() - start_time > fixedDownTime)
				break;

			plotter->plotBackground();
			plotter->plotGameMenu(mouseState);
			towerPlotter->plot();
			al_wait_for_vsync();
			al_flip_display();
		}

	}
}
