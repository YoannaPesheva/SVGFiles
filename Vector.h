#pragma once
#include<iostream>

template<typename T>
class Vector {
private:
	T* dynArr;
	int currSize;
	int capacity;
	bool reallocate()
	{
		capacity *= 2;
		T* temporary = new T[capacity];
		if (temporary == nullptr)
		{
			std::cout << "There was a problem allocating the needed memory!" << std::endl;
			return false;
		}
		for (int i = 0; i < currSize; i++) temporary[i] = dynArr[i];
		delete[] dynArr;
		dynArr = temporary;
		return true;
	}
	void copyAll(const Vector& other)
	{
		capacity = other.capacity;
		currSize = other.currSize;
		dynArr = new T[capacity];
		for (int i = 0; i < currSize; i++)
		{
			dynArr[i] = other.dynArr[i];
		}
	}

public:
	//big4
	Vector()
	{
		capacity = 16;
		currSize = 0;
		dynArr = new T[capacity];
	}
	Vector(const Vector<T>& other)
	{
		copyAll(other);
	}
	Vector<T>& operator=(const Vector<T>& other)
	{
		if (this != &other)
		{
			delete[] dynArr;
			copyAll(other);
		}
		return *this;
	}
	~Vector()
	{
		delete[] dynArr;
		_CrtDumpMemoryLeaks();
	}
	//endOfBig4

	//redefining operator []
	T& operator [](int index) { return dynArr[index]; }
	const T operator[](int index) const { return dynArr[index]; }

	//add item
	bool add(const T& el)
	{
		if (capacity == currSize)
		{
			return reallocate();
		}
		dynArr[currSize++] = el;
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
			std::swap(dynArr[i], dynArr[i + 1]);
		}
		pop();

	}

	T getAt(int index)
	{
		return dynArr[index];
	}

	const int getCurrSize() const
	{
		return currSize;
	}
};