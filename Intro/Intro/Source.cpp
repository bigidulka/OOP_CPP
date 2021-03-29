#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
//#define intro
//#define CONST_CHECK
//#define assignment_check
//#define ARITHEMETICAL_OPERATORS

class Point
{
	double x, y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//constructors
	//Point()
	//{
	//	x = y = 0;
	//	cout << "DefConstructor:\t" << this << endl;
	//}
	//Point(double x)
	//{
	//	this->x = x;
	//	this->y = 0;
	//	cout << "SingleArgumentConstructor" << this << endl;
	//	//Конструктор с одним параметром отвечает за преобразование типов
	//}
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		//cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		//cout << "CopuCon:\t" << this << endl;
	}
	~Point()
	{
		//cout << "Destructor:\t" << this << endl;
	}
	//Operators
	Point& operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Point& operator += (const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		cout << "Operator += " << this << endl;
		return *this;
	}
	Point& operator -= (const Point& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		cout << "Operator -= " << this << endl;
		return *this;
	}
	//		Increment & Decrement
	Point& operator++()
	{
		this->x++;
		this->y++;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this;
		this->x++;
		this->y++;
		return old;
	}
	/*Point operator+(const Point& other)
	{
		Point result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		cout << "Operator + " << this << endl;
		return result;
	}*/
	//methdos
	void Print()const
	{
		cout << "X = " << x << '\t' << "Y = " << y << endl;
	}
};

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	cout << "Global plus" << endl;
	return result;
}
Point operator-(const Point& left, const Point& right)
{
	Point result
	(
		left.get_x() + right.get_x(),
		left.get_y() + right.get_y()
	);
	cout << "Global minus" << endl;
	return result;
}
Point operator*(const Point& left, const Point& right)
{
	cout << "Global multiply" << endl;
	return Point
	(
		left.get_x() * right.get_x(),
		left.get_y() * right.get_y()
	);
}
Point operator/(const Point& left, const Point& right)
{
	cout << "Global divide" << endl;
	return Point
	(
		left.get_x() / right.get_x(),
		left.get_y() / right.get_y()
	);
}
ostream& operator<<(ostream& os, const Point& obj)
{
	return os << "X = " << obj.get_x() << '\t' << "Y = " << obj.get_y();
}
void func(Point* p)
{
	cout << p->get_x() << '\t' << p->get_y() << endl;
}
void func(Point obj)
{
	cout << obj.get_x() << '\t' << obj.get_y() << endl;
}

// Создавая структуру или класс мы создаем новый тип данных
		// CLASS - это тип данных
		// STRUCT - это тип данных
//Обьекты класса или структуры являются переменными соответствующего типа
void main()
{

	setlocale(0, " ");

#ifdef intro
	int a;		// Объявляем перемненную a типа int
	Point A;	// Обьявляем переменную А типа Point
				// Создаем обьект А структуры Point
				//Создаем экземпляр А структуры Point
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << '\t' << A.get_y() << endl;

	Point* pA = &A;
	cout << pA->get_x() << '\t' << pA->get_y() << endl;
	cout << sizeof(A) << endl;
	cout << sizeof(pA) << endl;
	{
		//Безымяная область видимости внутри функции main
		//class obj;
	}
	//Здесь объекта obj уже не будет
	//cout << (*pA).x << '\t' << (*pA).x << endl;
#endif // intro
#ifdef CONST_CHECK
	Point A;	
	A.Print();
	Point B(2, 3);
	B.Print();

	Point C = 5;//Single argument constructor
	C.Print();
	Point D(8);//Single argument constructor
	D.Print();
	Point E{ 13 }; //Single argument constructor
	E.Print();

	Point F = B;
	F.Print();
	Point G;
	G = F; //CopyAssignment (operator=)

	//int b(8);
	//cout << int() << endl; // Деф конструктор для типа int => 0
	/*int c{ 5 };
	cout << c << endl;
	cout << int{} << endl;*/ // Значение по умолчанию для 'int'
#endif // CONST_CHECK
#ifdef assignment_check
	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	A = B = C = Point();
#endif // assignment_check
#ifdef ARITHEMETICAL_OPERATORS
	Point A(2, 3);
	Point B(3, 4);
	(A + B).Print();
	(A - B).Print();
	(A * B).Print();
	(A / B).Print();
#endif // ARITHEMETICAL_OPERATORS

	Point A(2, 3);
	Point B(3, 4);
	(A += B).Print(); //Неявный вызов оператора
	(A -= B).Print();
	A.operator+=(B);
	A.Print();
	operator/(A, B).Print(); //Явный вызов глобального оператора
	(++A).Print();
	(A++).Print();
	cout << A << endl;
}