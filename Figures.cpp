#include "Figures.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"

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

void Figure::print() const
{
	std::cout << getShape() << std::endl;
	std::cout << "X is: " << x << std::endl;
	std::cout << "Y is: " << y << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Figure& shape)
{
	shape.printFile(out);
	return out;
}
