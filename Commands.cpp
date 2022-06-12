#include "Commands.h"
#include<iostream>

//const we will work with
const int INVALID_COMMAND = 0;
const int TRANSLATE = 1;
const int ADD_A_FIGURE = 2;
const int REMOVE_A_FIGURE = 3;
const int WITHIN = 4;
const int PRINT = 5;
const int END_SESSION = 6;
const int GET_HELP = 7;


void Commands::printCommands()
{
	std::cout << "List of Commands: " << std::endl;
	std::cout << "1. Translate." << std::endl;
	std::cout << "2. Add(a figure)." << std::endl;
	std::cout << "3. Remove(a figure)." << std::endl;
	std::cout << "4. Within(find all the figures within a shape." << std::endl;
	std::cout << "5. Prints all the figures." << std::endl;
	std::cout << "6. End(the session)." << std::endl;
	std::cout << "7. Help(prints the commands again)." << std::endl;
}

int Commands::getCommand(const char* command)
{
	if (strcmp(command, "Translate") == 0 || strcmp(command, "translate") == 0)
	{
		return TRANSLATE;
	}
	else if (strcmp(command, "Add") == 0 || strcmp(command, "add") == 0)
	{
		return ADD_A_FIGURE;
	}
	else if (strcmp(command, "Remove") == 0 || strcmp(command, "remove") == 0)
	{
		return REMOVE_A_FIGURE;
	}
	else if (strcmp(command, "Within") == 0 || strcmp(command, "within") == 0)
	{
		return WITHIN;
	}
	else if (strcmp(command, "Print") == 0 || strcmp(command, "print") == 0)
	{
		return PRINT;
	}
	else if (strcmp(command, "End") == 0 || strcmp(command, "end") == 0)
	{
		return END_SESSION;
	}
	else if (strcmp(command, "Help") == 0 || strcmp(command, "help") == 0)
	{
		return GET_HELP;
	}
	else
	{
		return INVALID_COMMAND;
	}
}