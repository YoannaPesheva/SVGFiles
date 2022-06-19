#pragma once
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
	//!!!
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
	virtual void writeFile() const = 0;
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

	void translateFig(double horizontal, double vertical) override;

	bool withinCircle(double _x, double _y, double _radius)const override;
	bool withinRectangle(double _x, double _y, double _height, double _width) const override;

	void print() const override;
	void writeFile() const override;//!!!
	Figure* clone() const
	{
		//Figure* copy = new Line(*this);
		//return copy;
		return new Line(*this);
	}
};


class Circle : public Figure {
private:
	double radius;
public:
	Circle();
	Circle(double _x, double _y, double _radius, char* shape);

	void setRadius(double _radius) { radius = _radius; }
	double getRadius() const { return radius; }

	void translateFig(double horizontal, double vertical) override;

	bool withinCircle(double _x, double _y, double _radius) const override;
	//!!!
	bool withinRectangle(double _x, double _y, double _height, double _width) const override;

	void print() const override;
	void writeFile() const override;
	Figure* clone() const
	{
		Figure* copy = new Circle(*this);
		return copy;
	}
};


class Rectangle : public Figure {
private:
	double width, height;
public:
	Rectangle();
	Rectangle(double _x, double _y, double _width, double _height, char* shape);

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
	void writeFile() const override;
	Figure* clone() const
	{
		Figure* copy = new Rectangle(*this);
		return copy;
	}
};