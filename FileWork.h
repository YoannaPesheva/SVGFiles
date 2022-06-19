#pragma once
#include "Vector.h"
#include "Figures.h"
#include<iostream>
#include<fstream>
#include<string>

class FileWork
{
	std::string name;
public:

	std::string const getName() const { return name; }
	void setName(std::string _name) { name = _name; }

	void saveChanges(ShapesContainer& arr);
	void openFile(ShapesContainer& arr);
	void closeFile();
	void saveChangesAs(ShapesContainer& arr);


	bool areTagsValid();

};;