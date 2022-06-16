#pragma once
class Line {
private:
	char shape[10];
	//string colour;
	double x, y;
public:
	Line();
	Line(double _x, double _y);

	void setX(double _x) { x = _x; }
	void setY(double _y) { y = _y; }
	char* setShape(char* _shape);

	const double getX() const { return x; }
	const double getY() const { return y; }
	const char* getShape() const { return shape; }

	void translateFig(double horizontal, double vertical);

	virtual bool withinCircle(double _x, double _y, double _radius);
	virtual bool withinRectangle(double _x, double _y, double _height, double _width);

	virtual void print();
};


class Circle : public Line {
private:
	double radius;
	//string colour;
public:
	Circle();
	Circle(double _x, double _y, double _radius, char* shape);

	void setRadius(double _radius) { radius = _radius; }
	double getRadius() const { return radius; }

	bool withinCircle(double _x, double _y, double _radius);
	//!!!
	bool withinRectangle(double _x, double _y, double _height, double _width);

	void print();
};


class Rectangle : public Line {
private:
	double width, height;
	//string colour;
public:
	Rectangle();
	Rectangle(int _x, int _y, int _width, int _height, char* shape);

	void setWidth(double _width) { width = _width; }
	void setHeight(double _height) { height = _height; }

	double getWidth() const { return width; }
	double getHeight() const { return height; }

	//!!!
	bool withinCircle(double _x, double _y, double _radius);
	//!!!
	bool withinRectangle(double _x, double _y, double _height, double _width);

	void print();
};