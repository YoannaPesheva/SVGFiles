#include<iostream>
#include "Figures.h"
#include "Vector.h"
#include "CommandExecutioner.h"
#include<crtdbg.h>

int main()
{

	CommandExecutioner c;
	c.start();

	char command[16] = "-1";
	int commandCode;
	Commands::printCommands();
	std::cout << "What would you like to do: ";
	std::cin.getline(command, 16);
	do
	{
		commandCode = Commands::getCommand(command);
		if (commandCode == 0)
		{
			c.InvalidCommandMessage();
		}
		else if (commandCode == 1)
		{
			c.executeTranslation();
		}
		else if (commandCode == 2)
		{
			c.addFigure();
		}
		else if (commandCode == 3)
		{
			c.removeFigure();
		}
		else if (commandCode == 4)
		{
			c.executeWithinFigure();
		}
		else if (commandCode == 5)
		{
			c.printAll();
		}
		else if (commandCode == 7)
		{
			Commands::printCommands();
		}
		if (commandCode == 6)
		{
			c.EndProgram();
			break;
		}
		std::cout << "What would you like to do: ";
		std::cin.getline(command, 16);

	} while (commandCode != 6);

	return 0;
}