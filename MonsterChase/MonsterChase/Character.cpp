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

void Character::setName(char* n)
{
	name = n;
}

