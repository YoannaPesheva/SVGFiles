#include "CommandExecutioner.h"
#include<iostream>

void CommandExecutioner::start()
{
	//read from file
}

void CommandExecutioner::InvalidCommandMessage()
{
	std::cout << "Invalid command, please try again!" << std::endl;
}

void CommandExecutioner::executeTranslation()
{
	int size = arr.getCurrSize();
	int horizontal = 0, vertical = 0;
	std::cout << "Please enter by how many centimeters do you want to move the figure/s horizontically(the X-axis): ";
	std::cin >> horizontal;
	std::cout << "Please enter by how many centimeters do you want to move the figure/s vertically(the Y-axis): ";
	std::cin >> vertical;
	std::cout << std::endl;
	int num = -1;
	do {
		std::cout << "Please press 1 if you would like to translate all figures and 2 if you want to translate only one: ";
		std::cin >> num;
	} while (num != 1 && num != 2);
	if (num == 2)
	{
		int index = -1;
		do {
			std::cout << "Please enter the number of the figure you want to delete: ";
			std::cin >> index;
		} while (index < 0 || index >= size);
		arr[index]->translateFig(horizontal, vertical);
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			arr[i]->translateFig(horizontal, vertical);
		}
	}
	std::cout << "Yay! Translation successful!" << std::endl;
}

void CommandExecutioner::executeWithinFigure()
{
}

void CommandExecutioner::addFigure()
{
	char figure[10];
	double x = 0, y = 0;
	std::cout << "What figure would you like to add: ";
	std::cin.getline(figure, 10);
	if (strcmp(figure, "circle") == 0)
	{
		double radius = 0;
		std::cout << "Please enter X: ";
		std::cin >> x;
		std::cout << "Please enter Y: ";
		std::cin >> y;
		std::cout << "Please enter the radius of the circle: ";
		std::cin >> radius;
		arr.add(new Circle(x, y, radius));
	}
	else if (strcmp(figure, "rectangle") == 0)
	{
		double width = 0;
		double height = 0;
		std::cout << "Please enter X: ";
		std::cin >> x;
		std::cout << "Please enter Y: ";
		std::cin >> y;
		std::cout << "Please enter the width of the rectangle: ";
		std::cin >> width;
		std::cout << "Please enter the height of the rectangle: ";
		std::cin >> height;
		arr.add(new Rectangle(x, y, width, height));
	}
	else if (strcmp(figure, "line") == 0)
	{
		std::cout << "Please enter X: ";
		std::cin >> x;
		std::cout << "Please enter Y: ";
		std::cin >> y;
		arr.add(new Line(x, y));
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Figure not found. Try again later!" << std::endl;
		return;
	}
	std::cout << "The " << figure << " was successfully added!" << std::endl;
	std::cin.ignore(1);
}

void CommandExecutioner::removeFigure()
{
	int index = -1;
	do {
		std::cout << "Please enter the number of the figure you want removed: ";
		std::cin >> index;
	} while (index<0 || index>arr.getCurrSize());
	arr.removeAt(index);
	std::cout << "The figure was successfully removed!" << std::endl;
	//std::cin.ignore(1);
}

void CommandExecutioner::printAll()
{
	int size = arr.getCurrSize();
	for (int i = 0; i < size; i++)
	{
		arr[i]->print();
	}
	std::cout << std::endl;
}

void CommandExecutioner::EndProgram()
{

}
