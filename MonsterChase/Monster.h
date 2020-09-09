#pragma once
#include "Framework/Character.h"

class Monster : public Engine::Character
{

public:
	Monster();
	Monster(int x, int y);
	void moveRandomly();

	bool collidedInTurn = false;
};

