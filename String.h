#include<iostream>

class MyString {
private:
	char* string;
	void copyAll(const MyString& other);
	void free();
	
public:
	MyString();
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	MyString(const char* str);

	int getSize() const;
	void print() const;
	MyString& subString(int index, char symbol);
	
	friend std::ostream& operator <<(std::ostream& out, const MyString& str);
	friend std::istream& operator >>(std::istream& in, const MyString& str);

};