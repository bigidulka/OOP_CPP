#pragma once
#include<iostream>
#include<exception>
#include<string>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define TEMP template<typename T>
//#define DEBUG
#define del "\n==========================================================================================\n"
//#define BASE_CHECK
#define HARDCORE
//#define COPY_METHODS_CHECK
//#define OPERATOR_PLUS_CHECK
//#define FACTORIAL
#ifdef BASE_CHECK
//#define ADDING_ELEMENTS_CHECK
//#define REMOVING_CHECK
#endif // BASE_CHECK

template<typename T>class Iterator;
template<typename T>class ForwardList;

template<typename T> class Element
{
	T Data; // «начение элемента
	Element* pNext; // ”казатель на следущий элемент
	static int count;
public:

	const Element* get_pNext()const;
	T get_data()const;
	//Constructors
	Element(T Data, Element* pNext = nullptr);
	~Element();
	friend class Iterator<T>;
	friend class ForwardList<T>;
	friend ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right);
};
template<typename T> class Iterator
{
	Element<T>* Temp;
public:
	Iterator(Element<T>* Temp = nullptr);
	~Iterator();
	//Operators
	Iterator<T>& operator++();
	Iterator<T> operator++(int);

	bool operator==(const Iterator<T>& other)const;
	bool operator!=(const Iterator<T>& other)const;
	const Element<T>* operator->()const;
	Element<T>* operator->();
	const T& operator*()const;
	T& operator*();
};
template<typename T> class ForwardList
{
	unsigned int size;
	Element<T>* Head; // ”казатель на начальный элемент списка
public:
	unsigned int get_size()const;
	const Element<T>* get_head()const;

	Iterator<T> begin();
	Iterator<T> end();
	// Constructors
	ForwardList();
	ForwardList(const initializer_list<T>& il);
	ForwardList(const ForwardList<T>& other);
	ForwardList(ForwardList<T>&& other);
	~ForwardList();
	//operators
	ForwardList<T>& operator=(const ForwardList<T>& other);
	ForwardList<T>& operator=(ForwardList<T>&& other);

	T& operator[](int index);

	// Adding elements
	void push_front(T Data);
	void push_back(T Data);
	void insert(int index, T Data);
	//Removing element
	void pop_front();
	void pop_back();
	void erase(int index);
	//Methods
	void print()const;
};