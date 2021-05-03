#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define DEBUG

class Element
{
	int Data; // Значение элемента
	Element* pNext; // Указатель на следущий элемент
	static int count;
public:
	Element(int Data, Element* pNext = nullptr):Data(Data), pNext(pNext)
	{
		count++;
#ifdef DEBUG
		cout << "EConstructor:\t" << this << endl;
#endif // DEBUG
	}
	~Element()
	{
		count--;
#ifdef DEBUG
		cout << "EDestructor:\t" << this << endl;
#endif // DEBUG
	}
	friend class ForwardList;
};
int Element::count = 0; //Инициализация статической переменной
class ForwardList
{
	unsigned int size;
	Element* Head; // Указатель на начальный элемент списка
public:
	ForwardList()
	{
		this->size = size;
		this->Head = nullptr; //nullptr в Head означает что список пуст
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		//while (Head) pop_front();
		for (; Head; pop_front());
		cout << "LDestructor:\t" << this << endl;
	}
	// Adding elements
	void push_front(int Data)
	{
		//Element* New(new Element(Data));
		//New->pNext = Head;
		//Head = New;
		Head = new Element(Data, Head);
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			return push_front(Data);
		}
		Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = New;
		size++;
	}
	void insert(int index, int Data)
	{
		if (index > Element::count) return;
		if (index == 0) return push_front(Data);
		Element* New = new Element(Data);
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}
	//Removing element
	void pop_front()
	{
		if (Head == nullptr)return;
		Element* erase_element = Head; //1) Запоминаем адрес удаляемого элемента
		Head = Head->pNext; //2) Исключаем элемент из списка
		delete erase_element;//3) Удаляем элемент из памяти
		size--;
	}
	void pop_back()
	{
		if (Head == nullptr)return;
		if (Head->pNext == nullptr)
		{
			return pop_front();
		}
		Element* Temp = Head;
		while (Temp->pNext->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}
	void erase(int index)
	{
		if (index < 0 || index >= size) return;
		if (index == 0) return pop_front();
		if (index == size - 1) return pop_back();
		Element* Temp = Head;
		for (int i = 0; i < index; i++)
		{
			Temp = Temp->pNext;
		}
		Element* buffer = Temp->pNext->pNext;
		delete Temp->pNext;
		Temp->pNext = buffer;
		size--;
	}
	//Methods
	void print()const
	{
		/*
		//Для того чтобы ходить по списку нужны
		//1) Итератор
		//2) Цикл
		Element* Temp = Head; //Temp - это итератор, Итератор - указатель при помощи которого можно получить доступ к элементам структуры данных
		while (Temp != nullptr)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			Temp = Temp->pNext; //Переход на  следующий элемент
		}
		*/
		for(Element* Temp = Head; Temp != nullptr; Temp = Temp->pNext)
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
		cout << "В списке " << size << " элементов\n";
		cout << "Общее количество элементов: " << Element::count << endl;
	}
};
//#define BASE_CHECK
#ifdef BASE_CHECK
//#define ADDING_ELEMENTS_CHECK
//#define REMOVING_CHECK
#endif // BASE_CHECK
void main()
{
	setlocale(0, "Rus");
#ifdef  BASE_CHECK
	int n; cout << "Размер: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
		//list.push_back(rand() % 100);
	}
	//list.print();
	cout << "List Ready" << endl;
#ifdef REMOVING_CHECK
	//list.pop_front();
	//list.pop_back();
	//cout << "Индекс: "; cin >> index;
	list.push_front(57);
	list.print();
#endif // REMOVING_CHECK
#ifdef ADDING_ELEMENTS_CHECK
	list.print();
	int value, index;
	cout << "Введите значение: "; cin >> value;
	cout << "\nВведите индекс: "; cin >> index;
	list.insert(index, value);
	list.print();
	//list.push_back(value);
	//list.print();

	ForwardList list2;
	cout << "Размер: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		list2.push_back(rand() % 100);
	}
	list2.print();


#endif //  ADDING_ELEMENTS_CHECK
#endif //  BASE_CHECK

	/*int arr[] = { 3, 5, 8, 13, 21, 34, 55, 89 };
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		cout << arr[i] << "\t";
	}*/

	//ForwardList list = { 3,5,8,13,21 };
	//list.print();
	/*for (int i = 0; i < list.get_size(); i++)
	{
		cout << list[i] << "\t";
	}*/
}