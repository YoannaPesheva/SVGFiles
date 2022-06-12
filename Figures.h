#pragma once
class Line {
private:
	double x, y;
public:
	Line() {
		x = 0;
		y = 0;
	}

	Line(double _x, double _y)
	{
		x = _x;
		y = _y;
	}

	void setX(double _x) { x = _x; }
	void setY(double _y) { y = _y; }

	const double getX() const { return x; }
	const double getY() const { return y; }

	void translateFig(double horizontal, double vertical)
	{
		x = x + horizontal;
		y = y + vertical;
	}
	virtual void print()
	{
		std::cout << "X is: " << x << std::endl;
		std::cout << "Y is: " << y << std::endl;
	}
};

class Circle : public Line {
private:
	double radius;
	// string maybe?
	//string colour;
public:
	Circle()
	{
		radius = 0;
	}

	Circle(double _x, double _y, double _radius)
	{
		setX(_x);
		setY(_y);
		radius = _radius;
	}

	void setRadius(double _radius) { radius = _radius; }

	double getRadius() const { return radius; }


	void print()
	{
		std::cout << "Circle: " << std::endl;
		Line::print();
		std::cout << "Radius: " << radius << std::endl;
	}
};

class Rectangle : public Line {
private:
	double width, height;
	// string maybe?
	//string colour;
public:
	Rectangle()
	{
		width = 0;
		height = 0;
	}

	Rectangle(int _x, int _y, int _width, int _height)
	{
		setX(_x);
		setY(_y);
		width = _width;
		height = _height;
	}

	void setWidth(double _width) { width = _width; }
	void setHeight(double _height) { height = _height; }

	double getWidth() const { return width; }
	double getHeight() const { return height; }


	void print()
	{
		std::cout << "Rectangle: " << std::endl;
		Line::print();
		std::cout << "Width: " << width << std::endl;
		std::cout << "Height: " << height << std::endl;
	}



};