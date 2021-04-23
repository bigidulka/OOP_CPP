#include<iostream>
using namespace std;

//#define DEBUG
#define DEF "--------------------------------------------------------------------------------"

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		if (age >= 15 && age <= 100) this->age = age;
		else this->age = 0;
	}

	//Constructors
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
#ifdef DEBUG
		cout << "HConstructor:\t" << this << endl;
#endif // DEBUG
	}
	~Human()
	{
#ifdef DEBUG
		cout << "HDestructor:\t" << this << endl;
#endif // DEBUG
	}

	//Methods
	void info()const
	{
		cout << "Имя и Фамилия:\t" << last_name << " " << first_name << "\nВозраст:\t" << age << endl;
	}
};
class Student :public Human
{
	string speciality;
	double rating;
	unsigned int semester;
public:
	const string& get_specialty()const
	{
		return speciality;
	}
	double get_rating()const
	{
		return rating;
	}
	unsigned int get_semester()const
	{
		return semester;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_rating(double rating)
	{
		if (rating > 0 && rating <= 5)
		{
			this->rating = rating;
		}
		else rating = 0;
	}
	void set_semester(unsigned int semester)
	{
		if (semester <= 5)
		{
			this->semester = semester;
		}
		else this->semester = 0;
	}

	//Constructors
	Student(const string& last_name, const string& first_name, unsigned int age, const string& speciality, double rating, unsigned int semester) :
		Human(last_name, first_name, age)
	{
		this->speciality = speciality;
		this->rating = rating;
		this->semester = semester;
#ifdef DEBUG
		cout << "SConstructor:\t" << this << endl;
#endif // DEBUG
	}
	~Student()
	{
#ifdef DEBUG
		cout << "SDestructor:\t" << this << endl;
#endif // DEBUG
	}

	//Methods
	void info()const
	{
		Human::info();
		cout << "Специальность:\t" << speciality << "\nУспеваемость:\t" << rating << "\nСеместер:\t" << semester << endl;
	}
};
class Teacher :public Human
{
	string speciality;
	unsigned int experience;
public:
	unsigned int get_experience()const
	{
		return experience;
	}
	const string& get_specialty()const
	{
		return speciality;
	}
	void set_experience(unsigned int experience)
	{
		if (experience <= 80) this->experience = experience;
		else experience = 0;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}

	Teacher(const string& last_name, const string& first_name, unsigned int age, const string& speciality, unsigned int experience) :
		Human(last_name, first_name, age)
	{
		this->speciality = speciality;
		this->experience = experience;
#ifdef DEBUG
		cout << "TConstructor:\t" << this << endl;
#endif // DEBUG
	}
	~Teacher()
	{
#ifdef DEBUG
		cout << "TDestructor:\t" << this << endl;
#endif // DEBUG
	}

	void info()const
	{
		Human::info();
		cout << "Специальность:\t" << speciality << "\nОпыт:\t\t" << experience << " лет" << endl;
	}
};
class Graduate :public Student
{
	double GPA;
	unsigned int year_of_issue;
	bool diplom;
public:
	double get_GPA()const
	{
		return GPA;
	}
	unsigned int get_year_of_issue()const
	{
		return year_of_issue;
	}
	bool get_diplom()const
	{
		return diplom;
	}
	void set_GPA(double GPA)
	{
		if (GPA > 0 && GPA <= 5)
		{
			this->GPA = GPA;
		}
		else GPA = 0;
	}
	void set_year_of_issue(unsigned int year_of_issue)
	{
		if (GPA >= 2000 && 2100 <= GPA) this->GPA = GPA;
		else this->GPA = 0;
	}
	void set_bool(bool diplom)
	{
		this->diplom = diplom;
	}

	Graduate(const string& last_name, const string& first_name, unsigned int age, const string& speciality, double rating, unsigned int semester, double GPA, unsigned int year_of_issue, bool diplom) :
		Student(last_name, first_name, age, speciality, rating, semester)
	{
		this->GPA = GPA;
		this->year_of_issue = year_of_issue;
		this->diplom = diplom;
#ifdef DEBUG
		cout << "GConstructor:\t" << this << endl;
#endif // DEBUG
	}
	~Graduate()
	{
#ifdef DEBUG
		cout << "GDestructor:\t" << this << endl;
#endif // DEBUG
	}

	void info()const
	{
		Student::info();
		cout << "Средний балл аттестата:\t" << GPA << "\nВыпускной:\t" << year_of_issue << endl;
		if (diplom) cout << "Диплом:\t\t" << "Есть" << endl;
		else cout << "Диплом:\t\t" << "Нету" << endl;
	}
};

void main()
{
	setlocale(0, "Rus");
	Teacher teacher1("Петров", "Петр", 90, "Сварщик, Электрогазосварщик, Газосварщик", 65);
	teacher1.info();
	cout << DEF << endl;
	Student student1("Иванов", "Иван", 21, "Сварщик", 2.3, 3);
	student1.info();
	cout << DEF << endl;
	Graduate graduate1("Степан", "Степанович", 23, "Электрогазосварщик", 4.5, 5, 4.5, 2007, true);
	graduate1.info();
}