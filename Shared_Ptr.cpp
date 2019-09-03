#include <iostream>

using namespace std;

void deleter(int* a)
{
	cout << "In custom deleter!" << endl;
	delete a;
}

class FunctorDeleter
{
public:
	void operator()(int* x)
	{
		cout << "In Functor Deleter!" << endl;
		delete x;
	}
};

int main()
{
	shared_ptr<int> ptr(new int(10));
	cout << "reference counting : " << ptr.use_count() << endl;
	cout << "value stored in ptr " << *ptr << endl;

	// modify value
	*ptr = 23;

	cout << "value stored in ptr " << *ptr << endl;

	// reset!
	ptr.reset();

	if (ptr)
		cout << "value stored in ptr " << *ptr << endl;
	cout << "reference counting : " << ptr.use_count() << endl;

	ptr = make_shared<int>();
	*ptr = 90;
	cout << "value stored in ptr " << *ptr << endl;
	cout << "reference counting : " << ptr.use_count() << endl;
	
	// Custom Deleter 1
	shared_ptr<int> ptr1(new int(10), deleter);
	ptr1.reset();

	// Custom Deleter 2
	shared_ptr<int> ptr2(new int(10), FunctorDeleter());
	ptr2.reset();

	// Custom Deleter 3
	shared_ptr<int> ptr3(new int(10), 
				[](int* x) 
				{
					cout << "in lambda function!";
					delete x;
		}
	);
	ptr3.reset();

	return 0;
}