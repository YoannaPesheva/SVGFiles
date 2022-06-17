#include "Figures.h"
#include<iostream>

Figure::Figure()
{
	x = 0;
	y = 0;
	strcpy_s(shape, 13, "not defined");
}

char* Figure::setShape(char* _shape)
{
	strcpy_s(shape, 10, _shape);
	return shape;
}

void Figure::print()
{
	std::cout << getShape() << std::endl;
	std::cout << "X is: " << x << std::endl;
	std::cout << "Y is: " << y << std::endl;
}

//line
Line::Line()
{
		xEnd = 0;
		yEnd = 0;
		char shape[5] = "line";
		setShape(shape);
}

Line::Line(double _x, double _y, double _xEnd, double _yEnd, char* shape)
{
	setShape(shape);
	setX(_x);
	setY(_y);
	xEnd = _xEnd;
	yEnd = _yEnd;
}


void Line::translateFig(double horizontal, double vertical)
{
	setX(getX() + horizontal);
	setY(getY() + vertical);
	xEnd = xEnd + horizontal;
	yEnd = yEnd + vertical;
}

bool Line::withinCircle(double _x, double _y, double _radius)
{

	double d = sqrt(pow((_x - getX()), 2) + pow((_y - getY()), 2));
	double d1 = sqrt(pow((_x - xEnd), 2) + pow((_y - yEnd), 2));
	if (d1 < _radius && d < _radius) return true;
	return false;
}


bool Line::withinRectangle(double _x, double _y, double _height, double _width)
{
	if ((getX() > _x && xEnd < _x + _width) && (getY() > _y && yEnd < _y - _height)) return true;
	return false;
}

void Line::print()
{
	Figure::print();
	std::cout << "X of the end point is: " << xEnd << std::endl;
	std::cout << "Y of the end point is: " << yEnd << std::endl;
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

void Circle::translateFig(double horizontal, double vertical)
{
	setX(getX() + horizontal);
	setY(getY() + vertical);
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
	Figure::print();
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

Rectangle::Rectangle(double _x, double _y, double _width, double _height, char* shape)
{
	setShape(shape);
	setX(_x);
	setY(_y);
	width = _width;
	height = _height;
}

void Rectangle::translateFig(double horizontal, double vertical)
{
	setX(getX() + horizontal);
	setY(getY() + vertical);
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
	Figure::print();
	std::cout << "Width: " << width << std::endl;
	std::cout << "Height: " << height << std::endl;
}
