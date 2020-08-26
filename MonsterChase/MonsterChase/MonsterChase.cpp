#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <iostream>
#include <stdio.h>
#include "Character.h"
#include "Monster.h"
#include "Player.h"

const int GRID_SIZE = 50;
int monsterNum;
Monster monsters[GRID_SIZE / 2] = {};
Player player;

void RunGame();

	int main()
	{
		//create 2D Grid - SQUARE
		//Character Grid[GRID_SIZE][GRID_SIZE] = {};
		RunGame();

		return 0;
	}

	void RunGame()
	{
		//welcome user and ask for name
		std::cout << "WELCOME TO MONSTER CHASE!!!" << "\n"
			<< "---------------------------\n\n" 
			<< " Enter your name: " << std::endl;

		char name[64];
		std::cin >> name;

		player = Player();
		player.setName(name);

		//query user for number of monsters
		printf("Enter number of monsters to create (Number must be between 1 and %1d ) \n", GRID_SIZE / 2);
		scanf_s("%d", &monsterNum);

		//validate monsterNum
		//monsters should be less than grid squares - i need places to put them
		if (monsterNum <= 0)
			monsterNum = 1;
		if (monsterNum > (GRID_SIZE / 2))
			monsterNum = GRID_SIZE / 2;

		printf("%d Monster(s) is/are being created...\n", monsterNum);

		//create array of monsters with that length
		for (int i = 0; i < monsterNum; i++)
		{
			char name[64];
			//for each monster ask user for name and assign to monster
			Monster newMonster = Monster();
			std::cout << "Enter Monster " << i + 1 << " name: ";
			std::cin >> name;

			newMonster.setName(name);

			monsters[i] = newMonster;
		}


		//begin game - start game loop
		//while userinput not q and player is not dead
			//monsters move randomly in grid
			//if monsters collide with each other destroy both monsters
			//if monster collides with player - player is hurt or dies
			//if no monsters collide for 3 seconds create another monster
			//player can move with input - maybe arrows idk yet

	}
