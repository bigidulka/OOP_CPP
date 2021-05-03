#include<iostream>
using namespace std;

class Animal
{
public:
	virtual ~Animal()
	{

	}
	virtual void sound()const = 0; //„исто виртуальный метод (Pure-virtual function), благодар€ которому класс €вл€етс€ абстрактным
};

class Cat :public Animal
{
	//Ёто тоже абстрактный класс, так как не реализует чисто виртуальный метод.
};

class Tiger :public Cat
{
	~Tiger()
	{

	}
	void sound()const
	{
		cout << "–––" << endl;
	}
};

class HomeCat :public Cat
{
	~HomeCat()
	{

	}
	void sound()const
	{
		cout << "ћ€у" << endl;
	}
};

class Dog :public Animal
{
	~Dog()
	{

	}
	void sound()const
	{
		cout << "√ав" << endl;
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