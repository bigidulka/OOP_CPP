#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;

#define DEBUG

class String;
String operator+(const String& left, const String& right);

class String
{
	char* str; // Указатель на строку в динамической памяти
	int size; // Размер строки в Байтах
public:
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	int get_size()const
	{
		return size;
	}
	char& operator[](int index)
	{
		return str[index];
	}
	const char& operator[](int index)const
	{
		return str[index];
	}

	explicit String(int size = 80):size(size), str(new char[size] {})
	{
		//this->size = size;
		//this->str = new char[size] {};
#ifdef DEBUG
		cout << (size == 80 ? "Default" : "Size") << "DefaultConstuctor:\t\t" << this << endl;
#endif // DEBUG
	}
	String(const char* str) :String(strlen(str) + 1)
	{
		//this->size = strlen(str) + 1;
		//this->str = new char[size] {};
		strcpy(this->str, str);
#ifdef DEBUG
		cout << "Constructor:\t\t\t" << this << endl;
#endif // DEBUG
	}
	String(const String& other):String(other.str)
	{
		//this->size = other.size;
		//this->str = new char[size] {};
		strcpy(this->str, other.str);
#ifdef DEBUG
		cout << "CopyConstructor:\t\t" << this << endl;
#endif // DEBUG
	}
	String(String&& other):size(other.size), str(other.str)
	{
		//this->size = other.size;
		//this->str = other.str;
		other.str = nullptr;
#ifdef DEBUG
		cout << "MoveConstructor:\t\t" << this << endl;
#endif // DEBUG
	}
	~String()
	{
		delete[] this->str;
#ifdef DEBUG
		cout << "Destructor:\t\t\t" << this << endl;
#endif // DEBUG 
	}

	String& operator=(const String& other)
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
	String& operator=(String&& other)
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
	String& operator +=(const String& other)
	{
		return *this = *this + other;
	}

	void Print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
		//for (int i = 0; i < size; i++) cout << (int)str[i]; cout << endl;
	}
};

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

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
#define OPERATOR_PLUS_CHECK

void main()
{
	setlocale(0, "");
#ifdef CONSTRUCTORS_CHECK
	String str;
	str.Print();

	String str2 = "Hello";
	str2.Print();
	cout << str2 << endl;

	String str3 = str2; // CopyConstructor
	cout << "Str3:\t" << str3 << endl;

	String str4;
	str4 = str3; // CopyAsssignment
	cout << "Str4:\t" << str4 << endl;
#endif // CONSTRUCTORS_CHECK
#ifdef ASSIGNMENT_CHECK
	String str1 = "Hello";
	String str2;
	str1 = str1;
	cout << str1 << endl;
	cout << str2 << endl;
#endif // ASSIGNMENT_CHECK
#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	String str3;
	//String str3 = str1 + str2; // Опреатор + будет выполнять конкатенацию строк
	str1 += str2;
	cout << str1 << endl;
#endif // OPERATOR_PLUS_CHECK

	//String str1;		//DefaultConstructor
	//String str2();		//Объявляется функция str2, которая ничего не принимает, и возвращает значение типа String
	//String str3{};		//DefaultConstructor
	//String str4(5);		//SizeConstructor
	//String str5{ 8 };
	//String str6("Hello");
	//String str7	{ "Hello" };
	//String str8 = 18;	//Неявное преобразование int в String
}