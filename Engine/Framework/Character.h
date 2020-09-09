#pragma once

namespace Engine
{
	class Character
	{
	public:
		Character();
		Character(int x, int y);

		//getters and setters
		void setName(char* n);
		char* getName();
		void setPositionX(int x);
		int getPositionX();
		void setPositionY(int y);
		int getPositionY();

		//move character
		void moveUp();
		void moveDown();
		void moveRight();
		void moveLeft();

	private:
		char* name;
		int positionX;
		int positionY;
	};
}