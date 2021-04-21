#pragma once
#include<iostream>
#include<stdio.h>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
ostream& operator<< (ostream& os, const Fraction& obj);

//#define DEBUG

class Fraction
{
	int integer; //Целая часть 
	int numerator; //Числитель
	int denominator; //Знаминатель
private:
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	Fraction(double decimal);
	Fraction();
	explicit Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();

	//operators
	Fraction& operator = (const Fraction& other);
	Fraction to_propper();
	Fraction to_improper();
	Fraction inverted()const;
	Fraction& reduce();
	Fraction& operator*= (const Fraction& other);
	Fraction operator/= (const Fraction& other);
	Fraction operator+= (const Fraction& other);
	Fraction operator-= (const Fraction& other);
	Fraction& operator++();
	Fraction& operator++(int);
	Fraction& operator--();
	Fraction& operator--(int);

	explicit operator int()const;
	explicit operator double()const;

	void Print()const;
};

Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);

void BringToCommon(Fraction& left, Fraction& right);
bool operator==(Fraction left, Fraction right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator>=(Fraction left, Fraction right);
bool operator<=(Fraction left, Fraction right);
bool operator>(Fraction left, Fraction right);
bool operator<(Fraction left, Fraction right);