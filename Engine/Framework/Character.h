#pragma once
#include "../Math/Point2D.h"

namespace Engine
{
	class Character
	{
	public:
		Character();
		Character(Point2D &pos);

		//getters and setters
		void setName(char* n);
		char* getName();
		void setPosition(Point2D &pos);
		Point2D getPosition();

		//move character
		void moveUp();
		void moveDown();
		void moveRight();
		void moveLeft();

	private:
		char* name;
		Point2D position;
		//int positionX;
		//int positionY;
	};
}