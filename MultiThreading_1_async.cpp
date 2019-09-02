#include <iostream>
#include <future>

using namespace std;

int func()
{
	cout << " in func()" << endl;
	// lets do some processing!
	for (int i = 0; i < 10000; ++i)
		;
	return 10;
}

int main()
{
	future<int> result = async(func);
	cout << " Wait until something is returned \n Okay,Got it!: " << result.get();

	return 0;
}