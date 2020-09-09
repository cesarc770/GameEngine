#include "Player.h"
#include "Math/Point2D.h"

Player::Player()
{
}

Player::Player(int x, int y)
{
	Point2D P(x, y);
	setPosition(P);
}
