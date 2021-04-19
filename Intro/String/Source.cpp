#include"String.h"
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define OPERATOR_PLUS_CHECK

void main()
{
	setlocale(0, "");
#ifdef CONSTRUCTORS_CHECK
	String str;
	str.Print();

	String str2 = "Hello";
	str2.Print();
	cout << str2 << endl;

	String str3 = str2; // CopyConstructor
	cout << "Str3:\t" << str3 << endl;

	String str4;
	str4 = str3; // CopyAsssignment
	cout << "Str4:\t" << str4 << endl;
#endif // CONSTRUCTORS_CHECK
#ifdef ASSIGNMENT_CHECK
	String str1 = "Hello";
	String str2;
	str1 = str1;
	cout << str1 << endl;
	cout << str2 << endl;
#endif // ASSIGNMENT_CHECK
#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	String str3;
	//String str3 = str1 + str2; // Опреатор + будет выполнять конкатенацию строк
	str1 += str2;
	cout << str1 << endl;
	//String str1;		//DefaultConstructor
	//String str2();		//Объявляется функция str2, которая ничего не принимает, и возвращает значение типа String
	//String str3{};		//DefaultConstructor
	//String str4(5);		//SizeConstructor
	//String str5{ 8 };
	//String str6("Hello");
	//String str7	{ "Hello" };
	//String str8 = 18;	//Неявное преобразование int в String
#endif // OPERATOR_PLUS_CHECK

	String A("Hello World");
	for (;;)
	{
		cout << A << '\t';
	}
}