#include "Figures.h"
#include "Circle.h"

#include<iostream>

Circle::Circle()
{
	radius = 0;
	char shape[7] = "circle";
	setShape(shape);
}

Circle::Circle(double _x, double _y, double _radius)
{
	char shape[7] = "circle";
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

// CIRCLE INSIDE A CIRCLE
bool Circle::withinCircle(double _x, double _y, double _radius) const
{
	double d = sqrt(pow((_x - getX()), 2) + pow((_y - getY()), 2));
	if (_radius > (d + radius)) return true;
	return false;
}


bool Circle::withinRectangle(double _x, double _y, double _height, double _width) const
{

	double xCircle = getX();
	double yCircle = getY()+radius;
	if (xCircle > _x && xCircle < _x + _width && yCircle < _y && yCircle>_y - _height)
	{
		xCircle = getX();
		yCircle = getX() - radius;
		if (xCircle > _x && xCircle < _x + _width && yCircle <_y && yCircle>_y - _height)
		{
			xCircle = getX()+ radius;
			yCircle = getX();
			if (xCircle > _x && xCircle < _x + _width && yCircle <_y && yCircle>_y - _height)
			{
				xCircle = getX() - radius;
				yCircle = getX();
				if (xCircle > _x && xCircle < _x + _width && yCircle <_y && yCircle>_y - _height) return true;
			}
		}
	}
	return false;
}

void Circle::print() const
{
	Figure::print();
	std::cout << "Radius: " << radius << std::endl;
}

void Circle::printFile(std::ostream& out) const
{
	out << "<" << getShape() << " cx = \"" << getX() << "\" cy = \"" << getY() << "\" r = \"" << radius << "\" fill = \"" << getColour() << "\" />";

}

