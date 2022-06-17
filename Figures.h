#pragma once
#include <string>

class Figure {
private:
	char shape[15];
	std::string colour;
	double x, y;
public:
	Figure();

	void setX(double _x) { x = _x; }
	void setY(double _y) { y = _y; }
	char* setShape(char* _shape);

	const double getX() const { return x; }
	const double getY() const { return y; }
	const char* getShape() const { return shape; }

	virtual void translateFig(double horizontal, double vertical) {};

	virtual bool withinCircle(double _x, double _y, double _radius) = 0;
	virtual bool withinRectangle(double _x, double _y, double _height, double _width) = 0;

	virtual void print();
};


class Line : public Figure {
private:
	double xEnd, yEnd;
public:
	Line();
	Line(double _x, double _y, double _xEnd, double _yEnd, char* shape);

	void setXEnd(double _x) { xEnd = _x; }
	void setYEnd(double _y) { yEnd = _y; }

	const double getXEnd() const { return xEnd; }
	const double getYEnd() const { return yEnd; }

	void translateFig(double horizontal, double vertical);

	bool withinCircle(double _x, double _y, double _radius);
	bool withinRectangle(double _x, double _y, double _height, double _width);

	void print();
};


class Circle : public Figure {
private:
	double radius;
	//string colour;
public:
	Circle();
	Circle(double _x, double _y, double _radius, char* shape);

	void setRadius(double _radius) { radius = _radius; }
	double getRadius() const { return radius; }

	void translateFig(double horizontal, double vertical);

	bool withinCircle(double _x, double _y, double _radius);
	//!!!
	bool withinRectangle(double _x, double _y, double _height, double _width);

	void print();
};


class Rectangle : public Figure {
private:
	double width, height;
	//string colour;
public:
	Rectangle();
	Rectangle(double _x, double _y, double _width, double _height, char* shape);

	void setWidth(double _width) { width = _width; }
	void setHeight(double _height) { height = _height; }

	double getWidth() const { return width; }
	double getHeight() const { return height; }

	void translateFig(double horizontal, double vertical);

	//!!!
	bool withinCircle(double _x, double _y, double _radius);
	//!!!
	bool withinRectangle(double _x, double _y, double _height, double _width);

	void print();
};