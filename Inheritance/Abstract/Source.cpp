#include<iostream>
using namespace std;

class Animal
{
public:
	virtual ~Animal()
	{

	}
	virtual void sound()const = 0; //����� ����������� ����� (Pure-virtual function), ��������� �������� ����� �������� �����������
};

class Cat :public Animal
{
	//��� ���� ����������� �����, ��� ��� �� ��������� ����� ����������� �����.
};

class Tiger :public Cat
{
	~Tiger()
	{

	}
	void sound()const
	{
		cout << "���" << endl;
	}
};

class HomeCat :public Cat
{
	~HomeCat()
	{

	}
	void sound()const
	{
		cout << "���" << endl;
	}
};

class Dog :public Animal
{
	~Dog()
	{

	}
	void sound()const
	{
		cout << "���" << endl;
	}
};

void main()
{
	setlocale(0, "Rus");

	//Cat tom;
	//Dog sky;

	//Generalization
	Animal* zoo[] =
	{
		new HomeCat,
		new Dog,
		new Tiger,
		new Dog,
		new HomeCat
	};
	//Specialisation
	for (int i = 0; i < sizeof(zoo) / sizeof(Animal*); i++)
	{
		zoo[i]->sound();
	}
	for (int i = 0; i < sizeof(zoo) / sizeof(Animal*); i++)
	{
		delete zoo[i];
	}
}