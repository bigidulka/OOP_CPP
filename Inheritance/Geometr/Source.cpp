#include<iostream>
using namespace std;

class Shape
{
	string color;
public:
	Shape(const string& color)
	{
		this->color = color;
	}
	virtual double area()const = 0;
	virtual double perimeter()const = 0;
	virtual void draw()const = 0;
};
class Square:public Shape
{
	double side;
public:
	double get_side()const
	{
		return side;
	}
	void set_side(double side)
	{
		if (side > 0) this->side = side; else this->side = side;
	}
	explicit Square(double side, const string& color = "White") :Shape(color)
	{
		set_side(side);
	}
	~Square()
	{

	}
	double area()const
	{
		return side * side;
	}
	double perimeter()const
	{
		return side * 4;
	}
	void draw()const
	{
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				cout << "+ ";
			}
			cout << endl;
		}
	}
};
class Rectangle : public Shape
{
	double a, b;
public:
	double get_a()const
	{
		return a;
	}
	double get_b()const
	{
		return b;
	}
	void set_a(double a)
	{
		this->a = a;
	}
	void set_b(double b)
	{
		this->b = b;
	}
	explicit Rectangle(double a, double b, const string& color) :Shape(color)
	{
		set_a(a);
		set_b(b);
	}
	~Rectangle()
	{

	}
	double area()const
	{
		return a * b;
	}
	double perimeter()const
	{
		return (a + b) * 2;
	}
	void draw()const
	{
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				cout << "+ ";
			}
			cout << endl;
		}
	}
};


void main()
{
	setlocale(0, "Rus");
	Square sq(5, "White");
	cout << "Площадь: " << sq.area() << endl;
	cout << "Периметр: " << sq.perimeter() << endl;
	sq.draw();
	Rectangle re(5, 8, "White");
	cout << "Площадь: " << re.area() << endl;
	cout << "Периметр: " << re.perimeter() << endl;
	re.draw();
}