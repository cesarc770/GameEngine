#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Character.h"
#include "Monster.h"
#include "Player.h"

const int GRID_SIZE = 8;
enum class GridTypes {None, PlayerCharacter, MonsterCharacter};
int monsterNum;
int Grid[GRID_SIZE][GRID_SIZE] = {};
Monster monsters[GRID_SIZE / 2] = {};
Player player;

void RunGame();
bool placeCharacter(Character &character, GridTypes gridType);
void updatePlayerMovement(int input);
void printPlayerPosition(int input);

	int main()
	{
		RunGame();

		return 0;
	}

	void RunGame()
	{

		char name[64];


		//welcome user and ask for name
		std::cout << "WELCOME TO MONSTER CHASE!!!" << "\n"
			<< "---------------------------\n\n"
			<< " Enter your name: ";
		std::cin >> name;
		std::cout << "\n";

		player = Player();
		player.setName(name);

		//place player in random position
		placeCharacter(player, GridTypes::PlayerCharacter);

		//query user for number of monsters
		printf("Enter number of monsters to create (Number must be between 1 and %1d ) ", GRID_SIZE / 2);
		scanf_s("%d", &monsterNum);

		//validate monsterNum
		//monsters should be less than grid squares - i need places to put them
		if (monsterNum <= 0)
			monsterNum = 1;
		if (monsterNum > (GRID_SIZE / 2))
			monsterNum = GRID_SIZE / 2;

		printf("\n%d Monster(s) is/are being created...\n", monsterNum);

		//create array of monsters with that length
		for (int i = 0; i < monsterNum; i++)
		{
			bool isPlaced = false;

			char name[64];
			//for each monster ask user for name and assign to monster
			Monster newMonster = Monster();
			std::cout << "Enter Monster " << i + 1 << " name: ";
			std::cin >> name;

			newMonster.setName(name);
			
			//place monster in grid in random position 
			placeCharacter(newMonster, GridTypes::MonsterCharacter);
			monsters[i] = newMonster;

		}
		printf("\n%d Monster(s) is/are have been placed...\n", monsterNum);


		//begin game - start game loop
		//while userinput not q and maybe player is not dead

		char userInput = '.';
			
		std::cout << " Begin Game: press w a s d keys to move player or q to quit" << std::endl;
		while (userInput != 'q')
		{
			
			userInput = getch();
			//player can move with input - maybe arrows idk yet
			updatePlayerMovement((int)userInput);

			//monsters move randomly in grid
			//if monsters collide with each other destroy both monsters
			//if monster collides with player - player is hurt or dies
			//if no monsters collide for 3 seconds create another monster
		}
			
		std::cout << " Ending Game: Thanks for playing..." << std::endl;
	}

	bool placeCharacter(Character &character, GridTypes gridType)
	{
		bool isPlaced = false;
		while (!isPlaced)
		{
			int x = rand() % GRID_SIZE;
			int y = rand() % GRID_SIZE;

			//check if occupied in grid

			if (Grid[x][y] == NULL || Grid[x][y] == (int)GridTypes::None)
			{
				//std::cout << x << " " << y << "is null";
				
				Grid[x][y] = (int)gridType;
			
				character.setPositionX(x);
				character.setPositionY(y);
				std::cout << x << " " << y << std::endl;
				isPlaced = true;
			}

		}

		return isPlaced;
	}

	void updatePlayerMovement(int input)
	{
		//validate that is an existing grid

		switch (input)
		{
			//arrow up
			case 119:
				player.moveUp();
				break;
			//arrow down
			case 115:
				player.moveDown(GRID_SIZE);
				break;
			//arrow right
			case 100:
				player.moveRight(GRID_SIZE);
				break;
			//arrow left
			case 97:
				player.moveLeft();
				break;
			default:
				//std::cout << input << std::endl;
				break;
		}

		printPlayerPosition(input);
	}

	void printPlayerPosition(int input)
	{
		switch (input)
		{
		case 115:
		case 119:
		case 97:
		case 100:
			printf("%s : [%d , %d]\n", player.getName(), player.getPositionX(), player.getPositionY());
		default:
			break;
		}
	}
