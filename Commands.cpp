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
const int OPEN_FILE = 8;
const int CLOSE_FILE = 9;
const int SAVE_FILE = 10;
const int SAVE_FILE_AS = 11;


void Commands::printCommands()
{
	std::cout << "List of Commands: " << std::endl;
	std::cout << "1. File Commands: " << std::endl;
	std::cout << "	1.1. Open(a file and get the information from it)." << std::endl;
	std::cout << "	1.2. Close(a file WITHOUT saving the changes)." << std::endl;
	std::cout << "	1.3. Save(the changes you made in the same file)." << std::endl;
	std::cout << "	1.4. SaveAs(save the changes in a new file with a name of your choice)." << std::endl;
	std::cout << std::endl;
	std::cout << "2. Commands concerning the figures: " << std::endl;
	std::cout << "	2.1. Translate." << std::endl;
	std::cout << "	2.2. Add(a figure)." << std::endl;
	std::cout << "	2.3. Remove(a figure)." << std::endl;
	std::cout << "	2.4. Within(find all the figures within a shape)." << std::endl;
	std::cout << "	2.5. Print(prints all the figures)." << std::endl;
	std::cout<<std::endl;
	std::cout << "3. End(the session)." << std::endl;
	std::cout << "4. Help(prints the commands again)." << std::endl;
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
	else if (strcmp(command, "Open") == 0 || strcmp(command, "open") == 0)
	{
		return OPEN_FILE;
	}
	else if (strcmp(command, "Close") == 0 || strcmp(command, "close") == 0)
	{
		return CLOSE_FILE;
	}
	else if (strcmp(command, "Save") == 0 || strcmp(command, "save") == 0)
	{
		return SAVE_FILE;
	}
	else if (strcmp(command, "SaveAs") == 0 || strcmp(command, "saveAs") == 0)
	{
		return SAVE_FILE_AS;
	}
	else
	{
		return INVALID_COMMAND;
	}
}