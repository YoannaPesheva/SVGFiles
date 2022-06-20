#pragma once
#include "Vector.h"
#include "Figures.h"

#include<iostream>
#include<fstream>
#include<string>

class FileWork
{
	std::string name;
	bool isFileOpen;
public:
	FileWork()
	{
		isFileOpen = false;
	}

	std::string const getName() const { return name; }
	void setName(std::string _name) { name = _name; }

	bool const getIsOpen() const { return isFileOpen; }
	void setIsOpen(bool statement) { isFileOpen = statement; }
	

	void saveChanges(ShapesContainer& arr);
	void openFile(ShapesContainer& arr);
	void closeFile();
	void saveChangesAs(ShapesContainer& arr, std::string name);


	//bool areTagsValid();

	char* subString(std::string line, int& index, char symbol);
	int getIndex(std::string line, int& index, char symbol);

};;