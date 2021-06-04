#include<iostream>
using namespace std;

class Tree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
		{
			this->Data = Data;
			this->pLeft = pLeft;
			this->pRight = pRight;
#ifdef DEBUG
			cout << "EConstructor:\t" << this << endl;
#endif // 
		}
		~Element()
		{
#ifdef DEBUG
			cout << "EDestructor:\t" << this << endl;
#endif // 
		}
		bool is_leaf()const
		{
			return pLeft == pRight;
		}
		friend class Tree;
	}*Root; //��������� �� �������� �������
public:
	const Element* getRoot()const
	{
		return Root;
	}
	Element* getRoot()
	{
		return Root;
	}
	Tree() :Root(nullptr)
	{
#ifdef DEBUG
		cout << "TContructor:\t" << this << endl;
#endif // 
	}
	Tree(const initializer_list<int>& il) :Tree()
	{
		cout << typeid(il.begin()).name() << endl;
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			insert(*it);
		}
	}
	Tree(const Tree& other) :Tree()
	{
		copy(other.Root);
#ifdef DEBUG
		cout << "CopyConstructor:\t" << this << endl;
#endif // 
	}
	~Tree()
	{
		clear(Root);
#ifdef DEBUG
		cout << "TDestructor:\t" << this << endl;
#endif // 
	}
	Tree& operator=(const Tree& other)
	{
		if(this == &other)
		clear();
		copy(other.Root);
#ifdef DEBUG
		cout << "CopyAssignment:\t" << this << endl;
#endif // 
		return *this;
	}
	void insert(int Data)
	{
		insert(Data, Root);
	}
	void erase(const int& Data)
	{
		erase(Data, Root);
	}
	int minValue()
	{
		return minValue(Root);
	}
	int maxValue()
	{
		return maxValue(Root);
	}
	int size()
	{
		return size(Root);
	}
	int sum()
	{
		return sum(Root);
	}
	double avg()
	{
		return avg(Root);
	}
	void print()
	{
		print(Root);
		cout << endl;
	}
	void clear()
	{
		clear(Root);
	}
private:
	void copy(Element* Root)
	{
		if (Root == nullptr) return;
		insert(Root->Data);
		copy(Root->pLeft);
		copy(Root->pRight);
	}
	void insert(int Data, Element* Root) // ����� Element* Root - ��� ��������� �� ����� (���������)
	{
		if (this->Root == nullptr) this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr) // ���� ������� ������� (Root) �� ����� ������ �������
				Root->pLeft = new Element(Data); // ������� ���
			else // � ��������� ������, ���� ������
				insert(Data, Root->pLeft);
		}
		else /*if(Data > Root->Data)*/
		{
			//if (Root->pRight == nullptr) // ���� ������� ������� (Root) �� ����� ������� �������
			//	Root->pRight = new Element(Data);
			//else
			//	insert(Data, Root->pRight);
			if (Root->pRight)insert(Data, Root->pRight);
			else Root->pRight = new Element(Data);
		}
	}
	void erase(const int& Data, Element*& Root)
	{
		if (Root == nullptr)return;
		erase(Data, Root->pLeft);
		erase(Data, Root->pRight);
		if (Data == Root->Data)
		{
			if (Root->is_leaf())
			{
				delete Root;
				Root = nullptr;
			}
			else
			{
				if (Root->pLeft)
				{
					Root->Data = maxValue(Root->pLeft);
					erase(maxValue(Root->pLeft), Root->pLeft);
				}
				else
				{
					Root->Data = minValue(Root->pRight);
					erase(minValue(Root->pRight), Root->pRight);
				}
			}
		}
	}
	int minValue(Element* Root)
	{
		/*Element* BUF = Root;
		while (BUF->pLeft != nullptr)
		{
			BUF = BUF->pLeft;
		}
		return(BUF->Data);*/
		/*if (Root->pLeft == nullptr)return Root->Data;
		else return minValue(Root->pLeft);*/
		return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
	}
	int maxValue(Element* Root)
	{
		/*if (Root->pRight == nullptr)return Root->Data;
		else return maxValue(Root->pRight);*/
		return Root->pRight ? maxValue(Root->pRight) : Root->Data;
	}
	int size(Element* Root)
	{
		/*if (Root == nullptr) return 0;
		return size(Root->pLeft) + size(Root->pRight) + 1;*/
		return Root == nullptr ? 0 : size(Root->pLeft) + size(Root->pRight) + 1;
	}
	int sum(Element* Root)
	{
		return Root == nullptr ? 0 : sum(Root->pLeft) + sum(Root->pRight) + Root->Data;
	}
	double avg(Element* Root)
	{
		return (double)sum(Root) / size(Root);
	}
	void print(Element* Root)
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << '\t';
		print(Root->pRight);
	}
	void clear(Element* Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
		Root = nullptr;
	}
};
#define BASE
void main()
{
	setlocale(0, "Rus");
#ifdef BASE
	/*int n;
	cout << "������� ���������� ��������: "; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}*/
	Tree tree = { 50,25,16,32,64,55,77 };
	Tree tree2; // CopyConstructor
	tree2 = tree;
	tree.print();
	tree2.print();
	cout << endl;
	cout << "����������� �������� � ������: " << tree.minValue() << endl;
	cout << "������������ �������� � ������: " << tree.maxValue() << endl;
	cout << "������ ������: " << tree.size() << endl;
	cout << "����� ��������� ������: " << tree.sum() << endl;
	cout << "������� �������������� ��������� ������: " << tree.avg() << endl;
	int value;
	cout << "������� ��������� ��������: "; cin >> value;
	tree.erase(value);
	tree.print();
	tree.clear();
	cout << tree.getRoot() << endl;
	tree.print();
#endif // BASE
}