#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include "Character.h"
#include <string.h>

namespace Engine
{
	Character::Character()
	{
		name = nullptr;
		position = Point2D();
	}

	Character::Character(Point2D &pos)
	{
		name = nullptr;
		position = pos;
	}

	char* Character::getName()
	{
		return name;
	}


	Point2D Character::getPosition()
	{
		return position;
	}

	void Character::setPosition(Point2D &pos)
	{
		position = pos;
	}


	void Character::moveUp()
	{

		position.Y--;
	}

	void Character::moveDown()
	{

		position.Y++;
	}

	void Character::moveRight()
	{

		position.X++;
	}

	void Character::moveLeft()
	{

		position.X--;
	}

	void Character::setName(char* n)
	{
		name = n;
	}


}
