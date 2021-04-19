#include"String.h"

//////////////////////////////////////////////////////////
//CLASS DEFINITION - ОПРЕДЕЛЕНИЕ КЛАССА///////////////////

const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
int String::get_size()const
{
	return size;
}
char& String::operator[](int index)
{
	return str[index];
}
const char& String::operator[](int index)const
{
	return str[index];
}

String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
#ifdef DEBUG
	cout << (size == 80 ? "Default" : "Size") << "DefaultConstuctor:\t\t" << this << endl;
#endif // DEBUG
}
String::String(const char* str) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};
	strcpy(this->str, str);
#ifdef DEBUG
	cout << "Constructor:\t\t\t" << this << endl;
#endif // DEBUG
}
String::String(const String& other) :String(other.str)
{
	//this->size = other.size;
	//this->str = new char[size] {};
	strcpy(this->str, other.str);
#ifdef DEBUG
	cout << "CopyConstructor:\t\t" << this << endl;
#endif // DEBUG
}
String::String(String&& other) :size(other.size), str(other.str)
{
	//this->size = other.size;
	//this->str = other.str;
	other.str = nullptr;
#ifdef DEBUG
	cout << "MoveConstructor:\t\t" << this << endl;
#endif // DEBUG
}
String::~String()
{
	delete[] this->str;
#ifdef DEBUG
	cout << "Destructor:\t\t\t" << this << endl;
#endif // DEBUG 
}

String& String::operator=(const String& other)
{
	// 0) Проверить не является ли другой объект самим собой
	if (this == &other) return *this;
	// 1) Сначала удаляем старое значение объекта
	delete[] this->str;
	// 2) И только потом присваимваем ему новое значение
	this->size = other.size;
	this->str = new char[size] {};
	strcpy(this->str, other.str);
#ifdef DEBUG
	cout << "CopyAssignment:\t\t" << this << endl;
#endif // DEBUG
	return *this;
}
String& String::operator=(String&& other)
{
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
#ifdef DEBUG
	cout << "MoveAssignment:\t\t" << this << endl;
#endif // DEBUG
	return *this;
}
String& String::operator +=(const String& other)
{
	return *this = *this + other;
}

void String::Print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
	//for (int i = 0; i < size; i++) cout << (int)str[i]; cout << endl;
}

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		result[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		result[i + left.get_size() - 1] = right[i];
	}
	return result;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//////////////////////////////////////////////////////////
//CLASS DEFINITION END ///////////////////////////////////