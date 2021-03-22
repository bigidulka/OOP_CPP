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
};
void func(Point* pA)
{
	cout << pA;
}
// Создавая структуру или класс мы создаем новый тип данных
		// CLASS - это тип данных
		// STRUCT - это тип данных
//Обьекты класса или структуры являются переменными соответствующего типа

void main()
{
	setlocale(0, " ");
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
	//cout << (*pA).x << '\t' << (*pA).x << endl;
}