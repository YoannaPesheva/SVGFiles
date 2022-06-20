#include "Figures.h"
#include "Line.h"
#include "String.h"

#include<iostream>


Line::Line()
{
	xEnd = 0;
	yEnd = 0;
	char shape[5] = "line";
	setShape(shape);
}

Line::Line(double _x, double _y, double _xEnd, double _yEnd, std::string _colour)
{
	setColour(_colour);
	char shape[5] = "line";
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

bool Line::withinCircle(double _x, double _y, double _radius) const
{

	double d = sqrt(pow((_x - getX()), 2) + pow((_y - getY()), 2));
	double d1 = sqrt(pow((_x - xEnd), 2) + pow((_y - yEnd), 2));
	if (d1 < _radius && d < _radius) return true;
	return false;
}


bool Line::withinRectangle(double _x, double _y, double _height, double _width) const
{
	if ((getX() > _x && xEnd < _x + _width) && (getY() < _y && yEnd > _y - _height)) return true;
	return false;
}

void Line::print() const
{
	Figure::print();
	std::cout << "X of the end point is: " << xEnd << std::endl;
	std::cout << "Y of the end point is: " << yEnd << std::endl;
	std::cout << "Colour: " << getColour() << std::endl;
}

void Line::printFile(std::ostream& out) const
{
	out << "<" << getShape() << " x1 = \"" << getX() << "\" y1 = \"" << getY() << "\" x2 = \"" << xEnd << "\" y2 = \"" << yEnd << "\" fill = \"" << getColour() << "\" />" << std::endl;
}
