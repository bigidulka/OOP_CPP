#include"Header.h"

template<typename T> const Element<T>* Element<T>::get_pNext()const
{
	return pNext;
}
template<typename T> T Element<T>::get_data()const
{
	return Data;
}
template<typename T> Element<T>::Element(T Data, Element* pNext) :Data(Data), pNext(pNext)
{
	count++;
#ifdef DEBUG
	cout << "EConstructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T> Element<T>:: ~Element()
{
	count--;
#ifdef DEBUG
	cout << "EDestructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T> int Element<T>::count = 0; //Инициализация статической переменной