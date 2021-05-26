#include"Header.h"
#include"Element.cpp"
#include"ForwardList.cpp"
#include"Iterator.cpp"

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
	cout << sizeof(Element<int>) << endl;
	ForwardList<int> list = { 3,5,8,13,21 };
	for (int i : list)
	{
		cout << i << "\t";
	}
	cout << endl;
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

	ForwardList<double> dfl = { 2.5, 2,87, 3.14, 5.9, 8.2 };
	for (double i : dfl) cout << i << '\t'; cout << endl;

	ForwardList<string> stih = { "Хорошо", "живет", "на", "свете", "Винни-Пух" };
	for (string i : stih) cout << i << ' '; cout << endl;
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