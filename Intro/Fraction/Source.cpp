#include"Fraction.h"

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS
//#define COMPAUND_ASSIGNMENTS
//#define INCREMENT_CHECK
//#define COMPARISON_OPERATORS

void main()
{
	setlocale(0, "Rus");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.Print();
	cout << A << endl;
	Fraction B = 5;
	B.Print();
	cout << B << endl;
	Fraction C (1, 2);
	C.Print();
	cout << C << endl;
	Fraction D(3, 4, 5);
	D.Print();
	cout << D << endl;
#endif // CONSTRUCTORS_CHECK
#ifdef ARITHMETICAL_OPERATORS
	//Fraction A(11, 4);
	//cout << A << " = " << A.to_propper() << " = " << A.to_improper() << endl;

	//int numerator, denominator;
	//cout << "Введите дробь!" << "\nЧислитель: "; cin >> numerator; 
	//cout << "Знаменатель: "; cin >> denominator;
	//Fraction B(numerator, denominator);
	//cout << "Ответ: " << B.reduce() << endl;

	Fraction A(11, 4);
	Fraction B(5, 6, 7);
	{
		cout << "Числа: \n" << A << " и " << B << endl;

		cout << "Plus: " << endl;
		Fraction C(A + B);
		cout << C << " = " << C.to_propper() << endl;

		cout << "Minus" << endl;
		Fraction D(A - B);
		cout << D << " = " << D.to_propper() << endl;

		cout << "multiply" << endl;
		Fraction F(A * B);
		cout << F << " = " << F.to_propper() << endl;

		cout << "divide" << endl;
		Fraction G(A / B);
		cout << G << " = " << G.to_propper() << endl;
	}
#endif // ARITHMETICAL_OPERATORS
#ifdef COMPAUND_ASSIGNMENTS
	double a = 2;
	double b = 3;
	a *= 3;
	Fraction A(11, 4);
	Fraction B(5, 6, 7);
	cout << A << "\t" << B << endl;
	A *= B;
	cout << A << endl;
	A /= B;
	cout << A << endl;
	cout << A - A << endl;
#endif // COMPAUND_ASSIGNMENTS
#ifdef INCREMENT_CHECK
	Fraction A(10, 5);
	Fraction B(11, 5);
	int luck = 0;
	int dontLuck = 0;
	if (A == A) luck++;
	else dontLuck++;
	if (A != B) luck++;
	else dontLuck++;
	if (A <= B) luck++;
	else dontLuck++;
	if (A >= A) luck++;
	else dontLuck++;
	if (A < B) luck++;
	else dontLuck++;
	if (A > 0) luck++;
	else dontLuck++;
	cout << "WORK: " << luck << endl << "DONTWORK: " << dontLuck << endl;
	Fraction C(1, 1);
	C++;
	cout << C << endl;
	C--;
	cout << C << endl;

	for (double i = .3; i < 10; i++)
		cout << i << '\t';
	cout << endl;
	for (Fraction i(3, 4); i.get_integer() < 10; i++)
		cout << i << '\t';
	cout << endl;
#endif // INCREMENT_CHECK
#ifdef COMPARISON_OPERATORS
	Fraction A(1, 2);
	Fraction B(5, 10);
	/*if (A == B) cout << "Дроби равны!" << endl;
	else cout << "Дроби разные!" << endl;*/
	cout << A << "\t" << B << endl;
	if (A == B) printf("+\n"); else printf("-\n");
	if (A != 0) printf("+\n"); else printf("-\n");
	cout << A << "\t" << B << endl;
#endif // COMPARISON_OPERATORS

	//Fraction A = (Fraction)5; // из int в fraction - одиночный конструктор
	Fraction A(5); // explicit конструктор можно вызвать только так, и невозможно вызвать операторм =
	cout << A << endl;
	A = Fraction(8); // копия
	cout << A << endl;
	Fraction B(3, 4, 5);
	double b = (double)B;
	cout << b << endl;

	Fraction C = 2.5;
	Fraction G = 2.55;
	Fraction K = 25;
	cout << C << endl;
	cout << G << endl;
	cout << K << endl;
	cout << B / B << endl;
}