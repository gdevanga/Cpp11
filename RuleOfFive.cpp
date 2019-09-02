#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class A
{
public:
	int x;
	int* pX{ nullptr };
	vector<string> v;
	A() {}
	A(int x, int* pX, vector<string> &v) : x(x), pX(new int(*pX)), v(v) {}

	// Destructor
	~A() { delete pX; }

	// Copy Constructor
	A(const A& other) : x(other.x), pX(other.pX ? new int(*(other.pX)) : nullptr), v(other.v) 
	{
		cout << " in copy constructor" << endl;
	}
	// Copy Assignment operator
	A& operator=(const A& other)
	{
		cout << " in copy assignment operator" << endl;
		if (this == &other)
			return *this;
		x = other.x;
		if (pX)
		{
			delete pX;
			pX = nullptr;
		}
		if (other.pX)
		{
			pX = new int(*(other.pX));
		}
		v = other.v;
	}
	// Move Constructor
	A(A&& other) : x(other.x)
	{
		cout << " in move constructor" << endl;
		v = std::move(other.v);
		std::swap(pX, other.pX);
	}
	// Move Assignment operator
	A& operator=(A&& other)
	{
		cout << " in move assignment operator" << endl;
		x = other.x;
		v = std::move(other.v);
		std::swap(pX, other.pX);
		return *this;
	}
};

int main()
{
	int x = 10;
	int* pX = new int(20);
	vector<string> v;
	v.emplace_back("abc");
	v.emplace_back("xyz");

	// constructor
	A a1(x, pX, v);

	//copy constructor
	A a2(a1);

	// move constructor
	A a3 = std::move(a2);

	// copy assignment operator
	A a4;
	a4 = a3;

	// move assignment operator
	A a5;
	a5 = move(a4);





	return 0;
}