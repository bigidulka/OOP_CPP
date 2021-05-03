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
	virtual ~Human()
	{
#ifdef DEBUG
		cout << "HDestructor:\t" << this << endl;
#endif // DEBUG
	}

	//Methods
	virtual void info()const
	{
		cout << "��� � �������:\t\t" << last_name << " " << first_name << "\n�������:\t\t" << age << endl;
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
		cout << "�������������:\t\t" << speciality << "\n������������:\t\t" << rating << "\n��������:\t\t" << semester << endl;
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
		cout << "�������������:\t\t" << speciality << "\n����:\t\t\t" << experience << " ���" << endl;
	}
};
class Graduate :public Student
{
	double GPA;
	unsigned int year_of_issue;
	bool diplom;
	string topic;
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
	const string& get_topic()const
	{
		return topic;
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
	void set_topic(const string& topic)
	{
		this->topic = topic;
	}

	Graduate(
		const string& last_name, const string& first_name, unsigned int age, 
		const string& speciality, double rating, unsigned int semester, 
		double GPA, const string& topic, unsigned int year_of_issue, bool diplom) :
		Student(last_name, first_name, age, speciality, rating, semester)
	{
		this->GPA = GPA;
		this->year_of_issue = year_of_issue;
		this->diplom = diplom;
		this->topic = topic;
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
		cout << "������� ���� ���������:\t" << GPA << "\n���������:\t\t" << year_of_issue << "\n���� �������:\t\t" << topic << endl;
		if (diplom) cout << "������:\t\t\t" << "����" << endl;
		else cout << "������:\t\t\t" << "����" << endl;
	}
};

void main()
{
	setlocale(0, "Rus");
	/*Teacher teacher1("������", "����", 90, "�������, ������������������, �����������", 65);
	Student student1("������", "����", 21, "�������", 2.3, 3);
	Graduate graduate1("������", "��������", 23, "������������������", 4.5, 5, 4.5, "��� ��������� �� ��������", 2007, true);*/

	/*Human* p_student1 = &student1;
	Human* p_teacher1 = &teacher1;
	Human* p_graduate1 = &graduate1;

	Human* group[] =
	{
		&student1, &teacher1, &graduate1
	};*/
	Human* group[] =
	{
		new Teacher("������", "����", 90, "�������, ������������������, �����������", 65),
		new Graduate("������", "��������", 23, "������������������", 4.5, 5, 4.5, "��� ��������� �� ��������", 2007, true),
		new Student("������", "����", 21, "�������", 2.3, 3),
		new Student("���������", "�������", 25, "����������������", 4.5, 2),
		new Student("Montana", "Antonio", 30, "Cocaine Diller", 4.8, 4)
	};
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		group[i]->info();
		cout << DEF << endl;
	}
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}
}