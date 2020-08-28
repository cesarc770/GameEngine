#pragma once
#include "Character.h"

class Monster : public Character
{

public:
	Monster();
	Monster(int x, int y);
	void moveRandomly();

	bool collidedInTurn = false;
};

