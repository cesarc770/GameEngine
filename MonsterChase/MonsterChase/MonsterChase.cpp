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

//const int GRID_SIZE = 8;
//enum class GridTypes {None, PlayerCharacter, MonsterCharacter};
int monsterNum;
//int Grid[GRID_SIZE][GRID_SIZE] = {};
Player player;
char NewName[] = "NewBabyMonster";

void RunGame();
void placeCharacter(Character &character);
Monster* updatePlayerMovement(int input, Monster* monsters);
Monster* checkCollision(Character& character, Monster* monsters, int index);
bool isInputValid(int input);
Monster* updateMovement(int input, Monster *monsters);
Monster* updateMonstersMove(Monster *monsters);
bool checkMonsterCollision(Monster& character, Monster* monsters, int index);
Monster* takeMonsterOutOfArray(Monster* arr, int index);
Monster* addToArray(Monster* arr);


	int main()
	{
		RunGame();

		return 0;
	}

	void RunGame()
	{

		char name[64];


		//welcome user
		std::cout << "WELCOME TO MONSTER CHASE!!!" << "\n"
			<< "---------------------------\n\n";

		//query user for number of monsters
		printf("Enter number of monsters to create: ");
		scanf_s("%d", &monsterNum);

		//validate monsterNum
		if (monsterNum <= 0)
			monsterNum = 1;


		Monster* monsters = new Monster[monsterNum];

		//printf("\n%d Monster(s) is/are being created...\n", monsterNum);

		//create array of monsters with that length
		for (int i = 0; i < monsterNum; i++)
		{

			char* name = new char[64]();
			//for each monster ask user for name and assign to monster
			Monster newMonster = Monster();
			std::cout << "Enter Monster " << i + 1 << " name:";
			std::cin >> name;

			newMonster.setName(name);
			
			
			//place monster in grid in random position 
			placeCharacter(newMonster);
			monsters[i] = newMonster;

		}
		//printf("\n%d Monster(s) is/are have been placed...\n\n", monsterNum);

		//ask user for name
		std::cout << "Enter your name: ";
		std::cin >> name;
		std::cout << "\n";

		player = Player();
		player.setName(name);

		//place player in random position
		placeCharacter(player);


		//begin game - start game loop
		//while userinput not q and maybe player is not dead

		char userInput = '.';
		bool allMonstersDead = false;
		
		while (userInput != 'q' && !allMonstersDead)
		{
			std::cout << "\nPress w to go Up , a to go Left, s to go Down and d to go Right or q to quit\n" << std::endl;
			userInput = getch();

			//if monsters collide with each other they have a baby
			//if monster collides with player - monster is killed
			monsters = updateMovement(userInput, monsters);
			
			//use this for testing
			//takeMonsterOutOfArray(monsters, 1);

			if (monsterNum == 0)
			{
				allMonstersDead = true;
			}
		}
		
		if (allMonstersDead)
		{
			std::cout << " You Won the game!... Thanks for playing" << std::endl;
		}
		std::cout << " Ending Game: Thanks for playing..." << std::endl;
	}

	void placeCharacter(Character &character)
	{

			int x = rand() % 100 -50;
			int y = rand() % 100 -50;
			character.setPositionX(x);
			character.setPositionY(y);

	}
	
	Monster* updateMovement(int input, Monster *monsters)
	{
		if(isInputValid(input))
		{
			monsters = updatePlayerMovement(input, monsters);
			monsters = updateMonstersMove(monsters);
		}

		return monsters;
		
	}

	Monster* updatePlayerMovement(int input, Monster *monsters)
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
				player.moveDown();
				break;
			//arrow right
			case 100:
				player.moveRight();
				break;
			//arrow left
			case 97:
				player.moveLeft();
				break;
			default:
				break;
		}

		//check is player collides with a monster
		monsters = checkCollision(player, monsters, monsterNum);


		std::cout << "Player:\n";
		printf("%s : [%d , %d]\n", player.getName(), player.getPositionX(), player.getPositionY());

		return monsters;
	}

	bool isInputValid(int input)
	{
		switch (input)
		{
		case 115:
		case 119:
		case 97:
		case 100:
			return true;
		default:
			return false;
		}
	}


	Monster* updateMonstersMove(Monster *monsters)
	{
		std::cout << "\nMonsters:\n";
		for (int i = 0; i < monsterNum; i++)
		{			
			monsters[i].moveRandomly();
			//check if monster collides with another monster
			if (checkMonsterCollision(monsters[i], monsters, i))
			{
				//create baby monster
				monsters = addToArray(monsters);
			}
			else
			{
				monsters[i].collidedInTurn = false;
			}

			printf("%s : [%d , %d]\n", monsters[i].getName(), monsters[i].getPositionX(), monsters[i].getPositionY());
		}

		return monsters;
	}

	Monster* checkCollision(Character& character, Monster *monsters, int index)
	{
		for (int i = 0; i < monsterNum; i++)
		{
			if (i != index)
			{
				if (character.getPositionX() == monsters[i].getPositionX() && character.getPositionY() == monsters[i].getPositionY())
				{
					//take monster out of array
					monsters = takeMonsterOutOfArray(monsters, i);
				}
			}
		}
		
		return monsters;
	}



	bool checkMonsterCollision(Monster& character, Monster* monsters, int index)
	{
		if (!character.collidedInTurn)
		{
			for (int i = 0; i < monsterNum; i++)
			{
				if (i != index)
				{
					if (character.getPositionX() == monsters[i].getPositionX() && character.getPositionY() == monsters[i].getPositionY())
					{
						monsters[i].collidedInTurn = true;
						character.collidedInTurn = true;
						return true;
					}
				}
			}
		}

		return false;
	}

	Monster* takeMonsterOutOfArray(Monster* arr, int index)
	{
		if (monsterNum > 0)
		{
			// move elements from array to front
			for (int i = index; i < monsterNum - 1; i++)
			{
				arr[i] = arr[i + 1];
			}

			//make new array and copy to new array
			//change pointer

			monsterNum--;
			Monster* temp = new Monster[monsterNum];
			for (int i = 0; i < monsterNum - 1; i++)
			{
				temp[i] = arr[i];
			}

			return temp;
		}

		return arr;
	}

	Monster* addToArray(Monster* arr)
	{
		monsterNum++;
		Monster* temp = new Monster[monsterNum];
		for (int i = 0; i < monsterNum - 1; i++)
		{
			temp[i] = arr[i];
		}

		char* ch = NewName;
		Monster tempMonster = Monster();
		tempMonster.setName(ch);


		//place monster in grid in random position 
		placeCharacter(tempMonster);
		temp[monsterNum - 1] = tempMonster;

		return temp;
	}