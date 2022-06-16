#include "Figures.h"
#include<iostream>

//line
Line::Line()
{
		x = 0;
		y = 0;
		strcpy_s(shape, 5, "line");
}

Line::Line(double _x, double _y)
{
	x = _x;
	y = _y;
}

char* Line::setShape(char* _shape)
{
		strcpy_s(shape, 10, _shape);
		return shape;
}

void Line::translateFig(double horizontal, double vertical)
{
	x = x + horizontal;
	y = y + vertical;
}

bool Line::withinCircle(double _x, double _y, double _radius)
{
	if ( x< _x && y < _y) return true;
	return false;
}


bool Line::withinRectangle(double _x, double _y, double _height, double _width)
{
	if (x < _x && y < _y) return true;
	return false;
}

void Line::print()
{
	std::cout << getShape() << std::endl;
	std::cout << "X is: " << x << std::endl;
	std::cout << "Y is: " << y << std::endl;
}


//circle
Circle::Circle()
{
	radius = 0;
	char shape[7] = "circle";
	setShape(shape);
}

Circle::Circle(double _x, double _y, double _radius, char* shape)
{
	setShape(shape);
	setX(_x);
	setY(_y);
	radius = _radius;
}

bool Circle::withinCircle(double _x, double _y, double _radius)
{
	double d = sqrt(pow((_x - getX()), 2) + pow((_y - getY()), 2));
	if (_radius > (d + radius)) return true;
	return false;
}

bool Circle::withinRectangle(double _x, double _y, double _height, double _width)
{
	return false;
}

void Circle::print()
{
	Line::print();
	std::cout << "Radius: " << radius << std::endl;
}


//rectangle
Rectangle::Rectangle()
{
	width = 0;
	height = 0;
	char shape[10] = "rectangle";
	setShape(shape);
}

Rectangle::Rectangle(int _x, int _y, int _width, int _height, char* shape)
{
	setShape(shape);
	setX(_x);
	setY(_y);
	width = _width;
	height = _height;
}

bool Rectangle::withinCircle(double _x, double _y, double _radius)
{
	return false;
}

bool Rectangle::withinRectangle(double _x, double _y, double _height, double _width)
{
	return false;
}

void Rectangle::print()
{
	Line::print();
	std::cout << "Width: " << width << std::endl;
	std::cout << "Height: " << height << std::endl;
}
