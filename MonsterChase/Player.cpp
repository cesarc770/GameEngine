#include "Player.h"
#include "Math/Point2D.h"

Player::Player()
{
}

Player::Player(int x, int y)
{
	Point2D p = Point2D(x, y);
	setPosition(p);
}
