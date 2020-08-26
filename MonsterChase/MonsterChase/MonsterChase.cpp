#include <iostream>
#include <string>
#include "Character.h"

	int main()
	{
		//create 2D Grid - SQUARE
		const int GRID_SIZE = 50;
		Character Grid[GRID_SIZE][GRID_SIZE] = {};


		//welcome user and ask for name
		std::cout << "WELCOME TO MONSTER CHASE!!!" << "\n";
		std::cout << "---------------------------" << std::endl;
		//query user for number of monsters -  create array of monsters with that length

		//monsters should be less than grid squares - i need places to put them

		//for each monster ask user for name and assign to monster

		//begin game - start game loop
		//while userinput not q and player is not dead
			//monsters move randomly in grid
			//if monsters collide with each other destroy both monsters
			//if monster collides with player - player is hurt or dies
			//if no monsters collide for 3 seconds create another monster
			//player can move with input - maybe arrows idk yet


		return 0;
	}
