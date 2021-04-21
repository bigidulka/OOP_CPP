#include"Fraction.h"

int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}

Fraction::Fraction(double decimal)
{
	/*this->integer = 0;
	double buffer = decimal - (int)decimal;
	for (int i = 0; i < 9; i++)
	{
		if (buffer == 0)
		{
			this->numerator = decimal;
			this->denominator = 1;
		}
		else
		{
			this->numerator = (decimal * 10);
			this->denominator = 10;
		}
	}*/
	decimal += 1e-15;
	integer = decimal;
	decimal -= integer;
	denominator = 1e+9;
	numerator = decimal * denominator;
	reduce();
}
Fraction::Fraction()
{
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
#ifdef DEBUG
	cout << "DefaultConstructor: " << this << endl;
#endif // DEBUG
}
Fraction::Fraction(int integer)
{
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
#ifdef DEBUG
	cout << "SingleArgumentConstructor: " << this << endl;
#endif // DEBUG
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	this->set_denominator(denominator);
#ifdef DEBUG
	cout << "Constructor:\t\t" << this << endl;
#endif // DEBUG
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	this->set_denominator(denominator);
#ifdef DEBUG
	cout << "Constructor:\t" << this << endl;
#endif // DEBUG
}
Fraction::Fraction(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
#ifdef DEBUG
	cout << "CopyConstructor:\t" << this << endl;
#endif // DEBUG
}
Fraction::~Fraction()
{
#ifdef DEBUG
	cout << "Destructor:\t\t" << this << endl;
#endif // DEBUG 
}

//operators
Fraction& Fraction::operator = (const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
#ifdef DEBUG
	cout << "CopyAssignment:\t" << this << endl;
#endif // DEBUG
	return *this;
}
//Fraction operator* (const Fraction& other)const
//{
//	Fraction left = *this;
//	Fraction right = other;
//	left.to_improper();
//	right.to_improper();
//	Fraction result
//	(
//		left.numerator * right.numerator,
//		left.denominator * right.denominator
//	);
//	result.to_propper();
//	return result;
//}
//Methods
Fraction Fraction::to_propper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
	/*Fraction copy = *this;
	copy.integer += copy.numerator / copy.denominator;
	copy.numerator %= copy.denominator;
	return copy;*/
}
Fraction Fraction::to_improper()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
	/*Fraction copy = *this;
	copy.numerator += copy.integer * copy.denominator;
	copy.integer = 0;
	return copy;*/
}
Fraction Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	swap(inverted.numerator, inverted.denominator); // функция swap две переменные местами
	return inverted;
}
Fraction& Fraction::reduce()
{
	/*if (numerator != 0 && denominator != 0)
	{
		Fraction copy = *this;
		int DEN = copy.denominator;
		int NUM = copy.numerator;
		int	OST = DEN % NUM;
		if (OST != 0)
		{
			DEN = NUM;
			NUM = OST;
			OST = DEN % NUM;
		}
		int NOD = NUM;
		if (NOD != 1)
		{
			copy.numerator /= NOD;
			copy.denominator /= NOD;
		}
		return copy;
	}*/
	if (numerator != 0 && denominator != 0)
	{
		int more, less, rest;
		if (numerator > denominator) more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;
		numerator /= GCD, denominator /= GCD;
	}
	return *this;
}
Fraction& Fraction::operator*= (const Fraction& other)
{
	return *this = *this * other;
#ifdef DEBUG
	cout << "Operator *= " << this << endl;
#endif // DEBUG
}
Fraction Fraction::operator/= (const Fraction& other)
{
	return *this = *this / other;
#ifdef DEBUG
	cout << "Operator /= " << this << endl;
#endif // DEBUG
}
Fraction Fraction::operator+= (const Fraction& other)
{
	return *this /= other;
#ifdef DEBUG
	cout << "Operator += " << this << endl;
#endif // DEBUG
}
Fraction Fraction::operator-= (const Fraction& other)
{
	return *this -= other;
#ifdef DEBUG
	cout << "Operator -= " << this << endl;
#endif // DEBUG
}
Fraction& Fraction::operator++()
{
	this->integer++;
	return *this;
}
Fraction& Fraction::operator++(int)
{
	Fraction nThis = *this;
	this->integer++;
	return nThis;
}
Fraction& Fraction::operator--()
{
	this->integer--;
	return *this;
}
Fraction& Fraction::operator--(int)
{
	Fraction nThis = *this;
	this->integer--;
	return nThis;
}

Fraction::operator int()const
{
	return integer;
}
Fraction::operator double()const
{
	return integer + (double)numerator / denominator;
}
//	Fraction& operator *= (const Fraction& other)
//	{
//		this->integer *= integer;
//		this->numerator *= numerator;
//		this->denominator *= denominator;
//#ifdef DEBUG
//		cout << "Operator *= " << this << endl;
//#endif // DEBUG
//		return *this;
//	}
	//методы
void Fraction::Print()const
{
	cout << integer << "(" << numerator << "/" << denominator << ")" << endl;
}

Fraction operator+(Fraction left, Fraction right)
{
	left.to_propper();
	right.to_improper();
	Fraction result;
	result.set_integer(left.get_integer() + right.get_integer());
	result.set_numerator(
		left.get_numerator() * right.get_denominator() +
		right.get_numerator() * left.get_denominator()
	);
	result.set_denominator(left.get_denominator() * right.get_denominator());
	result.to_propper();
	result.reduce();
	return result;
#ifdef DEBUG
	cout << "Global plus" << endl;
#endif // DEBUG
	return result;
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_propper();
	right.to_propper();
	Fraction result
	(
		left.get_integer() - right.get_integer(),
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	);
	result.to_propper();
	result.reduce();
	return result;

#ifdef DEBUG
	cout << "Global minus" << endl;
#endif // DEBUG
	return result;
}
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(

		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_propper().reduce();
}
Fraction operator/(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	).to_propper();*/
	return left * right.inverted();
}

ostream& operator<< (ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0) os << 0;
	return os;
}

void BringToCommon(Fraction& left, Fraction& right)
{
	left.set_numerator(left.get_numerator() * right.get_denominator());
	right.set_numerator(right.get_numerator() * left.get_denominator());
	left.set_denominator(left.get_denominator() * right.get_denominator());
	right.set_numerator(left.get_denominator());
}
bool operator==(Fraction left, Fraction right)
{
	/*Fraction BringToCommon();
	return (left.get_numerator() == right.get_numerator());*/
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
//bool operator!=(Fraction left, Fraction right)
//{
//	return !(left.get_numerator() == right.get_numerator());
//}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>=(Fraction left, Fraction right)
{
	Fraction BringToCommon();
	return (left.get_numerator() >= right.get_numerator());
}
bool operator<=(Fraction left, Fraction right)
{
	Fraction BringToCommon();
	return (left.get_numerator() <= right.get_numerator());
}
bool operator>(Fraction left, Fraction right)
{
	Fraction BringToCommon();
	return (left.get_numerator() > right.get_numerator());
}
bool operator<(Fraction left, Fraction right)
{
	Fraction BringToCommon();
	return (left.get_numerator() < right.get_numerator());
}