#include <iostream>
#include <future>

using namespace std;

class Base
{
public:
	void fun()
	{
		cout << "In Base::fun()" << endl;
	}
};

class D1 : virtual public Base
{
};

class D2 : virtual public Base
{
};

class MultiInheritence : public D1, public D2
{
};

int main()
{
	MultiInheritence mhObj;
	mhObj.fun();

	return 0;
}