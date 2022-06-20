#define _CRT_SECURE_NO_WARNINGS
#include "Figures.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Vector.h"
#include "FileWork.h"

#include<fstream>
#include<iostream>

 void FileWork::saveChanges(ShapesContainer& arr)
{
	if (isFileOpen)
	{
		std::ofstream MyFile(name.c_str());
		MyFile << arr;
		MyFile.close();
		isFileOpen = false;
		std::cout << "Successfully saved the changes in " << name << "."<<std::endl;
	}
	else
	{
		std::cout << "This command requires an open file. Please open one before trying to save the changes there!" << std::endl;
	}
}

 void FileWork::saveChangesAs(ShapesContainer& arr, std::string name)
{
	 if (isFileOpen)
	 {
		 std::cout << "Please enter the name of the file you want to save the changes into: ";
		 std::string nameNew;
		 std::cin >> nameNew;
		 std::ofstream MyFile(name.c_str());
		 MyFile << arr;
		 MyFile.close();
		 std::ofstream prevFile(name.c_str());
		 prevFile.close();
		 isFileOpen = false;
	 }
	 else
	 {
		 std::cout << "This command requires an open file. Please open one before trying to save the changes there!" << std::endl;
	 }
}

bool isShapeValid(char* shape)
{
	if (strcmp(shape, "circle") == 0 || strcmp(shape, "rect") == 0 || strcmp(shape, "line") == 0)
		return true;
	return false;
}


int FileWork::getIndex(std::string line, int &index, char symbol)
{
	while (line[index] != symbol)
	{
		index++;
	}
	return ++index;
}

char* FileWork::subString(std::string line, int &index, char symbol)
{
	char buffer[30] = "\0";
	int j = 0;
	while (line[index] != symbol)
	{
		buffer[j] = line[index];
		index++;
		j++;
	}
	index += 2;
	return buffer;
}

void FileWork::openFile(ShapesContainer& arr)
{
	std::ifstream MyFile(name.c_str()); // std::fstream::out, because fstream wont create a new file otherwise
	if (!MyFile.is_open())
	{
		std::cout << "An error occured while trying to open to file!" << std::endl;
		return;
	}
	std::cout << "File successfully opened!" << std::endl;
	isFileOpen = true;
	bool isEmpty = MyFile.peek() == EOF;
	if (!isEmpty)
	{
		std::string line="";
		std::string opTag = "<svg>";
		while (!MyFile.eof() && opTag!=line)
		{
			std::getline(MyFile, line);
		}
		if (MyFile.eof()) {
			std::cout << "No SVG text found in the file!" << std::endl;
			return;
		}
		else {
			std::getline(MyFile, line);
			do {
				int index = 1;
				char buff[20] = " ";
				char shape[20] = "";
				double x, y;
				char colour[20] = "";
				int colourIndex = 0;
				strcpy(shape, subString(line, index, ' '));
				if (!isShapeValid(shape))
				{
					std::cout << "Invalid shape!" << std::endl;
					std::getline(MyFile, line);
					if (MyFile.eof()) break;
					continue;
				}

				int xIndex = getIndex(line, index, '\"');
				strcpy(buff, subString(line, xIndex, '\"'));
				x = std::atof(buff);
				index = xIndex;

				int yIndex = getIndex(line, index, '\"');
				strcpy(buff, subString(line, yIndex, '\"'));
				y = std::atof(buff);
				index = yIndex;


				if (strcmp(shape, "circle")==0)
				{	
					double radius = 0;
					int rIndex = getIndex(line, index, '\"');
					strcpy(buff, subString(line, index, '\"'));
					radius = std::atof(buff);
					
					colourIndex = getIndex(line, index, '\"');
					strcpy(buff, subString(line, index, '\"'));
					strcpy(colour, buff);
					arr.add(new Circle(x, y, radius, colour));
				}

				else if(strcmp(shape, "line")==0)
				{
					double x1 = 0;
					int x1Index = getIndex(line, index, '\"');
					strcpy(buff, subString(line, index, '\"'));
					x1 = std::atof(buff);

					double y1 = 0;
					int y1Index = getIndex(line, index, '\"');
					strcpy(buff, subString(line, index, '\"'));
					y1 = std::atof(buff);

					colourIndex = getIndex(line, index, '\"');
					strcpy(buff, subString(line, index, '\"'));
					strcpy(colour, buff);
					arr.add(new Line(x, y, x1, y1, colour));
				}
				else if (strcmp(shape,"rect")==0)
				{
					double width = 0;
					int widthIndex = getIndex(line, index, '\"');
					strcpy(buff, subString(line, index, '\"'));
					width = std::atof(buff);

					double height = 0;
					int heightIndex = getIndex(line, index, '\"');
					strcpy(buff, subString(line, index, '\"'));
					height = std::atof(buff);

					colourIndex = getIndex(line, index, '\"');
					strcpy(buff, subString(line, index, '\"'));
					strcpy(colour, buff);
					arr.add(new Rectangle(x, y, width, height, colour));
					
				}
				std::getline(MyFile, line);
			} while (!MyFile.eof() && line!="</svg>");
		}
	}
}

void FileWork::closeFile()
{
	std::ifstream myFile(name.c_str());
	if (myFile.is_open())
	{
		myFile.close();
		std::cout << "File successfully closed!" << std::endl;
		isFileOpen = false;
	}
	else std::cout << "Error! Please open a file, before trying to use this command!" << std::endl;
}

