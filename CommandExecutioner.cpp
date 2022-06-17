#include "CommandExecutioner.h"
#include<iostream>

void CommandExecutioner::remove()
{
	for (int i = 0; i < arr.getCurrSize(); i++)
	{
		delete arr[i];
	}
}

CommandExecutioner::CommandExecutioner()
{
	arr = Vector<Figure*>();
}

CommandExecutioner::CommandExecutioner(const CommandExecutioner& other)
{
	for (int i = 0; i < other.arr.getCurrSize(); i++)
	{
		this->arr[i] = other.arr[i];
	}
}

CommandExecutioner& CommandExecutioner::operator=(const CommandExecutioner& other)
{
	if (this != &other)
	{
		remove();
		for (int i = 0; i < other.arr.getCurrSize(); i++)
		{
			this->arr[i] = other.arr[i];
		}
	}
	return *this;
}

void CommandExecutioner::start()
{
	char command[16] = "-1";
	int commandCode = 0;
	Commands::printCommands();
	std::cout << "What would you like to do: ";
	std::cin.getline(command, 16);
	do
	{
		commandCode = Commands::getCommand(command);
		if (commandCode == 0)
		{
			InvalidCommandMessage();
		}
		else if (commandCode == 1)
		{
			executeTranslation();
		}
		else if (commandCode == 2)
		{
			addFigure();
		}
		else if (commandCode == 3)
		{
			removeFigure();
		}
		else if (commandCode == 4)
		{
			executeWithinFigure();
		}
		else if (commandCode == 5)
		{
			printAll();
		}
		else if (commandCode == 7)
		{
			Commands::printCommands();
		}
		if (commandCode == 6)
		{
			EndProgram();
			break;
		}
		std::cout << "What would you like to do: ";
		std::cin.getline(command, 16);

	} while (commandCode != 6);
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
			std::cout << "Please enter the number of the figure you want to translate: ";
			std::cin >> index;
		} while (index < 0 || index > size);
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

	// x and y for circle - the coordinates of the center
	// x and y for rectangle - the coordinates of the top left corner
	char figure[10]="\0";
	do {
		std::cout << "Please enter the figure, which you would like to check whats inside for (be aware, the figure can be either circle or rectangle): ";
		std::cin.getline(figure, 10);
	} while (strcmp(figure, "circle") != 0 || strcmp(figure, "rectangle") != 0);

	int size = arr.getCurrSize();

	double x = 0, y = 0;
	std::cout << "Please enter X-axis: ";
	std::cin >> x;
	std::cout << "Please enter Y-axis: ";
	std::cin >> y;
	if (strcmp(figure, "circle") == 0)
	{
		double radius = 0;
		std::cout << "Please enter the radius: ";
		std::cin >> radius;

		for (int i = 0; i < size; i++)
		{
			if (arr[i]->withinCircle(x, y, radius))
			{
				arr[i]->print();
			}
		}

	}
	else if (strcmp(figure, "rectangle") == 0)
	{
		double height = 0, width = 0;
		std::cout << "Please enter the height of the rectangle: ";
		std::cin >> height;
		std::cout << "Please enter the width of the rectangle: ";
		std::cin >> width;

		for (int i = 0; i < size; i++)
		{
			if (arr[i]->withinRectangle(x, y, height, width))
			{
				arr[i]->print();
			}
		}

	}

}

void CommandExecutioner::addFigure()
{
	char figure[10];
	double x = 0, y = 0;
	std::cout << "What figure would you like to add: ";
	std::cin.getline(figure, 10);
	if (strcmp(figure, "circle") == 0 || strcmp(figure, "Circle") == 0)
	{
		double radius = 0;
		std::cout << "Please enter X: ";
		std::cin >> x;
		std::cout << "Please enter Y: ";
		std::cin >> y;
		std::cout << "Please enter the radius of the circle: ";
		std::cin >> radius;
		arr.add(new Circle(x, y, radius, figure));
	}
	else if (strcmp(figure, "rectangle") == 0 || strcmp(figure, "Rectangle") == 0)
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
		arr.add(new Rectangle(x, y, width, height, figure));
	}
	else if (strcmp(figure, "line") == 0 || strcmp(figure, "Line") == 0)
	{
		double xEnd = 0;
		double yEnd = 0;
		std::cout << "Please enter X: ";
		std::cin >> x;
		std::cout << "Please enter Y: ";
		std::cin >> y;
		std::cout << "Please enter X, which is the coordinate of the end point: ";
		std::cin >> xEnd;
		std::cout << "Please enter Y, which is the coordinate of the start point: ";
		std::cin >> yEnd;
		arr.add(new Line(x, y, xEnd, yEnd, figure));
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
	} while (index<=0 || index>arr.getCurrSize());
	arr.removeAt(++index);
	std::cout << "The figure was successfully removed!" << std::endl;
	std::cin.ignore(1);
}

void CommandExecutioner::printAll()
{
	int size = arr.getCurrSize();
	if (size == 0) {
		std::cout << "No figures found! You can add a figure, using the command \"Add\" :)" << std::endl;
		return;
	}
	int i = 0;
	for (i = 0; i < size-1; i++)
	{
		arr[i]->print();
		std::cout << std::endl;
	}
	if (i == size - 1)
	{
		arr[i]->print();
	}
}

void CommandExecutioner::EndProgram()
{
	std::cout << "Thank you for using the program! See you next time :)" << std::endl;
	return;
}
