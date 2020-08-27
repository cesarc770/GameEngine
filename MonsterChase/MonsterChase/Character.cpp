#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include "Character.h"
#include <string.h>

Character::Character()
{
	name = nullptr;
	positionX = 0;
	positionY = 0;
}

Character::Character(int x, int y)
{
	name = nullptr;
	positionX = x;
	positionY = y;
}

char* Character::getName()
{
	return name;
}

void Character::setPositionX(int x)
{
	positionX = x;
}

int Character::getPositionX()
{
	return positionX;
}

void Character::setPositionY(int y)
{
	positionY = y;
}

int Character::getPositionY()
{
	return positionY;
}

void Character::moveUp()
{
	//safe guard
	if (positionX - 1 < 0) return;

	positionX--;
}

void Character::moveDown(int edge)
{
	//safe guard
	if (positionX + 1 >= edge) return;

	positionX++;
}

void Character::moveRight(int edge)
{
	//safe guard
	if (positionY + 1 >= edge) return;

	positionY++;
}

void Character::moveLeft()
{
	//safe guard
	if (positionY - 1 < 0) return;

	positionY--;
}

void Character::setName(char* n)
{
	name = n;
}

