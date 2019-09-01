#include <iostream>

using namespace std;

class CAbstract
{
public:
	CAbstract(int a) : x(a){}
	int x{ 0 };
	int noOfCalls{ 0 };
	virtual int operator()(int num) = 0;
	int getNoOfInvokes() { return noOfCalls; }
};

class CAdd : public CAbstract
{
public:
	CAdd(int a) : CAbstract(a){}
	int operator()(int num2) 
	{ 
		++noOfCalls; 
		x = x + num2; 
		return x; 
	}
};

class CMul : public CAbstract
{

};


int main()
{
	CAdd addObj(7);
	cout << addObj(9) << endl;
	cout << addObj(9) << endl;
	cout << addObj(9) << endl;
	cout << addObj(9) << endl;
	cout << "\n No of Invokes: " << addObj.getNoOfInvokes() << endl;

	return 0;
}