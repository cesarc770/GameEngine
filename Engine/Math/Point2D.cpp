#include "Point2D.h"

	Point2D::Point2D()
	{
		X = 0;
		Y = 0;
	}

	Point2D::Point2D(int x, int y)
	{
		X = x;
		Y = y;
	}

	bool Point2D::operator==(const Point2D& P) const
	{
		return (X == P.X) && (Y == P.Y);
	}

	bool Point2D::operator!=(const Point2D& P) const
	{
		return !((X == P.X) && (Y == P.Y));
	}

	Point2D Point2D::operator+ (const Point2D& P) const
	{
		return Point2D(X + P.X, Y + P.Y);
	}

	Point2D Point2D::operator-(const Point2D& P) const
	{
		return Point2D(X - P.X, Y - P.Y);
	}

	Point2D Point2D::operator*(const int& num) const
	{
		return Point2D(X * num, Y * num);
	}

	Point2D Point2D::operator/(const int& num) const
	{
		return Point2D(X / num, Y / num);
	}

	Point2D Point2D::operator-() const
	{
		return Point2D(-X, -Y);
	}

	Point2D Point2D::operator+=(const Point2D& P)
	{
		X += P.X;
		Y += P.Y;
		return *this;
	}

	Point2D Point2D::operator-=(const Point2D& P)
	{
		X -= P.X;
		Y -= P.Y;
		return *this;
	}

	Point2D Point2D::operator*=(const int& num)
	{
		X *= num;
		Y *= num;
		return *this;
	}

	Point2D Point2D::operator/=(const int& num)
	{
		X /= num;
		Y /= num;
		return *this;
	}

