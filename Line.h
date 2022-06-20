#pragma once
#include "Figures.h"

class Line : public Figure {
private:
	double xEnd, yEnd;
public:
	Line();
	Line(double _x, double _y, double _xEnd, double _yEnd, std::string _colour); //!!colour

	void setXEnd(double _x) { xEnd = _x; }
	void setYEnd(double _y) { yEnd = _y; }

	const double getXEnd() const { return xEnd; }
	const double getYEnd() const { return yEnd; }

	void translateFig(double horizontal, double vertical) override;

	bool withinCircle(double _x, double _y, double _radius)const override;
	bool withinRectangle(double _x, double _y, double _height, double _width) const override;

	void print() const override;
	Figure* clone() const { return new Line(*this); }
	void printFile(std::ostream& out) const override;

};
