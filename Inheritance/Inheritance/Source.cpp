#include<iostream>
using namespace std;

#define DEBUG

class Box
{
	double width;
	double height;
	double length;
	string material;
public:
	double get_width()const
	{
		return width;
	}
	double get_height()const
	{
		return height;
	}
	double get_length()const
	{
		return length;
	}
	const string& get_material()const
	{
		return this->material;
	}
	//Constructors
	Box(double width, double height, double length, const string& material) :
		width(width), height(height), length(length), material(material)
	{
		cout << "BoxConstructor:\t\t" << this << endl;
	}
	~Box()
	{
		cout << "BoxDestructor:\t\t" << this << endl;
	}
	//Methods
	void info()const
	{
		cout << "Dimensions: " << width << "x" << height << "x" << length << endl;
		cout << "Материал: " << material << endl;
	}
};

class GiftBox:public Box
{
	string cover;
public:
	const string& get_cover()const
	{
		return cover;
	}
	//Constructors
	GiftBox(double width, double height, double length, const string& material, const string& cover) :
		Box(width, height, length, material)
	{
		this->cover = cover;
		cout << "GiftBoxConstructor:\t" << this << endl;
	}
	~GiftBox()
	{
		cout << "GiftBoxDestructor:\t" << this << endl;
	}
	//Methdos
	void info()const
	{
		Box::info();
		cout << "Упаковка: " << cover << endl;
	}
};

void main()
{
	setlocale(0, "Rus");
	/*Box box (2, 5, 8, "Картон");
	box.info();*/
	GiftBox giftBox(2, 5, 8, "Картон", "С котами и мышами");
	giftBox.info();
}