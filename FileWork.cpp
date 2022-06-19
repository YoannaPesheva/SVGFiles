#include "FileWork.h"
#include<fstream>
#include<iostream>
#include "Vector.h"


void FileWork::saveChanges(ShapesContainer& arr)
{

}

void FileWork::openFile(ShapesContainer& arr)
{
	std::fstream MyFile(name.c_str());
	if (!MyFile.is_open())
	{
		std::cout << "An error occured while trying to open to file!" << std::endl;
		return;
	}
	std::cout << "File successfully opened!" << std::endl;
	bool isEmpty = MyFile.peek() == EOF;
	if (!isEmpty)
	{

	}
}

void FileWork::closeFile()
{
	std::ofstream myFile(name.c_str());
	if (myFile.is_open())
	{
		myFile.close();
		std::cout << "File successfully closed!" << std::endl;
	}
	else std::cout << "Error! Please open a file, before trying to use this command!" << std::endl;
}

void FileWork::saveChangesAs(ShapesContainer& arr)
{
}
