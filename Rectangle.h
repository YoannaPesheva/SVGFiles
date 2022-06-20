#pragma once
#include "Figures.h"

class Rectangle : public Figure {
private:
	double width, height;
public:
	Rectangle();
	Rectangle(double _x, double _y, double _width, double _height);//!!!! shape

	void setWidth(double _width) { width = _width; }
	void setHeight(double _height) { height = _height; }

	double getWidth() const { return width; }
	double getHeight() const { return height; }

	void translateFig(double horizontal, double vertical) override;

	//!!!
	bool withinCircle(double _x, double _y, double _radius)const override;
	//!!!
	bool withinRectangle(double _x, double _y, double _height, double _width)const override;

	void print() const override;
	Figure* clone() const { return new Rectangle(*this); }
	void printFile(std::ostream& out) const override;
};