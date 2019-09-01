#include <iostream>
#include <thread>
#include <mutex>
#include <future>

using namespace std;


void f1(future<int> &fut)
{
	cout << "thread 1 started" << endl;
	int x = fut.get();
	cout << "x :" << x << endl;
}

int main()
{
	promise<int> prom;
	future<int> fut = prom.get_future();
	thread t1 = thread(f1, ref(fut));

	cout << "Setting promise now.." << endl;
	prom.set_value(10);

	cout << "Waiting for thread1 to finish" << endl;
	if (t1.joinable())
		t1.join();

	cout << "Main exited Normally" << endl;
	return 0;
}