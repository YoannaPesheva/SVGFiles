#include "Figures.h"
#include "Rectangle.h"

#include<iostream>

Rectangle::Rectangle()
{
	width = 0;
	height = 0;
	char shape[10] = "rectangle";
	setShape(shape);
}

Rectangle::Rectangle(double _x, double _y, double _width, double _height)
{
	char shape[10] = "rectangle";
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

bool Rectangle::withinCircle(double _x, double _y, double _radius) const
{
	double dx;
	double dy;
	if (_x - getX() > _x - (getX() + width))
		dx = _x - getX();
	 dx = _x - (getX() + width);
	if (_y - getY() > _y - (getY() - height))
		 dy = _y - getY();
	 dy = _y - (getY() - height);
	return _radius * _radius >= dx * dx + dy * dy;
}

bool Rectangle::withinRectangle(double _x, double _y, double _height, double _width) const
{
	if ((getX() + width < _x + _width) && getX() > _x && getY() < _y && (getY() - height > _y - _height))
		return true;
	return false;
}

void Rectangle::print() const
{
	Figure::print();
	std::cout << "Width: " << width << std::endl;
	std::cout << "Height: " << height << std::endl;
}

void Rectangle::printFile(std::ostream& out) const
{
	out << "<" << getShape() << " x = \"" << getX() << "\" y = \"" << getY() << "\" width = \"" << width << "\" height = \"" << height << "\" fill = \"" << getColour() << "\" />";

}


