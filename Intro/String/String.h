#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;

#define DEBUG

//////////////////////////////////////////////////////////
//CLASS DECLARATION - ОБЬЯВЛЕНИЕ КЛАССА///////////////////

class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);

class String
{
	char* str; // Указатель на строку в динамической памяти
	int size; // Размер строки в Байтах
public:
	const char* get_str()const;
	char* get_str();
	int get_size()const;
	char& operator[](int index);
	const char& operator[](int index)const;

	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator +=(const String& other);

	void Print()const;
};

//////////////////////////////////////////////////////////
//CLASS DECLARATION END //////////////////////////////////