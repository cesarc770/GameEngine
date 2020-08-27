#pragma once

class Character
{
public:
	Character();
	Character(int x, int y);

	//getters and setters
	void setName(char *n);
	char* getName();
	void setPositionX(int x);
	int getPositionX();
	void setPositionY(int y);
	int getPositionY();

	//move character
	void moveUp();
	void moveDown(int edge);
	void moveRight(int edge);
	void moveLeft();

private:
	char* name;
	int positionX;
	int positionY;
};

