#pragma once
#include<iostream>
#include "Figures.h"


class ShapesContainer {
private:
	Figure** shapes;
	int currSize;
	int capacity;
	bool reallocate()
	{
		capacity *= 2;
		Figure** temporary = new Figure * [capacity];
		if (temporary == nullptr)
		{
			std::cout << "There was a problem allocating the needed memory!" << std::endl;
			return false;
		}
		for (int i = 0; i < currSize; i++) temporary[i] = shapes[i];
		delete[] shapes;
		shapes = temporary;
		temporary = nullptr;
		return true;
	}
	void copyAll(const ShapesContainer& other)
	{
		capacity = other.capacity;
		currSize = other.currSize;
		shapes = new Figure * [capacity];
		for (int i = 0; i < currSize; i++)
		{
			shapes[i] = other.shapes[i]->clone();
		}
	}

	void free()
	{
		for (int i = 0; i < currSize; i++)
		{
			delete shapes[i];
		}
		delete[] shapes;
	}

public:
	//big4
	ShapesContainer()
	{
		capacity = 16;
		currSize = 0;
		shapes = new Figure * [capacity];
	}
	ShapesContainer(const ShapesContainer& other)
	{
		copyAll(other);
	}
	ShapesContainer& operator=(const ShapesContainer& other)
	{
		if (this != &other)
		{
			free();
			copyAll(other);
		}
		return *this;
	}
	~ShapesContainer()
	{
		free();
		_CrtDumpMemoryLeaks();
	}
	//endOfBig4

	//redefining operator []
	Figure*& operator [](int index) { return shapes[index]; }
	const Figure* operator[](int index) const { return shapes[index]; }

	//add item
	bool add(Figure* el)
	{
		if (capacity == currSize)
		{
			return reallocate();
		}
		shapes[currSize++] = el;
		return true;
	}

	void pop()
	{
		currSize--;
	}

	void removeAt(int index)
	{
		for (int i = index; i < currSize - 1; i++)
		{
			std::swap(shapes[i], shapes[i + 1]);
		}
		delete shapes[currSize - 1];////added
		pop();

	}

	Figure* getAt(int index)
	{
		return shapes[index];
	}

	const int getCurrSize() const
	{
		return currSize;
	}

};
