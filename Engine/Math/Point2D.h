#pragma once

	class Point2D
	{

	public:
		Point2D();
		Point2D(int x, int y);
		int X, Y;

		//operators overload
		bool operator== (const Point2D& P) const;
		bool operator!= (const Point2D& P) const;
		Point2D operator+ (const Point2D& P) const;
		Point2D operator- (const Point2D& P) const;
		Point2D operator* (const int& num) const;
		Point2D operator/ (const int& num) const;
		Point2D operator- () const;
		Point2D operator+= (const Point2D& P);
		Point2D operator-= (const Point2D& P);
		Point2D operator*= (const int& num);
		Point2D operator/= (const int& num);
	};