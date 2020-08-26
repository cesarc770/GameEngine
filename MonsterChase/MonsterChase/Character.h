#pragma once

class Character
{
public:
	Character();
	Character(int x, int y);

	//getters and setters
	void setName(char *n);
	char* getName();

	int positionX;
	int positionY;

private:
	char* name;
};

