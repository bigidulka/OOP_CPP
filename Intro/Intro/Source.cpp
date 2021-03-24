#include<iostream>
using namespace std;

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
		this -> x = x;
	}
	void set_y(double y)
	{
		this -> y = y;
	}
	//constructors
	Point()
	{
		x = y = 0;
		cout << "DefConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//methdos
	void Print()const
	{
		cout << "X = " << x << '\t' << "Y = " << y << endl;
	}
};
void func(Point* p)
{
	cout << p->get_x() << '\t' << p->get_y() << endl;
}
// Создавая структуру или класс мы создаем новый тип данных
		// CLASS - это тип данных
		// STRUCT - это тип данных
//Обьекты класса или структуры являются переменными соответствующего типа

//#define intro

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
	Point A;	
	A.Print();
//#define razd "\n - - - - - - - - - - - \n"
	//cout << razd << endl;
	Point B(2, 3);
	B.Print();
}