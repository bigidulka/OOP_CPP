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
// �������� ��������� ��� ����� �� ������� ����� ��� ������
		// CLASS - ��� ��� ������
		// STRUCT - ��� ��� ������
//������� ������ ��� ��������� �������� ����������� ���������������� ����

void main()
{
	setlocale(0, " ");
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
	//cout << (*pA).x << '\t' << (*pA).x << endl;
}