#include<iostream>
#include<stdio.h>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);

//#define DEBUG

class Fraction
{
	int integer; //Целая часть 
	int numerator; //Числитель
	int denominator; //Знаминатель
private:
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	Fraction(double decimal)
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
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
#ifdef DEBUG
		cout << "DefaultConstructor: " << this << endl;
#endif // DEBUG
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
#ifdef DEBUG
		cout << "SingleArgumentConstructor: " << this << endl;
#endif // DEBUG
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
#ifdef DEBUG
		cout << "Constructor:\t\t" << this << endl;
#endif // DEBUG
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
#ifdef DEBUG
		cout << "Constructor:\t" << this << endl;
#endif // DEBUG
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
#ifdef DEBUG
		cout << "CopyConstructor:\t" << this << endl;
#endif // DEBUG
	}
	~Fraction()
	{
#ifdef DEBUG
		cout << "Destructor:\t\t" << this << endl;
#endif // DEBUG 
	}

	//operators
	Fraction& operator = (const Fraction& other)
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
	Fraction to_propper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
		/*Fraction copy = *this;
		copy.integer += copy.numerator / copy.denominator;
		copy.numerator %= copy.denominator;
		return copy;*/
	}
	Fraction to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
		/*Fraction copy = *this;
		copy.numerator += copy.integer * copy.denominator;
		copy.integer = 0;
		return copy;*/
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator); // функция swap две переменные местами
		return inverted;
	}
	Fraction& reduce()
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
	Fraction& operator*= (const Fraction& other)
	{
		return *this = *this * other;
#ifdef DEBUG
		cout << "Operator *= " << this << endl;
#endif // DEBUG
	}
	Fraction operator/= (const Fraction& other)
	{
		return *this = *this / other;
#ifdef DEBUG
		cout << "Operator /= " << this << endl;
#endif // DEBUG
	}
	Fraction operator+= (const Fraction& other)
	{
		return *this /= other;
#ifdef DEBUG
		cout << "Operator += " << this << endl;
#endif // DEBUG
	}
	Fraction operator-= (const Fraction& other)
	{
		return *this -= other;
#ifdef DEBUG
		cout << "Operator -= " << this << endl;
#endif // DEBUG
	}
	Fraction& operator++()
	{
		this->integer++;
		return *this;
	}
	Fraction& operator++(int)
	{
		Fraction nThis = *this;
		this->integer++;
		return nThis;
	}
	Fraction& operator--()
	{
		this->integer--;
		return *this;
	}
	Fraction& operator--(int)
	{
		Fraction nThis = *this;
		this->integer--;
		return nThis;
	}

	explicit operator int()const
	{
		return integer;
	}
	explicit operator double()const
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
	void Print()const
	{
		cout << integer << "(" << numerator << "/" << denominator << ")" << endl;
	}
};

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

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS
//#define COMPAUND_ASSIGNMENTS
//#define INCREMENT_CHECK
//#define COMPARISON_OPERATORS

void main()
{
	setlocale(0, "Rus");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.Print();
	cout << A << endl;
	Fraction B = 5;
	B.Print();
	cout << B << endl;
	Fraction C (1, 2);
	C.Print();
	cout << C << endl;
	Fraction D(3, 4, 5);
	D.Print();
	cout << D << endl;
#endif // CONSTRUCTORS_CHECK
#ifdef ARITHMETICAL_OPERATORS
	//Fraction A(11, 4);
	//cout << A << " = " << A.to_propper() << " = " << A.to_improper() << endl;

	//int numerator, denominator;
	//cout << "Введите дробь!" << "\nЧислитель: "; cin >> numerator; 
	//cout << "Знаменатель: "; cin >> denominator;
	//Fraction B(numerator, denominator);
	//cout << "Ответ: " << B.reduce() << endl;

	Fraction A(11, 4);
	Fraction B(5, 6, 7);
	{
		cout << "Числа: \n" << A << " и " << B << endl;

		cout << "Plus: " << endl;
		Fraction C(A + B);
		cout << C << " = " << C.to_propper() << endl;

		cout << "Minus" << endl;
		Fraction D(A - B);
		cout << D << " = " << D.to_propper() << endl;

		cout << "multiply" << endl;
		Fraction F(A * B);
		cout << F << " = " << F.to_propper() << endl;

		cout << "divide" << endl;
		Fraction G(A / B);
		cout << G << " = " << G.to_propper() << endl;
	}
#endif // ARITHMETICAL_OPERATORS
#ifdef COMPAUND_ASSIGNMENTS
	double a = 2;
	double b = 3;
	a *= 3;
	Fraction A(11, 4);
	Fraction B(5, 6, 7);
	cout << A << "\t" << B << endl;
	A *= B;
	cout << A << endl;
	A /= B;
	cout << A << endl;
	cout << A - A << endl;
#endif // COMPAUND_ASSIGNMENTS
#ifdef INCREMENT_CHECK
	Fraction A(10, 5);
	Fraction B(11, 5);
	int luck = 0;
	int dontLuck = 0;
	if (A == A) luck++;
	else dontLuck++;
	if (A != B) luck++;
	else dontLuck++;
	if (A <= B) luck++;
	else dontLuck++;
	if (A >= A) luck++;
	else dontLuck++;
	if (A < B) luck++;
	else dontLuck++;
	if (A > 0) luck++;
	else dontLuck++;
	cout << "WORK: " << luck << endl << "DONTWORK: " << dontLuck << endl;
	Fraction C(1, 1);
	C++;
	cout << C << endl;
	C--;
	cout << C << endl;

	for (double i = .3; i < 10; i++)
		cout << i << '\t';
	cout << endl;
	for (Fraction i(3, 4); i.get_integer() < 10; i++)
		cout << i << '\t';
	cout << endl;
#endif // INCREMENT_CHECK
#ifdef COMPARISON_OPERATORS
	Fraction A(1, 2);
	Fraction B(5, 10);
	/*if (A == B) cout << "Дроби равны!" << endl;
	else cout << "Дроби разные!" << endl;*/
	cout << A << "\t" << B << endl;
	if (A == B) printf("+\n"); else printf("-\n");
	if (A != 0) printf("+\n"); else printf("-\n");
	cout << A << "\t" << B << endl;
#endif // COMPARISON_OPERATORS

	//Fraction A = (Fraction)5; // из int в fraction - одиночный конструктор
	Fraction A(5); // explicit конструктор можно вызвать только так, и невозможно вызвать операторм =
	cout << A << endl;
	A = Fraction(8); // копия
	cout << A << endl;
	Fraction B(3, 4, 5);
	double b = (double)B;
	cout << b << endl;

	Fraction C = 2.5;
	Fraction G = 2.55;
	Fraction K = 25;
	cout << C << endl;
	cout << G << endl;
	cout << K << endl;
}