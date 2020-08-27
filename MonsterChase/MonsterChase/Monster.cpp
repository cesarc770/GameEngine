#include "Monster.h"
#include <stdlib.h>

Monster::Monster()
{
	Character();
}

Monster::Monster(int x, int y)
{
	Character(x, y);
}

void Monster::moveRandomly(int bound)
{
	int random = rand() % 4;

	switch (random)
	{
	case 0:
		moveUp();
		break;
	case 1:
		moveDown(bound);
		break;
	case 2:
		moveLeft();
		break;
	case 3:
		moveRight(bound);
		break;
	default:
		moveUp();
		break;
	}
}
