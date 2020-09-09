#include "Monster.h"
#include <stdlib.h>

Monster::Monster()
{
	Engine::Character();
}

Monster::Monster(int x, int y)
{
	Engine::Character(x, y);
}

void Monster::moveRandomly()
{
	int random = rand() % 4;

	switch (random)
	{
	case 0:
		moveUp();
		break;
	case 1:
		moveDown();
		break;
	case 2:
		moveLeft();
		break;
	case 3:
		moveRight();
		break;
	default:
		moveUp();
		break;
	}
}
