#include "Monster.h"
#include "Math/Point2D.h"
#include <stdlib.h>

Monster::Monster()
{
}

Monster::Monster(int x, int y)
{
	Point2D P(x, y);
	setPosition(P);
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
