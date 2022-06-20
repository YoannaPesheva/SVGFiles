#pragma once
#include "Figures.h"

class Circle : public Figure {
private:
	double radius;
public:
	Circle();
	Circle(double _x, double _y, double _radius); //!!!!mahnah shape

	void setRadius(double _radius) { radius = _radius; }
	double getRadius() const { return radius; }

	void translateFig(double horizontal, double vertical) override;

	bool withinCircle(double _x, double _y, double _radius) const override;
	//!!!
	bool findIfPointInside(double xCircle, double yCircle, double _x, double _y, double _height, double _width);
	bool withinRectangle(double _x, double _y, double _height, double _width) const override;

	void print() const override;
	Figure* clone() const { return new Circle(*this); }
	void printFile(std::ostream& out) const override;
};
