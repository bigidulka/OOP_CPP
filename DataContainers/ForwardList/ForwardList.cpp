#include"Header.h"

template<typename T> unsigned int ForwardList<T>::get_size()const
{
	return size;
}
template<typename T> const Element<T>* ForwardList<T>::get_head()const
{
	return Head;
}
template<typename T> Iterator<T> ForwardList<T>::begin()
{
	return Head;
}
template<typename T> Iterator<T> ForwardList<T>::end()
{
	return nullptr;
}
template<typename T> ForwardList<T>::ForwardList()
{
	this->size = size;
	this->Head = nullptr; //nullptr в Head означает что список пуст
	cout << "LConstructor:\t\t" << this << endl;
}
template<typename T> ForwardList<T>::ForwardList(const initializer_list<T>& il) :ForwardList()
{
	cout << typeid(il.begin()).name() << endl;
	/*for (const int* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}*/
	for (T i : il)
	{
		push_back(i);
	}
	cout << "IlConstructor:\t" << this << endl;
}
template<typename T> ForwardList<T>::ForwardList(const ForwardList<T>& other) :ForwardList()
{
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
	{
		push_back(Temp->Data);
	}
	cout << "LCopyConstructor:\t" << this << endl;
}
template<typename T> ForwardList<T>::ForwardList(ForwardList<T>&& other)
{
	this->size = other.size;
	this->Head = other.Head;
	other.Head = nullptr;
	cout << "LMoveConstructor:\t" << this << endl;
}
template<typename T> ForwardList<T>::~ForwardList()
{
	//while (Head) pop_front();
	for (; Head; pop_front());
	cout << "LDestructor:\t\t" << this << endl;
}
template<typename T> ForwardList<T>& ForwardList<T>::operator=(const ForwardList<T>& other)
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
template<typename T> ForwardList<T>& ForwardList<T>::operator=(ForwardList<T>&& other)
{
	while (Head)pop_front();
	this->size = other.size;
	this->Head = other.Head;
	other.Head = nullptr;
	cout << "LMoveAssignment:\t" << this << endl;
	return *this;
}
template<typename T> T& ForwardList<T>::operator[](int index)
{
	if (index >= size)throw exception("Out of range"); // Бросить исключение
	Element* Temp = Head;
	for (int i = 0; i < index; i++)
	{
		Temp = Temp->pNext;
	}
	return Temp->Data;
}
template<typename T> void ForwardList<T>::push_front(T Data)
{
	//Element* New(new Element(Data));
	//New->pNext = Head;
	//Head = New;
	Head = new Element<T>(Data, Head);
	size++;
}
template<typename T> void ForwardList<T>::push_back(T Data)
{
	if (Head == nullptr)
	{
		return push_front(Data);
	}
	Element<T>* New = new Element<T>(Data);
	Element<T>* Temp = Head;
	while (Temp->pNext != nullptr)
	{
		Temp = Temp->pNext;
	}
	Temp->pNext = New;
	size++;
}
template<typename T> void ForwardList<T>::insert(int index, T Data)
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
template<typename T> void ForwardList<T>::pop_front()
{
	if (Head == nullptr)return;
	Element<T>* erase_element = Head; //1) Запоминаем адрес удаляемого элемента
	Head = Head->pNext; //2) Исключаем элемент из списка
	delete erase_element;//3) Удаляем элемент из памяти
	size--;
}
template<typename T> void ForwardList<T>::pop_back()
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
template<typename T> void ForwardList<T>::erase(int index)
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
template<typename T> void ForwardList<T>::print()const
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
template<typename T> ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right)
{
	ForwardList<T> cat = left; // CopyConstructor
	for (const Element* Temp = right.get_head(); Temp; Temp = Temp->get_pNext())
	{
		cat.push_back(Temp->get_data());
	}
	return cat;
}