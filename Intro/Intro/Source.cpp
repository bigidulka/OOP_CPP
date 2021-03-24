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
// �������� ��������� ��� ����� �� ������� ����� ��� ������
		// CLASS - ��� ��� ������
		// STRUCT - ��� ��� ������
//������� ������ ��� ��������� �������� ����������� ���������������� ����

//#define intro

void main()
{
	setlocale(0, " ");
#ifdef intro
	int a;		// ��������� ����������� a ���� int
	Point A;	// ��������� ���������� � ���� Point
				// ������� ������ � ��������� Point
				//������� ��������� � ��������� Point
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << '\t' << A.get_y() << endl;

	Point* pA = &A;
	cout << pA->get_x() << '\t' << pA->get_y() << endl;
	cout << sizeof(A) << endl;
	cout << sizeof(pA) << endl;
	{
		//��������� ������� ��������� ������ ������� main
		//class obj;
	}
	//����� ������� obj ��� �� �����
	//cout << (*pA).x << '\t' << (*pA).x << endl;
#endif // intro
	Point A;	
	A.Print();
//#define razd "\n - - - - - - - - - - - \n"
	//cout << razd << endl;
	Point B(2, 3);
	B.Print();
}