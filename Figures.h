#pragma once
#include "String.h"

#include <string>

class Figure {
private:
	char shape[15];
	std::string colour;
	double x, y;
public:
	Figure();
	virtual ~Figure() {}
	virtual Figure* clone() const = 0;

	void setX(double _x) { x = _x; }
	void setY(double _y) { y = _y; }
	char* setShape(char* _shape);//const char* 
	void setColour(std::string _colour) { colour = _colour; }

	const std::string getColour() const { return colour; }
	const double getX() const { return x; }
	const double getY() const { return y; }
	const char* getShape() const { return shape; }

	virtual void translateFig(double horizontal, double vertical) = 0;

	virtual bool withinCircle(double _x, double _y, double _radius) const = 0;
	virtual bool withinRectangle(double _x, double _y, double _height, double _width) const = 0;

	virtual void print() const;
	virtual void printFile(std::ostream& out) const = 0;

	friend std::ostream& operator<<(std::ostream& out, const Figure& shape);
};
