#include<iostream>
#include<exception>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define DEBUG
#define del "\n==========================================================================================\n"

class Element
{
	int Data; // Значение элемента
	Element* pNext; // Указатель на следущий элемент
	static int count;
public:

	const Element* get_pNext()const
	{
		return pNext;
	}
	int get_data()const
	{
		return Data;
	}
	//Constructors
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
	friend class Iterator;
	friend class ForwardList;
	friend ForwardList operator+(const ForwardList& left, const ForwardList right);
};
int Element::count = 0; //Инициализация статической переменной

class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr) :Temp(Temp)
	{
#ifdef DEBUG
		cout << "IConstructor:\t" << this << endl;
#endif // DEBUG
	}
	~Iterator()
	{
#ifdef DEBUG
		cout << "iDestructor:\t" << this << endl;
#endif // DEBUG
	}

	//Operators
	Iterator& operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}
	Iterator operator++(int)
	{
		Iterator old = *this;
		Temp = Temp->pNext;
		return old;
	}

	bool operator==(const Iterator& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const Iterator& other)const
	{
		return this->Temp != other.Temp;
	}
	const Element* operator->()const
	{
		return Temp;
	}
	Element* operator->()
	{
		return Temp;
	}
	const int& operator*()const
	{
		return Temp->Data;
	}
	int& operator*()
	{
		return Temp->Data;
	}
};

class ForwardList
{
	unsigned int size;
	Element* Head; // Указатель на начальный элемент списка
public:
	unsigned int get_size()const
	{
		return size;
	}
	const Element* get_head()const
	{
		return Head;
	}

	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	// Constructors
	ForwardList()
	{
		this->size = size;
		this->Head = nullptr; //nullptr в Head означает что список пуст
		cout << "LConstructor:\t\t" << this << endl;
	}
	ForwardList(const initializer_list<int>& il):ForwardList()
	{
		cout << typeid(il.begin()).name() << endl;
		/*for (const int* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}*/
		for (int i : il)
		{
			push_back(i);
		}
		cout << "IlConstructor:\t" << this << endl;
	}
	ForwardList(const ForwardList& other):ForwardList()
	{
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		{
			push_back(Temp->Data);
		}
		cout << "LCopyConstructor:\t" << this << endl;
	}
	ForwardList(ForwardList&& other)
	{
		this->size = other.size;
		this->Head = other.Head;
		other.Head = nullptr;
		cout << "LMoveConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		//while (Head) pop_front();
		for (; Head; pop_front());
		cout << "LDestructor:\t\t" << this << endl;
	}
	//operators
	ForwardList& operator=(const ForwardList& other)
	{
		// Проверяем, не является ли список самим собой
		if (this == &other)return *this;
		// Очищаем список от старых значений
		while (Head)pop_front();
		// Копируем список
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		{
			push_back(Temp->Data);
		}
		cout << "LCopyAssignment:\t" << this << endl;
		return *this;
	}
	ForwardList& operator=(ForwardList&& other)
	{
		while (Head)pop_front();
		this->size = other.size;
		this->Head = other.Head;
		other.Head = nullptr;
		cout << "LMoveAssignment:\t" << this << endl;
		return *this;
	}

	int& operator[](int index)
	{
		if (index >= size)throw exception("Out of range"); // Бросить исключение
		Element* Temp = Head;
		for (int i = 0; i < index; i++)
		{
			Temp = Temp->pNext;
		}
		return Temp->Data;
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
		//for(Element* Temp = Head; Temp != nullptr; Temp = Temp->pNext/*Temp++*/)
		//	cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
		for (Iterator Temp = Head; Temp != nullptr; Temp++)
			cout << *Temp << '\t';
		cout << endl;
		cout << "В списке " << size << " элементов\n";
		cout << "Общее количество элементов: " << Element::count << endl;
	}
};
ForwardList operator+(const ForwardList& left, const ForwardList right)
{
	ForwardList cat = left; // CopyConstructor
	for (const Element* Temp = right.get_head(); Temp; Temp = Temp->get_pNext())
	{
		cat.push_back(Temp->get_data());
	}
	return cat;
}

//#define BASE_CHECK
#define HARDCORE
//#define COPY_METHODS_CHECK
//#define OPERATOR_PLUS_CHECK
//#define FACTORIAL
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
#ifdef HARDCORE
	int arr[] = { 3, 5, 8, 13, 21, 34, 55 };
	cout << sizeof(Element) << endl;
	ForwardList list = { 3,5,8,13,21 };
	//for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	//{
	//	cout << arr[i] << "\t";
	//}

	//range-based for (Диапазонный фор, фор для контейнера, для структуры данных)
	for (int i : list)
	{
		cout << i << '\t';
	}
	cout << endl;
	//list.print();
#endif // HARDCORE
#ifdef FACTORIAL
	//try
	//{
	//	for (int i = 0; i < list.get_size(); i++)
	//	{
	//		list[i] = rand() % 100;
	//	}
	//	for (int i = 0; i < list.get_size(); i++)
	//	{
	//		cout << list[i] << "\t";
	//	}
	//	cout << endl;
	//}
	//catch (const exception& e)
	//{
	//	cerr << e.what() << endl; // Метод what возвращает сообщение об ошибке
	//}
#endif // FACTORIAL
#ifdef COPY_METHODS_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list = list;
	list.print();
	cout << del;
	//ForwardList list2 = list; // CopyConstructor
	ForwardList list2; // DefaultConstructor
	list2 = list; // CopyAssignment
	list2.print();
#endif // COPY_METHODS_CHECK
#ifdef OPERATOR_PLUS_CHECK
	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);
	ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);
	list2.push_back(144);
	cout << del << endl;
	ForwardList list3;
	list3 = list1 + list2;
	list3.print();
	cout << del << endl;
#endif // OPERATOR_PLUS_CHECK
}