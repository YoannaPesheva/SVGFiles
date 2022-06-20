#include "String.h"

void MyString::copyAll(const MyString& other)
{
    string = new char[strlen(other.string) + 1];
    strcpy_s(string, strlen(other.string)+1, other.string);
}

void MyString::free()
{
    delete[] string;
}

MyString::MyString()
{
    string = new char[1];
    string[0] = '\0';
}

MyString::MyString(const MyString& other)
{
    copyAll(other);
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other)
    {
        free();
        copyAll(other);
    }
    return *this;
}

MyString::~MyString()
{
    free();
}

int MyString::getSize() const
{
    return strlen(string);
}

void MyString::print() const
{
    std::cout << string;
}

std::ostream& operator<<(std::ostream& out, const MyString& str)
{
    out << str.string;
    return out;
}

std::istream& operator>>(std::istream& in, const MyString& str)
{
    in >> str;
    return in;
    
}
